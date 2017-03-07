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

#line 67 "src/c_parser.tab.cpp" /* yacc.c:339  */

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
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y" /* yacc.c:355  */

  #include "ast.hpp"
  #include <cassert>

  extern const Unit *prog_root;

  int yylex(void);
  void yyerror(const char *);



#line 109 "src/c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPEDEF = 283,
    EXTERN = 284,
    STATIC = 285,
    AUTO = 286,
    REGISTER = 287,
    CHAR = 288,
    SHORT = 289,
    INT = 290,
    LONG = 291,
    SIGNED = 292,
    UNSIGNED = 293,
    FLOAT = 294,
    DOUBLE = 295,
    CONST = 296,
    VOLATILE = 297,
    VOID = 298,
    STRUCT = 299,
    UNION = 300,
    ENUM = 301,
    ELLIPSIS = 302,
    CASE = 303,
    DEFAULT = 304,
    IF = 305,
    ELSE = 306,
    SWITCH = 307,
    WHILE = 308,
    DO = 309,
    FOR = 310,
    GOTO = 311,
    CONTINUE = 312,
    BREAK = 313,
    RETURN = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "src/c_parser.y" /* yacc.c:355  */

  const Expression *expr;
  const Statement *stmt;
  const Declarator *dltr;
  const FunctionDefinition *fdfn;
  const ExternalDeclaration *edln;
  const Unit *unit;

  double number;
  std::string *string_value;

