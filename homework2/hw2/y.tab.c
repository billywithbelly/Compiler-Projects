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
	int strictOrder = 0;
	extern int lineCount;
	extern char parsed[1024];
	extern char* yytext;
#line 33 "y.tab.c"

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
    0,    2,    0,    4,    0,    7,    0,    0,    8,    8,
    8,    8,    9,    9,   14,   14,   14,   14,   14,   10,
   16,   16,   11,   11,   11,   12,   12,   18,   18,   19,
   20,   20,   20,   20,   20,    6,    6,   15,   21,   21,
   21,   22,   22,   24,   24,   23,   23,   27,   27,    1,
    1,    1,    5,    5,    5,    5,   28,   28,   28,   28,
   25,   25,   29,   29,   29,   29,   29,   26,   26,   30,
    3,    3,    3,    3,    3,    3,    3,    3,    3,   17,
   17,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   13,
};
static const YYINT yylen[] = {                            2,
    0,    0,    4,    0,    4,    0,    6,    2,    1,    1,
    1,    1,    8,    6,    9,    4,    7,    2,    0,   11,
    1,    0,    7,    9,    5,    8,    7,    4,    5,    3,
    1,    1,    1,    1,    1,    1,    2,    2,    1,    3,
    0,    1,    2,    2,    1,    2,    3,    3,    4,    2,
    3,    1,    4,    4,    5,    5,    5,    4,    3,    2,
    1,    3,    1,    3,    2,    6,    5,    3,    5,    3,
    3,    4,    4,    3,    1,    1,    2,    2,    2,    1,
    3,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    3,    4,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   75,   76,
    0,    0,    0,    2,    4,    0,    0,    9,   10,   11,
   12,    0,   50,    0,    0,    0,    0,    0,    0,    0,
   93,   98,   94,   95,   96,   99,    0,    0,    0,    0,
    0,    0,   78,   79,    0,    0,    0,    0,    0,    0,
    0,    8,    0,    0,    0,    0,    0,    0,    0,   21,
    0,    0,    0,    0,    0,    0,    0,    0,   91,   92,
    0,  100,    0,  101,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,    0,   74,    0,    0,    0,
    0,    0,    0,    0,   53,    0,    0,    0,    0,   62,
   54,    0,    0,    0,    0,   46,    0,    0,    0,   45,
   37,    0,    0,    0,    0,  104,    0,  102,    0,    0,
    0,   86,   87,   88,   89,   90,    0,    0,   73,    0,
    3,    5,    6,    0,   55,    0,   56,   81,    0,    0,
    0,   25,   47,    0,   44,   43,   40,    0,    0,    0,
  103,    0,   49,    0,    0,    0,   67,    0,    0,    0,
   38,    0,    0,    0,   14,    0,    0,    0,    7,   58,
    0,   66,    0,   23,    0,    0,    0,    0,   18,   32,
   33,   34,   35,   31,    0,    0,   27,    0,   69,   57,
    0,    0,   13,    0,    0,    0,    0,   26,    0,   24,
    0,   16,    0,   30,    0,    0,   29,   20,    0,    0,
    0,   17,    0,   15,
};
static const YYINT yydgoto[] = {                         13,
   14,   49,   15,   50,   16,   64,  154,   17,   18,   19,
   20,   21,   58,  165,  142,   59,   60,  167,  188,  185,
   65,  111,   66,  112,   23,   85,   55,   96,   24,    0,
};
static const YYINT yysindex[] = {                       408,
 -248, -247,    4,    7,  -88,   29,   76,  142,    0,    0,
 -226,  -20,    0,    0,    0,  -58,  408,    0,    0,    0,
    0,  -27,    0,   32,   85,  142,  142, -236,  142, -146,
    0,    0,    0,    0,    0,    0,   46,  142,  142,  142,
   93, -134,    0,    0,  142,   63,  142,   88,   87,   92,
 -236,    0,  -39,  142,   91, -131,  -30,  -28,   97,    0,
   25, -131, -104,   34,  255,   98,   36,  121,    0,    0,
  120,    0,  310,    0,   48,  142,  142,  142,  142,  142,
  142,  142,  142,  109,    0,   55,    0,  133,   93,  142,
  408,  408,   56,  -95,    0,  147,   93,   79,  -49,    0,
    0,  166,  142,  142,  -94,    0, -134,  -56,  152,    0,
    0,  255, -236,  -77,   89,    0,  172,    0,  310,  310,
  310,    0,    0,    0,    0,    0,  142,  127,    0,   93,
    0,    0,    0,  106,    0,  131,    0,    0,  178, -236,
  183,    0,    0,  203,    0,    0,    0, -236,  -22,  -24,
    0,   68,    0,  408,  -14,  213,    0,  136,  142,  151,
    0,  142,  170, -105,    0,  351,  -97, -134,    0,    0,
  -14,    0,  250,    0,   77,  -22,  256, -236,    0,    0,
    0,    0,    0,    0,  243,  244,    0,  179,    0,    0,
  180,  252,    0,  142,  184, -236, -236,    0, -236,    0,
   86,    0,  -24,    0,  187,  -73,    0,    0, -236,  -22,
  191,    0,  -22,    0,
};
static const YYINT yyrindex[] = {                       334,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  276,  334,    0,    0,    0,
    0,   -5,    0,  190,    0,  281,    0,  370,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,    0,
  284,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  370,    0,    0,    0,  241,    0,    0,   -4,    0,    0,
    0,    0,    0,    0, -122,  -51,    0,    0,    0,    0,
    0,    0,  145,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  285,    0,
  334,  334,    0,    0,    0,    0,  289,    0,  326,    0,
    0,    0,    0,  281,    0,    0,    0,    0,    0,    0,
    0,  -26,  207,    0,    0,    0,    0,    0,  165,  221,
  269,    0,    0,    0,    0,    0,    0,  -37,    0,  286,
    0,    0,    0,  313,    0,    0,    0,    0,    0,  370,
    0,    0,    0,    0,    0,    0,    0,  370,    1,    0,
    0,  304,    0,  334,    0,  315,    0,    0,  320,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,  370,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  207,  370,    0,  370,    0,
    0,    0,  -92,    0,    0,    0,    0,    0,  370,    1,
    0,    0,    1,    0,
};
static const YYINT yygindex[] = {                        15,
    0,    0,  508,    0,    0,   -6,    0,  -25,    0,    0,
    0,    0,  578,  129,  -63,  -79,  -19,  161,    0,    0,
  258,  253,    0,    0,  -13,  -86,   11,   37,    0,    0,
};
#define YYTABLESIZE 772
static const YYINT yytable[] = {                         48,
   19,   95,   36,   48,   48,   48,   48,   48,   83,   48,
  101,   54,   53,   81,   79,  103,   80,  178,   82,   46,
  143,   48,   48,   48,  139,   62,   88,  187,  140,   22,
   25,   52,   28,   54,   28,   42,   80,   63,   63,  110,
   47,   45,  100,   26,   93,  148,   27,   72,  106,  209,
  149,  117,   97,   63,   80,   48,   97,   97,   97,   97,
   97,   83,   97,   45,   51,  105,   81,   79,   29,   80,
   45,   82,   83,   39,   97,   56,  114,   81,   79,  173,
   80,  189,   82,  138,   83,   71,  110,   48,  118,   81,
   79,   83,   80,  102,   82,   38,   81,   79,   42,   80,
  179,   82,   40,   87,   83,  131,  132,   39,   97,   81,
   79,  168,   80,   83,   82,   30,  158,  192,   81,   79,
   80,   80,   83,   82,   57,   19,  206,   81,   79,   83,
   80,   68,   82,  160,   81,   79,   45,   80,  153,   82,
   97,  163,  210,   84,  156,   91,   99,  128,   90,  155,
   92,   98,   38,   36,   36,  104,  113,  107,  108,   40,
  116,  115,  177,   38,   39,    8,    9,   10,  169,  127,
   40,  195,   12,  129,   38,   39,    8,    9,   10,  186,
  133,   40,  134,   12,   28,   82,   39,  135,   82,  203,
  204,  170,  205,    8,    9,   10,   45,    8,    9,   10,
   12,  136,  211,   82,   12,   85,  137,  190,   85,  144,
  145,  150,  151,   39,   39,   39,   39,   45,   39,   39,
   39,   39,   94,   85,   39,   39,   39,   48,   48,   48,
   48,   94,   48,   48,   48,   48,  159,   82,   48,   48,
   48,  161,  162,   48,   48,   48,  164,   94,   61,   42,
   42,  166,   76,   77,   78,  157,  171,   85,   43,   44,
  172,   84,   19,   19,   84,   19,   19,   19,   19,   82,
   19,   19,   19,   19,   19,  174,   19,   19,   19,   84,
   97,   97,   97,   97,   65,   97,   97,   97,   97,   85,
  191,   97,   97,   97,  176,  194,   97,   97,   97,   65,
  196,  197,  199,  198,  193,   76,   77,   78,  202,   83,
  200,  208,   83,   84,   61,  213,   76,   77,   78,   31,
   32,   33,   34,   35,   69,   70,   36,   83,   76,   77,
   78,   41,   64,    1,   52,   76,   77,   78,  212,   22,
   37,  214,   77,   71,   72,   84,   83,   64,   76,   77,
   78,   81,   79,   60,   80,   59,   82,   76,   77,   78,
   22,   83,   68,  207,  146,   65,   76,   77,   78,   63,
  147,    0,    0,   76,   77,   78,   31,   32,   33,   34,
   35,    0,    0,   36,   63,    0,    0,   31,   32,   33,
   34,   35,    0,   83,   36,    0,    0,   37,   31,   32,
   33,   34,   35,    0,    0,   36,    0,    0,   37,   82,
   82,   82,   82,   64,   82,   82,   82,   82,    0,   37,
   82,   82,   82,    0,    0,   82,   82,   82,   68,   85,
   85,   85,   85,    0,   85,   85,   85,   85,    0,    0,
   85,   85,   85,    0,    0,   85,   85,   85,    0,    0,
   63,    0,    0,    0,   61,   61,   61,   61,    0,   61,
   61,   61,   61,    0,    0,   61,   61,   61,    0,    0,
    0,   41,   41,   41,   41,    0,   41,   41,   41,   41,
    0,    0,   41,   41,   41,   84,   84,   84,   84,    0,
   84,   84,   84,   84,   41,    0,   84,   84,   84,    0,
    0,   84,   84,   84,    0,   65,   65,   65,   65,    0,
   65,   65,   65,   65,    0,    0,   65,   65,   65,    3,
    4,    5,    6,    0,    7,    8,    9,   10,    0,    0,
    0,    0,   12,   83,   83,   83,   83,    0,   83,   83,
   83,   83,    0,    0,   83,   83,   83,    0,    0,   83,
   83,   83,    0,   64,   64,   64,   64,    0,   64,   64,
   64,   64,    0,    0,   64,   64,   64,    0,   68,   68,
   68,   68,  109,   68,   68,   68,   68,    0,    0,   68,
   68,   68,    0,    0,    0,   41,    0,    0,    0,    0,
   63,   63,   63,   63,    0,   63,   63,   63,   63,    0,
    0,   63,   63,   63,   61,    0,   67,  180,    0,  181,
  182,  183,  141,    0,  184,   73,   74,   75,    0,  109,
    0,  141,   86,    0,   89,    0,    0,    0,    0,    0,
    0,   97,    0,    0,   41,   41,   41,   41,    0,   41,
   41,   41,   41,    0,    0,    0,    0,   41,    0,    0,
    0,    0,    0,  119,  120,  121,  122,  123,  124,  125,
  126,    0,    0,    0,    0,    0,    0,  130,    0,    1,
    2,  141,    3,    4,    5,    6,    0,    7,    8,    9,
   10,   11,    0,    0,    0,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  152,    0,    0,    0,    0,    0,
    0,    0,    0,  141,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  175,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  201,
};
static const YYINT yycheck[] = {                         37,
    0,   41,  125,   41,   42,   43,   44,   45,   37,   47,
   41,   61,   40,   42,   43,   44,   45,  123,   47,   40,
  107,   59,   12,   61,  104,  262,   46,  125,  123,  278,
  278,   17,  125,   61,  123,  262,   41,  274,   44,   65,
   61,   91,   56,   40,   51,  123,   40,   37,   62,  123,
  114,   71,   37,   59,   59,   93,   41,   42,   43,   44,
   45,   37,   47,   91,  123,   41,   42,   43,   40,   45,
   91,   47,   37,  125,   59,   44,   41,   42,   43,  159,
   45,  168,   47,  103,   37,   40,  112,  125,   41,   42,
   43,   37,   45,   57,   47,   33,   42,   43,  125,   45,
  164,   47,   40,   41,   37,   91,   92,   45,   93,   42,
   43,   44,   45,   37,   47,   40,  136,   41,   42,   43,
  125,   45,   37,   47,   40,  125,   41,   42,   43,   37,
   45,  278,   47,  140,   42,   43,   91,   45,  128,   47,
  125,  148,  206,  278,  134,   59,  278,   93,   61,   44,
   59,   61,   33,  276,  277,   59,   59,  262,  125,   40,
   41,   41,  268,   33,   45,  271,  272,  273,  154,   61,
   40,  178,  278,   41,   33,   45,  271,  272,  273,  277,
  125,   40,  278,  278,  277,   41,   45,   41,   44,  196,
  197,  155,  199,  271,  272,  273,   91,  271,  272,  273,
  278,  123,  209,   59,  278,   41,   41,  171,   44,  266,
   59,  123,   41,  265,  266,  267,  268,   91,  270,  271,
  272,  273,  262,   59,  276,  277,  278,  265,  266,  267,
  268,  262,  270,  271,  272,  273,   59,   93,  276,  277,
  278,   59,   40,  281,  282,  283,  269,  262,   59,  276,
  277,  276,  281,  282,  283,  125,   44,   93,  279,  280,
  125,   41,  262,  263,   44,  265,  266,  267,  268,  125,
  270,  271,  272,  273,  274,  125,  276,  277,  278,   59,
  265,  266,  267,  268,   44,  270,  271,  272,  273,  125,
   41,  276,  277,  278,  125,   40,  281,  282,  283,   59,
   58,   58,  123,  125,  176,  281,  282,  283,  125,   41,
   59,  125,   44,   93,  125,  125,  281,  282,  283,  257,
  258,  259,  260,  261,  279,  280,  264,   59,  281,  282,
  283,  125,   44,    0,   59,  281,  282,  283,  210,   59,
  278,  213,   59,   59,   59,  125,   37,   59,  281,  282,
  283,   42,   43,   41,   45,   41,   47,  281,  282,  283,
   41,   93,   59,  203,  112,  125,  281,  282,  283,   44,
  113,   -1,   -1,  281,  282,  283,  257,  258,  259,  260,
  261,   -1,   -1,  264,   59,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  125,  264,   -1,   -1,  278,  257,  258,
  259,  260,  261,   -1,   -1,  264,   -1,   -1,  278,  265,
  266,  267,  268,  125,  270,  271,  272,  273,   -1,  278,
  276,  277,  278,   -1,   -1,  281,  282,  283,  125,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,   -1,   -1,  281,  282,  283,   -1,   -1,
  125,   -1,   -1,   -1,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,   -1,  276,  277,  278,   -1,   -1,
   -1,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,   -1,  276,  277,  278,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,  125,   -1,  276,  277,  278,   -1,
   -1,  281,  282,  283,   -1,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,   -1,   -1,  276,  277,  278,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,   -1,   -1,
   -1,   -1,  278,  265,  266,  267,  268,   -1,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,   -1,   -1,  281,
  282,  283,   -1,  265,  266,  267,  268,   -1,  270,  271,
  272,  273,   -1,   -1,  276,  277,  278,   -1,  265,  266,
  267,  268,   65,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,   -1,   -1,   -1,    8,   -1,   -1,   -1,   -1,
  265,  266,  267,  268,   -1,  270,  271,  272,  273,   -1,
   -1,  276,  277,  278,   27,   -1,   29,  257,   -1,  259,
  260,  261,  105,   -1,  264,   38,   39,   40,   -1,  112,
   -1,  114,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   54,   -1,   -1,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,  278,   -1,   -1,
   -1,   -1,   -1,   76,   77,   78,   79,   80,   81,   82,
   83,   -1,   -1,   -1,   -1,   -1,   -1,   90,   -1,  262,
  263,  164,  265,  266,  267,  268,   -1,  270,  271,  272,
  273,  274,   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  127,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  206,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  162,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  194,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 316
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
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program :",
"$$1 :",
"program : declaration $$1 ';' program",
"$$2 :",
"program : assignment $$2 ';' program",
"$$3 :",
"program : function '{' inner_statement '}' $$3 program",
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
"inner_statement : localDeclaration",
"inner_statement : localDeclaration functionImplementation",
"singleLineStatement : assignment ';'",
"localDeclaration : declareLocally",
"localDeclaration : declareLocally ';' localDeclaration",
"localDeclaration :",
"functionImplementation : functionCode",
"functionImplementation : functionCode functionImplementation",
"functionCode : assignment ';'",
"functionCode : statement",
"declareLocally : TYPE identifiers",
"declareLocally : KEY_CONST TYPE const_identifiers",
"index : '[' expression ']'",
"index : '[' expression ']' index",
"declaration : TYPE identifiers",
"declaration : KEY_CONST TYPE const_identifiers",
"declaration : function",
"function : TYPE ID '(' ')'",
"function : TYPE_VOID ID '(' ')'",
"function : TYPE ID '(' parameters ')'",
"function : TYPE_VOID ID '(' parameters ')'",
"parameters : TYPE ID index ',' parameters",
"parameters : TYPE ID ',' parameters",
"parameters : TYPE ID index",
"parameters : TYPE ID",
"identifiers : identifier",
"identifiers : identifier ',' identifiers",
"identifier : ID",
"identifier : ID '=' expression",
"identifier : ID index",
"identifier : ID index '=' '{' expressions '}'",
"identifier : ID index '=' '{' '}'",
"const_identifiers : ID '=' expression",
"const_identifiers : ID '=' expression ',' const_identifiers",
"const_identifier : ID '=' expression",
"assignment : ID '=' expression",
"assignment : ID index '=' expression",
"assignment : ID '(' expressions ')'",
"assignment : ID '(' ')'",
"assignment : KEY_BREAK",
"assignment : KEY_CONTINUE",
"assignment : KEY_RETURN expression",
"assignment : ID OPER_PLUS_PLUS",
"assignment : ID OPER_MINUS_MINUS",
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
#line 222 "parser.y"

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
#line 562 "y.tab.c"

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
case 2:
#line 31 "parser.y"
	{if (strictOrder == 1) {
					fprintf (stderr, "*** Error at line %d: %s\n", lineCount, parsed);
					fprintf (stderr, "\n");
					fprintf (stderr, "Unmatched token:%s\n", yytext);
					fprintf (stderr, "*** syntax error\n");
					exit(-1);
				}
			}
break;
case 4:
#line 39 "parser.y"
	{strictOrder = 0;}
break;
case 6:
#line 40 "parser.y"
	{functionDeclarationFlag = 1;}
break;
#line 780 "y.tab.c"
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
