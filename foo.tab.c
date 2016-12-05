/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "foo.tab.c" /* yacc.c:339  */

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
   by #include "foo.tab.h".  */
#ifndef YY_YY_FOO_TAB_H_INCLUDED
# define YY_YY_FOO_TAB_H_INCLUDED
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
    VOID = 258,
    TYPE = 259,
    ID = 260,
    RETURN = 261,
    FLOATPT = 262,
    INTEGER = 263,
    CHAR = 264,
    PARAMS = 265,
    STRING = 266,
    IF = 267,
    WHILE = 268,
    ELSE = 269,
    OP = 270,
    COP = 271,
    AOP = 272,
    IOP = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 1 "foo.y" /* yacc.c:355  */

	int i;
	float x;
	char c;
	int s;

#line 133 "foo.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FOO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 45 "foo.y" /* yacc.c:358  */

	#include "fubar.h"
	//open file to write digraph to
	FILE *fchart = fopen("fchart.dot", "w");
	//position of final node at the end of top level control structures
	int nc = 0;
	//recursive depth
	int depth = 0;
	//maximum recursive depth in this recursion
	int maxdepth = 0;
	//maximum node, place to continue after recursion complete
	int maxnode = 0;
	//assumes a recursive depth of less than 101
	//holds the number of junk (non-control) nodes at each level
	int junk[100];
	int junkSize = sizeof(junk)/sizeof(junk[0]);
	//number of control nodes at each level
	int atDepth[100];
	int atDepthSize = sizeof(atDepth)/sizeof(atDepth[0]);
<<<<<<< HEAD
	//stores current node for reuse in if else statements
	int storeCurrent[100];
	int storeCurrentSize = sizeof(storeCurrent)/sizeof(storeCurrent[0]);
	//stores the current file position for rewinding at the end of while and if else statements
	long int pos = 0;
	int lsize = 0;

#line 176 "foo.tab.c" /* yacc.c:358  */
=======

#line 168 "foo.tab.c" /* yacc.c:358  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

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
      20,    21,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
<<<<<<< HEAD
       0,    76,    76,    76,    78,    93,    97,   105,   112,   113,
     113,   117,   120,   124,   129,   137,   139,   141,   143,   196,
     265,   329,   330,   331,   374,   420,   423,   429,   435,   444,
     452,   463,   473,   485,   486,   487,   488,   489,   495
