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

    int source_on = 1;
    int token_on = 1;
    int doubleOrFloat = 0; // double = 1, float = 2;

%}

PUNC            ":"|","|"."|"["|"]"|"("|")"|"{"|"}"|";"
STR             \".*\"
CHAR            \'.\'
SPACE           [ \t]
FLOAT           [0-9]+.[0-9]+
DIGIT           [0-9]
ID              [a-zA-Z_][a-zA-Z0-9_]*
OP              "+"|"-"|"*"|"/"|"<"|">"|"="|"<="|">="|"=="|"%"|"++"|"--"|"!="|"&&"|"||"|"!"
SCI             [0-9]+.[0-9]*[a-zA-Z_][\+\-]*[0-9]*

%x              COMMENT
%x              HEADER
%x              FUNC_OR_VAR


%%

"#pragma source on" {
    source_on = 1;
    strcat(parsed, yytext);
}

"#pragma source off"    {
    source_on = 0;
    strcat(parsed, yytext);
}

"#pragma token on"  {
    token_on = 1;
    strcat(parsed, yytext);
}

"#pragma token off" {
    token_on = 0;
    strcat(parsed, yytext);
}

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
    if (token_on) {
        printf("#string:%s\n", tmpt);
    }
}

{CHAR}  {
    strcat (parsed, yytext);
    if (token_on) {
        printf("#char:%s\n", yytext);
    }
}

"if"|"for"|"while"|"else"   {
    strcat (parsed, yytext);
    if (token_on) {
        printf("#key:%s\n", yytext);
    }
}

{FLOAT} {
    strcat (parsed, yytext);   
    if (doubleOrFloat == 1) {
        if (token_on) {
            printf("#double:%s\n", yytext);
        }
        doubleOrFloat = 0;
    } else if (doubleOrFloat == 2) {
        if (token_on) {
            printf("#float:%s\n", yytext);
        }
        doubleOrFloat = 0;
    }
    doubleOrFloat = 0;
}

{DIGIT}+    {
    strcat (parsed, yytext);                        
    if (token_on) {
        printf("#integer:%s\n", yytext);
    }
}

"//".+  {
    strcat (parsed, yytext);
    //printf("#%d one line comment: %s\n", lineCount, yytext);
}

{OP}    {
    strcat (parsed, yytext);
    if (token_on) {
        printf("#op:%s\n", yytext );
    }
}

"/*"    {
    strcat (parsed, yytext);
    printf("#%dcomment:/*\n", lineCount);
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
    if (token_on) {
        printf("#key:%s\n", yytext);
    }
    declare_flag = 1;
}

return  {
    strcat (parsed, yytext);
    if (token_on) {
        printf("#key:%s\n", yytext);
    }
}

printf  {
    strcat (parsed, yytext);
    if (token_on) {
        printf("#key:%s\n", yytext);
    }
}

{ID}    { 
    strcat (parsed, yytext);
    strcpy(id, yytext);
    if (token_on) {
        printf ("#id:%s\n", yytext);
    }
    id_line = lineCount;
    //BEGIN(FUNC_OR_VAR);
}

{SCI}   {
    int length = strlen (yytext);
    int i;
    for (i=0; i<length; i++) {
        if (yytext[i] >= 'a' && yytext[i] <= 'z') {
            if (yytext[i] != 'e') {
                printf ("Error in line %d, found id after integer\n", lineCount);
                exit (1);
            }
        }
        if (yytext[i] >= 'A' && yytext[i] <= 'Z') {
            if (yytext[i] != 'E') {
                printf ("Error in line %d, found id after integer\n", lineCount);
                exit (1);
            }
        }
    }
    strcat (parsed, yytext);
    if (token_on) {
        printf("#sci:%s\n", yytext);
    }
}

\n  {
    //strcat (parsed, yytext);
    if (source_on) {
        printf("%d:%s\n", lineCount, parsed);
    }
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
        strcat (parsed, yytext);
        if (source_on) {
            printf("#%dcomment:*/\n", lineCount);
        }
        BEGIN(0);
     }
     {SPACE}   //ignore
     [^\n]+   {
        strcat (parsed, yytext);
        if (source_on) {
            printf ("#%dcomment:%s\n",lineCount, yytext);
        }
    }
    \n        {
        strcat (parsed, yytext);
        lineCount++;
    }
}

.   {
    printf ("Error in line %d, unidentified argument\n", lineCount);
}
%%


int main(void) { 
    yylex();
    printf("%d:%s\n", lineCount, parsed);
    return 0;
}

int yywrap(){
    return 1;
}
