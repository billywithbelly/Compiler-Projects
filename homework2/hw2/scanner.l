/* 
    argument :
    ./scanner <test0_1.c 1>output.txt 2>error.txt
*/

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "y.tab.h"
    int lineCount=1; 
    int charCount=0;
    char id[256];
    char parsed[1024];

    int source_on = 1;
    int token_on = 1;
    int doubleOrFloat = 0; // double = 1, float = 2;

%}

PUNC            ":"|","|"."|"["|"]"|"("|")"|"{"|"}"|";"
STR             \".*\"
CHAR            \'.*\'
SPACE           [ \r\t\f\v]
DIGIT           [0-9]
ID              [a-zA-Z_][a-zA-Z0-9_]*
OP              "+"|"-"|"*"|"/"|"%"|"++"|"--"|"<"|"<="|">"|">"|">="|"=="|"!="|"="|"&&"|"||"|"!"|"*"|"&"
KEY             "void"|"int"|"double"|"bool"|"char"|"null"|"for"|"while"|"do"|"if"|"else"|"switch"|"return"|"break"|"continue"|"const"|"true"|"false"|"struct"|"case"|"default"|"fclose"|"clearerr"|"feof"|"ferror"|"fflush"|"fgetpos"|"fopen"|"fread"|"freopen"|"fseek"|"fsetpos"|"ftell"|"fwrite"|"remove"|"rename"|"rewind"|"setbuf"|"tmpfile"|"tmpnam"|"fprintf"|"printf"|"sprintf"|"vfprintf"|"vprintf"|"vsprintf"|"fscanf"|"scanf"|"sscanf"|"fgetc"|"fgets"|"fputc"|"fputs"|"getc"|"getchar"|"gets"|"putc"|"putchar"|"puts"|"ungetc"|"perror"|"unsigned"

%x              COMMENT

%%

<INITIAL>0/[0-9a-zA-Z] {fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);exit(1);}
<INITIAL>[0-9]+/[a-zA-Z] {fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);exit(1);}

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
    if (token_on)
        printf("#punc:%s\n", yytext); 
    return yytext[0];  
}

{STR}   {
    char tmpt[1024];
    int i;
    for (i=1; i<yyleng-1; i++)
        tmpt[i-1] = yytext[i];
    tmpt[yyleng-2] = '\0';
    if(token_on)
        printf("#string:%s\n", tmpt);
    strcat (parsed, yytext);
    return STRING;
}

{CHAR}  {
    if (yyleng > 4) {
        //printf("error in char\n");
        fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext); exit(1);
        exit (1);
    }
    if (yyleng == 4) {
        if (yytext[1] != '\\') {
            fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext); exit(1);
        }
    }

    strcat (parsed, yytext);
    if (token_on) {
        printf("#char:%s\n", yytext);
    }
    return CHAR;
}

{KEY}   {
    if (strcmp(yytext, "double") == 0) {
        doubleOrFloat = 1;
    } else if (strcmp (yytext, "float") == 0) {
        doubleOrFloat = 2;
    } else {
        doubleOrFloat = 0;
    }

    strcat (parsed, yytext);
    if (token_on) {
        printf("#key:%s\n", yytext);
    }

    if (!strcmp(yytext, "for")){
        return KEY_FOR;
    } else if (strcmp(yytext, "while") == 0) {
        return KEY_WHILE;
    } else if (strcmp(yytext, "do") == 0) {
        return KEY_DO;
    } else if (strcmp(yytext, "if") == 0) {
        return KEY_IF;
    } else if (strcmp(yytext, "else") == 0) {
        return KEY_ELSE;
    } else if (strcmp(yytext, "switch") == 0) {
        return KEY_SWITCH;
    } else if (strcmp(yytext, "return") == 0) {
        return KEY_RETURN;
    } else if (strcmp(yytext, "break") == 0) {
        return KEY_BREAK;
    } else if (strcmp(yytext, "continue") == 0) {
        return KEY_CONTINUE;
    } else if (strcmp(yytext, "struct") == 0) {
        return KEY_STRUCT;
    } else if (strcmp(yytext, "case") == 0) {
        return KEY_CASE;
    } else if (strcmp(yytext, "default") == 0) {
        return KEY_DEFAULT;
    } else if (strcmp(yytext, "null") == 0) {
        return CONSTANT;
    } else if (strcmp(yytext, "true") == 0) {
        return CONSTANT;
    } else if (strcmp(yytext, "false") == 0) {
        return CONSTANT;
    } else if(strcmp(yytext, "int") == 0) {
        return TYPE;
    }
    else if(strcmp(yytext, "double") == 0) {
        doubleOrFloat = 1;
        return TYPE;
    }
    else if(strcmp(yytext, "bool") == 0) {
        return TYPE;
    }
    else if(strcmp(yytext, "char") == 0) {
        return TYPE;
    }
    else if(strcmp(yytext, "const") == 0) {
        return KEY_CONST;
    }
    else if(strcmp(yytext, "void") == 0) {
        return TYPE_VOID;
    }
    else
        return ID;
}