=======
       0,    70,    70,    70,    72,    73,    76,    77,    77,    81,
      84,    88,    92,    96,    98,   100,   102,   154,   157,   160,
     161,   162,   195,   198,   204,   210,   219,   227,   238,   248,
     260,   261,   262,   263,   264,   270
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "TYPE", "ID", "RETURN",
  "FLOATPT", "INTEGER", "CHAR", "PARAMS", "STRING", "IF", "WHILE", "ELSE",
  "OP", "COP", "AOP", "IOP", "'+'", "'('", "')'", "'{'", "'}'", "';'",
  "'='", "$accept", "program", "fndef", "void", "type", "params", "block",
  "returnblock", "statements", "statement", "else", "expr", "sexpr", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    43,
      40,    41,   123,   125,    59,    61
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -39,    96,   -39,    10,    19,   -39,    13,    30,   -39,   -39,
      47,    47,    49,    47,    57,    61,   -39,   -39,    37,    39,
     -39,   -39,   -39,   -39,    18,    40,    82,    38,   -39,   -39,
     -39,    72,    72,   -39,   -39,   -39,   -39,   -10,    85,    76,
      73,    76,   -39,    47,    81,    86,    37,    37,    37,    76,
     -39,    76,     3,    87,   -12,    76,    -5,    83,    48,    -5,
      52,    51,   -39,    89,   -39,    87,    -5,    76,    74,    -8,
      84,    47,    76,    76,    76,   -39,   -39,   -39,   -39,   -39,
      88,    55,    58,    59,    90,   -39,   -39,   -39,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     2,     0,     0,     6,     7,
      10,    10,     0,    10,     0,     0,     9,     8,     0,     0,
      14,     4,    14,     5,     0,     0,     0,    35,    34,    33,
      36,     0,     0,    11,    22,    21,    13,     0,    25,     0,
       0,     0,    38,    10,     0,     0,     0,     0,     0,     0,
      23,     0,    35,     0,    25,     0,    27,     0,    35,    28,
      35,    25,    20,    18,    19,    37,    26,     0,     0,    25,
       0,    10,     0,     0,     0,    29,    24,    12,    15,    16,
       0,    25,    25,    25,     0,    31,    32,    30,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -11,    -9,   -39,    91,   -39,
     -39,    -6,    75,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,     7,    14,    35,    23,    24,    36,
      46,    53,    47,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    54,    17,    56,    51,    49,    59,    61,    51,    21,
     -25,    51,    68,    66,    50,     8,    78,    69,    37,    37,
      41,    42,    26,    27,     9,    28,    29,    30,    67,    59,
      31,    32,    57,    10,    81,    82,    83,    62,    63,    64,
      20,    33,    34,    65,    26,    27,    39,    28,    29,    30,
      11,    12,    31,    32,    16,    41,    42,    13,    43,    20,
      80,    22,    20,    44,    34,    41,    42,    74,    71,    72,
      42,    51,    75,    67,    51,    51,    85,    73,    18,    86,
      87,    52,    19,    28,    29,    30,    58,    40,    28,    29,
      30,    60,    45,    28,    29,    30,     2,    77,    55,     3,
       4,    51,    49,    76,    70,     0,     0,    48,    79,    84,
       0,     0,     0,    25,    88
};

static const yytype_int8 yycheck[] =
{
      11,    39,    13,    41,    16,    15,    44,    45,    16,    18,
      15,    16,    24,    51,    24,     5,    24,    55,    24,    25,
      17,    18,     4,     5,     5,     7,     8,     9,    25,    67,
      12,    13,    43,    20,    72,    73,    74,    46,    47,    48,
      22,    23,    24,    49,     4,     5,     6,     7,     8,     9,
      20,     4,    12,    13,     5,    17,    18,    10,    20,    22,
      71,    22,    22,    25,    24,    17,    18,    16,    20,    17,
      18,    16,    21,    25,    16,    16,    21,    25,    21,    21,
      21,     5,    21,     7,     8,     9,     5,     5,     7,     8,
       9,     5,    20,     7,     8,     9,     0,    23,    25,     3,
       4,    16,    15,    14,    21,    -1,    -1,    32,    24,    21,
      -1,    -1,    -1,    22,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     3,     4,    28,    29,    30,     5,     5,
      20,    20,     4,    10,    31,    31,     5,    31,    21,    21,
      22,    32,    22,    33,    34,    34,     4,     5,     7,     8,
       9,    12,    13,    23,    24,    32,    35,    37,    39,     6,
       5,    17,    18,    20,    25,    20,    36,    38,    38,    15,
      24,    16,     5,    37,    39,    25,    39,    31,     5,    39,
       5,    39,    32,    32,    32,    37,    39,    25,    24,    39,
      21,    20,    17,    25,    16,    21,    14,    23,    24,    24,
      31,    39,    39,    39,    21,    21,    21,    21,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    28,    28,    29,    30,    31,    31,
      31,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    36,    37,    37,    37,    37,    38,
      38,    38,    38,    39,    39,    39,    39,    39,    39
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     5,     2,     2,     2,     2,
       0,     3,     6,     2,     0,     5,     5,     7,     3,     3,
       3,     1,     1,     2,     3,     1,     3,     3,     3,     3,
       5,     5,     5,     1,     1,     1,     1,     3,     2
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
        case 3:
<<<<<<< HEAD
#line 76 "foo.y" /* yacc.c:1646  */
    {cout << "ready" << endl; }
#line 1305 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 79 "foo.y" /* yacc.c:1646  */
    { 
		if(junk[0] != 0) {
			nc = nc + junk[0] + 1;
			junk[0] = 0;
			fprintf(fchart, "%d[label = \"end_void\"]", nc);

		}
		else {
			fprintf(fchart, "%d[label = \"end_void\"]", nc);
		}
		
		
		
	}
#line 1324 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "foo.y" /* yacc.c:1646  */
    { cout << "function defined" << endl;}
#line 1330 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "foo.y" /* yacc.c:1646  */
    { 
		
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", nc, nc + 1, nc, lookup((yyvsp[0].s)).c_str());
		//nc++;
	}
#line 1340 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "foo.y" /* yacc.c:1646  */
    { 
		
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", nc, nc + 1, nc, lookup((yyvsp[0].s)).c_str());
		//nc++;
	}
#line 1350 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = saveBlock(lookupStatements((yyvsp[-1].s)));}
#line 1356 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "foo.y" /* yacc.c:1646  */
=======
#line 70 "foo.y" /* yacc.c:1646  */
    {cout << "ready" << endl; }
#line 1302 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "foo.y" /* yacc.c:1646  */
    { cout << "void function defined" << endl;}
#line 1308 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 73 "foo.y" /* yacc.c:1646  */
    { cout << "function defined" << endl;}
#line 1314 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = saveBlock(lookupStatements((yyvsp[-1].s)));}
#line 1320 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 88 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { 
									(yyval.s) = saveStatements(lookupStatements((yyvsp[-1].s)) + lookup((yyvsp[0].s)) + "\\n");
									
								}
