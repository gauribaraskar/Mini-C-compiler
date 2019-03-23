/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADD = 258,
     SUBTRACT = 259,
     MULTIPLY = 260,
     DIVIDE = 261,
     ASSIGN = 262,
     ADD_ASSIGN = 263,
     SUB_ASSIGN = 264,
     MUL_ASSIGN = 265,
     DIV_ASSIGN = 266,
     MOD_ASSIGN = 267,
     MOD = 268,
     GREATER_THAN = 269,
     LESSER_THAN = 270,
     LESS_EQ = 271,
     GREATER_EQ = 272,
     NOT_EQ = 273,
     EQUAL = 274,
     VOID = 275,
     IF = 276,
     ELSE = 277,
     FOR = 278,
     DO = 279,
     WHILE = 280,
     GOTO = 281,
     BREAK = 282,
     CONTINUE = 283,
     RETURN = 284,
     INT = 285,
     SHORT = 286,
     LONG = 287,
     CHAR = 288,
     FLOAT = 289,
     LG_OR = 290,
     LG_AND = 291,
     NOT = 292,
     DECREMENT = 293,
     INCREMENT = 294,
     HEX_CONSTANT = 295,
     DEC_CONSTANT = 296,
     INT_CONSTANT = 297,
     STRING = 298,
     IDENTIFIER = 299,
     IFX = 300
   };