{DIGIT}*"."{DIGIT}+ {
    strcat (parsed, yytext);   
    if (doubleOrFloat == 1) {
        if (token_on) {
            printf("#double:%s\n", yytext);
        }
        doubleOrFloat = 0;
        return DOUBLE;
    } else if (doubleOrFloat == 2) {
        if (token_on) {
            printf("#float:%s\n", yytext);
        }
        doubleOrFloat = 0;
        //return FLOAT;
    }
    printf("#double:%s\n", yytext);
    doubleOrFloat = 0;
    return DOUBLE;
}

{DIGIT}+"."{DIGIT}* {
    strcat (parsed, yytext);   
    if (doubleOrFloat == 1) {
        if (token_on) {
            printf("#double:%s\n", yytext);
        }
        doubleOrFloat = 0;
        return DOUBLE;
    } else if (doubleOrFloat == 2) {
        if (token_on) {
            printf("#float:%s\n", yytext);
        }
        doubleOrFloat = 0;
        //return FLOAT;
    }
    printf("#double:%s\n", yytext);
    doubleOrFloat = 0;
    return DOUBLE;
}

{DIGIT}+    {
    if (yytext[0] == '0' && yyleng != 1) {
        //printf("Error at line %d: 0\n", lineCount);
        fprintf(stderr, "Error at line %d: 0\n", lineCount); exit(1);
        exit(1);
    }
    strcat (parsed, yytext);                        
    if (token_on) {
        printf("#integer:%s\n", yytext);
    }
    return INTEGER;
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
    if ( strcmp(yytext, "++") == 0)
        return OPER_PLUS_PLUS;
    else if ( strcmp(yytext, "--") == 0)
        return OPER_MINUS_MINUS;
    else if ( strcmp(yytext, "<") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, "<=") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, ">") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, ">=") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, "==") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, "!=") == 0)
        return OPER_CMP;
    else if ( strcmp(yytext, "&&") == 0)
        return OPER_AND;
    else if ( strcmp(yytext, "||") == 0)
        return OPER_OR;
    else
        return yytext[0];
}

"/*"    {
    int length = strlen (yytext);
    int i;
    int start=0;
    char tmpt[1024];
    /*
    for (i=0; i<length-1; i++)
            if (yytext[i] == '/')
                if (yytext[i+1] =='*') {
                    start = i+1;
                }
    for (i=0;i<=start; i++)
        tmpt[i] = yytext[i];
    strcat (parsed, tmpt);
    memset (tmpt, '\0', strlen(tmpt));
    for (i=start+1; i<length; i++)
        tmpt[i-start-1] = yytext[i];
    memset (yytext, '\0', strlen(yytext));
    for (i=0; i<strlen(tmpt); i++)
        yytext[i] = tmpt[i];

    BEGIN(COMMENT);
    */
    strcat (parsed, yytext);
    BEGIN(COMMENT);
}

{ID}    { 
    strcat (parsed, yytext);
    strcpy(id, yytext);
    if (token_on) {
        printf ("#id:%s\n", yytext);
    }
    return ID;
}

(([0-9]+)|([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))[e|E][+-]?[0-9]+/[^\.0-9a-zA-Z_] {
    strcat (parsed, yytext);
    if(token_on)
        printf("#sci:%s\n", yytext);
    return SCI;
}

\n  {
    //strcat (parsed, yytext);
    if (source_on) {
        printf("%d:%s\n", lineCount, parsed);
    }
    memset(parsed, '\0', strlen(parsed) );
    lineCount++; 
    //return ENDLINE;
} 


<COMMENT>{
     "*/"      {
        BEGIN(0);
        strcat (parsed,yytext);
     }
     \n        {  
        if (source_on) {
            printf ("%d:%s\n",lineCount, parsed);
        }
        memset(parsed, '\0', strlen(parsed) );
        lineCount++;
    }
    [^\n]   {
        strcat (parsed, yytext);
    }
}

.   {fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);exit(1);}
%%

int yywrap(){
    return 1;
}