<<<<<<< HEAD
#line 1365 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "foo.y" /* yacc.c:1646  */
    { 
			(yyval.s) = saveStatements("");
				
		}
#line 1374 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1380 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1386 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1392 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "foo.y" /* yacc.c:1646  */
=======
#line 1329 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = saveStatements("");}
#line 1335 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 96 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1341 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1347 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 100 "foo.y" /* yacc.c:1646  */
    { junk[depth]++; }
#line 1353 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    {
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//add node to graph linking to statements if true
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current, current + 1, current, lookup((yyvsp[-1].s)).c_str());


		//check if end node highest, else swap end node
<<<<<<< HEAD
		if(current + junk[depth] + 1 > maxnode) {
=======
		if(current + 1 + junk[depth] > maxnode) {
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
			maxnode = current + junk[depth] + 1;
		}
		//connect false part to end of if statement
		fprintf(fchart, "%d->%d\n", current, maxnode);
		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
<<<<<<< HEAD
			nc = maxnode - 1;
=======
			nc = maxnode;
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}
<<<<<<< HEAD
#line 1447 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 197 "foo.y" /* yacc.c:1646  */
    {
		if(junk[depth] > 0) {
			int curPos = ftell(fchart);
			fseek(fchart, pos, SEEK_SET);
			for(int i = 0; i < lsize; i++) {
				fprintf(fchart, " ");
			}
			fseek(fchart, curPos, SEEK_SET);
		}

		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//add node to graph linking to statements if true
		if(junk[depth] > 0) {
			fprintf(fchart, "%d->%d[label=true]\n%d[label = \"%s\", shape=diamond]", current, current + 1, current, lookup((yyvsp[-1].s)).c_str());

			fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current + junk[depth], current, current, lookup((yyvsp[-1].s)).c_str());
		}
		else {
			fprintf(fchart, "%d->%d[label=true]\n%d[label = \"%s\", shape=diamond]", current, current, current, lookup((yyvsp[-1].s)).c_str());	
		}


		//check if end node highest, else swap end node
		if(current + junk[depth] + 1 > maxnode) {
			maxnode = current + junk[depth] + 1;
		}
		//connect false part to end of if statement
		fprintf(fchart, "%d->%d[label = false]\n", current, maxnode);
		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
			nc = maxnode - 1;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}
