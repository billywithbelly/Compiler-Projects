/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170430

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *s);
	int yylex(void);
	int functionDeclarationFlag = 0;
	int syntaxError = 0;
	extern int lineCount;
	extern char parsed[];
	extern char* yytext;
#line 32 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define STRING 258
#define DOUBLE 259
#define SCI 260
#define CHAR 261
#define TYPE 262
#define TYPE_VOID 263
#define CONSTANT 264
#define KEY_FOR 265
#define KEY_WHILE 266
#define KEY_DO 267
#define KEY_IF 268
#define KEY_ELSE 269
#define KEY_SWITCH 270
#define KEY_RETURN 271
#define KEY_BREAK 272
#define KEY_CONTINUE 273
#define KEY_CONST 274
#define KEY_STRUCT 275
#define KEY_CASE 276
#define KEY_DEFAULT 277
#define ID 278
#define OPER_PLUS_PLUS 279
#define OPER_MINUS_MINUS 280
#define OPER_CMP 281
#define OPER_AND 282
#define OPER_OR 283
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    5,    0,    0,    6,    6,    6,    6,
    7,    7,   12,   12,   12,   12,   12,    8,   14,   14,
    9,    9,    9,   10,   10,   16,   16,   17,   18,   18,
   18,   18,   18,    4,   13,   19,   19,   21,   21,   20,
   20,   23,   23,   24,   24,    2,    2,    2,    2,    2,
    2,    2,    2,    2,   25,   25,    1,    1,    1,   22,
   22,    3,    3,   28,   28,   29,   29,   29,   29,   26,
   26,   31,   31,   31,   31,   31,   30,   30,   27,   27,
   32,   15,   15,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,
};
static const YYINT yylen[] = {                            2,
    0,    3,    3,    0,    6,    2,    1,    1,    1,    1,
    8,    6,    9,    4,    7,    2,    0,   11,    1,    0,
    7,    9,    5,    8,    7,    4,    5,    3,    1,    1,
    1,    1,    1,    2,    2,    1,    0,    2,    3,    1,
    0,    1,    2,    2,    1,    3,    4,    4,    3,    1,
    1,    2,    2,    2,    3,    4,    2,    3,    1,    2,
    3,    5,    5,    1,    0,    5,    4,    3,    2,    1,
    3,    1,    3,    2,    6,    5,    3,    4,    1,    3,
    3,    1,    3,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    2,    3,    4,    3,    4,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,   51,
    0,    0,    0,    0,    0,    0,    0,    7,    8,    9,
   10,    0,   57,    0,    0,    0,    0,    0,    0,    0,
   95,  100,   96,   97,   98,  101,    0,    0,    0,    0,
    0,    0,   53,   54,    0,    0,    0,    0,    0,    0,
    0,    6,    0,    0,    0,    0,    0,    0,    0,    0,
   19,    0,    0,    0,    0,    0,   36,    0,    0,    0,
   93,   94,    0,    0,    0,  102,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   58,    0,    0,   49,
    0,    0,    0,    2,    3,    0,    0,    0,    0,   64,
    0,    0,    0,   71,    0,    0,    0,    0,   60,    0,
    0,    0,   45,   34,   40,    0,    0,    0,    0,    0,
  105,    0,  103,    0,    0,    0,   88,   89,   90,   91,
   92,    0,    0,    0,   48,    0,    4,    0,    0,   62,
    0,   63,   83,    0,    0,    0,   23,   61,    0,   44,
   43,   39,    0,    0,    0,  106,  104,    0,   80,   56,
    0,   78,    0,    0,   76,    0,    0,    0,   35,    0,
    0,    0,   12,    0,    0,    5,   67,    0,   75,    0,
   21,    0,    0,    0,    0,   16,   30,   31,   32,   33,
   29,    0,    0,   25,    0,   66,    0,    0,   11,    0,
    0,    0,    0,   24,    0,   22,    0,   14,    0,   28,
    0,    0,   27,   18,    0,    0,    0,   15,    0,   13,
};
static const YYINT yydgoto[] = {                         13,
   14,   15,   16,   65,  161,   17,   18,   19,   20,   21,
   59,  173,  147,   60,   61,  175,  195,  192,   66,  114,
   67,   68,  115,  116,   48,   23,   87,   99,  100,   56,
   24,   88,
};
static const YYINT yysindex[] = {                       216,
 -252, -249,    5,   30,  -92,   55,   71,  -22,    0,    0,
 -223,   23,    0,   -2,   41,  -21,  216,    0,    0,    0,
    0,   72,    0,   69,   99,  -22,  -22, -237,  -22, -160,
    0,    0,    0,    0,    0,    0,  -19,  -22,  -22,  -22,
   56, -144,    0,    0,  -22,   87,  -22,   89,  216,  216,
 -237,    0,  -97, -100,  -22,  112, -110, -100,  -28,  111,
    0,   -1, -110,  -69,   74,  230,    0,  138,    6,  160,
    0,    0,  -22,   96,  281,    0,   17,  -22,  -22,  -22,
  -22,  -22,  -22,  -22,  -22,  141,    0,  163,   24,    0,
  167,   56,  -22,    0,    0,   84,  118,  -66,  175,    0,
   56,   95,   28,    0,  176,  -22,  -22,  -90,    0, -144,
  -44,  164,    0,    0,    0,  230, -237,  -68,  101,   31,
    0,  188,    0,  281,  281,  281,    0,    0,    0,    0,
    0,  -22, -144,  139,    0,   56,    0,  140,   61,    0,
  109,    0,    0,  174, -237,  181,    0,    0,  201,    0,
    0,    0, -237,  -26,  -27,    0,    0,   56,    0,    0,
  216,    0, -100,  203,    0,  123,  -22,  126,    0,  -22,
  127,  -93,    0,  142, -122,    0,    0, -100,    0,  217,
    0,   38,  -26,  219, -237,    0,    0,    0,    0,    0,
    0,  199,  204,    0,  151,    0,  161,  206,    0,  -22,
  158, -237, -237,    0, -237,    0,   49,    0,  -27,    0,
  168,  -58,    0,    0, -237,  -26,  170,    0,  -26,    0,
};
static const YYINT yyrindex[] = {                       285,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  227,  285,    0,    0,    0,
    0,   62,    0,  233,    0,  237,    0,  197,    0,    0,
    0,    0,    0,    0,    0,    0,  -37,    0,    0,    0,
  238,    0,    0,    0,    0,    0,    0,    0,  285,  285,
  197,    0,    0,  260,    0,   64,    0,  260,   -9,    0,
    0,    0,    0,    0,    0, -105,    0,    0,    0,    0,
    0,    0,    0,    0,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  245,    0,    0,
    0,  251,    0,    0,    0,    0,    0,    0,    0,    0,
   86,    0,   62,    0,    0,    0,  237,    0,    0,    0,
    0,    0,    0,    0,    0,  -87,  145,    0,    0,    0,
    0,    0,    0,   94,  102,  107,    0,    0,    0,    0,
    0,    0,    0,  254,    0,  257,    0,  250,  276,    0,
    0,    0,    0,    0,  197,    0,    0,    0,    0,    0,
    0,    0,  197,    1,    0,    0,    0,  125,    0,    0,
  285,    0,    0,  284,    0,    0,  286,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,  197,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  183,  197,    0,  197,    0,    0,    0, -101,    0,
    0,    0,    0,    0,  197,    1,    0,    0,    1,    0,
};
static const YYINT yygindex[] = {                        60,
    0,   78,    0,  -38,    0,  -64,    0,    0,    0,    0,
  353,    9,  -14,  -80,   85,  120,    0,    0,    0,    0,
  218,    0,  220,    0,  200,  -29,  -98,  275,  -81,   18,
    0,    0,
};
#define YYTABLESIZE 553
static const YYINT yytable[] = {                         99,
   17,  113,  194,   99,   99,   99,   99,   99,   85,   99,
   38,  148,   96,   83,   81,  106,   82,   40,   84,   41,
   74,   99,   39,   26,   63,   22,  144,  104,   25,  185,
   28,   82,  145,  109,  159,   85,   64,   42,   42,  108,
   83,   81,   85,   82,   26,   84,  118,   83,   81,   82,
   82,  113,   84,   85,  153,   99,   49,  123,   83,   81,
   85,   82,   46,   84,  215,   83,   81,   85,   82,   27,
   84,   73,   83,   81,   85,   82,   52,   84,  198,   83,
   81,  177,   82,   47,   84,   85,  180,   99,   55,  212,
   83,   81,   85,   82,   29,   84,  196,   83,   81,   50,
   82,   51,   84,  154,  163,   72,  168,   74,   94,   95,
   30,   54,   57,   45,  171,   82,  134,   70,   53,   38,
   72,   84,   74,  156,   84,   17,   40,   90,   38,   73,
   91,   39,   55,   86,   87,   40,  121,   87,   58,   84,
   39,   38,   86,  112,   73,   86,  201,   85,   40,   93,
   85,   53,   87,   39,  193,  162,  164,  186,  122,   97,
   86,   98,   53,  209,  210,   85,  211,  103,   81,  107,
   41,   41,  102,   84,  184,   26,  217,    8,    9,   10,
    8,    9,   10,   81,   12,  146,   87,   12,   42,   42,
  143,  199,  110,  112,   86,  146,  117,  216,  111,   85,
  119,  132,    8,    9,   10,   84,  133,  135,  137,   12,
  138,  139,    8,    9,   10,  140,  142,  141,   87,   12,
  176,  149,  150,  155,  218,  166,   86,  220,  157,   45,
   53,   85,  167,  165,   31,   32,   33,   34,   35,  169,
  170,   36,  172,   99,   99,   99,  178,  179,  174,  146,
  181,  183,   78,   79,   80,   37,  202,  197,  200,   71,
   72,  203,   17,   17,  206,   17,   17,   17,   17,   38,
   17,   17,   17,   17,   17,  204,   17,   17,   17,   78,
   79,   80,  208,  205,    1,   59,   78,   79,   80,  146,
   77,   70,  214,   77,  219,   20,   52,   78,   79,   80,
   65,   43,   44,   79,   78,   79,   80,   37,   77,   46,
   77,   78,   79,   80,   55,   47,   69,   85,   78,   79,
   80,   37,   83,   81,   68,   82,   20,   84,  213,   78,
   79,   80,  105,  160,  152,  151,   78,   79,   80,    0,
    0,    0,    0,   31,   32,   33,   34,   35,    0,    0,
   36,    0,   31,   32,   33,   34,   35,    0,    0,   36,
   41,   84,   84,   84,   37,   31,   32,   33,   34,   35,
    0,    0,   36,   37,   87,   87,   87,    0,    0,   62,
    0,   69,   86,   86,   86,    0,   37,   85,   85,   85,
   75,   76,   77,    0,    0,    0,    0,   89,  187,   92,
  188,  189,  190,    0,    0,  191,    0,  101,    0,   38,
   38,   38,   38,    0,   38,   38,   38,   38,    0,    0,
   38,   38,   38,    0,    0,  120,    0,    0,    0,    0,
  124,  125,  126,  127,  128,  129,  130,  131,    0,    0,
    0,    0,    0,    0,    0,  136,    0,   37,   37,   37,
   37,    0,   37,   37,   37,   37,    0,    0,   37,   37,
   37,   37,   37,   37,   37,    0,   37,   37,   37,   37,
    0,    0,    0,    0,   37,    0,    0,    1,    2,    0,
    3,    4,    5,    6,  158,    7,    8,    9,   10,   11,
    0,    0,    0,   12,    3,    4,    5,    6,    0,    7,
    8,    9,   10,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  182,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  207,
};
static const YYINT yycheck[] = {                         37,
    0,   66,  125,   41,   42,   43,   44,   45,   37,   47,
   33,  110,   51,   42,   43,   44,   45,   40,   47,  125,
   40,   59,   45,  125,  262,  278,  107,   57,  278,  123,
  123,   41,  123,   63,  133,   37,  274,  125,  262,   41,
   42,   43,   37,   45,   40,   47,   41,   42,   43,   59,
   45,  116,   47,   37,  123,   93,   59,   41,   42,   43,
   37,   45,   40,   47,  123,   42,   43,   37,   45,   40,
   47,   91,   42,   43,   37,   45,   17,   47,   41,   42,
   43,  163,   45,   61,   47,   37,  167,  125,   61,   41,
   42,   43,   37,   45,   40,   47,  178,   42,   43,   59,
   45,  123,   47,  118,   44,   44,  145,   44,   49,   50,
   40,   40,   44,   91,  153,  125,   93,  278,   91,   33,
   59,   41,   59,   93,   44,  125,   40,   41,   33,   44,
   46,   45,   61,  278,   41,   40,   41,   44,   40,   59,
   45,   33,   41,   66,   59,   44,  185,   41,   40,   61,
   44,   91,   59,   45,  277,  138,  139,  172,   74,  257,
   59,  262,   91,  202,  203,   59,  205,  278,   44,   59,
  276,  277,   61,   93,  268,  277,  215,  271,  272,  273,
  271,  272,  273,   59,  278,  108,   93,  278,  276,  277,
  106,  183,  262,  116,   93,  118,   59,  212,  125,   93,
   41,   61,  271,  272,  273,  125,   44,   41,  125,  278,
   93,  278,  271,  272,  273,   41,   41,  123,  125,  278,
  161,  266,   59,  123,  216,  141,  125,  219,   41,   91,
   91,  125,   59,  125,  257,  258,  259,  260,  261,   59,
   40,  264,  269,  281,  282,  283,   44,  125,  276,  172,
  125,  125,  281,  282,  283,  278,   58,   41,   40,  279,
  280,   58,  262,  263,   59,  265,  266,  267,  268,  125,
  270,  271,  272,  273,  274,  125,  276,  277,  278,  281,
  282,  283,  125,  123,    0,   59,  281,  282,  283,  212,
   41,   59,  125,   44,  125,   59,   59,  281,  282,  283,
   41,  279,  280,   59,  281,  282,  283,  125,   59,   59,
   61,  281,  282,  283,   61,   59,   41,   37,  281,  282,
  283,  125,   42,   43,   41,   45,   41,   47,  209,  281,
  282,  283,   58,  134,  117,  116,  281,  282,  283,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,   -1,
  264,   -1,  257,  258,  259,  260,  261,   -1,   -1,  264,
    8,  281,  282,  283,  278,  257,  258,  259,  260,  261,
   -1,   -1,  264,  278,  281,  282,  283,   -1,   -1,   27,
   -1,   29,  281,  282,  283,   -1,  278,  281,  282,  283,
   38,   39,   40,   -1,   -1,   -1,   -1,   45,  257,   47,
  259,  260,  261,   -1,   -1,  264,   -1,   55,   -1,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,   -1,   -1,   73,   -1,   -1,   -1,   -1,
   78,   79,   80,   81,   82,   83,   84,   85,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,  265,  266,  267,
  268,   -1,  270,  271,  272,  273,   -1,   -1,  276,  277,
  278,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,   -1,   -1,   -1,  278,   -1,   -1,  262,  263,   -1,
  265,  266,  267,  268,  132,  270,  271,  272,  273,  274,
   -1,   -1,   -1,  278,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,  278,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  170,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  200,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 318
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","STRING","DOUBLE","SCI","CHAR",
"TYPE","TYPE_VOID","CONSTANT","KEY_FOR","KEY_WHILE","KEY_DO","KEY_IF",
"KEY_ELSE","KEY_SWITCH","KEY_RETURN","KEY_BREAK","KEY_CONTINUE","KEY_CONST",
"KEY_STRUCT","KEY_CASE","KEY_DEFAULT","ID","OPER_PLUS_PLUS","OPER_MINUS_MINUS",
"OPER_CMP","OPER_AND","OPER_OR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program :",
"program : declaration ';' program",
"program : assignment ';' program",
"$$1 :",
"program : function '{' inner_statement '}' $$1 program",
"program : statement program",
"statement : if_else",
"statement : for",
"statement : while",
"statement : switch",
"if_else : KEY_IF '(' expression ')' '{' inner_statement '}' else_if",
"if_else : KEY_IF '(' expression ')' singleLineStatement else_if",
"else_if : KEY_ELSE KEY_IF '(' expression ')' '{' inner_statement '}' else_if",
"else_if : KEY_ELSE '{' inner_statement '}'",
"else_if : KEY_ELSE KEY_IF '(' expression ')' singleLineStatement else_if",
"else_if : KEY_ELSE singleLineStatement",
"else_if :",
"for : KEY_FOR '(' forExpression ';' forExpression ';' forExpression ')' '{' inner_statement '}'",
"forExpression : expressions",
"forExpression :",
"while : KEY_WHILE '(' expression ')' '{' inner_statement '}'",
"while : KEY_DO '{' inner_statement '}' KEY_WHILE '(' expression ')' ';'",
"while : KEY_WHILE '(' expression ')' singleLineStatement",
"switch : KEY_SWITCH '(' ID ')' '{' cases defaultCase '}'",
"switch : KEY_SWITCH '(' ID ')' '{' cases '}'",
"cases : KEY_CASE constant ':' inner_statement",
"cases : KEY_CASE constant ':' inner_statement cases",
"defaultCase : KEY_DEFAULT ':' inner_statement",
"constant : CONSTANT",
"constant : INTEGER",
"constant : DOUBLE",
"constant : SCI",
"constant : CHAR",
"inner_statement : declarationInFunctions implementingFunction",
"singleLineStatement : assignment ';'",
"declarationInFunctions : localDeclaration",
"declarationInFunctions :",
"localDeclaration : localyDeclaration ';'",
"localDeclaration : localyDeclaration ';' localDeclaration",
"implementingFunction : functionImplementation",
"implementingFunction :",
"functionImplementation : functionCode",
"functionImplementation : functionCode functionImplementation",
"functionCode : assignment ';'",
"functionCode : statement",
"assignment : ID '=' expression",
"assignment : ID index '=' expression",
"assignment : ID '(' expressions ')'",
"assignment : ID '(' ')'",
"assignment : KEY_BREAK",
"assignment : KEY_CONTINUE",
"assignment : KEY_RETURN expression",
"assignment : ID OPER_PLUS_PLUS",
"assignment : ID OPER_MINUS_MINUS",
"index : '[' expression ']'",
"index : '[' expression ']' index",
"declaration : TYPE identifiers",
"declaration : KEY_CONST TYPE const_identifiers",
"declaration : function",
"localyDeclaration : TYPE identifiers",
"localyDeclaration : KEY_CONST TYPE const_identifiers",
"function : TYPE ID '(' parameters ')'",
"function : TYPE_VOID ID '(' parameters ')'",
"parameters : parameters_over1",
"parameters :",
"parameters_over1 : TYPE ID arr_parenthesis ',' parameters_over1",
"parameters_over1 : TYPE ID ',' parameters_over1",
"parameters_over1 : TYPE ID arr_parenthesis",
"parameters_over1 : TYPE ID",
"identifiers : identifier",
"identifiers : identifier ',' identifiers",
"identifier : ID",
"identifier : ID '=' expression",
"identifier : ID arr_parenthesis",
"identifier : ID arr_parenthesis '=' '{' expressions '}'",
"identifier : ID arr_parenthesis '=' '{' '}'",
"arr_parenthesis : '[' INTEGER ']'",
"arr_parenthesis : '[' INTEGER ']' arr_parenthesis",
"const_identifiers : const_identifier",
"const_identifiers : const_identifier ',' const_identifiers",
"const_identifier : ID '=' expression",
"expressions : expression",
"expressions : expression ',' expressions",
"expression : '!' expression",
"expression : expression OPER_OR expression",
"expression : expression OPER_AND expression",
"expression : expression OPER_CMP expression",
"expression : expression '+' expression",
"expression : expression '-' expression",
"expression : expression '*' expression",
"expression : expression '/' expression",
"expression : expression '%' expression",
"expression : ID OPER_PLUS_PLUS",
"expression : ID OPER_MINUS_MINUS",
"expression : INTEGER",
"expression : DOUBLE",
"expression : SCI",
"expression : CHAR",
"expression : ID",
"expression : STRING",
"expression : CONSTANT",
"expression : '-' expression",
"expression : '(' expression ')'",
"expression : ID '(' expressions ')'",
"expression : ID '(' ')'",
"expression : ID '[' expression ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 229 "parser.y"

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
#line 520 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 4:
#line 32 "parser.y"
	{functionDeclarationFlag = 1;}
break;
#line 723 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