#line 193 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    72,    65,     2,
      62,    63,    66,    67,    79,    68,    64,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    78,    61,
      73,    60,    74,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,    76,    83,    69,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    77,    78,    79,    83,    84,    85,    86,
      87,    88,    92,    93,    94,   107,   108,   109,   110,   114,
     115,   116,   120,   121,   122,   126,   127,   128,   129,   130,
     134,   135,   136,   140,   141,   145,   146,   150,   151,   155,
     156,   160,   161,   165,   166,   171,   172,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   190,   191,
     195,   199,   200,   204,   205,   209,   210,   214,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   231,   236,   237,
     238,   239,   240,   244,   245,   251,   252,   253,   254,   255,
     256,   260,   261,   262,   266,   267,   268,   269,   273,   274,
     278,   279,   283,   284,   289,   290,   291,   295,   296,   297,
     298,   302,   303,   304,   305,   306,   310,   311,   315,   316,
     320,   321,   322,   323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'='", "';'", "'('", "')'", "'.'", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "':'", "','", "'['", "']'", "'{'", "'}'", "$accept",
  "ROOT", "primary_expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "eor_expression", "or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "identifier_list", "statement",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "this_unit",
  "external_declaration", "function_definition", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      61,    59,    40,    41,    46,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    58,    44,
      91,    93,   123,   125
};
# endif

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     274,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,    50,     5,  -121,     0,   194,   286,    57,   274,  -121,
    -121,   -29,  -121,  -121,   -52,   -50,   286,  -121,    32,  -121,
       0,  -121,   286,    40,    47,  -121,  -121,  -121,    50,  -121,
     286,    49,  -121,  -121,   207,   207,   207,    56,   -17,    11,
      76,   236,    97,   158,   131,   174,    22,  -121,  -121,  -121,
     109,   319,    96,    86,   175,     3,   173,   105,   108,   143,
     220,   -13,  -121,  -121,    60,  -121,  -121,  -121,   141,   200,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   -46,  -121,
    -121,  -121,  -121,   157,  -121,  -121,   236,  -121,  -121,   168,
     236,   207,   207,   207,   198,   121,   186,  -121,  -121,  -121,
      61,   257,  -121,  -121,   199,   260,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,  -121,   207,  -121,
     217,  -121,  -121,  -121,   261,  -121,  -121,   236,  -121,   -19,
      -5,    68,   206,   121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,    96,    96,    86,    86,   175,   175,   175,
     175,     3,     3,   173,   105,   108,   143,   220,   128,  -121,
    -121,  -121,  -121,   236,   236,   236,   207,    15,   207,   228,
    -121,  -121,    69,   236,    72,  -121,   236,   219,  -121,   236,
    -121,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,    69,    70,    71,    72,    75,    76,    73,    74,
      68,     0,     0,   119,     0,    63,     0,    77,     2,   116,
     118,     0,     1,    61,     0,    65,    67,    64,     0,    98,
       0,   123,     0,     0,     0,   117,    79,    62,     0,   121,
       0,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,    94,     6,
      12,    15,    19,    22,    25,    30,    33,    35,    37,    39,
      41,    43,    45,    58,     0,   100,    85,    86,     0,     0,
      87,    88,    89,    90,    67,    99,   122,    83,     0,     3,
      81,    15,    60,     0,    66,   120,     0,    13,    14,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,     0,    10,    11,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    56,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,    96,
       0,    95,   101,    82,     0,    80,    91,     0,    93,     0,
       0,     0,     0,     0,   111,   115,     9,     7,     8,    46,
      16,    17,    18,    20,    21,    23,    24,    28,    29,    26,
      27,    31,    32,    34,    36,    38,    40,    42,     0,    59,
      97,    84,    92,     0,     0,     0,     0,     0,     0,   104,
     106,   107,     0,     0,     0,    44,     0,     0,   109,     0,
     105,   108,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   -34,    82,    84,   166,   103,   140,
     145,   153,   154,   160,  -121,   -33,  -120,  -121,   -54,   269,
     123,    39,  -121,   268,  -121,   122,  -121,  -121,   -37,  -121,
       6,   -20,   238,   -84,  -121,  -121,  -121,  -121,   309,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   127,    74,    93,
      29,    30,    24,    25,    15,    16,    17,    88,    75,    76,
      77,    32,    79,    80,    81,    82,    83,    18,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      91,    92,   110,     1,   145,    22,    40,   169,    78,    37,
      97,    98,    91,    92,   104,   135,   136,   153,    89,    42,
      43,   163,    31,    44,    45,    89,    42,    43,   189,    38,
      44,    45,    39,   154,    36,    41,    42,    43,    86,    14,
      44,    45,   152,    87,   193,   101,    95,   159,   160,   161,
      89,    42,    43,     1,    27,    44,    45,    14,   194,   156,
     148,    23,    11,   158,   146,     2,     3,     4,     5,     6,
       7,     8,     9,   102,   148,    10,   137,   138,   203,   197,
      46,    47,    48,   109,    49,    50,    51,    52,    53,    54,
      55,    56,   188,    57,   170,   171,   172,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    11,   152,    28,    58,   111,   112,   113,    33,
     192,   147,   165,    13,    89,    42,    43,    96,    90,    44,
      45,   195,   207,    21,   100,   209,    26,    34,   103,   148,
     148,    13,   202,   204,    41,    42,    43,   148,   148,    44,
      45,   148,    84,   131,   132,    85,   199,   200,   201,   105,
      84,   106,   128,    85,    91,   205,   208,   129,   130,   210,
     141,   114,   212,   115,     2,     3,     4,     5,     6,     7,
       8,     9,    57,   142,    10,   133,   134,   139,   140,    46,
      47,    48,   107,    49,    50,    51,    52,    53,    54,    55,
      56,    85,    57,    41,    42,    43,   198,   148,    44,    45,
      89,    42,    43,   173,   174,    44,    45,   175,   176,   143,
      41,    42,    43,    28,   149,    44,    45,     2,     3,     4,
       5,     6,     7,     8,     9,   108,   144,    10,   155,    41,
      42,    43,   181,   182,    44,    45,   157,   164,    46,    47,
      48,   162,    49,    50,    51,    52,    53,    54,    55,    56,
     166,    57,   167,   168,   191,    46,    47,    48,   196,    49,
      50,    51,    52,    53,    54,    55,    56,     1,    57,   206,
     211,   183,    28,   151,    46,    47,    48,   184,    49,    50,
      51,    52,    53,    54,    55,    56,   185,    57,   186,    28,
     190,   177,   178,   179,   180,   187,    94,     2,     3,     4,
       5,     6,     7,     8,     9,    99,   150,    10,    28,     2,
       3,     4,     5,     6,     7,     8,     9,    35,     0,    10,
       0,     0,     0,     0,     0,     0,    11,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126
};

