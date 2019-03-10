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
     LG_OR = 289,
     LG_AND = 290,
     NOT = 291,
     DECREMENT = 292,
     INCREMENT = 293,
     HEX_CONSTANT = 294,
     DEC_CONSTANT = 295,
     INT_CONSTANT = 296,
     STRING = 297,
     IDENTIFIER = 298,
     IFX = 299
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
#define LG_OR 289
#define LG_AND 290
#define NOT 291
#define DECREMENT 292
#define INCREMENT 293
#define HEX_CONSTANT 294
#define DEC_CONSTANT 295
#define INT_CONSTANT 296
#define STRING 297
#define IDENTIFIER 298
#define IFX 299




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
    char* curr_data_type;
    int yylex(void);
    int is_bool = 1;
    int isfunDec = 0;
    int curr_nest_level = 1;

    extern int yylineno;
    extern char* yytext;



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
#line 29 "parser.y"
{
  	char *str;
  	entry *tbEntry;
  	double dval;
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    15,    20,
      24,    26,    28,    32,    34,    39,    42,    44,    46,    48,
      51,    53,    54,    62,    68,    70,    71,    75,    77,    80,
      82,    86,    88,    90,    92,    94,    96,    98,   100,   102,
     103,   108,   111,   112,   115,   117,   123,   131,   137,   145,
     155,   157,   158,   162,   165,   168,   171,   174,   178,   182,
     186,   190,   194,   197,   200,   202,   206,   208,   212,   214,
     217,   219,   223,   227,   231,   235,   239,   243,   245,   249,
     253,   255,   259,   263,   265,   268,   271,   273,   275,   277,
     279,   284,   288,   290,   292,   297,   299,   300,   304,   306,
     308,   310,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    55,    56,    -1,    56,    -1,
      57,    -1,    64,    -1,    -1,    58,    62,    59,    46,    -1,
      59,    44,    60,    -1,    60,    -1,    61,    -1,    61,     7,
      82,    -1,    96,    -1,    96,    47,    41,    48,    -1,    62,
      63,    -1,    30,    -1,    20,    -1,    33,    -1,     5,    63,
      -1,     5,    -1,    -1,    62,    65,    96,    49,    66,    50,
      70,    -1,    43,    49,    66,    50,    70,    -1,    67,    -1,
      -1,    67,    44,    68,    -1,    68,    -1,    62,    69,    -1,
      43,    -1,    43,    47,    48,    -1,    74,    -1,    71,    -1,
      75,    -1,    76,    -1,    78,    -1,    79,    -1,    80,    -1,
      57,    -1,    -1,    72,    51,    73,    52,    -1,    73,    70,
      -1,    -1,    81,    46,    -1,    46,    -1,    21,    49,    82,
      50,    70,    -1,    21,    49,    82,    50,    70,    22,    70,
      -1,    25,    49,    82,    50,    70,    -1,    24,    70,    25,
      49,    81,    50,    46,    -1,    23,    49,    77,    46,    77,
      46,    77,    50,    70,    -1,    81,    -1,    -1,    26,    43,
      46,    -1,    28,    46,    -1,    29,    46,    -1,    29,    81,
      -1,    27,    46,    -1,    90,     7,    81,    -1,    90,     8,
      81,    -1,    90,     9,    81,    -1,    90,    10,    81,    -1,
      90,    11,    81,    -1,    90,    38,    -1,    90,    37,    -1,
      82,    -1,    82,    34,    83,    -1,    83,    -1,    83,    35,
      84,    -1,    84,    -1,    36,    84,    -1,    85,    -1,    86,
      14,    86,    -1,    86,    15,    86,    -1,    86,    16,    86,
      -1,    86,    17,    86,    -1,    86,    18,    86,    -1,    86,
      19,    86,    -1,    86,    -1,    86,     3,    87,    -1,    86,
       4,    87,    -1,    87,    -1,    87,     5,    88,    -1,    87,
       6,    88,    -1,    88,    -1,     3,    88,    -1,     4,    88,
      -1,    89,    -1,    91,    -1,    90,    -1,    43,    -1,    90,
      47,    81,    48,    -1,    49,    81,    50,    -1,    92,    -1,
      95,    -1,    43,    49,    93,    50,    -1,    94,    -1,    -1,
      94,    44,    81,    -1,    81,    -1,    40,    -1,    41,    -1,
      39,    -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    80,    80,    82,    82,    85,    85,    87,
      87,    89,    89,    90,    90,    91,    92,    93,    94,   103,
     103,   106,   106,   107,   110,   110,   111,   111,   112,   113,
     113,   116,   116,   116,   116,   116,   116,   116,   116,   119,
     119,   120,   121,   123,   123,   124,   125,   128,   129,   130,
     132,   132,   134,   134,   135,   136,   137,   139,   140,   141,
     142,   143,   144,   145,   146,   149,   150,   152,   153,   155,
     156,   158,   159,   160,   161,   162,   163,   164,   166,   167,
     168,   173,   174,   175,   178,   179,   180,   183,   183,   184,
     184,   185,   185,   185,   186,   187,   187,   188,   188,   190,
     191,   192,   195
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
  "CHAR", "LG_OR", "LG_AND", "NOT", "DECREMENT", "INCREMENT",
  "HEX_CONSTANT", "DEC_CONSTANT", "INT_CONSTANT", "STRING", "IDENTIFIER",
  "','", "IFX", "';'", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "declarationList", "declaration", "varDeclaration", "@1",
  "varDeclList", "varDeclInitialize", "varDecId", "typeSpecifier",
  "pointer", "funDeclaration", "@2", "params", "paramList",
  "paramTypeList", "paramId", "statement", "compoundStmt", "@3",
  "statementList", "expressionStmt", "selectionStmt", "iterationStmt",
  "optExpression", "jumpStmt", "returnStmt", "breakStmt", "expression",
  "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "sumExpression", "term", "unaryExpression", "factor",
  "mutable", "immutable", "call", "args", "argList", "const_type",
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
     295,   296,   297,   298,    44,   299,    59,    91,    93,    40,
      41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    58,    57,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    65,    64,    64,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    72,
      71,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    92,    93,    93,    94,    94,    95,
      95,    95,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     3,
       1,     1,     3,     1,     4,     2,     1,     1,     1,     2,
       1,     0,     7,     5,     1,     0,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     2,     0,     2,     1,     5,     7,     5,     7,     9,
       1,     0,     3,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       4,     3,     1,     1,     4,     1,     0,     3,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    16,    18,     0,     0,     2,     4,     5,     0,
      21,     6,    25,     1,     3,     0,    20,    15,     0,     0,
       0,    24,    27,   102,     0,    10,    11,    13,    19,     0,
      29,    28,     7,     0,     0,     8,     0,     0,    25,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,   101,    99,   100,    89,    44,     0,    38,    23,    32,
       0,    31,    33,    34,    35,    36,    37,     0,    64,    66,
      68,    70,    77,    80,    83,    86,    88,    87,    92,    93,
      26,     9,    12,    88,     0,     0,    30,    84,    85,     0,
      51,     0,     0,     0,    56,    53,    54,    55,    69,    96,
       0,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    62,     0,    14,     7,     0,     0,    50,     0,     0,
      52,    98,     0,    95,    91,     7,    65,    67,    78,    79,
      71,    72,    73,    74,    75,    76,    81,    82,    57,    58,
      59,    60,    61,     0,    22,     7,    51,     0,     7,    94,
       0,    40,    41,    90,    45,     0,     0,    47,    97,     7,
      51,     0,    46,     0,    48,     7,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    57,     9,    24,    25,    26,    19,
      17,    11,    18,    20,    21,    22,    31,    58,    59,    60,
     135,    61,    62,    63,   126,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     132,   133,    79,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
      -2,  -148,  -148,  -148,   -37,    15,    -2,  -148,  -148,    53,
      12,  -148,    53,  -148,  -148,     1,  -148,  -148,   -23,     2,
      11,     8,  -148,  -148,   -30,  -148,    58,    30,  -148,    33,
      32,  -148,   146,    53,   -23,  -148,   162,    63,    53,    57,
      23,    23,    61,    64,   146,    68,    75,    60,    73,     7,
     162,  -148,  -148,  -148,    71,  -148,   162,  -148,  -148,  -148,
      56,  -148,  -148,  -148,  -148,  -148,  -148,    77,    87,    89,
    -148,  -148,    18,    79,  -148,  -148,   169,  -148,  -148,  -148,
    -148,  -148,    87,    80,    78,    82,  -148,  -148,  -148,   162,
     162,   103,   162,    83,  -148,  -148,  -148,  -148,  -148,   162,
     104,  -148,  -148,   162,   162,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,   162,   162,   162,   162,   162,
    -148,  -148,   162,  -148,   146,   -10,    88,  -148,    81,     4,
    -148,  -148,   106,   113,  -148,   112,    89,  -148,    79,    79,
      84,    84,    84,    84,    84,    84,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   111,  -148,   146,   162,   162,   146,  -148,
     162,  -148,  -148,  -148,   138,   116,   118,  -148,  -148,   146,
     162,   135,  -148,   133,  -148,   146,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,   178,    13,  -148,  -148,   154,  -148,    49,
     174,  -148,  -148,   153,  -148,   160,  -148,   -44,  -148,  -148,
    -148,  -148,  -148,  -148,  -147,  -148,  -148,  -148,   -48,   -32,
      91,   -45,  -148,    35,   -16,   -38,  -148,   -11,  -148,  -148,
    -148,  -148,  -148,   181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
      91,    97,    87,    88,    82,    98,    16,    16,   100,   165,
      40,    41,    12,     8,    34,    13,    35,    16,     1,     8,
      23,   105,   106,   173,   103,    83,    40,    41,     2,    83,
      83,     3,   107,   108,   109,   110,   111,   112,   103,    83,
     155,     4,   127,    50,    23,    30,    51,    52,    53,    10,
      54,   131,    33,    96,   158,    10,    56,   125,    15,   137,
     129,    32,    51,    52,    53,    36,    54,   148,   149,   150,
     151,   152,    56,     1,   153,   146,   147,    37,    83,    39,
     154,    83,    38,     2,   113,   114,     3,   105,   106,   138,
     139,   162,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    86,    94,   101,   127,   166,
      89,   164,   168,    90,   167,    40,    41,    92,    93,    95,
      99,   103,   127,   102,   104,   172,   123,   122,   128,   130,
     157,   176,   124,    42,   156,    43,    44,    45,    46,    47,
      48,    49,   140,   141,   142,   143,   144,   145,    50,    40,
      41,    51,    52,    53,   134,    54,   159,   160,    55,   163,
     169,    56,   170,   -39,   161,    40,    41,    42,   171,    43,
      44,    45,    46,    47,    48,    49,   115,   116,   117,   118,
     119,   174,    50,   175,    14,    51,    52,    53,    81,    54,
      28,    85,    55,    80,   136,    56,     0,   -39,    50,    29,
       0,    51,    52,    53,     0,    54,   120,   121,     0,     0,
       0,    56,     0,     0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      44,    49,    40,    41,    36,    50,     5,     5,    56,   156,
       3,     4,    49,     0,    44,     0,    46,     5,    20,     6,
      43,     3,     4,   170,    34,    36,     3,     4,    30,    40,
      41,    33,    14,    15,    16,    17,    18,    19,    34,    50,
      50,    43,    90,    36,    43,    43,    39,    40,    41,     0,
      43,    99,    44,    46,    50,     6,    49,    89,     9,   104,
      92,    50,    39,    40,    41,     7,    43,   115,   116,   117,
     118,   119,    49,    20,   122,   113,   114,    47,    89,    47,
     124,    92,    49,    30,     5,     6,    33,     3,     4,   105,
     106,   135,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    41,    48,    46,    51,   156,   157,
      49,   155,   160,    49,   158,     3,     4,    49,    43,    46,
      49,    34,   170,    46,    35,   169,    48,    47,    25,    46,
      49,   175,    50,    21,    46,    23,    24,    25,    26,    27,
      28,    29,   107,   108,   109,   110,   111,   112,    36,     3,
       4,    39,    40,    41,    50,    43,    50,    44,    46,    48,
      22,    49,    46,    51,    52,     3,     4,    21,    50,    23,
      24,    25,    26,    27,    28,    29,     7,     8,     9,    10,
      11,    46,    36,    50,     6,    39,    40,    41,    34,    43,
      16,    38,    46,    33,   103,    49,    -1,    51,    36,    18,
      -1,    39,    40,    41,    -1,    43,    37,    38,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    33,    43,    54,    55,    56,    57,    58,
      62,    64,    49,     0,    56,    62,     5,    63,    65,    62,
      66,    67,    68,    43,    59,    60,    61,    96,    63,    96,
      43,    69,    50,    44,    44,    46,     7,    47,    49,    47,
       3,     4,    21,    23,    24,    25,    26,    27,    28,    29,
      36,    39,    40,    41,    43,    46,    49,    57,    70,    71,
      72,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    95,
      68,    60,    82,    90,    41,    66,    48,    88,    88,    49,
      49,    70,    49,    43,    46,    46,    46,    81,    84,    49,
      81,    51,    46,    34,    35,     3,     4,    14,    15,    16,
      17,    18,    19,     5,     6,     7,     8,     9,    10,    11,
      37,    38,    47,    48,    50,    82,    77,    81,    25,    82,
      46,    81,    93,    94,    50,    73,    83,    84,    87,    87,
      86,    86,    86,    86,    86,    86,    88,    88,    81,    81,
      81,    81,    81,    81,    70,    50,    46,    49,    50,    50,
      44,    52,    70,    48,    70,    77,    81,    70,    81,    22,
      46,    50,    70,    77,    46,    50,    70
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
#line 85 "parser.y"
    {isfunDec = 0;}
    break;

  case 16:
#line 92 "parser.y"
    {curr_data_type = strdup("INT");}
    break;

  case 17:
#line 93 "parser.y"
    {curr_data_type = strdup("VOID");}
    break;

  case 18:
#line 94 "parser.y"
    {curr_data_type = strdup("CHAR");}
    break;

  case 21:
#line 106 "parser.y"
    {isfunDec=1;}
    break;

  case 39:
#line 119 "parser.y"
    {curr_nest_level++;}
    break;

  case 40:
#line 119 "parser.y"
    {insertNest(curr_nest_level,yylineno);}
    break;

  case 57:
#line 139 "parser.y"
    {(yyvsp[(1) - (3)].dval) = (yyvsp[(3) - (3)].dval);}
    break;

  case 58:
#line 140 "parser.y"
    {(yyvsp[(1) - (3)].dval) = (yyvsp[(1) - (3)].dval)+(yyvsp[(3) - (3)].dval);}
    break;

  case 59:
#line 141 "parser.y"
    { (yyvsp[(1) - (3)].dval) = (yyvsp[(1) - (3)].dval)-(yyvsp[(3) - (3)].dval);}
    break;

  case 60:
#line 142 "parser.y"
    { (yyvsp[(1) - (3)].dval) = (yyvsp[(1) - (3)].dval)*(yyvsp[(3) - (3)].dval);}
    break;

  case 61:
#line 143 "parser.y"
    {(yyvsp[(1) - (3)].dval) = (yyvsp[(1) - (3)].dval)/ (yyvsp[(3) - (3)].dval);}
    break;

  case 62:
#line 144 "parser.y"
    { (yyvsp[(1) - (2)].dval) = (yyvsp[(1) - (2)].dval)+1;}
    break;

  case 63:
#line 145 "parser.y"
    {  (yyvsp[(1) - (2)].dval) = (yyvsp[(1) - (2)].dval)-1;}
    break;

  case 64:
#line 146 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 65:
#line 149 "parser.y"
    {(yyval.dval) = (yyvsp[(1) - (3)].dval) || (yyvsp[(3) - (3)].dval);}
    break;

  case 66:
#line 150 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 67:
#line 152 "parser.y"
    {(yyval.dval) = (yyvsp[(1) - (3)].dval) && (yyvsp[(3) - (3)].dval);}
    break;

  case 68:
#line 153 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 69:
#line 155 "parser.y"
    {(yyval.dval) = (!(yyvsp[(2) - (2)].dval));}
    break;

  case 70:
#line 156 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 71:
#line 158 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) > (yyvsp[(3) - (3)].dval)); printf("%f",(yyval.dval));}
    break;

  case 72:
#line 159 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) < (yyvsp[(3) - (3)].dval));}
    break;

  case 73:
#line 160 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) <= (yyvsp[(3) - (3)].dval));}
    break;

  case 74:
#line 161 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) >= (yyvsp[(3) - (3)].dval));}
    break;

  case 75:
#line 162 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) != (yyvsp[(3) - (3)].dval));}
    break;

  case 76:
#line 163 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) == (yyvsp[(3) - (3)].dval));}
    break;

  case 77:
#line 164 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 78:
#line 166 "parser.y"
    {(yyval.dval) = ((yyvsp[(1) - (3)].dval) + (yyvsp[(3) - (3)].dval)); printf("%f",(yyval.dval));}
    break;

  case 79:
#line 167 "parser.y"
    {(yyval.dval) = (yyvsp[(1) - (3)].dval) - (yyvsp[(3) - (3)].dval);}
    break;

  case 80:
#line 168 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 81:
#line 173 "parser.y"
    {(yyval.dval) = (yyvsp[(1) - (3)].dval) * (yyvsp[(3) - (3)].dval);}
    break;

  case 82:
#line 174 "parser.y"
    {(yyval.dval) = (yyvsp[(1) - (3)].dval) / (yyvsp[(3) - (3)].dval);}
    break;

  case 83:
#line 175 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 84:
#line 178 "parser.y"
    {(yyval.dval)=+(yyvsp[(2) - (2)].dval);}
    break;

  case 85:
#line 179 "parser.y"
    {(yyval.dval)=-(yyvsp[(2) - (2)].dval);}
    break;

  case 86:
#line 180 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 87:
#line 183 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 88:
#line 183 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 89:
#line 184 "parser.y"
    {checkScope(yylval.str); (yyval.dval)=(yyvsp[(1) - (1)].tbEntry)->value;}
    break;

  case 90:
#line 184 "parser.y"
    {(yyval.dval)=0;}
    break;

  case 91:
#line 185 "parser.y"
    {(yyval.dval)=(yyvsp[(2) - (3)].dval);}
    break;

  case 92:
#line 185 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 93:
#line 185 "parser.y"
    {(yyval.dval)=(yyvsp[(1) - (1)].dval);}
    break;

  case 94:
#line 186 "parser.y"
    {(yyval.dval)=0;}
    break;

  case 99:
#line 190 "parser.y"
    { (yyval.dval) = (yyvsp[(1) - (1)].dval);}
    break;

  case 100:
#line 191 "parser.y"
    { (yyval.dval) = (yyvsp[(1) - (1)].dval);}
    break;

  case 101:
#line 192 "parser.y"
    { (yyval.dval) = (yyvsp[(1) - (1)].dval);}
    break;

  case 102:
#line 195 "parser.y"
    {if(isfunDec){
        entry* ent = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
        ent->is_function = 1;
        printf("FUNCTION");
        isfunDec = 0;
        }
        else
        {
            entry* ent = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
        ent->is_function = 0;
        } 
    }
    break;


/* Line 1267 of yacc.c.  */
#line 1861 "y.tab.c"
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


#line 207 "parser.y"


void disp()
{
    printf("\n\tSymbol table");
    Display(SymbolTable);
    printf("\n\tConstant table");
    Display(ConstantTable);
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
    
    entry *res = Search(SymbolTable,extract);
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
        if(Nester[level] == NULL)
            endLine = yylineno + 100;
        else
            endLine = Nester[level]->line_end;
        if(level <= curr_nest_level && yylineno <= endLine)
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

    SymbolTable = CreateTable();
    ConstantTable = CreateTable();
    nested_homekeeping();

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
    return 0;
}

int yyerror(char *msg)
{
  // Function to display error messages with line no and token
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}

