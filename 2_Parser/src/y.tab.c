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
#line 7 "cminus.y" /* yacc.c:339  */

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */

/* 11.25 추가 */
static int savedNumber;

static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

/* 에러 방지용으로 추가 */
static int yylex(void);
int yyerror(char * message);


#line 89 "y.tab.c" /* yacc.c:339  */

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
    NO_ELSE = 258,
    ELSE = 259,
    ERROR = 260,
    IF = 261,
    WHILE = 262,
    RETURN = 263,
    INT = 264,
    VOID = 265,
    ID = 266,
    NUM = 267,
    ASSIGN = 268,
    EQ = 269,
    NE = 270,
    LT = 271,
    LE = 272,
    GT = 273,
    GE = 274,
    PLUS = 275,
    MINUS = 276,
    TIMES = 277,
    OVER = 278,
    LPAREN = 279,
    RPAREN = 280,
    LBRACE = 281,
    RBRACE = 282,
    LCURLY = 283,
    RCURLY = 284,
    SEMI = 285,
    COMMA = 286
  };
#endif
/* Tokens.  */
#define NO_ELSE 258
#define ELSE 259
#define ERROR 260
#define IF 261
#define WHILE 262
#define RETURN 263
#define INT 264
#define VOID 265
#define ID 266
#define NUM 267
#define ASSIGN 268
#define EQ 269
#define NE 270
#define LT 271
#define LE 272
#define GT 273
#define GE 274
#define PLUS 275
#define MINUS 276
#define TIMES 277
#define OVER 278
#define LPAREN 279
#define RPAREN 280
#define LBRACE 281
#define RBRACE 282
#define LCURLY 283
#define RCURLY 284
#define SEMI 285
#define COMMA 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    46,    55,    58,    59,    62,    68,    74,
      80,    89,    93,    99,    99,   111,   112,   119,   128,   131,
     136,   143,   150,   159,   162,   171,   174,   175,   176,   177,
     178,   181,   182,   185,   192,   202,   209,   213,   220,   225,
     228,   232,   232,   243,   249,   255,   261,   267,   273,   279,
     282,   288,   294,   297,   303,   309,   312,   313,   314,   315,
     321,   321,   331,   332,   335,   344
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NO_ELSE", "ELSE", "ERROR", "IF",
  "WHILE", "RETURN", "INT", "VOID", "ID", "NUM", "ASSIGN", "EQ", "NE",
  "LT", "LE", "GT", "GE", "PLUS", "MINUS", "TIMES", "OVER", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LCURLY", "RCURLY", "SEMI", "COMMA",
  "$accept", "program", "declaration_list", "declaration", "identifier",
  "number_token", "var_declaration", "type_specifier", "fun_declaration",
  "@1", "params", "param_list", "param", "compound_stmt",
  "local_declarations", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "iteration_stmt", "return_stmt", "expression", "var",
  "@2", "simple_expression", "additive_expression", "term", "factor",
  "call", "@3", "args", "arg_list", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -53,   -53,     6,    16,   -53,   -53,    19,   -53,   -53,
     -53,   -53,   -18,    22,   -53,    18,    13,    16,    52,    19,
      23,    57,   -53,   -53,    59,    61,    16,    63,   -53,   -53,
      19,   -53,   -53,    16,   -53,    19,     3,   -18,    67,    68,
      25,   -53,    -8,   -53,   -53,   -19,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,    64,    80,   -53,    54,    28,   -53,   -53,
      -8,    -8,   -53,    65,    71,    72,    73,   -53,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    74,
      75,   -53,   -53,    -8,    -8,   -53,   -53,    32,    32,    32,
      32,    32,    32,    28,    28,   -53,   -53,    11,    11,    76,
     -53,    77,    70,   100,   -53,   -53,   -53,    -8,    11,   -53,
     -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    12,     0,     2,     4,     5,     0,     6,     1,
       3,     7,    13,     0,     9,     0,     0,     0,     0,    16,
       0,    15,    18,    10,    19,     0,     0,     0,    23,    14,
       0,    17,    20,    25,    22,     0,     0,     0,     0,     0,
       0,     8,     0,    21,    32,    40,    59,    27,    24,    26,
      28,    29,    30,     0,    57,    39,    49,    52,    55,    58,
       0,     0,    36,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    56,     0,    63,    38,    57,    47,    48,    44,
      43,    45,    46,    50,    51,    53,    54,     0,     0,     0,
      65,     0,    62,    33,    35,    42,    61,     0,     0,    64,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   101,    -6,   -53,    78,    21,   -53,   -53,
     -53,   -53,    81,    83,   -53,   -53,   -52,   -53,   -53,   -53,
     -53,   -40,   -12,   -53,   -53,     7,     8,     9,   -53,   -53,
     -53,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    45,    46,     6,     7,     8,    15,
      20,    21,    22,    47,    33,    36,    48,    49,    50,    51,
      52,    53,    54,    65,    55,    56,    57,    58,    59,    66,
     101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    12,    64,    11,    41,   -60,     9,   -41,    13,    38,
      39,    40,    14,    24,    11,    41,    42,    38,    39,    40,
      79,    80,    11,    41,    24,     1,     2,    42,    85,    37,
      11,    28,    43,    44,    16,    42,    11,    41,    19,    28,
      18,    44,    17,    99,   100,   103,   104,    30,    25,    42,
      77,    78,    75,    76,    35,    62,   110,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,   109,    69,    70,
      71,    72,    73,    74,    75,    76,    87,    88,    89,    90,
      91,    92,    23,    93,    94,    27,    95,    96,    26,    28,
      32,    60,    61,    68,    67,    81,    82,    84,    83,    97,
      98,   107,   106,   105,   108,    10,     0,    31,    29,     0,
       0,    34
};

