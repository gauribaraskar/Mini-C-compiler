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
    


#line 109 "y.tab.c" /* yacc.c:339  */

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
#line 46 "parser.y" /* yacc.c:355  */

  	char *str;
  	entry *tbEntry;
  	double dval;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,    93,    93,    95,    95,    97,    97,    99,   101,   101,
     103,   103,   104,   104,   105,   106,   107,   108,   109,   112,
     114,   114,   118,   124,   117,   141,   141,   141,   142,   142,
     143,   151,   151,   153,   153,   153,   153,   153,   153,   153,
     153,   156,   156,   157,   158,   160,   160,   161,   162,   165,
     165,   166,   166,   167,   167,   169,   169,   171,   171,   172,
     174,   179,   181,   182,   183,   184,   185,   186,   187,   188,
     191,   192,   194,   195,   197,   198,   200,   201,   202,   203,
     204,   205,   206,   208,   209,   210,   215,   216,   217,   220,
     221,   222,   225,   225,   226,   226,   227,   227,   227,   228,
     235,   235,   237,   238,   240,   246,   247,   248,   249,   251
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
  "assign_symbol", "pointer", "funDeclaration", "$@1", "$@2", "params",
  "$@3", "paramList", "paramTypeList", "paramId", "statement",
  "compoundStmt", "$@4", "statementList", "expressionStmt",
  "selectionStmt", "iterationStmt", "$@5", "$@6", "$@7", "optExpression",
  "jumpStmt", "returnStmt", "breakStmt", "expression", "simpleExpression",
  "andExpression", "unaryRelExpression", "relExpression", "sumExpression",
  "term", "unaryExpression", "factor", "mutable", "immutable", "call",
  "args", "argList", "arg", "const_type", "identifier", YY_NULLPTR
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

#define YYPACT_NINF -156

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-156)))

