%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *s);
	int yylex(void);
	int functionDeclarationFlag = 0;
	int syntaxError = 0;
	int strictOrder = 0;
	extern int lineCount;
	extern char parsed[1024];
	extern char* yytext;
%}

%start program

%token INTEGER STRING DOUBLE SCI CHAR
%token TYPE TYPE_VOID
%token CONSTANT
%token KEY_FOR KEY_WHILE KEY_DO KEY_IF KEY_ELSE KEY_SWITCH KEY_RETURN KEY_BREAK KEY_CONTINUE KEY_CONST KEY_STRUCT KEY_CASE KEY_DEFAULT
%token ID
%token OPER_PLUS_PLUS OPER_MINUS_MINUS OPER_CMP OPER_AND OPER_OR

%left OPER_OR OPER_AND '!' OPER_CMP OPER_PLUS_PLUS OPER_MINUS_MINUS
%left '+' '-' '*' '/' '%'
%left '[' ']'

%%

program: /* empty */
	|declaration {if (strictOrder == 1) {
					fprintf (stderr, "*** Error at line %d: %s\n", lineCount, parsed);
					fprintf (stderr, "\n");
					fprintf (stderr, "Unmatched token:%s\n", yytext);
					fprintf (stderr, "*** syntax error\n");
					exit(-1);
				}
			}';' program 
	|assignment {strictOrder = 0;} ';' program 
	|function '{' inner_statement '}' {functionDeclarationFlag = 1;} program 
	|statement program
	;

declaration: 
	TYPE identifiers
	|KEY_CONST TYPE const_identifiers
	|function
	;

statement:
	if_else
	|for
	|while
	|switch
	;

function:  
	TYPE ID '(' ')'
	|TYPE_VOID ID '(' ')'
	|TYPE ID '(' parameters ')'
	|TYPE_VOID ID '(' parameters ')'
	;


if_else: 
	KEY_IF '(' expression ')' '{' inner_statement '}' else_if
	|KEY_IF '(' expression ')' singleLineStatement else_if
	;

else_if:
	KEY_ELSE KEY_IF '(' expression ')' '{' inner_statement '}' else_if
	|KEY_ELSE '{' inner_statement '}'
	|KEY_ELSE KEY_IF '(' expression ')' singleLineStatement else_if
	|KEY_ELSE singleLineStatement
	|
	;

for: 
	KEY_FOR '(' forExpression ';' forExpression ';' forExpression ')' '{' inner_statement '}'
	;

forExpression: 
	expressions
	| // expression can be empty
	;

while: 
	KEY_WHILE '(' expression ')' '{' inner_statement '}'
	|KEY_WHILE '(' expression ')' singleLineStatement
	;

switch: 
	KEY_SWITCH '(' ID ')' '{' cases defaultCase '}' // with and without default
	|KEY_SWITCH '(' ID ')' '{' cases '}'
	;

cases:
	KEY_CASE constant ':' inner_statement
	|KEY_CASE constant ':' inner_statement cases
	;

defaultCase: 
	KEY_DEFAULT ':' inner_statement
	;

inner_statement:  
	localDeclaration
	|localDeclaration functionImplementation
	;

singleLineStatement:
	assignment ';'
	;

localDeclaration:  
	declareLocally
	|declareLocally ';' localDeclaration
	|
	;

functionImplementation:  
	functionCode
	|functionCode functionImplementation
	;

functionCode:  
	assignment ';'
	|statement
	;

declareLocally: 
	TYPE identifiers
	|KEY_CONST TYPE const_identifiers
	;

index:  
	'[' expression ']'
	|'[' expression ']' index
	;

parameters:  
	TYPE ID index
	|TYPE ID
	|TYPE ID index ',' parameters
	|TYPE ID ',' parameters
	;

identifiers: 
	identifier
	|identifier ',' identifiers
	;

identifier:	
	ID
	|ID '=' expression
	|ID index
	|ID index '=' '{' expressions '}'
	|ID index '=' '{' '}'
	;

const_identifiers:  
	ID '=' expression
	|ID '=' expression ',' const_identifiers
	;

constant:
	CONSTANT
	|INTEGER
	|DOUBLE
	|SCI
	|CHAR
	;

assignment:  
	ID '=' expression 
	|ID index '=' expression
	|ID '(' expressions  ')'
	|ID '(' ')'
	|KEY_BREAK
	|KEY_CONTINUE
	|KEY_RETURN expression
	|ID OPER_PLUS_PLUS
	|ID OPER_MINUS_MINUS
	;

expressions:  
	expression
	|expression ',' expressions
	;

expression:  
	'!' expression
	|expression OPER_OR expression
	|expression OPER_AND expression
	|expression OPER_CMP expression
	|expression '+' expression
	|expression '-' expression
	|expression '*' expression
	|expression '/' expression
	|expression '%' expression
	|ID OPER_PLUS_PLUS
	|ID OPER_MINUS_MINUS
	|INTEGER
	|DOUBLE
	|SCI
	|CHAR
	|ID
	|STRING
	|CONSTANT
	|ID index
	|'-' expression // < 0
	|'(' expression ')'
	|ID '(' expressions ')'
	|ID '(' ')'
	;

%%

void yyerror(char *msg){
	fprintf (stderr, "*** Error at line %d: %s\n", lineCount, parsed);
	fprintf (stderr, "\n");
	fprintf (stderr, "Unmatched token:%s\n", yytext);
	fprintf (stderr, "*** syntax error\n");
	exit(-1);
}

int main(void){
	yyparse();
	if (functionDeclarationFlag == 1) {
		//printf("I got functions\n");
		printf ("No syntax error!\n");
	} else {
		fprintf (stderr, "*** Error at line %d: %s\n", lineCount, parsed);
		fprintf (stderr, "\n");
		fprintf (stderr, "Unmatched token:%s\n", yytext);
		fprintf (stderr, "*** syntax error\n");
		exit(-1);
	}

	return 0;
}