static const yytype_int8 yycheck[] =
{
      40,     7,    42,    11,    12,    24,     0,    26,    26,     6,
       7,     8,    30,    19,    11,    12,    24,     6,     7,     8,
      60,    61,    11,    12,    30,     9,    10,    24,    68,    35,
      11,    28,    29,    30,    12,    24,    11,    12,    17,    28,
      27,    30,    24,    83,    84,    97,    98,    26,    25,    24,
      22,    23,    20,    21,    33,    30,   108,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   107,    14,    15,
      16,    17,    18,    19,    20,    21,    69,    70,    71,    72,
      73,    74,    30,    75,    76,    26,    77,    78,    31,    28,
      27,    24,    24,    13,    30,    30,    25,    24,    26,    25,
      25,    31,    25,    27,     4,     4,    -1,    26,    25,    -1,
      -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    33,    34,    35,    38,    39,    40,     0,
      35,    11,    36,    26,    30,    41,    12,    24,    27,    39,
      42,    43,    44,    30,    36,    25,    31,    26,    28,    45,
      39,    44,    27,    46,    38,    39,    47,    36,     6,     7,
       8,    12,    24,    29,    30,    36,    37,    45,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    58,    59,    60,
      24,    24,    30,    53,    53,    55,    61,    30,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    53,
      53,    30,    25,    26,    24,    53,    54,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    25,    25,    53,
      53,    62,    63,    48,    48,    27,    25,    31,     4,    53,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    37,    38,
      38,    39,    39,    41,    40,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    55,    54,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    59,    59,
      61,    60,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     0,     5,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       0,     5,     1,     0,     3,     1
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
        case 2:
#line 43 "cminus.y" /* yacc.c:1646  */
    { savedTree = (yyvsp[0]);}
#line 1361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 46 "cminus.y" /* yacc.c:1646  */
    { 
                        YYSTYPE t = (yyvsp[-1]);
                        if (t != NULL) { 
                          while (t->sibling != NULL)t = t->sibling;
                          t->sibling = (yyvsp[0]);
                          (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);
                      }
#line 1375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "cminus.y" /* yacc.c:1646  */
    {
                        savedName = copyString(tokenString);
                        savedLineNo = lineno;
                      }
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 68 "cminus.y" /* yacc.c:1646  */
    {
                        savedNumber = atoi(tokenString);
                        savedLineNo = lineno;
                      }
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newDeclNode(VarK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->lineno = lineno;
                        (yyval)->attr.name = savedName;
                      }
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newDeclNode(ArrVarK);
                        (yyval)->child[0] = (yyvsp[-5]);
                        (yyval)->lineno = lineno;
                        (yyval)->attr.var_name = savedName;
                        (yyval)->attr.var_size = savedNumber;
                      }
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newDeclNode(TypeK);
                        (yyval)->attr.type = INT;
                      }
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 93 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newDeclNode(TypeK);
                        (yyval)->attr.type = VOID;
                      }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 99 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newDeclNode(FunK);
                        (yyval)->attr.name = savedName;
                      }
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-4]);
                        (yyval)->child[0] = (yyvsp[-6]);
                        (yyval)->child[1] = (yyvsp[-2]);
                        (yyval)->child[2] = (yyvsp[0]);
                      }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 111 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "cminus.y" /* yacc.c:1646  */
    {
                       (yyval) = newParamNode(SingleParamK);
                        (yyval)->child[0] = (yyvsp[0]);
                        (yyval)->attr.name = copyString("(null)");
                      }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "cminus.y" /* yacc.c:1646  */
    {
                        YYSTYPE t = (yyvsp[-2]);
                        if(t != NULL) { 
                          while (t->sibling != NULL)  t = t->sibling;
                          t->sibling = (yyvsp[0]);
                          (yyval) = (yyvsp[-2]); 
                        }
                        else (yyval) = (yyvsp[0]);
                      }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newParamNode(SingleParamK);
                        (yyval)->attr.name = savedName;
                        (yyval)->child[0] = (yyvsp[-1]);
                      }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newParamNode(ArrParamK);
                        (yyval)->attr.name = savedName;
                        (yyval)->child[0] = (yyvsp[-3]);
                      }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newStmtNode(CompK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[-1]);
                      }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "cminus.y" /* yacc.c:1646  */
    {
                        YYSTYPE t = (yyvsp[-1]);
                        if(t != NULL) { 
                          while (t->sibling != NULL)  t = t->sibling;
                          t->sibling = (yyvsp[0]);
                          (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);
                      }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "cminus.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "cminus.y" /* yacc.c:1646  */
    {
                        YYSTYPE t = (yyvsp[-1]);
                        if(t != NULL) { 
                          while (t->sibling != NULL)  t = t->sibling;
                          t->sibling = (yyvsp[0]);
                          (yyval) = (yyvsp[-1]); 
                        }
                        else (yyval) = (yyvsp[0]);
                      }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 171 "cminus.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 178 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 181 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 182 "cminus.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newStmtNode(IfK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->child[2] = NULL;
                        (yyval)->lineno = (yyvsp[-2])->lineno;
                      }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newStmtNode(IfEK);
                        (yyval)->child[0] = (yyvsp[-4]);
                        (yyval)->child[1] = (yyvsp[-2]);
                        (yyval)->child[2] = (yyvsp[0]);
                        (yyval)->lineno = (yyvsp[-4])->lineno;
                      }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 202 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newStmtNode(WhileK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                      }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 209 "cminus.y" /* yacc.c:1646  */
    {
                      (yyval) = newStmtNode(ReturnK);
                      (yyval)->child[0] = NULL;
                    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 213 "cminus.y" /* yacc.c:1646  */
    {
                      (yyval) = newStmtNode(ReturnK);
                      (yyval)->child[0] = (yyvsp[-1]);
                    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 220 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(AssignK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                      }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 225 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 228 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(IdK);
                        (yyval)->attr.name = savedName;
                      }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 232 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(ArrIdK);
                        (yyval)->attr.name = savedName;
                      }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-3]);
                        (yyval)->child[0] = (yyvsp[-1]);
                      }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = LE;
                      }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 249 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = LT;
                      }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 255 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = GT;
                      }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 261 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = GE;
                      }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 267 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = EQ;
                      }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 273 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = NE;
                      }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 279 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 282 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = PLUS;
                      }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 288 "cminus.y" /* yacc.c:1646  */
    {
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = MINUS;
                      }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 294 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 297 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = TIMES;
                      }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 303 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(OpK);
                        (yyval)->child[0] = (yyvsp[-2]);
                        (yyval)->child[1] = (yyvsp[0]);
                        (yyval)->attr.op = OVER;
                      }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 309 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 312 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 313 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 314 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 315 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(ConstK);
                        (yyval)->attr.val = savedNumber;
                      }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = newExpNode(CallK);
                        (yyval)->attr.name = savedName;
                      }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 325 "cminus.y" /* yacc.c:1646  */
    { 
                        (yyval) = (yyvsp[-3]);
                        (yyval)->child[0] = (yyvsp[-1]);
                      }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 331 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 332 "cminus.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 335 "cminus.y" /* yacc.c:1646  */
    { 
                        YYSTYPE t = (yyvsp[-2]);
                        if(t != NULL) { 
                          while (t->sibling != NULL) t = t->sibling;
                          t->sibling = (yyvsp[0]);
                          (yyval) = (yyvsp[-2]); 
                        }
                        else (yyval) = (yyvsp[0]);
                      }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 344 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1924 "y.tab.c" /* yacc.c:1646  */
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
#line 347 "cminus.y" /* yacc.c:1906  */


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