#endif
/* Tokens.  */
#define ADD 258
#define SUBTRACT 259
#define MULTIPLY 260
#define DIVIDE 261
#define ASSIGN 262
#define ADD_ASSIGN 263
#define SUB_ASSIGN 264
#define MUL_ASSIGN 265
#define DIV_ASSIGN 266
#define MOD_ASSIGN 267
#define MOD 268
#define GREATER_THAN 269
#define LESSER_THAN 270
#define LESS_EQ 271
#define GREATER_EQ 272
#define NOT_EQ 273
#define EQUAL 274
#define VOID 275
#define IF 276
#define ELSE 277
#define FOR 278
#define DO 279
#define WHILE 280
#define GOTO 281
#define BREAK 282
#define CONTINUE 283
#define RETURN 284
#define INT 285
#define SHORT 286
#define LONG 287
#define CHAR 288
#define FLOAT 289
#define LG_OR 290
#define LG_AND 291
#define NOT 292
#define DECREMENT 293
#define INCREMENT 294
#define HEX_CONSTANT 295
#define DEC_CONSTANT 296
#define INT_CONSTANT 297
#define STRING 298
#define IDENTIFIER 299
#define IFX 300




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

    // Header files
    #include<stdio.h>
	  #include<stdlib.h>
	  #include "tables.h"
    #include<limits.h>
    #include<ctype.h>
    #include<string.h>

    // Initialising Symbol table and constant table
    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;
    
    int yyerror(char *msg);
    int checkScope(char *value);
    int typeCheck(char*,char*,char*);
    int checkFunc(char*);
    char* curr_data_type;
    int yylex(void);
    int is_loop = 0;
    int curr_nest_level = 1;
    int return_exists = 0;
    int is_param = 0;
    extern int yylineno;
    extern char* yytext;

    
    int is_declaration = 0;
    int is_function = 0;
    char* func_type;
    char *param_list[10];
     char *arg_list[10];
   
    int p_idx = 0;
    int a_idx = 0;
    int p=0;

    int stack[100] = {0};
    int top = 0;

    char ICGstack[200][20];
    int ICGtop = 0;

    void push(char *text);

    void gencode();
    void gencode_unary();
    void gencode_if();
    
    int label = 0;
    int line_instruction = 0;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 57 "parser.y"
{
  	char *str;
  	entry *tbEntry;
  	double dval;
}
/* Line 193 of yacc.c.  */
#line 246 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 259 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    22,
      24,    26,    30,    32,    37,    40,    42,    44,    46,    48,
      50,    53,    55,    56,    57,    66,    67,    70,    71,    75,
      77,    80,    82,    86,    88,    90,    92,    94,    96,    98,
     100,   102,   103,   108,   111,   112,   115,   117,   118,   126,
     129,   130,   131,   138,   139,   148,   149,   160,   162,   163,
     167,   170,   173,   176,   179,   180,   185,   186,   191,   192,
     197,   198,   203,   204,   209,   212,   215,   217,   221,   223,
     227,   229,   232,   234,   238,   242,   246,   250,   254,   258,
     260,   264,   268,   270,   274,   278,   280,   283,   286,   288,
     290,   292,   294,   299,   303,   305,   307,   312,   314,   315,
     319,   321,   323,   325,   327,   329,   331
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    56,    57,    -1,    57,    -1,
      58,    -1,    65,    -1,    62,    59,    47,    -1,    59,    45,
      60,    -1,    60,    -1,    61,    -1,    61,    63,    95,    -1,
     110,    -1,   110,    48,    42,    49,    -1,    62,    64,    -1,
      30,    -1,    20,    -1,    33,    -1,    34,    -1,     7,    -1,
       5,    64,    -1,     5,    -1,    -1,    -1,    62,   110,    66,
      50,    68,    51,    67,    74,    -1,    -1,    69,    70,    -1,
      -1,    70,    45,    71,    -1,    71,    -1,    62,    72,    -1,
     110,    -1,   110,    48,    49,    -1,    77,    -1,    74,    -1,
      78,    -1,    81,    -1,    86,    -1,    87,    -1,    88,    -1,
      58,    -1,    -1,    75,    52,    76,    53,    -1,    76,    73,
      -1,    -1,    89,    47,    -1,    47,    -1,    -1,    21,    50,
      95,    51,    79,    76,    80,    -1,    22,    73,    -1,    -1,
      -1,    25,    50,    95,    51,    82,    73,    -1,    -1,    24,
      83,    73,    25,    50,    89,    51,    47,    -1,    -1,    23,
      50,    85,    47,    85,    47,    85,    51,    84,    73,    -1,
      89,    -1,    -1,    26,   110,    47,    -1,    28,    47,    -1,
      29,    47,    -1,    29,    89,    -1,    27,    47,    -1,    -1,
     103,     7,    90,    89,    -1,    -1,   103,     8,    91,    89,
      -1,    -1,   103,     9,    92,    89,    -1,    -1,   103,    10,
      93,    89,    -1,    -1,   103,    11,    94,    89,    -1,   103,
      39,    -1,   103,    38,    -1,    95,    -1,    95,    35,    96,
      -1,    96,    -1,    96,    36,    97,    -1,    97,    -1,    37,
      97,    -1,    98,    -1,    99,    14,    99,    -1,    99,    15,
      99,    -1,    99,    16,    99,    -1,    99,    17,    99,    -1,
      99,    18,    99,    -1,    99,    19,    99,    -1,    99,    -1,
      99,     3,   100,    -1,    99,     4,   100,    -1,   100,    -1,
     100,     5,   101,    -1,   100,     6,   101,    -1,   101,    -1,
       3,   102,    -1,     4,   102,    -1,   102,    -1,   104,    -1,
     103,    -1,   110,    -1,   110,    48,    42,    49,    -1,    50,
      89,    51,    -1,   105,    -1,   109,    -1,   110,    50,   106,
      51,    -1,   107,    -1,    -1,   107,    45,   108,    -1,   108,
      -1,    89,    -1,    41,    -1,    42,    -1,    40,    -1,    43,
      -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   106,   106,   108,   108,   110,   112,   112,
     114,   114,   115,   115,   116,   117,   118,   119,   120,   123,
     125,   125,   129,   135,   128,   152,   152,   152,   153,   153,
     154,   162,   162,   164,   164,   164,   164,   164,   164,   164,
     164,   167,   167,   168,   169,   171,   171,   172,   172,   175,
     175,   177,   177,   178,   178,   179,   179,   181,   181,   183,
     183,   184,   186,   191,   193,   193,   194,   194,   195,   195,
     196,   196,   197,   197,   198,   199,   200,   203,   204,   206,
     207,   209,   210,   212,   213,   214,   215,   216,   217,   218,
     220,   221,   222,   227,   228,   229,   232,   233,   234,   237,
     237,   238,   238,   239,   239,   239,   240,   247,   247,   249,
     250,   252,   258,   259,   260,   261,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE",
  "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "MOD", "GREATER_THAN", "LESSER_THAN", "LESS_EQ",
  "GREATER_EQ", "NOT_EQ", "EQUAL", "VOID", "IF", "ELSE", "FOR", "DO",
  "WHILE", "GOTO", "BREAK", "CONTINUE", "RETURN", "INT", "SHORT", "LONG",
  "CHAR", "FLOAT", "LG_OR", "LG_AND", "NOT", "DECREMENT", "INCREMENT",
  "HEX_CONSTANT", "DEC_CONSTANT", "INT_CONSTANT", "STRING", "IDENTIFIER",
  "','", "IFX", "';'", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "declarationList", "declaration", "varDeclaration",
  "varDeclList", "varDeclInitialize", "varDecId", "typeSpecifier",
  "assign_symbol", "pointer", "funDeclaration", "@1", "@2", "params", "@3",
  "paramList", "paramTypeList", "paramId", "statement", "compoundStmt",
  "@4", "statementList", "expressionStmt", "selectionStmt", "@5", "else",
  "iterationStmt", "@6", "@7", "@8", "optExpression", "jumpStmt",
  "returnStmt", "breakStmt", "expression", "@9", "@10", "@11", "@12",
  "@13", "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "sumExpression", "term", "unaryExpression", "factor",
  "mutable", "immutable", "call", "args", "argList", "arg", "const_type",
  "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,   300,    59,    91,    93,
      40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    64,    66,    67,    65,    69,    68,    68,    70,    70,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    75,    74,    76,    76,    77,    77,    79,    78,    80,
      80,    82,    81,    83,    81,    84,    81,    85,    85,    86,
      86,    87,    87,    88,    90,    89,    91,    89,    92,    89,
      93,    89,    94,    89,    89,    89,    89,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   100,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   105,   106,   106,   107,
     107,   108,   109,   109,   109,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     4,     2,     1,     1,     1,     1,     1,
       2,     1,     0,     0,     8,     0,     2,     0,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     2,     1,     0,     7,     2,
       0,     0,     6,     0,     8,     0,    10,     1,     0,     3,
       2,     2,     2,     2,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     2,     2,     1,     3,     1,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     2,     2,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    15,    17,    18,     0,     2,     4,     5,     0,
       6,     1,     3,    21,   116,     0,     9,    10,    14,    12,
      20,     0,     7,    19,     0,     0,     0,     8,    12,     0,
       0,     0,   114,   112,   113,   115,     0,    11,    78,    80,
      82,    89,    92,    95,    98,   100,    99,   104,   105,   101,
       0,    25,    96,    97,    81,     0,    76,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,    13,     0,     0,   103,    64,    66,    68,    70,
      72,    75,    74,    77,    79,    90,    91,    83,    84,    85,
      86,    87,    88,    93,    94,     0,   111,     0,   107,   110,
      23,     0,    26,    29,     0,     0,     0,     0,     0,   102,
     106,     0,    41,    30,    31,     0,    65,    67,    69,    71,
      73,   109,    24,     0,     0,    28,    44,    32,    41,     0,
       0,    53,     0,     0,     0,     0,     0,    46,    42,    40,
       0,    43,    34,    33,    35,    36,    37,    38,    39,     0,
       0,    58,    41,     0,     0,    63,    60,    61,    62,    45,
       0,     0,    57,     0,     0,    59,    47,    58,     0,    51,
      44,     0,     0,    41,    41,    58,     0,    52,    41,    48,
       0,     0,    49,    55,    54,    41,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   139,    15,    16,    17,   140,    24,
      18,    10,    26,   112,    73,    74,   102,   103,   113,   141,
     142,   123,   128,   143,   144,   170,   179,   145,   173,   152,
     185,   161,   146,   147,   148,   149,   104,   105,   106,   107,
     108,    56,    38,    39,    40,    41,    42,    43,    44,    57,
      46,    47,    97,    98,    99,    48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -161