#define YYTABLE_NINF -28

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,  -156,  -156,  -156,  -156,     9,   -10,  -156,  -156,    14,
    -156,  -156,  -156,  -156,  -156,   -33,  -156,    50,  -156,   -18,
    -156,    -5,  -156,  -156,   133,    37,    38,  -156,    41,   146,
     146,   133,  -156,  -156,  -156,  -156,   133,    61,    66,  -156,
    -156,   188,    32,  -156,  -156,  -156,  -156,  -156,  -156,   -14,
      54,    58,  -156,  -156,  -156,    60,    61,   171,   133,   133,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
      63,   133,  -156,    64,   -10,  -156,   133,   133,   133,   133,
     133,  -156,  -156,    66,  -156,    32,    32,    67,    67,    67,
      67,    67,    67,  -156,  -156,    59,  -156,    65,    73,  -156,
    -156,    14,    74,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,   133,  -156,  -156,    76,   -10,  -156,  -156,    77,    81,
    -156,  -156,  -156,   118,    62,    83,  -156,    90,    -5,   106,
     107,    22,  -156,  -156,  -156,    14,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,   109,   133,   133,    57,   133,   110,
    -156,  -156,  -156,  -156,  -156,   -30,   116,  -156,   139,   -29,
    -156,    57,   133,   117,  -156,   144,   122,   133,    57,    57,
     133,   121,  -156,  -156,   134,   137,  -156,  -156,    57,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    15,    17,    18,     0,     2,     4,     5,     0,
       6,     1,     3,    21,   109,     0,     9,    10,    14,    12,
      20,     0,     7,    19,     0,     0,     0,     8,    12,     0,
       0,     0,   107,   105,   106,   108,     0,    11,    71,    73,
      75,    82,    85,    88,    91,    93,    92,    97,    98,    94,
       0,    25,    89,    90,    74,     0,    69,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,    13,     0,     0,    96,     0,     0,     0,     0,
       0,    68,    67,    70,    72,    83,    84,    76,    77,    78,
      79,    80,    81,    86,    87,     0,   104,     0,   100,   103,
      23,     0,    26,    29,    62,    63,    64,    65,    66,    95,
      99,     0,    41,    30,    31,     0,   102,    24,     0,     0,
      28,    44,    32,    41,     0,     0,    51,     0,     0,     0,
       0,     0,    46,    42,    40,     0,    43,    34,    33,    35,
      36,    37,    38,    39,     0,     0,    56,    41,     0,     0,
      61,    58,    59,    60,    45,     0,     0,    55,     0,     0,
      57,    41,    56,     0,    49,    47,     0,     0,    41,    41,
      56,     0,    50,    48,     0,     0,    53,    52,    41,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   187,    27,  -156,   173,  -156,     2,  -156,
     182,  -156,  -156,  -156,  -156,  -156,  -156,    82,  -156,   -55,
      86,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -155,
    -156,  -156,  -156,   -36,   -20,   141,   -28,  -156,   149,    13,
      -1,  -156,   -13,  -156,  -156,  -156,  -156,    89,  -156,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   134,    15,    16,    17,   135,    24,
      18,    10,    26,   112,    73,    74,   102,   103,   113,   136,
     137,   118,   123,   138,   139,   140,   168,   147,   178,   156,
     141,   142,   143,   144,    56,    38,    39,    40,    41,    42,
      43,    44,    57,    46,    47,    97,    98,    99,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    19,     9,    54,    37,    58,    58,   166,     9,    11,
       1,    45,    21,    28,    22,   174,    45,    45,    45,    13,
       2,   161,   164,     3,     4,    29,    30,     8,    52,    53,
      25,    84,   -22,     8,    70,    96,    71,    68,    69,    14,
     104,   105,   106,   107,   108,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    23,    14,    31,
      29,    30,    32,    33,    34,    35,    14,    93,    94,   152,
      60,    61,    36,    85,    86,    96,   101,     1,   124,    50,
     125,   126,   127,   128,   129,   130,   131,     2,    51,    25,
       3,     4,   158,   114,    31,   153,    58,    32,    33,    34,
      35,    14,    59,    72,   132,    95,   165,    36,   109,   -27,
     157,    75,   145,   172,   173,   100,   110,   101,   111,   115,
     149,    29,    30,   179,   119,   155,   157,    28,   159,   121,
     122,   171,    45,   146,   157,    45,    29,    30,     1,   124,
     148,   125,   126,   127,   128,   129,   130,   131,     2,    29,
      30,     3,     4,   150,   151,    31,   154,   160,    32,    33,
      34,    35,    14,   162,   163,   132,   169,   167,    36,   170,
      31,   133,   175,    32,    33,    34,    35,    14,    76,    77,
      78,    79,    80,    36,   177,   176,    32,    33,    34,    35,
      14,    60,    61,    12,    27,    20,    36,   120,   117,    83,
     116,     0,    62,    63,    64,    65,    66,    67,     0,    81,
      82,    87,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      36,     9,     0,    31,    24,    35,    35,   162,     6,     0,
      20,    24,    45,    21,    47,   170,    29,    30,    31,     5,
      30,    51,    51,    33,    34,     3,     4,     0,    29,    30,
      48,    59,    50,     6,    48,    71,    50,     5,     6,    44,
      76,    77,    78,    79,    80,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     7,    44,    37,
       3,     4,    40,    41,    42,    43,    44,    68,    69,    47,
       3,     4,    50,    60,    61,   111,    74,    20,    21,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    50,    48,
      33,    34,   147,   101,    37,   131,    35,    40,    41,    42,
      43,    44,    36,    49,    47,    42,   161,    50,    49,    51,
     146,    51,    50,   168,   169,    51,    51,   115,    45,    45,
     128,     3,     4,   178,    48,   145,   162,   135,   148,    52,
      49,   167,   145,    50,   170,   148,     3,     4,    20,    21,
      50,    23,    24,    25,    26,    27,    28,    29,    30,     3,
       4,    33,    34,    47,    47,    37,    47,    47,    40,    41,
      42,    43,    44,    47,    25,    47,    22,    50,    50,    47,
      37,    53,    51,    40,    41,    42,    43,    44,     7,     8,
       9,    10,    11,    50,    47,    51,    40,    41,    42,    43,
      44,     3,     4,     6,    21,    13,    50,   115,   112,    58,
     111,    -1,    14,    15,    16,    17,    18,    19,    -1,    38,
      39,    62,    63,    64,    65,    66,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    33,    34,    55,    56,    57,    58,    62,
      65,     0,    57,     5,    44,    59,    60,    61,    64,   103,
      64,    45,    47,     7,    63,    48,    66,    60,   103,     3,
       4,    37,    40,    41,    42,    43,    50,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   102,   103,
      42,    50,    94,    94,    90,    87,    88,    96,    35,    36,
       3,     4,    14,    15,    16,    17,    18,    19,     5,     6,
      48,    50,    49,    68,    69,    51,     7,     8,     9,    10,
      11,    38,    39,    89,    90,    93,    93,    92,    92,    92,
      92,    92,    92,    94,    94,    42,    87,    99,   100,   101,
      51,    62,    70,    71,    87,    87,    87,    87,    87,    49,
      51,    45,    67,    72,   103,    45,   101,    74,    75,    48,
      71,    52,    49,    76,    21,    23,    24,    25,    26,    27,
      28,    29,    47,    53,    58,    62,    73,    74,    77,    78,
      79,    84,    85,    86,    87,    50,    50,    81,    50,   103,
      47,    47,    47,    87,    47,    88,    83,    87,    73,    88,
      47,    51,    47,    25,    51,    73,    83,    50,    80,    22,
      47,    87,    73,    73,    83,    51,    51,    47,    82,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    64,    66,    67,    65,    69,    68,    68,    70,    70,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    75,    74,    76,    76,    77,    77,    78,    78,    80,
      79,    81,    79,    82,    79,    83,    83,    84,    84,    85,
      85,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      99,    99,   100,   100,   101,   102,   102,   102,   102,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     3,     1,     4,     2,     1,     1,     1,     1,     1,
       2,     1,     0,     0,     8,     0,     2,     0,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     2,     1,     5,     7,     0,
       6,     0,     8,     0,    10,     1,     0,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     2,     2,     1,
       3,     1,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     2,
       2,     1,     1,     1,     1,     4,     3,     1,     1,     4,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1
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
#line 99 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0;}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].tbEntry)->data_type,(yyvsp[0].str),"="); is_declaration=1;}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.tbEntry)=(yyvsp[0].tbEntry);}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-1].tbEntry)->value < 1){yyerror("Arrays can't have dimension lesser than 1");} (yyval.tbEntry)=(yyvsp[-3].tbEntry); (yyvsp[-3].tbEntry)->is_array = 1; (yyvsp[-3].tbEntry)->array_dim = (int)(yyvsp[-1].tbEntry)->value;}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("INT");  is_declaration = 1; }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 107 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("VOID");  is_declaration = 1; }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 108 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("CHAR");  is_declaration = 1;}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 109 "parser.y" /* yacc.c:1646  */
    {curr_data_type = strdup("FLOAT");  is_declaration = 1;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "parser.y" /* yacc.c:1646  */
    {is_declaration = 0;}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "parser.y" /* yacc.c:1646  */
    {
                                                
                                                func_type = curr_data_type;
						                        is_declaration = 0;

                                            }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "parser.y" /* yacc.c:1646  */
    {
                                               fill_parameter_list((yyvsp[-4].tbEntry),param_list,p_idx);
                                                p_idx = 0;
                                                is_function = 1;
						                        int flag = set_is_function(SymbolTable,(yyvsp[-4].tbEntry)->lexeme);
                                                if(flag == 0){return -1;}
                                                p=1;
                                            }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    { is_function = 0;
                                              if(!return_exists && strcmp(func_type,"VOID") != 0)
                                              {
                                                yyerror("This Function must have a return type");
                                                
                                              }
					     }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "parser.y" /* yacc.c:1646  */
    {is_param = 1; }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                              is_declaration = 0;
                                             
                                }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 156 "parser.y" /* yacc.c:1646  */
    {curr_nest_level++; stack[top] = curr_nest_level; top+=1; insertNestStart(curr_nest_level,yylineno);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 156 "parser.y" /* yacc.c:1646  */
    {curr_nest_level++; insertNestEnd(stack[top-1],yylineno);top-=1;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 165 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 165 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 166 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 166 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 167 "parser.y" /* yacc.c:1646  */
    {is_loop = 1;}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 167 "parser.y" /* yacc.c:1646  */
    {is_loop = 0;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 171 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of continue");}}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "parser.y" /* yacc.c:1646  */
    { if(is_function) { if(strcmp(func_type,"VOID")!=0) yyerror("return type (VOID) does not match function type");}}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "parser.y" /* yacc.c:1646  */
    {
                                      return_exists = 1;
                                      if(strcmp(curr_data_type,(yyvsp[0].str))!=0)
                                        yyerror("return type does not match function type");
                                   }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 179 "parser.y" /* yacc.c:1646  */
    {if(!is_loop) {yyerror("Illegal use of break");}}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 181 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"=");(yyval.str) = (yyvsp[-2].str);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"+=");(yyval.str) = (yyvsp[-2].str);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"-=");(yyval.str) = (yyvsp[-2].str);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 184 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"*=");(yyval.str) = (yyvsp[-2].str);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 185 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"/=");(yyval.str) = (yyvsp[-2].str);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 186 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-1].str),(yyvsp[-1].str),"++"); (yyval.str) = (yyvsp[-1].str);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 187 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-1].str),(yyvsp[-1].str),"--"); (yyval.str) = (yyvsp[-1].str);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 191 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"||"); (yyval.str) = (yyvsp[-2].str);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 194 "parser.y" /* yacc.c:1646  */
    { typeCheck((yyvsp[-2].str),(yyvsp[0].str),"&&");(yyval.str) = (yyvsp[-2].str);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 197 "parser.y" /* yacc.c:1646  */
    { typeCheck((yyvsp[0].str),(yyvsp[0].str),"!u");(yyval.str) = (yyvsp[0].str);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 200 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),">");(yyval.str) = (yyvsp[-2].str);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 201 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"<");(yyval.str) = (yyvsp[-2].str);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 202 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"<=");(yyval.str) = (yyvsp[-2].str);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 203 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),">=");(yyval.str) = (yyvsp[-2].str);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 204 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"!=");(yyval.str) = (yyvsp[-2].str);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 205 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"==");(yyval.str) = (yyvsp[-2].str);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 208 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"+");(yyval.str) = (yyvsp[-2].str);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 209 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"-");(yyval.str) = (yyvsp[-2].str);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 215 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"*");(yyval.str) = (yyvsp[-2].str);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 216 "parser.y" /* yacc.c:1646  */
    {typeCheck((yyvsp[-2].str),(yyvsp[0].str),"/");(yyval.str) = (yyvsp[-2].str);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 220 "parser.y" /* yacc.c:1646  */
    { typeCheck((yyvsp[0].str),(yyvsp[0].str),"+u");(yyval.str) = (yyvsp[0].str);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 221 "parser.y" /* yacc.c:1646  */
    { typeCheck((yyvsp[0].str),(yyvsp[0].str),"-u");(yyval.str) = (yyvsp[0].str);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 226 "parser.y" /* yacc.c:1646  */
    {if(checkScope(yylval.str) == 0){ return -1;}; (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 226 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1].tbEntry)->value < 0 || (yyvsp[-1].tbEntry)->value >= (yyvsp[-3].tbEntry)->array_dim ){yyerror("Exceeds Array Dimensions\n"); } (yyval.str) = (yyvsp[-3].tbEntry)->data_type;}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
                                      if(checkFunc((yyvsp[-3].tbEntry)->lexeme) == 0)
                                        {return -1;};
                                      (yyval.str) = (yyvsp[-3].tbEntry)->data_type;
                                      check_parameter_list((yyvsp[-3].tbEntry),arg_list,a_idx);
                                      a_idx = 0;
                                    }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 240 "parser.y" /* yacc.c:1646  */
    {
                            arg_list[a_idx] = (char *)malloc(sizeof((yyvsp[0].str)));
                            strcpy(arg_list[a_idx++],(yyvsp[0].str));
                        }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].tbEntry)->data_type;}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 251 "parser.y" /* yacc.c:1646  */
    { 
					if(is_declaration){
					// $1 = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
					(yyval.tbEntry) = (yyvsp[0].tbEntry);
                    is_function = 0;
					}
					else 
					{
					(yyvsp[0].tbEntry) = Search(SymbolTable,yytext);
					(yyval.tbEntry) = (yyvsp[0].tbEntry);
                    if((yyvsp[0].tbEntry) == NULL)
                    {
                        yyerror("Variable Not Declared");
                        return -1;
                    }
					}
			    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1954 "y.tab.c" /* yacc.c:1646  */
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
#line 268 "parser.y" /* yacc.c:1906  */



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