#line 1518 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 266 "foo.y" /* yacc.c:1646  */
    {
		
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//link the top node of the if statement stored in storeCurrent to the first node of the else side
		fprintf(fchart, "%d->%d[label=\"false\"]\n", current, storeCurrent[depth - 1]);



		//check if end node highest, else swap end node
		if(current + junk[depth] + 1 > maxnode) {
			maxnode = current + junk[depth] + 1;
		}

		if(storeCurrent[depth - 1] - 1 != current) {
			fprintf(fchart, "%d->%d\n", storeCurrent[depth - 1] - 1, maxnode);

		}
		else {
			fprintf(fchart, "%d->%d[label=\"true\"]\n%d[label = \"%s\",  shape = \"diamond\"]", current, maxnode, current, lookup((yyvsp[-2].s)).c_str());
		}

		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				storeCurrent[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
			nc = maxnode - 1;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}
#line 1585 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 332 "foo.y" /* yacc.c:1646  */
=======
#line 1408 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "foo.y" /* yacc.c:1646  */
    {cout << "while expression found" << endl;
					}
#line 1415 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "foo.y" /* yacc.c:1646  */
    {cout << "if else expression found" << endl;
					   }
#line 1422 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 163 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { 
			(yyval.s) = save(lookup((yyvsp[-1].s))+";");
			//check if greatest recursive depth
			if(depth > maxdepth){
				maxdepth = depth;
			}
			//get current node
			int current = nc;
			//increment number of junk nodes at this level
			junk[depth]++;
			//add number of junk nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			//add number of control nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
			current += atDepth[i];
			}
			//if this is the last node increase last node
			if(current + 1 > maxnode) {
				maxnode = current + 1;
			}

<<<<<<< HEAD
			
			//cout << maxdepth;

			//store position to rewind if need
			pos = ftell(fchart);

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n", current, current + 1);
			
			lsize = ftell(fchart) - pos;

			fprintf(fchart, "%d[label = \"%s\", shape = \"rectangle\"]\n", current, lookup((yyvsp[-1].s)).c_str());
			
		}
#line 1627 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 375 "foo.y" /* yacc.c:1646  */
    {
		if(junk[depth] > 0) {
			int curPos = ftell(fchart);
			fseek(fchart, pos, SEEK_SET);
			for(int i = 0; i < lsize; i++) {
				fprintf(fchart, " ");
			}
			fseek(fchart, curPos, SEEK_SET);
		}
		
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}
		
		//add node to graph linking to statements if true
		fprintf(fchart, "%d->%d[label=\"true\"]\n%d[label = \"%s\",  shape = \"diamond\"]", current, current + 1, current, lookup((yyvsp[-2].s)).c_str());


		//check if end node highest, else swap end node
		if(current + 1 + junk[depth] > maxnode) {
			maxnode = current + junk[depth] + 1;
		}

		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		//store the first node of the second side
		storeCurrent[depth - 1] = maxnode;

	}
#line 1675 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 420 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(lookup((yyvsp[0].s))); }
#line 1681 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 423 "foo.y" /* yacc.c:1646  */
=======
			
			//cout << maxdepth;

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current, current + 1, current, lookup((yyvsp[-1].s)).c_str());
		}
#line 1456 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 195 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(lookup((yyvsp[0].s))); }
#line 1462 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { string s = lookup((yyvsp[-2].s)); 
			  	  s += lookupOP((yyvsp[-1].s));
			  	  s += lookup((yyvsp[0].s));
			 	  (yyval.s) = save(s); }
<<<<<<< HEAD
#line 1690 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 429 "foo.y" /* yacc.c:1646  */
=======
#line 1471 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { string s = lookup((yyvsp[-2].s)); 
			  	  s += lookupOP((yyvsp[-1].s));
			  	  s += lookup((yyvsp[0].s));
			 	  (yyval.s) = save(s); 
				}
<<<<<<< HEAD
#line 1700 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 435 "foo.y" /* yacc.c:1646  */
=======
#line 1481 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { string s = lookup((yyvsp[-2].s)); 
			  	  s += "=";
			  	  s += lookup((yyvsp[0].s));
			 	  (yyval.s) = save(s); 
				}
