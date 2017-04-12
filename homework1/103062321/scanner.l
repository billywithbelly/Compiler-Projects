/* 
    argument :
    ./scanner < test0_1.c 1>output.txt 2>error.txt
*/


%{
    #include <stdio.h>
    #include <string.h>
    int lineCount=1; 
    int charCount=0;
    char id[256];
    int id_line;
    int declare_flag = 0;
    char parsed[1024];
    int startLine = 1;
    int doubleOrFloat = 0; // double = 1, float = 2;
    void print(FILE *fp, int lineNum, char* type){
        fprintf(fp, "#%d %s\n", lineNum, type);
    }
%}

PUNC            ":"|","|"."|"["|"]"|"("|")"|"{"|"}"|";"
STR             \".*\"
CHAR            \'.\'
SPACE           [ \r\t\f\v]
FLOAT           [0-9]+.[0-9]+
DIGIT           [0-9]
ID              [a-zA-Z_][a-zA-Z0-9_]*
OP              "+"|"-"|"*"|"/"|"<"|">"|"="|"<="|">="|"=="|"%"|"++"|"--"|"!="|"&&"|"||"|"!"
SCI             [0-9]+.[0-9]*[\E\e][\+\-]*[0-9]*

%x              COMMENT
%x              HEADER
%x              FUNC_OR_VAR


%%

{SPACE} {
    strcat (parsed, yytext);
}


{PUNC}  {
    strcat (parsed, yytext);   
    printf("#punc:%s\n", yytext);   
}

"#" BEGIN(HEADER);

{STR}   {
    char tmpt[1024];
    int length = strlen(yytext);
    int j;
    for (j=1; j<length-1; j++) {
        tmpt[j-1] = yytext[j];
    }
    strcat (parsed, yytext);
    printf("#string:%s\n", tmpt);
}

{CHAR}  {
    strcat (parsed, yytext);
    printf("#char:%s\n", yytext);
}

"if"|"for"|"while"|"else"   {
    strcat (parsed, yytext);
    printf("#key:%s\n", yytext);
}

{FLOAT} {
    strcat (parsed, yytext);   
    if (doubleOrFloat == 1) {
        printf("#double:%s\n", yytext);
        doubleOrFloat = 0;
    } else if (doubleOrFloat == 2) {
        printf("#float:%s\n", yytext);
        doubleOrFloat = 0;
    }
    doubleOrFloat = 0;
}

{DIGIT}+    {
    strcat (parsed, yytext);                        
    printf("#integer:%s\n", yytext);
}

"//".+  {
    strcat (parsed, yytext);
    //printf("#%d one line comment: %s\n", lineCount, yytext);
}

{OP}    {
    strcat (parsed, yytext);
    printf("#op:%s\n", yytext );
}

"/*"    {
    strcat (parsed, yytext);
    printf("#%d block comment start\n", lineCount);
    BEGIN(COMMENT);
}

"int"|"double"|"char"|"float"   {
    if (yytext[0] == 'd') {
        doubleOrFloat = 1;
    } else if (yytext[0] == 'f') {
        doubleOrFloat = 2;
    } else {
        doubleOrFloat = 0;
    }

    strcat (parsed, yytext);
    printf("#key:%s\n", yytext);
    declare_flag = 1;
}

return  {
    strcat (parsed, yytext);
    printf("#key:%s\n", yytext);
}

printf  {
    strcat (parsed, yytext);
    printf("#key:%s\n", yytext);
}

{ID}    { 
    strcat (parsed, yytext);
    strcpy(id, yytext);
    printf ("#id:%s\n", yytext);
    id_line = lineCount;
    //BEGIN(FUNC_OR_VAR);
}

{SCI}   {
    strcat (parsed, yytext);
    printf("#sci:%s\n", yytext);
}

\n  {
    //strcat (parsed, yytext);
    printf("%d:%s\n", lineCount, parsed);
    memset(parsed, '\0', strlen(parsed) );
    startLine = 1;
    lineCount++; 
} 

<HEADER>{
    ">" BEGIN(0);
    \n  lineCount++;BEGIN(0);
    .+   {printf("%d:header:%s\n", lineCount, yytext);}
}

<COMMENT>{
     "*/"      {
        printf("#%d block comment end\n", lineCount);
        BEGIN(INITIAL);
     }
     {SPACE}   
     [^*\n]+   printf ("#%d COMMENT: %s\n", lineCount, yytext);
     "*"       // eat the lone star
     \n        lineCount++;
}

.   {printf("Unrec: %s\n",yytext);}
%%


int main(void) { 
    yylex();
    printf("%d:%s\n", lineCount, parsed);
    return 0;
}

int yywrap(){
    return 1;
}
