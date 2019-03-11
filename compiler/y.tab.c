/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */

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
    char* curr_data_type;
    int yylex(void);
    int is_bool = 1;
    int curr_nest_level = 1;

    extern int yylineno;
    extern char* yytext;

    
    int is_declaration = 0;
    int is_function = 0;
    char* func_type;
    char *func_name;
    char *param_list[10];
     char *arg_list[10];
   
    int p_idx = 0;
    int p=0;
    char *param_list[10];

   char *expr_type;
   char *mut_type;
    


#line 108 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "parser.y" /* yacc.c:355  */

  	char *str;
  	entry *tbEntry;
  	double dval;

#line 244 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    94,    94,    96,    96,    98,    98,   100,   102,   102,
     104,   104,   105,   105,   106,   107,   108,   109,   110,   115,
     115,   119,   125,   118,   136,   136,   137,   137,   138,   145,
     145,   147,   147,   147,   147,   147,   147,   147,   147,   150,
     150,   151,   152,   154,   154,   155,   156,   159,   160,   161,
     163,   163,   165,   165,   166,   168,   169,   171,   172,   173,
     174,   175,   176,   177,   178,   181,   182,   184,   185,   187,
     188,   190,   191,   192,   193,   194,   195,   196,   198,   199,
     200,   205,   206,   207,   210,   211,   212,   215,   215,   216,
     216,   217,   217,   217,   218,   219,   219,   220,   221,   223,
     225,   226,   227,   230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "pointer", "funDeclaration", "$@1", "$@2", "params", "paramList",
  "paramTypeList", "paramId", "statement", "compoundStmt", "$@3",
  "statementList", "expressionStmt", "selectionStmt", "iterationStmt",
  "optExpression", "jumpStmt", "returnStmt", "breakStmt", "expression",
  "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "sumExpression", "term", "unaryExpression", "factor",
  "mutable", "immutable", "call", "args", "argList", "arg", "const_type",
  "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,  -154,  -154,  -154,  -154,     7,    65,  -154,  -154,    20,
    -154,  -154,  -154,  -154,  -154,   -30,  -154,    21,  -154,   -24,
    -154,    31,  -154,   144,    -6,    23,  -154,    26,   151,   151,
     144,  -154,  -154,  -154,   144,    44,    45,  -154,  -154,   193,
      25,  -154,  -154,    32,  -154,  -154,  -154,    51,    33,    65,
    -154,  -154,  -154,    55,    44,    30,   144,   144,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   144,   144,
    -154,    20,    57,    66,  -154,  -154,   144,   144,   144,   144,
     144,  -154,  -154,    45,  -154,    25,    25,    29,    29,    29,
      29,    29,    29,  -154,  -154,    53,  -154,    61,    69,  -154,
    -154,    70,  -154,    65,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   144,    72,  -154,  -154,  -154,  -154,  -154,    71,  -154,
      63,    78,    79,   116,    84,    31,    75,   104,   128,  -154,
    -154,  -154,    20,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   105,   144,   144,   134,   144,   114,  -154,  -154,  -154,
    -154,  -154,   -32,   115,  -154,   117,   -31,  -154,   116,   144,
     144,   116,   142,   124,   122,  -154,   116,   144,   127,  -154,
     125,  -154,   116,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    15,    17,    18,     0,     2,     4,     5,     0,
       6,     1,     3,    20,   103,     0,     9,    10,    14,    12,
      19,     0,     7,     0,     0,     0,     8,    12,     0,     0,
       0,   102,   100,   101,     0,    11,    66,    68,    70,    77,
      80,    83,    86,    88,    87,    92,    93,    89,     0,    25,
      84,    85,    69,     0,    64,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      13,     0,     0,    24,    27,    91,     0,     0,     0,     0,
       0,    63,    62,    65,    67,    78,    79,    71,    72,    73,
      74,    75,    76,    81,    82,     0,    99,     0,    95,    98,
      28,    29,    22,     0,    57,    58,    59,    60,    61,    90,
      94,     0,     0,    39,    26,    97,    30,    23,     0,    42,
      39,     0,     0,    39,     0,     0,     0,     0,     0,    44,
      40,    38,     0,    41,    32,    31,    33,    34,    35,    36,
      37,     0,     0,    51,     0,     0,     0,    56,    53,    54,
      55,    43,     0,     0,    50,     0,     0,    52,    39,    51,
       0,    39,    45,     0,     0,    47,    39,    51,     0,    46,
       0,    48,    39,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   171,     5,  -154,   158,  -154,    12,   167,
    -154,  -154,  -154,  -154,  -154,    80,  -154,   -96,    74,  -154,
    -154,  -154,  -154,  -154,  -153,  -154,  -154,  -154,   -34,   -15,
     126,   -28,  -154,   153,    13,   -19,  -154,    -7,  -154,  -154,
    -154,  -154,    87,  -154,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   131,    15,    16,    17,   132,    18,
      10,    25,   113,    72,    73,    74,   100,   133,   134,   118,
     120,   135,   136,   137,   153,   138,   139,   140,   141,    54,
      36,    37,    38,    39,    40,    41,    42,    55,    44,    45,
      97,    98,    99,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    19,    52,    56,    56,     8,   163,    11,    35,    50,
      51,     8,     9,    27,   170,    21,    43,    22,     9,   158,
     161,    43,    43,    43,    24,    13,   -21,   144,    23,    84,
      66,    67,    58,    59,    95,    96,    48,    76,    77,    78,
      79,    80,   104,   105,   106,   107,   108,    93,    94,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    71,   162,   101,    14,   165,    28,    29,    81,    82,
     169,    85,    86,    49,    24,    14,   173,    96,    68,    56,
      68,    57,    70,     1,   121,     1,   122,   123,   124,   125,
     126,   127,   128,     2,   150,     2,     3,     4,     3,     4,
      30,    69,   109,    31,    32,    33,    75,    14,   102,   154,
     129,   103,   110,    34,   111,    71,   130,   146,   112,    28,
      29,   116,   147,   119,    27,   154,   164,   152,   142,   143,
     156,    28,    29,   154,   145,    43,     1,   121,    43,   122,
     123,   124,   125,   126,   127,   128,     2,    28,    29,     3,
       4,   148,   151,    30,    28,    29,    31,    32,    33,   155,
      14,   157,   159,   129,   166,    30,    34,   160,    31,    32,
      33,   167,    14,   168,   171,   149,   172,    12,    34,    26,
      20,    30,    83,   114,    31,    32,    33,   117,    14,     0,
       0,    31,    32,    33,    34,    14,    58,    59,   115,     0,
       0,    34,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    87,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      34,     9,    30,    35,    35,     0,   159,     0,    23,    28,
      29,     6,     0,    21,   167,    45,    23,    47,     6,    51,
      51,    28,    29,    30,    48,     5,    50,   123,     7,    57,
       5,     6,     3,     4,    68,    69,    42,     7,     8,     9,
      10,    11,    76,    77,    78,    79,    80,    66,    67,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    49,   158,    71,    44,   161,     3,     4,    38,    39,
     166,    58,    59,    50,    48,    44,   172,   111,    48,    35,
      48,    36,    49,    20,    21,    20,    23,    24,    25,    26,
      27,    28,    29,    30,   128,    30,    33,    34,    33,    34,
      37,    50,    49,    40,    41,    42,    51,    44,    51,   143,
      47,    45,    51,    50,    45,   103,    53,   125,    48,     3,
       4,    49,    47,    52,   132,   159,   160,   142,    50,    50,
     145,     3,     4,   167,    50,   142,    20,    21,   145,    23,
      24,    25,    26,    27,    28,    29,    30,     3,     4,    33,
      34,    47,    47,    37,     3,     4,    40,    41,    42,    25,
      44,    47,    47,    47,    22,    37,    50,    50,    40,    41,
      42,    47,    44,    51,    47,    47,    51,     6,    50,    21,
      13,    37,    56,   103,    40,    41,    42,   113,    44,    -1,
      -1,    40,    41,    42,    50,    44,     3,     4,   111,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    60,    61,    62,    63,    64,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    33,    34,    55,    56,    57,    58,    62,
      64,     0,    57,     5,    44,    59,    60,    61,    63,    98,
      63,    45,    47,     7,    48,    65,    60,    98,     3,     4,
      37,    40,    41,    42,    50,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    97,    98,    42,    50,
      89,    89,    85,    82,    83,    91,    35,    36,     3,     4,
      14,    15,    16,    17,    18,    19,     5,     6,    48,    50,
      49,    62,    67,    68,    69,    51,     7,     8,     9,    10,
      11,    38,    39,    84,    85,    88,    88,    87,    87,    87,
      87,    87,    87,    89,    89,    82,    82,    94,    95,    96,
      70,    98,    51,    45,    82,    82,    82,    82,    82,    49,
      51,    45,    48,    66,    69,    96,    49,    72,    73,    52,
      74,    21,    23,    24,    25,    26,    27,    28,    29,    47,
      53,    58,    62,    71,    72,    75,    76,    77,    79,    80,
      81,    82,    50,    50,    71,    50,    98,    47,    47,    47,
      82,    47,    83,    78,    82,    25,    83,    47,    51,    47,
      50,    51,    71,    78,    82,    71,    22,    47,    51,    71,
      78,    47,    51,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    65,    66,    64,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    73,
      72,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    88,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    93,    94,    94,    95,    95,    96,
      97,    97,    97,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     4,     2,     1,     1,     1,     1,     2,
       1,     0,     0,     8,     1,     0,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     2,     0,     2,     1,     5,     7,     5,     7,     9,
       1,     0,     3,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       4,     3,     1,     1,     4,     1,     0,     3,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 100 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0;}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].tbEntry)->data_type,(yyvsp[0].str),"=");}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.tbEntry)=(yyvsp[0].tbEntry);}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.tbEntry)=(yyvsp[-3].tbEntry);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("INT");  is_declaration = 1; }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("VOID");  is_declaration = 1; }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("CHAR");  is_declaration = 1;}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("FLOAT");  is_declaration = 1;}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "parser.y" /* yacc.c:1646  */
    {
						
                                                
                                                func_type = curr_data_type;
						is_declaration = 0;
                                            }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 125 "parser.y" /* yacc.c:1646  */
    {
                                               fill_parameter_list((yyvsp[-4].tbEntry),param_list,p_idx);
                                                p_idx = 0;
                                                is_function = 1;
						set_is_function(SymbolTable,(yyvsp[-4].tbEntry)->lexeme);
                                                p=1;
                                            }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 132 "parser.y" /* yacc.c:1646  */
    { is_function = 0;
					     }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "parser.y" /* yacc.c:1646  */
    {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                             
                                }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 150 "parser.y" /* yacc.c:1646  */
    {curr_nest_level++;}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 150 "parser.y" /* yacc.c:1646  */
    {insertNest(curr_nest_level,yylineno);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 166 "parser.y" /* yacc.c:1646  */
    { if(is_function) { if(strcmp(func_type,"VOID")!=0) yyerror("return type (VOID) does not match functioN type");}}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 168 "parser.y" /* yacc.c:1646  */
    { if(is_function){ if(strcmp(func_type,(yyvsp[0].str))!=0) yyerror("Return type mismatch"); }}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"=");(yyval.str) = (yyvsp[-2].str);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"+=");(yyval.str) = (yyvsp[-2].str);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 173 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"-=");(yyval.str) = (yyvsp[-2].str);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"*=");(yyval.str) = (yyvsp[-2].str);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 175 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"/=");(yyval.str) = (yyvsp[-2].str);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 190 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),">");(yyval.str) = (yyvsp[-2].str);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 191 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"<");(yyval.str) = (yyvsp[-2].str);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 192 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"<=");(yyval.str) = (yyvsp[-2].str);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 193 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),">=");(yyval.str) = (yyvsp[-2].str);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 194 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"!=");(yyval.str) = (yyvsp[-2].str);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 195 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"==");(yyval.str) = (yyvsp[-2].str);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 198 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"+");(yyval.str) = (yyvsp[-2].str);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 199 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"-");(yyval.str) = (yyvsp[-2].str);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 205 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"*");(yyval.str) = (yyvsp[-2].str);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 206 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"/");(yyval.str) = (yyvsp[-2].str);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 216 "parser.y" /* yacc.c:1646  */
    {checkScope(yylval.str); (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = "";}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = "fgh";}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 230 "parser.y" /* yacc.c:1646  */
    { 
					if(is_declaration){
					(yyvsp[0].tbEntry) = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
					(yyval.tbEntry) = (yyvsp[0].tbEntry);
					}
					
					else 
					{
					(yyvsp[0].tbEntry) = Search(SymbolTable,yytext,curr_nest_level);
					(yyval.tbEntry) = (yyvsp[0].tbEntry);
					
					}
					if(!(yyvsp[0].tbEntry)){
					SearchFunction(SymbolTable, yytext);
					(yyval.tbEntry) = (yyvsp[0].tbEntry);
					printf("%s",(yyval.tbEntry)->data_type);
					}
				

			    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1864 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 253 "parser.y" /* yacc.c:1906  */



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
    
    entry *res = Search(SymbolTable,extract,curr_nest_level);
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
    return 0;
}

int yyerror(char *msg)
{
  // Function to display error messages with line no and token
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}