<<<<<<< HEAD
#line 1710 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 444 "foo.y" /* yacc.c:1646  */
=======
#line 1491 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { 
					(yyval.s) = save(lookup((yyvsp[-1].s))); 
					//increment number of control nodes at this depth and increment depth
					atDepth[depth]++;
					depth++;
				}
<<<<<<< HEAD
#line 1721 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 452 "foo.y" /* yacc.c:1646  */
=======
#line 1502 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 227 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { 
								string s = lookup((yyvsp[-3].s)); 
						  	  	s += lookupOP((yyvsp[-2].s));
						  	  	s += lookup((yyvsp[-1].s));
						 	  	(yyval.s) = save(s); 
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
								depth++;
							}
<<<<<<< HEAD
#line 1735 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 463 "foo.y" /* yacc.c:1646  */
=======
#line 1516 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 238 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    {
								string s = lookup((yyvsp[-3].s)); 
					  	  		s += lookupOP((yyvsp[-2].s));
					  	  		s += lookup((yyvsp[-1].s));
					 	  		(yyval.s) = save(s);
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
								depth++; 
							}
<<<<<<< HEAD
#line 1749 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 473 "foo.y" /* yacc.c:1646  */
=======
#line 1530 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 248 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    {
								string s = lookup((yyvsp[-3].s)); 
					  	  		s += "=";
					  	  		s += lookup((yyvsp[-1].s));
					 	  		(yyval.s) = save(s); 
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
								depth++;
							}
<<<<<<< HEAD
#line 1763 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 485 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(to_string((yyvsp[0].i))); }
#line 1769 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 486 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(to_string((yyvsp[0].x))); }
#line 1775 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 487 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s);}
#line 1781 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 488 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s);}
#line 1787 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 489 "foo.y" /* yacc.c:1646  */
=======
#line 1544 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 260 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(to_string((yyvsp[0].i))); }
#line 1550 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 261 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = save(to_string((yyvsp[0].x))); }
#line 1556 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 262 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s);}
#line 1562 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 263 "foo.y" /* yacc.c:1646  */
    { (yyval.s) = (yyvsp[0].s);}
#line 1568 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 264 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { string s = lookup((yyvsp[-2].s)); 
			  	  s += lookupOP((yyvsp[-1].s));
			  	  s += lookup((yyvsp[0].s));
			 	  (yyval.s) = save(s); 
				}
<<<<<<< HEAD
#line 1797 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 495 "foo.y" /* yacc.c:1646  */
=======
#line 1578 "foo.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 270 "foo.y" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
    { string s = lookup((yyvsp[-1].s)); 
			  	  s += lookupOP((yyvsp[0].s));
			 	  (yyval.s) = save(s); 
				}
<<<<<<< HEAD
#line 1806 "foo.tab.c" /* yacc.c:1646  */
    break;


#line 1810 "foo.tab.c" /* yacc.c:1646  */
=======
#line 1587 "foo.tab.c" /* yacc.c:1646  */
    break;


#line 1591 "foo.tab.c" /* yacc.c:1646  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
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
<<<<<<< HEAD
#line 500 "foo.y" /* yacc.c:1906  */
=======
#line 275 "foo.y" /* yacc.c:1906  */
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907



void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	//initialize digraph
	fprintf(fchart, "digraph {\nnode [shape=circle]\n");
	//initialize arrays
	for(int i = 0; i < junkSize; i++) {
		junk[i] = 0;
	}
	for(int i = 0; i < atDepthSize; i++) {
		atDepth[i] = 0;
	}
<<<<<<< HEAD
	for(int i = 0; i < storeCurrentSize; i++) {
		storeCurrent[i] = 0;
	}

=======
	
>>>>>>> e1af1da07d0754c19346c194bafa010e87890907
	yyparse();
	//end digraph
	fprintf(fchart, "}");
	//close file
	fclose(fchart);
	return 0;
}





