static const yytype_int16 yypact[] =
{
      76,  -161,  -161,  -161,  -161,    37,    76,  -161,  -161,    14,
    -161,  -161,  -161,  -161,  -161,   -22,  -161,     7,  -161,    26,
    -161,   -24,  -161,  -161,   183,    10,     9,  -161,    25,   205,
     205,   183,  -161,  -161,  -161,  -161,   183,    57,    71,  -161,
    -161,   225,    21,  -161,  -161,  -161,  -161,  -161,  -161,    49,
      69,    68,  -161,  -161,  -161,    75,    57,    23,   183,   183,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
      78,   183,  -161,    77,    76,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,    71,  -161,    21,    21,    63,    63,    63,
      63,    63,    63,  -161,  -161,    73,  -161,    84,    82,  -161,
    -161,    14,    93,  -161,   183,   183,   183,   183,   183,  -161,
    -161,   183,  -161,  -161,    81,    76,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,    90,   102,  -161,  -161,  -161,   120,   105,
     106,  -161,   115,   -24,   119,   121,    13,  -161,  -161,  -161,
      14,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   122,
     183,   183,   155,   183,   127,  -161,  -161,  -161,  -161,  -161,
     -33,   130,  -161,   165,   -30,  -161,  -161,   183,   141,  -161,
    -161,   146,   183,   155,    61,   183,   101,  -161,   155,  -161,
     143,   153,  -161,  -161,  -161,   155,  -161
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   195,    22,  -161,   182,  -161,     6,  -161,
     191,  -161,  -161,  -161,  -161,  -161,  -161,    91,  -161,  -149,
      95,  -161,    43,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -160,  -161,  -161,  -161,   -36,  -161,  -161,  -161,  -161,
    -161,   -16,   156,    20,  -161,   194,    17,    44,    87,   -20,
    -161,  -161,  -161,  -161,   104,  -161,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      55,    19,    58,   163,    45,    58,     9,   171,    37,    45,
      45,    45,     9,    28,    23,   180,    29,    30,   166,    13,
      14,   169,     8,    21,   177,    22,    68,    69,     8,   182,
      76,    77,    78,    79,    80,    96,   186,    11,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      31,    54,    50,    32,    33,    34,    35,    14,    14,    51,
     157,    81,    82,    36,    29,    30,    60,    61,   116,   117,
     118,   119,   120,    25,    25,    96,   -22,    85,    86,    84,
     101,     1,   129,   178,   130,   131,   132,   133,   134,   135,
     136,     2,    58,   114,     3,     4,     1,    70,    31,    71,
     158,    32,    33,    34,    35,    14,     2,    59,   137,     3,
       4,    36,    93,    94,   -50,   162,    52,    53,    72,   -27,
      95,   101,   109,    29,    30,   154,    75,   111,   100,   124,
      45,   162,    28,    45,   160,   110,   176,   164,   115,   162,
       1,   129,   126,   130,   131,   132,   133,   134,   135,   136,
       2,   127,   181,     3,     4,   150,   151,    31,    29,    30,
      32,    33,    34,    35,    14,   153,   155,   137,   156,   159,
      36,    29,    30,   138,   165,     1,   129,   167,   130,   131,
     132,   133,   134,   135,   136,     2,    29,    30,     3,     4,
     168,   172,    31,   175,   183,    32,    33,    34,    35,    14,
     184,    12,   137,    27,    20,    36,   125,   122,    32,    33,
      34,    35,    14,   174,    83,   121,     0,     0,    36,     0,
      31,     0,     0,    32,    33,    34,    35,    14,    60,    61,
       0,     0,     0,    36,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    32,    33,    34,    35,    14,
       0,     0,     0,     0,     0,    36,    87,    88,    89,    90,
      91,    92
};