static const yytype_int16 yycheck[] =
{
      34,    34,    56,     3,    17,     0,    26,   127,    28,    61,
      44,    45,    46,    46,    51,    12,    13,    63,     3,     4,
       5,   105,    16,     8,     9,     3,     4,     5,   148,    79,
       8,     9,    26,    79,    63,     3,     4,     5,    32,     0,
       8,     9,    79,     3,    63,    62,    40,   101,   102,   103,
       3,     4,     5,     3,    15,     8,     9,    18,    63,    96,
      79,    61,    62,   100,    77,    33,    34,    35,    36,    37,
      38,    39,    40,    62,    79,    43,    73,    74,    63,   163,
      48,    49,    50,    61,    52,    53,    54,    55,    56,    57,
      58,    59,   146,    61,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    62,   150,    82,    83,     7,     8,     9,    62,
     157,    61,    61,     0,     3,     4,     5,    78,    81,     8,
       9,    63,    63,    11,    78,    63,    14,    80,    62,    79,
      79,    18,   196,   197,     3,     4,     5,    79,    79,     8,
       9,    79,    30,    67,    68,    32,   193,   194,   195,    62,
      38,     3,    66,    40,   198,   198,   203,    71,    72,   206,
      65,    62,   209,    64,    33,    34,    35,    36,    37,    38,
      39,    40,    61,    75,    43,    10,    11,    14,    15,    48,
      49,    50,    61,    52,    53,    54,    55,    56,    57,    58,
      59,    78,    61,     3,     4,     5,    78,    79,     8,     9,
       3,     4,     5,   131,   132,     8,     9,   133,   134,    76,
       3,     4,     5,    82,    83,     8,     9,    33,    34,    35,
      36,    37,    38,    39,    40,    61,    16,    43,    81,     3,
       4,     5,   139,   140,     8,     9,    78,    61,    48,    49,
      50,    53,    52,    53,    54,    55,    56,    57,    58,    59,
       3,    61,    63,     3,     3,    48,    49,    50,    62,    52,
      53,    54,    55,    56,    57,    58,    59,     3,    61,    51,
      61,   141,    82,    83,    48,    49,    50,   142,    52,    53,
      54,    55,    56,    57,    58,    59,   143,    61,   144,    82,
      83,   135,   136,   137,   138,   145,    38,    33,    34,    35,
      36,    37,    38,    39,    40,    46,    78,    43,    82,    33,
      34,    35,    36,    37,    38,    39,    40,    18,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    33,    34,    35,    36,    37,    38,    39,    40,
      43,    62,    85,   104,   105,   108,   109,   110,   121,   122,
     123,   109,     0,    61,   106,   107,   109,   105,    82,   104,
     105,   114,   115,    62,    80,   122,    63,    61,    79,   114,
     115,     3,     4,     5,     8,     9,    48,    49,    50,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    83,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   102,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   109,   104,   114,     3,   111,     3,
      81,    88,    99,   103,   107,   114,    78,    88,    88,   103,
      78,    62,    62,    62,   112,    62,     3,    61,    61,    61,
     102,     7,     8,     9,    62,    64,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    60,   101,    66,    71,
      72,    67,    68,    10,    11,    12,    13,    73,    74,    14,
      15,    65,    75,    76,    16,    17,    77,    61,    79,    83,
     116,    83,   112,    63,    79,    81,   112,    78,   112,   102,
     102,   102,    53,   117,    61,    61,     3,    63,     3,   100,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    92,    92,    93,    94,    95,    96,    97,   102,   100,
      83,     3,   112,    63,    63,    63,    62,   117,    78,   112,
     112,   112,   102,    63,   102,    99,    51,    63,   112,    63,
     112,    61,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    92,    92,
      93,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     103,   104,   104,   105,   105,   106,   106,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     2,     1,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
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
#line 74 "src/c_parser.y" /* yacc.c:1646  */
    { prog_root = (yyvsp[0].unit); }
#line 1491 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Identifier( *(yyvsp[0].string_value) ); }
#line 1497 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Constant( *(yyvsp[0].string_value) ); }
#line 1503 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringLiteral( *(yyvsp[0].string_value) ); }
#line 1509 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixEmpty( (yyvsp[0].expr), "" ); }
#line 1515 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixEmpty( (yyvsp[-2].expr), "" ); }
#line 1521 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixPeriod( (yyvsp[-2].expr), *(yyvsp[0].string_value) ); }
#line 1527 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixPtrOp( (yyvsp[-2].expr), *(yyvsp[0].string_value) ); }
#line 1533 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixIncOp( (yyvsp[-1].expr), "" ); }
#line 1539 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 88 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixDecOp( (yyvsp[-1].expr), ""); }
#line 1545 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryPostfixExpression( (yyvsp[0].expr) ); }
#line 1551 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryIncExpression( (yyvsp[0].expr) ); }
#line 1557 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryDecExpression( (yyvsp[0].expr) ); }
#line 1563 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new MultiplyMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1569 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DivideMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1575 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ModMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1581 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AddAdditive( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1587 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SubAdditive( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1593 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LeftOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1599 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new RightOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1605 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StrictLessThanExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1611 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StrictGreaterThanExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1617 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LessEqualExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1623 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GreaterEqualExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1629 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new EqualOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1635 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NotEqualOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1641 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AndExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1647 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 146 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new XorExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1653 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 151 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OrExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1659 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 156 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalAndExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1665 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 161 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalOrExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1671 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 167 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ConditionalExpression ( (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1677 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 172 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignmentExpression ( (yyvsp[-2].expr), *(yyvsp[-1].string_value), (yyvsp[0].expr) ); }
#line 1683 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 191 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new MainExpression( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1689 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 199 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new MainDeclaration( (yyvsp[-1].dltr), NULL); }
#line 1695 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 200 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new MainDeclaration( (yyvsp[-2].dltr), (yyvsp[-1].dltr)); }
#line 1701 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationSpecifier( (yyvsp[0].expr), NULL ); }
#line 1707 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationSpecifier( (yyvsp[-1].expr), (yyvsp[0].dltr) ); }
#line 1713 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 209 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationList(); }
#line 1719 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 210 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1725 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 214 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new InitDeclarator( (yyvsp[0].dltr), NULL ); }
#line 1731 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 218 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1737 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 219 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1743 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 220 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1749 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 221 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1755 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 222 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1761 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 223 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1767 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 224 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1773 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 225 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1779 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 226 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1785 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 236 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new IdentifierDeclarator( new Identifier( *(yyvsp[0].string_value) ) ); }
#line 1791 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 237 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new BracketedDeclarator( (yyvsp[-1].dltr) ); }
#line 1797 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-3].dltr), (yyvsp[-1].expr) ); }
#line 1803 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-2].dltr), NULL );}
#line 1809 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-3].dltr), (yyvsp[-1].expr) ); }
#line 1815 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 244 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExpressionList(); }
#line 1821 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 245 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr)->AddItem(new Identifier( *(yyvsp[0].string_value) ) ); }
#line 1827 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 260 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IdentifierStatement( new Identifier( *(yyvsp[-2].string_value) ), (yyvsp[0].stmt) ); }
#line 1833 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 261 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseStatement( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1839 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 262 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DefaultStatement( (yyvsp[0].stmt) ); }
#line 1845 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 266 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( NULL, NULL ); }
#line 1851 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 267 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( (yyvsp[-1].stmt), NULL ); }
#line 1857 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 268 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( NULL, (yyvsp[-1].dltr) ); }
#line 1863 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 269 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( (yyvsp[-1].stmt), (yyvsp[-2].dltr) ); }
#line 1869 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 273 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationList(); }
#line 1875 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 274 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1881 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 278 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new StatementList();}
#line 1887 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 279 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt)->AddItem( (yyvsp[0].stmt) ); }
#line 1893 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 283 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExpressionStatement( NULL ); }
#line 1899 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 284 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExpressionStatement( (yyvsp[-1].expr) ); }
#line 1905 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 289 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfSelection( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1911 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 290 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfElseSelection( (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt) ); }
#line 1917 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 291 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SwitchSelection( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1923 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 295 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileIteration( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1929 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 296 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DoWhileIteration( (yyvsp[-5].stmt), (yyvsp[-2].expr) ); }
#line 1935 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 297 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForNoExprIteration( (yyvsp[-3].stmt), (yyvsp[-2].stmt), (yyvsp[0].stmt) ); }
#line 1941 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 298 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForExprIteration( (yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[0].stmt), (yyvsp[-2].expr)); }
#line 1947 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 302 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new GotoStatement( new Identifier( *(yyvsp[-1].string_value) ) ); }
#line 1953 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 303 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ContinueStatement( NULL ); }
#line 1959 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 304 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BreakStatement( NULL ); }
#line 1965 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 305 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnStatement( NULL ); }
#line 1971 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 306 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnExprStatement( (yyvsp[-1].expr) ); }
#line 1977 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 315 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.edln) = new ExternalDeclaration( (yyvsp[0].fdfn), NULL ); }
#line 1983 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 316 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.edln) = new ExternalDeclaration( NULL, (yyvsp[0].dltr) ); }
#line 1989 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 320 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinition( (yyvsp[-3].dltr), (yyvsp[-2].dltr), (yyvsp[-1].dltr), (yyvsp[0].stmt) ); }
#line 1995 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 321 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinition( (yyvsp[-2].dltr), (yyvsp[-1].dltr), NULL, (yyvsp[0].stmt) ); }
#line 2001 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 322 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinition( NULL, (yyvsp[-2].dltr), (yyvsp[-1].dltr), (yyvsp[0].stmt) ); }
#line 2007 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 323 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinition( NULL, (yyvsp[-1].dltr), NULL, (yyvsp[0].stmt) ); }
#line 2013 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2017 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 328 "src/c_parser.y" /* yacc.c:1906  */


const Unit *prog_root; // match variable defined earlier

const Unit *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
