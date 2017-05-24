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
	extern char parsed[1024];
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
   26,   30,   30,   30,   30,   30,   27,   27,   31,   15,
   15,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,
};
static const YYINT yylen[] = {                            2,
    0,    3,    3,    0,    6,    2,    1,    1,    1,    1,
    8,    6,    9,    4,    7,    2,    0,   11,    1,    0,
    7,    9,    5,    8,    7,    4,    5,    3,    1,    1,
    1,    1,    1,    2,    2,    1,    0,    2,    3,    1,
    0,    1,    2,    2,    1,    3,    4,    4,    3,    1,
    1,    2,    2,    2,    3,    4,    2,    3,    1,    2,
    3,    5,    5,    1,    0,    5,    4,    3,    2,    1,
    3,    1,    3,    2,    6,    5,    1,    3,    3,    1,
    3,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    3,    4,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,   51,
    0,    0,    0,    0,    0,    0,    0,    7,    8,    9,
   10,    0,   57,    0,    0,    0,    0,    0,    0,    0,
   93,   98,   94,   95,   96,   99,    0,    0,    0,    0,
    0,    0,   53,   54,    0,    0,    0,    0,    0,    0,
    0,    6,    0,    0,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,    0,   36,    0,    0,    0,   91,
   92,    0,  100,    0,  101,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   58,    0,    0,   49,    0,
    0,    0,    2,    3,    0,    0,    0,   64,    0,    0,
    0,   71,    0,    0,    0,    0,   60,    0,    0,    0,
   45,   34,   40,    0,    0,    0,    0,  104,    0,  102,
    0,    0,    0,   86,   87,   88,   89,   90,    0,    0,
    0,   48,    0,    4,    0,   62,    0,   63,   81,    0,
    0,    0,   23,   61,    0,   44,   43,   39,    0,    0,
    0,  103,    0,   78,   56,    0,    0,    0,   76,    0,
    0,    0,   35,    0,    0,    0,   12,    0,    0,    5,
   67,    0,   75,    0,   21,    0,    0,    0,    0,   16,
   30,   31,   32,   33,   29,    0,    0,   25,    0,   66,
    0,    0,   11,    0,    0,    0,    0,   24,    0,   22,
    0,   14,    0,   28,    0,    0,   27,   18,    0,    0,
    0,   15,    0,   13,
};
static const YYINT yydgoto[] = {                         13,
   14,   15,   16,   64,  156,   17,   18,   19,   20,   21,
   58,  167,  143,   59,   60,  169,  189,  186,   65,  112,
   66,   67,  113,  114,   55,   23,   86,   97,   98,   24,
   87,
};
static const YYINT yysindex[] = {                       221,
 -251, -250,   -6,   64,  -88,   69,   72,  -22,    0,    0,
 -222,   41,    0,    7,   61,   -2,  221,    0,    0,    0,
    0,  132,    0,   79,   76,  -22,  -22, -236,  -22, -134,
    0,    0,    0,    0,    0,    0,   55,  -22,  -22,  -22,
   56, -120,    0,    0,  -22,   84,  -22,  106,  221,  221,
 -236,    0,  -83,  -22,  108,  -91,  -83,   -1,  141,    0,
    8,  -91,  -71,   86,  235,    0,  160,   17,  180,    0,
    0,   94,    0,  173,    0,   26,  -22,  -22,  -22,  -22,
  -22,  -22,  -22,  -22,  164,    0,  183,   35,    0,  188,
   56,  -22,    0,    0,  105,  -45,  199,    0,   56,  120,
   52,    0,  206,  -22,  -22,  -90,    0, -120,  -18,  191,
    0,    0,    0,  235, -236,  -76,  128,    0,  211,    0,
  173,  173,  173,    0,    0,    0,    0,    0,  -22, -120,
  166,    0,   56,    0,  -15,    0,  107,    0,    0,  200,
 -236,  201,    0,    0,  218,    0,    0,    0, -236,   -8,
  -14,    0,   56,    0,    0,  221,  -83,  226,    0,  140,
  -22,  158,    0,  -22,  159,  -98,    0,  134, -122,    0,
    0,  -83,    0,  244,    0,   42,   -8,  246, -236,    0,
    0,    0,    0,    0,    0,  229,  230,    0,  167,    0,
  170,  236,    0,  -22,  169, -236, -236,    0, -236,    0,
   49,    0,  -14,    0,  171,  -66,    0,    0, -236,   -8,
  172,    0,   -8,    0,
};
static const YYINT yyrindex[] = {                       301,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  243,  301,    0,    0,    0,
    0,   -7,    0,  245,    0,  247,    0,  203,    0,    0,
    0,    0,    0,    0,    0,    0,  -28,    0,    0,    0,
  251,    0,    0,    0,    0,    0,    0,    0,  301,  301,
  203,    0,  262,    0,  118,    0,  262,  -11,    0,    0,
    0,    0,    0,    0, -123,    0,    0,    0,    0,    0,
    0,    0,    0,   78,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  252,    0,    0,    0,
  253,    0,    0,    0,    0,    0,    0,    0,  145,    0,
   -7,    0,    0,    0,  247,    0,    0,    0,    0,    0,
    0,    0,    0, -113,  151,    0,    0,    0,    0,    0,
   92,   97,  101,    0,    0,    0,    0,    0,    0,    0,
  -37,    0,  254,    0,  264,    0,    0,    0,    0,    0,
  203,    0,    0,    0,    0,    0,    0,    0,  203,    1,
    0,    0,  155,    0,    0,  301,    0,  274,    0,    0,
  278,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,  203,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  189,  203,    0,  203,    0,
    0,    0,  -93,    0,    0,    0,    0,    0,  203,    1,
    0,    0,    1,    0,
};
static const YYINT yygindex[] = {                        57,
    0,   43,    0,  -31,    0,  -44,    0,    0,    0,    0,
  361,   21,   -5,  -30,  104,  119,    0,    0,    0,    0,
  212,    0,  215,    0,   93,  130,  -69,  269,  -57,    0,
    0,
};
#define YYTABLESIZE 555
static const YYINT yytable[] = {                         55,
   17,   41,  188,   55,   55,   55,   55,   55,   97,   55,
   38,   42,   97,   97,   97,   97,   97,   40,   97,   95,
  111,   55,   39,   55,  179,   62,   22,   25,  157,   80,
   97,   26,  141,   26,   28,   84,   72,   63,  144,   42,
   82,   80,  104,   81,   84,   83,  149,   80,  106,   82,
   80,   72,   81,   84,   83,   55,  209,  116,   82,   80,
  154,   81,   84,   83,   97,   49,  120,   82,   80,  111,
   81,   84,   83,   52,  140,   45,   82,   80,   84,   81,
   46,   83,  192,   82,   80,   84,   81,   55,   83,  206,
   82,   80,   84,   81,   72,   83,   97,   82,   80,  171,
   81,   47,   83,   27,   48,   93,   94,  110,   29,  162,
  150,   30,   54,   80,  190,   57,   38,  165,   82,   50,
   51,   82,   56,   40,   89,   17,   38,  131,   39,   73,
  174,   45,   85,   40,  118,   85,   82,   84,   39,   38,
   84,   83,   45,   69,   83,   45,   40,  195,  142,   90,
   85,   39,   41,   41,  187,   84,  110,   85,  142,   83,
  180,   74,   42,   42,  203,  204,   92,  205,  100,  178,
   82,   53,    8,    9,   10,  119,   74,  211,   96,   12,
    8,    9,   10,   26,   85,  102,  101,   12,   73,   84,
  108,  107,   54,   83,    8,    9,   10,  193,   79,  105,
  210,   12,   82,   73,    8,    9,   10,  139,  142,   84,
  109,   12,  170,   79,   82,   80,   85,   81,  115,   83,
  117,   84,   45,  155,  129,   83,  130,  158,  132,  134,
  212,  159,  135,  214,   31,   32,   33,   34,   35,  136,
  160,   36,  137,   55,   55,   55,  138,  145,  142,  146,
  151,  152,   97,   97,   97,   37,   45,  164,  161,  163,
  166,  168,   17,   17,  173,   17,   17,   17,   17,  172,
   17,   17,   17,   17,   17,   38,   17,   17,   17,   77,
   78,   79,  175,  177,  191,  194,  196,  197,   77,   78,
   79,  198,  199,  202,  200,  208,  213,   77,   78,   79,
    1,   59,   65,   70,   69,   20,   77,   78,   79,   52,
   77,   46,   47,   37,   68,   77,   78,   79,   20,   43,
   44,  207,   77,   78,   79,  103,  148,   37,  147,   77,
   78,   79,    0,   70,   71,    0,   77,   78,   79,    0,
   31,   32,   33,   34,   35,    0,    0,   36,    0,    0,
   31,   32,   33,   34,   35,    0,    0,   36,   82,   82,
   82,   37,    0,   31,   32,   33,   34,   35,   41,    0,
   36,   37,   85,   85,   85,    0,    0,   84,   84,   84,
    0,   83,   83,   83,   37,    0,    0,   61,    0,   68,
  181,    0,  182,  183,  184,    0,    0,  185,   74,   75,
   76,    0,    0,    0,    0,   88,    0,   91,    0,    0,
    0,    0,    0,    0,   99,   38,   38,   38,   38,    0,
   38,   38,   38,   38,    0,    0,   38,   38,   38,    0,
    0,    0,    0,    0,    0,    0,    0,  121,  122,  123,
  124,  125,  126,  127,  128,    0,    0,    0,    0,    0,
    0,    0,  133,   37,   37,   37,   37,    0,   37,   37,
   37,   37,    0,    0,   37,   37,   37,   37,   37,   37,
   37,    0,   37,   37,   37,   37,    0,    0,    0,    0,
   37,    0,    1,    2,    0,    3,    4,    5,    6,  153,
    7,    8,    9,   10,   11,    0,    0,    0,   12,    3,
    4,    5,    6,    0,    7,    8,    9,   10,    0,    0,
    0,    0,   12,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  176,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  201,
};
static const YYINT yycheck[] = {                         37,
    0,  125,  125,   41,   42,   43,   44,   45,   37,   47,
   33,  125,   41,   42,   43,   44,   45,   40,   47,   51,
   65,   59,   45,   61,  123,  262,  278,  278,   44,   41,
   59,  125,  123,   40,  123,   37,   44,  274,  108,  262,
   42,   43,   44,   45,   37,   47,  123,   59,   41,   42,
   43,   59,   45,   37,   47,   93,  123,   41,   42,   43,
  130,   45,   37,   47,   93,   59,   41,   42,   43,  114,
   45,   37,   47,   17,  105,   91,   42,   43,   37,   45,
   40,   47,   41,   42,   43,   37,   45,  125,   47,   41,
   42,   43,   37,   45,   40,   47,  125,   42,   43,  157,
   45,   61,   47,   40,   12,   49,   50,   65,   40,  141,
  116,   40,   61,  125,  172,   40,   33,  149,   41,   59,
  123,   44,   44,   40,   41,  125,   33,   93,   45,   37,
  161,   91,   41,   40,   41,   44,   59,   41,   45,   33,
   44,   41,   91,  278,   44,   91,   40,  179,  106,   46,
   59,   45,  276,  277,  277,   59,  114,  278,  116,   59,
  166,   44,  276,  277,  196,  197,   61,  199,   61,  268,
   93,   40,  271,  272,  273,   72,   59,  209,  262,  278,
  271,  272,  273,  277,   93,   56,  278,  278,   44,   93,
  262,   62,   61,   93,  271,  272,  273,  177,   44,   59,
  206,  278,  125,   59,  271,  272,  273,  104,  166,   37,
  125,  278,  156,   59,   42,   43,  125,   45,   59,   47,
   41,  125,   91,  131,   61,  125,   44,  135,   41,  125,
  210,  125,  278,  213,  257,  258,  259,  260,  261,   41,
  137,  264,  123,  281,  282,  283,   41,  266,  206,   59,
  123,   41,  281,  282,  283,  278,   91,   40,   59,   59,
  269,  276,  262,  263,  125,  265,  266,  267,  268,   44,
  270,  271,  272,  273,  274,  125,  276,  277,  278,  281,
  282,  283,  125,  125,   41,   40,   58,   58,  281,  282,
  283,  125,  123,  125,   59,  125,  125,  281,  282,  283,
    0,   59,   41,   59,   41,   59,  281,  282,  283,   59,
   59,   59,   59,  125,   41,  281,  282,  283,   41,  279,
  280,  203,  281,  282,  283,   57,  115,  125,  114,  281,
  282,  283,   -1,  279,  280,   -1,  281,  282,  283,   -1,
  257,  258,  259,  260,  261,   -1,   -1,  264,   -1,   -1,
  257,  258,  259,  260,  261,   -1,   -1,  264,  281,  282,
  283,  278,   -1,  257,  258,  259,  260,  261,    8,   -1,
  264,  278,  281,  282,  283,   -1,   -1,  281,  282,  283,
   -1,  281,  282,  283,  278,   -1,   -1,   27,   -1,   29,
  257,   -1,  259,  260,  261,   -1,   -1,  264,   38,   39,
   40,   -1,   -1,   -1,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   54,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,   -1,   -1,  276,  277,  278,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   77,   78,   79,
   80,   81,   82,   83,   84,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   92,  265,  266,  267,  268,   -1,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,  265,  266,  267,
  268,   -1,  270,  271,  272,  273,   -1,   -1,   -1,   -1,
  278,   -1,  262,  263,   -1,  265,  266,  267,  268,  129,
  270,  271,  272,  273,  274,   -1,   -1,   -1,  278,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,   -1,   -1,
   -1,   -1,  278,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  194,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 317
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
0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"localDeclaration : declareLocally ';'",
"localDeclaration : declareLocally ';' localDeclaration",
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
"declareLocally : TYPE identifiers",
"declareLocally : KEY_CONST TYPE const_identifiers",
"function : TYPE ID '(' parameters ')'",
"function : TYPE_VOID ID '(' parameters ')'",
"parameters : parameter",
"parameters :",
"parameter : TYPE ID index ',' parameter",
"parameter : TYPE ID ',' parameter",
"parameter : TYPE ID index",
"parameter : TYPE ID",
"identifiers : identifier",
"identifiers : identifier ',' identifiers",
"identifier : ID",
"identifier : ID '=' expression",
"identifier : ID index",
"identifier : ID index '=' '{' expressions '}'",
"identifier : ID index '=' '{' '}'",
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
"expression : ID index",
"expression : '-' expression",
"expression : '(' expression ')'",
"expression : ID '(' expressions ')'",
"expression : ID '(' ')'",

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
#line 226 "parser.y"

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
#line 519 "y.tab.c"

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
#line 722 "y.tab.c"
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