static const yytype_int16 yycheck[] =
{
      36,     9,    35,   152,    24,    35,     0,   167,    24,    29,
      30,    31,     6,    21,     7,   175,     3,     4,    51,     5,
      44,    51,     0,    45,   173,    47,     5,     6,     6,   178,
       7,     8,     9,    10,    11,    71,   185,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      37,    31,    42,    40,    41,    42,    43,    44,    44,    50,
      47,    38,    39,    50,     3,     4,     3,     4,   104,   105,
     106,   107,   108,    48,    48,   111,    50,    60,    61,    59,
      74,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    35,   101,    33,    34,    20,    48,    37,    50,
     136,    40,    41,    42,    43,    44,    30,    36,    47,    33,
      34,    50,    68,    69,    53,   151,    29,    30,    49,    51,
      42,   115,    49,     3,     4,   133,    51,    45,    51,    48,
     150,   167,   140,   153,   150,    51,   172,   153,    45,   175,
      20,    21,    52,    23,    24,    25,    26,    27,    28,    29,
      30,    49,    51,    33,    34,    50,    50,    37,     3,     4,
      40,    41,    42,    43,    44,    50,    47,    47,    47,    47,
      50,     3,     4,    53,    47,    20,    21,    47,    23,    24,
      25,    26,    27,    28,    29,    30,     3,     4,    33,    34,
      25,    50,    37,    47,    51,    40,    41,    42,    43,    44,
      47,     6,    47,    21,    13,    50,   115,   112,    40,    41,
      42,    43,    44,   170,    58,   111,    -1,    -1,    50,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    44,     3,     4,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    62,    63,    64,    65,
      66,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    33,    34,    55,    56,    57,    58,    62,
      65,     0,    57,     5,    44,    59,    60,    61,    64,   110,
      64,    45,    47,     7,    63,    48,    66,    60,   110,     3,
       4,    37,    40,    41,    42,    43,    50,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   109,   110,
      42,    50,   102,   102,    97,    89,    95,   103,    35,    36,
       3,     4,    14,    15,    16,    17,    18,    19,     5,     6,
      48,    50,    49,    68,    69,    51,     7,     8,     9,    10,
      11,    38,    39,    96,    97,   100,   100,    99,    99,    99,
      99,    99,    99,   101,   101,    42,    89,   106,   107,   108,
      51,    62,    70,    71,    90,    91,    92,    93,    94,    49,
      51,    45,    67,    72,   110,    45,    89,    89,    89,    89,
      89,   108,    74,    75,    48,    71,    52,    49,    76,    21,
      23,    24,    25,    26,    27,    28,    29,    47,    53,    58,
      62,    73,    74,    77,    78,    81,    86,    87,    88,    89,
      50,    50,    83,    50,   110,    47,    47,    47,    89,    47,
      95,    85,    89,    73,    95,    47,    51,    47,    25,    51,
      79,    85,    50,    82,    76,    47,    89,    73,    22,    80,
      85,    51,    73,    51,    47,    84,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 110 "parser.y"
    {is_declaration = 0;}
    break;

  case 11:
#line 114 "parser.y"
    {gencode();typeCheck((yyvsp[(1) - (3)].tbEntry)->data_type,(yyvsp[(3) - (3)].str),"="); is_declaration=1;}
    break;

  case 12:
#line 115 "parser.y"
    {(yyval.tbEntry)=(yyvsp[(1) - (1)].tbEntry);}
    break;

  case 13:
#line 115 "parser.y"
    { if((yyvsp[(3) - (4)].tbEntry)->value < 1){yyerror("Arrays can't have dimension lesser than 1");} (yyval.tbEntry)=(yyvsp[(1) - (4)].tbEntry); (yyvsp[(1) - (4)].tbEntry)->is_array = 1; (yyvsp[(1) - (4)].tbEntry)->array_dim = (int)(yyvsp[(3) - (4)].tbEntry)->value;}
    break;

  case 15:
#line 117 "parser.y"
    {curr_data_type = strdup("INT");  is_declaration = 1; }
    break;

  case 16:
#line 118 "parser.y"
    {curr_data_type = strdup("VOID");  is_declaration = 1; }
    break;

  case 17:
#line 119 "parser.y"
    {curr_data_type = strdup("CHAR");  is_declaration = 1;}
    break;

  case 18:
#line 120 "parser.y"
    {curr_data_type = strdup("FLOAT");  is_declaration = 1;}
    break;

  case 19:
#line 123 "parser.y"
    {is_declaration = 0;push("=");}
    break;

  case 22:
#line 129 "parser.y"
    {
                                                
                                                func_type = curr_data_type;
						                        is_declaration = 0;

                                            }
    break;

  case 23:
#line 135 "parser.y"
    {
                                               fill_parameter_list((yyvsp[(2) - (6)].tbEntry),param_list,p_idx);
                                                p_idx = 0;
                                                is_function = 1;
						                        int flag = set_is_function(SymbolTable,(yyvsp[(2) - (6)].tbEntry)->lexeme);
                                                if(flag == 0){return -1;}
                                                p=1;
                                            }
    break;

  case 24:
#line 143 "parser.y"
    { is_function = 0;
                                              if(!return_exists && strcmp(func_type,"VOID") != 0)
                                              {
                                                yyerror("This Function must have a return type");
                                                
                                              }
					     }
    break;

  case 25:
#line 152 "parser.y"
    {is_param = 1; }
    break;

  case 30:
#line 156 "parser.y"
    {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                              is_declaration = 0;
                                             
                                }
    break;

  case 41:
#line 167 "parser.y"
    {curr_nest_level++; stack[top] = curr_nest_level; top+=1; insertNestStart(curr_nest_level,yylineno);}
    break;

  case 42:
#line 167 "parser.y"
    {curr_nest_level++; insertNestEnd(stack[top-1],yylineno);top-=1;}
    break;

  case 45:
#line 171 "parser.y"
    {ICGtop = 0;}
    break;

  case 46:
#line 171 "parser.y"
    {ICGtop=0;}
    break;

  case 47:
#line 172 "parser.y"
    {gencode_if();}
    break;

  case 51:
#line 177 "parser.y"
    {is_loop = 1;}
    break;

  case 52:
#line 177 "parser.y"
    {is_loop = 0;}
    break;

  case 53:
#line 178 "parser.y"
    {is_loop = 1;}
    break;

  case 54:
#line 178 "parser.y"
    {is_loop = 0;}
    break;

  case 55:
#line 179 "parser.y"
    {is_loop = 1;}
    break;

  case 56:
#line 179 "parser.y"
    {is_loop = 0;}
    break;

  case 60:
#line 183 "parser.y"
    {if(!is_loop) {yyerror("Illegal use of continue");}}
    break;

  case 61:
#line 184 "parser.y"
    { if(is_function) { if(strcmp(func_type,"VOID")!=0) yyerror("return type (VOID) does not match function type");}}
    break;

  case 62:
#line 186 "parser.y"
    {
                                      return_exists = 1;
                                      if(strcmp(curr_data_type,(yyvsp[(2) - (2)].str))!=0)
                                        yyerror("return type does not match function type");
                                   }
    break;

  case 63:
#line 191 "parser.y"
    {if(!is_loop) {yyerror("Illegal use of break");}}
    break;

  case 64:
#line 193 "parser.y"
    {push("=");}
    break;

  case 65:
#line 193 "parser.y"
    {typeCheck((yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str),"=");(yyval.str) = (yyvsp[(1) - (4)].str);gencode();}
    break;

  case 66:
#line 194 "parser.y"
    {push("+=");}
    break;

  case 67:
#line 194 "parser.y"
    {typeCheck((yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str),"+=");(yyval.str) = (yyvsp[(1) - (4)].str);gencode();}
    break;

  case 68:
#line 195 "parser.y"
    {push("-=");}
    break;

  case 69:
#line 195 "parser.y"
    {typeCheck((yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str),"-=");(yyval.str) = (yyvsp[(1) - (4)].str);gencode();}
    break;

  case 70:
#line 196 "parser.y"
    {push("*=");}
    break;

  case 71:
#line 196 "parser.y"
    {typeCheck((yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str),"*=");(yyval.str) = (yyvsp[(1) - (4)].str);gencode();}
    break;

  case 72:
#line 197 "parser.y"
    {push("/=");}
    break;

  case 73:
#line 197 "parser.y"
    {typeCheck((yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str),"/=");(yyval.str) = (yyvsp[(1) - (4)].str);gencode();}
    break;

  case 74:
#line 198 "parser.y"
    {typeCheck((yyvsp[(1) - (2)].str),(yyvsp[(1) - (2)].str),"++"); (yyval.str) = (yyvsp[(1) - (2)].str);}
    break;

  case 75:
#line 199 "parser.y"
    {typeCheck((yyvsp[(1) - (2)].str),(yyvsp[(1) - (2)].str),"--"); (yyval.str) = (yyvsp[(1) - (2)].str);}
    break;

  case 76:
#line 200 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 77:
#line 203 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"||"); (yyval.str) = (yyvsp[(1) - (3)].str);{push("||");}gencode();}
    break;

  case 78:
#line 204 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 79:
#line 206 "parser.y"
    { typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"&&");(yyval.str) = (yyvsp[(1) - (3)].str);{push("&&");}gencode();}
    break;

  case 80:
#line 207 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 81:
#line 209 "parser.y"
    { typeCheck((yyvsp[(2) - (2)].str),(yyvsp[(2) - (2)].str),"!u");(yyval.str) = (yyvsp[(2) - (2)].str);{push("!");} }
    break;

  case 82:
#line 210 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 83:
#line 212 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),">");(yyval.str) = (yyvsp[(1) - (3)].str);{push(">");}gencode();}
    break;

  case 84:
#line 213 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"<");(yyval.str) = (yyvsp[(1) - (3)].str);{push("<");}gencode();}
    break;

  case 85:
#line 214 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"<=");(yyval.str) = (yyvsp[(1) - (3)].str);{push("<=");}gencode();}
    break;

  case 86:
#line 215 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),">=");(yyval.str) = (yyvsp[(1) - (3)].str);{push(">=");}gencode();}
    break;

  case 87:
#line 216 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"!=");{push("!=");} gencode();}
    break;

  case 88:
#line 217 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"==");(yyval.str) = (yyvsp[(1) - (3)].str); {push("==");} gencode();}
    break;

  case 89:
#line 218 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 90:
#line 220 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"+");(yyval.str) = (yyvsp[(1) - (3)].str);{push("+");}gencode();}
    break;

  case 91:
#line 221 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"-");(yyval.str) = (yyvsp[(1) - (3)].str);{push("-");} gencode(); }
    break;

  case 92:
#line 222 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 93:
#line 227 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"*");(yyval.str) = (yyvsp[(1) - (3)].str); {push("*");}gencode();}
    break;

  case 94:
#line 228 "parser.y"
    {typeCheck((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),"/");(yyval.str) = (yyvsp[(1) - (3)].str); {push("/");}gencode();}
    break;

  case 95:
#line 229 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 96:
#line 232 "parser.y"
    { typeCheck((yyvsp[(2) - (2)].str),(yyvsp[(2) - (2)].str),"+u");(yyval.str) = (yyvsp[(2) - (2)].str); {push("+");}gencode_unary();}
    break;

  case 97:
#line 233 "parser.y"
    { typeCheck((yyvsp[(2) - (2)].str),(yyvsp[(2) - (2)].str),"-u");(yyval.str) = (yyvsp[(2) - (2)].str); {push("-");}gencode_unary();}
    break;

  case 98:
#line 234 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 99:
#line 237 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 100:
#line 237 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 101:
#line 238 "parser.y"
    {if(checkScope(yylval.str) == 0){ return -1;}; (yyval.str) = (yyvsp[(1) - (1)].tbEntry)->data_type;}
    break;

  case 102:
#line 238 "parser.y"
    {if((yyvsp[(3) - (4)].tbEntry)->value < 0 || (yyvsp[(3) - (4)].tbEntry)->value >= (yyvsp[(1) - (4)].tbEntry)->array_dim ){yyerror("Exceeds Array Dimensions\n"); } (yyval.str) = (yyvsp[(1) - (4)].tbEntry)->data_type;}
    break;

  case 103:
#line 239 "parser.y"
    { (yyval.str) = (yyvsp[(2) - (3)].str);}
    break;

  case 104:
#line 239 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 105:
#line 239 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 106:
#line 240 "parser.y"
    { 
                                      if(checkFunc((yyvsp[(1) - (4)].tbEntry)->lexeme) == 0)
                                        {return -1;};
                                      (yyval.str) = (yyvsp[(1) - (4)].tbEntry)->data_type;
                                      check_parameter_list((yyvsp[(1) - (4)].tbEntry),arg_list,a_idx);
                                      a_idx = 0;
                                    }
    break;

  case 111:
#line 252 "parser.y"
    {
                            arg_list[a_idx] = (char *)malloc(sizeof((yyvsp[(1) - (1)].str)));
                            strcpy(arg_list[a_idx++],(yyvsp[(1) - (1)].str));
                        }
    break;

  case 112:
#line 258 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].tbEntry)->data_type;push((yyvsp[(1) - (1)].tbEntry)->lexeme);}
    break;

  case 113:
#line 259 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].tbEntry)->data_type;push((yyvsp[(1) - (1)].tbEntry)->lexeme);}
    break;

  case 114:
#line 260 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].tbEntry)->data_type;push((yyvsp[(1) - (1)].tbEntry)->lexeme);}
    break;

  case 115:
#line 261 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].tbEntry)->data_type;push((yyvsp[(1) - (1)].tbEntry)->lexeme);}
    break;

  case 116:
#line 263 "parser.y"
    { 
					if(is_declaration){
					// $1 = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
					(yyval.tbEntry) = (yyvsp[(1) - (1)].tbEntry);
                    is_function = 0;
                    push((yyvsp[(1) - (1)].tbEntry)->lexeme);
					}
					else 
					{
					(yyvsp[(1) - (1)].tbEntry) = Search(SymbolTable,yytext);
					(yyval.tbEntry) = (yyvsp[(1) - (1)].tbEntry);
                    if((yyvsp[(1) - (1)].tbEntry) == NULL)
                    {
                        yyerror("Variable Not Declared");
                        return -1;
                    }
                    push((yyvsp[(1) - (1)].tbEntry)->lexeme);
					}
			    }
    break;


/* Line 1267 of yacc.c.  */
#line 2102 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 282 "parser.y"



int checkFunc(char* lexeme)
{
    entry *res = searchFunc(SymbolTable,lexeme);
    if(res != NULL)
    {
        res = InsertSearch(SymbolTable,lexeme,curr_nest_level);
        if(res != NULL)
        {
            yyerror("Defined as variable in this scope, calling not allowed");
            return 0;
        }
        else
        {
            return 1;
        }
        
    }
    else
    {
        yyerror("No such declaration\n");
        return 0;
    }
}

int typeCheck(char *a,char *b,char *c){
	
	if(strcmp(a,b)!=0){
		yyerror("Type Mismatch");
		exit(0);
	}

	else 
		return 1;
}
void disp()
{
    printf("\n\tSymbol table");
    Display(SymbolTable);
    printf("\n\tConstant table");
    DisplayConstant(ConstantTable);
}

int checkScope(char *val)
{
    
    char *extract = (char *)malloc(sizeof(char)*32);
    int i;
    // Don't touch this CRUCIAL AS FUCK
    for(i = 0; i < strlen(val) ;i=i+1)
    {
        //printf("%d\n",i);
        if((isalnum(*(val + i)) != 0) || (*(val + i)) == '_')
        {
            *(extract + i) = *(val + i);
        }
        else
        {
            *(extract + i) = '\0';
            break;
        }
    }
    
    entry *res = ScopeSearch(SymbolTable,extract,curr_nest_level);
    // First check if variable exists then check for nesting level
    if (res == NULL)
    {
        yyerror("Variable Not Declared\n");
        return 0;
    }
    else
    { 
        int level = res->nesting_level;
        int endLine = -1;
        int startLine = -1;
        if(Nester[level] == NULL)
        {
            startLine = 0;
            endLine = yylineno + 100;
        }   
        else
        {
            startLine = Nester[level]->line_start;
            endLine = Nester[level]->line_end;
        }

        

        if((yylineno <= endLine && yylineno >= startLine))
        {
            
            return 1;
        }
        else
        {
            
            yyerror("Variable Out Of Scope\n");
            return 0; 
        }
    }
    
}

#include "lex.yy.c"
int main(int argc , char *argv[]){

    system("clear");

    SymbolTable = CreateTable();
    ConstantTable = CreateTable();
    nested_homekeeping();
    int i;
    // Open a file for parsing
    yyin = fopen(argv[1], "r");
    if(!yyparse())
    {
        printf("\nParsing complete.\n");
        disp();
    }
    else
    {
        printf("\nParsing failed.\n");
    }
    fclose(yyin);
    for(i=0;i<ICGtop;i++)
    {
        printf("%s\n",ICGstack[i]);
    }
    return 0;
}

int yyerror(char *msg)
{
  // Function to display error messages with line no and token
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}

void push(char *text)
{
    strcpy(ICGstack[ICGtop++],text);
}

void gencode()
{
    //Code For Debugging
    
    // int i;
    // printf("\nSTACK\n");
    // for(i=0;i<ICGtop;i++)
    // {
    //     printf("%s\n",ICGstack[i]);
    // }
    // printf("----------------------\n");

    char *op1 = ICGstack[--ICGtop]; 
    char *op2 = ICGstack[--ICGtop];
    char *op3 = ICGstack[--ICGtop];
    
    if( strcmp(op2,"=")== 0)
    {
        printf("%s = %s\n",op3,op1);
    }
    else if(strcmp(op2,"+=") == 0)
    {
        printf("%s = %s + %s",op3,op3,op1);   
    }
    else if(strcmp(op2,"-=") == 0)
    {
        printf("%s = %s - %s",op3,op3,op1);   
    }
    else if(strcmp(op2,"*=") == 0)
    {
        printf("%s = %s * %s",op3,op3,op1);   
    }
    else if(strcmp(op2,"/=") == 0)
    {
        printf("%s = %s / %s",op3,op3,op1);
    }
    else
    {
        char temp[3] = "t0\0";
        temp[1] = (char)(label + '0');
        temp[2] = '\0';
        label++;

        printf("%s = %s %s %s\n",temp,op3,op1,op2);

        push(temp);
    } 
    line_instruction++;  
}

void gencode_unary()
{
    line_instruction++;
    char *op1 = ICGstack[--ICGtop]; 
    char *op2 = ICGstack[--ICGtop];

    char temp[3] = "t0\0";
    temp[1] = (char)(label + '0');
    temp[2] = '\0';
    label++;

    printf("%s = %s %s\n",temp,op1,op2);

    push(temp);
    line_instruction++;  
}

void gencode_if()
{
    char temp[3] = "t0\0";
    temp[1] = (char)(label + '0');
    temp[2] = '\0';
    label++;
    printf("%s = not %s\n",temp,ICGstack[ICGtop--]);
    printf("if %s goto L%d\n",temp,1);

    push(temp);

}

