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
    ASSIGN = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
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

#line 194 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    68,     2,
      65,    66,    69,    64,    81,    70,    67,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    61,
      75,     2,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    78,    63,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    78,    79,    80,    81,    85,    86,    87,
      88,    89,    90,    94,    95,    96,   109,   110,   111,   112,
     116,   117,   118,   122,   123,   124,   128,   129,   130,   131,
     132,   136,   137,   138,   142,   143,   147,   148,   152,   153,
     157,   158,   162,   163,   167,   168,   173,   174,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   192,
     193,   197,   201,   202,   206,   207,   211,   212,   216,   217,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   234,
     238,   239,   240,   241,   242,   243,   244,   248,   249,   253,
     254,   258,   259,   263,   267,   268,   269,   270,   271,   272,
     276,   277,   278,   282,   283,   284,   285,   289,   290,   294,
     295,   299,   300,   305,   306,   307,   311,   312,   313,   314,
     318,   319,   320,   321,   322,   326,   327,   331,   332,   333,
     337,   338,   341,   342,   343,   344
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
  "ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "';'", "'{'", "'}'", "'+'", "'('", "')'",
  "'.'", "'&'", "'*'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "','", "'['", "']'", "$accept", "ROOT",
  "primary_expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "eor_expression", "or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer", "statement",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "this_unit",
  "external_declaration", "function_definition_list",
  "function_definition", YY_NULLPTR
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
     315,    59,   123,   125,    43,    40,    41,    46,    38,    42,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    44,    91,    93
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     303,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     4,   303,    15,   406,   366,   -31,   303,  -110,
     303,  -110,   -55,  -110,     0,  -110,  -110,   -34,   -56,   355,
    -110,   156,  -110,    15,  -110,   366,    92,    58,  -110,  -110,
    -110,   366,  -110,     0,   139,  -110,   366,   -39,  -110,  -110,
     139,   139,   139,   -23,     7,    26,    31,   316,    33,    49,
      79,   101,    74,  -110,  -110,   139,  -110,    36,   411,    76,
     106,   143,    10,   152,   103,   102,    91,   173,    -9,  -110,
    -110,   -21,  -110,  -110,  -110,   219,   236,  -110,  -110,  -110,
    -110,   174,  -110,  -110,  -110,  -110,     0,   -28,  -110,   -17,
    -110,  -110,  -110,  -110,   118,  -110,  -110,  -110,  -110,   316,
    -110,  -110,   123,   316,   139,   139,   139,   154,   323,   159,
    -110,  -110,  -110,   -13,    -7,   222,  -110,  -110,   160,   230,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,  -110,   139,  -110,   299,  -110,  -110,  -110,  -110,   406,
    -110,   231,  -110,  -110,   316,  -110,     9,    18,    21,   170,
     323,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,    76,    76,   106,   106,   143,   143,   143,   143,    10,
      10,   152,   103,   102,    91,   173,    97,  -110,  -110,  -110,
    -110,  -110,   316,   316,   316,   139,    28,   139,   184,  -110,
    -110,    23,   316,    71,  -110,   316,   176,  -110,   316,  -110,
    -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    80,    71,    72,    73,    74,    77,    78,    75,    76,
      70,     0,     0,   128,     0,    64,     0,    79,     2,   125,
     127,   130,     0,     1,     0,   129,    62,     0,    66,    68,
      65,     0,   107,     0,   135,     0,     0,     0,   126,   131,
      81,     0,    63,     0,     0,   133,     0,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   103,     0,     7,    13,    16,    20,
      23,    26,    31,    34,    36,    38,    40,    42,    44,    46,
      59,     0,   109,    94,    95,     0,     0,    96,    97,    98,
      99,    68,   108,   134,    91,    86,    90,     0,    87,     0,
       3,    83,    16,    61,     0,    67,    93,    69,   132,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,     0,     0,     0,    11,    12,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    58,    57,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   105,     0,   104,   110,    89,    85,     0,
      84,     0,    82,   100,     0,   102,     0,     0,     0,     0,
       0,   120,   124,     6,    10,     8,     9,    47,    17,    18,
      19,    21,    22,    24,    25,    29,    30,    27,    28,    32,
      33,    35,    37,    39,    41,    43,     0,    60,   106,    88,
      92,   101,     0,     0,     0,     0,     0,     0,   113,   115,
     116,     0,     0,     0,    45,     0,     0,   118,     0,   114,
     117,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,   -37,    38,    39,    80,    45,    83,
      86,    89,    85,    88,  -110,   -36,   -16,  -110,   -60,   196,
      12,     6,  -110,   206,  -110,    -4,  -110,  -110,    81,  -110,
    -110,   -40,  -110,   122,    19,   166,  -109,  -110,  -110,  -110,
    -110,   234,  -110,    68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   141,    81,   104,
      32,    33,    27,    28,    15,    16,    17,    97,    98,    99,
     107,    82,    83,    84,    46,    86,    87,    88,    89,    90,
      18,    19,    20,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     102,   103,   123,     1,    23,   124,    14,    22,   159,   180,
      29,    40,    13,   110,   111,   102,   103,   117,     1,    24,
      41,    30,   149,   150,    14,    43,    24,    42,   106,    91,
      13,   100,    48,    49,    36,    35,    50,    51,   168,    91,
     161,   109,    96,   125,   126,   127,   166,    92,   182,   170,
      85,    37,   119,   169,   176,   177,   178,   113,    92,   183,
     162,   100,    48,    49,   171,    11,    50,    51,   162,   173,
     160,   216,   114,   175,   162,   212,    26,   100,    48,    49,
      11,    25,    50,    51,   213,   151,   152,   214,    39,   226,
     162,   115,   167,    65,   222,    94,   116,    92,   118,   162,
     206,   128,   162,   129,   162,   188,   189,   190,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,    65,   166,   187,     2,     3,     4,     5,
       6,     7,     8,     9,   211,   122,    10,   228,    34,    65,
     120,   101,   100,    48,    49,   142,   207,    50,    51,   143,
     144,    45,   162,   147,   148,   221,   223,    93,    95,    47,
      48,    49,   121,    45,    50,    51,   153,   154,   108,   157,
     145,   155,   218,   219,   220,    96,   146,   217,   162,   156,
     102,   224,   227,   191,   192,   229,   193,   194,   231,   158,
       2,     3,     4,     5,     6,     7,     8,     9,   199,   200,
      10,   172,    44,   174,    65,    52,    53,    54,   179,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    31,    64,
     181,    65,    47,    48,    49,   184,   185,    50,    51,   195,
     196,   197,   198,   186,   210,   215,   225,   230,   201,    47,
      48,    49,   202,   204,    50,    51,   203,   205,   112,   105,
     209,   164,    38,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,     0,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    31,   163,     0,    65,    52,    53,    54,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    31,   165,
       0,    65,    47,    48,    49,     0,     1,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,     0,     0,    50,    51,   100,    48,    49,     0,
       0,    50,    51,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,    10,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    31,   208,     0,    65,    52,    53,    54,    11,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    31,     0,
       0,    65,     0,    44,    63,     0,     0,     0,    65,     2,
       3,     4,     5,     6,     7,     8,     9,     0,     0,    10,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      10,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
      10
};

static const yytype_int16 yycheck[] =
{
      37,    37,    62,     3,     0,    65,     0,    11,    17,   118,
      14,    66,     0,    50,    51,    52,    52,    57,     3,    13,
      24,    15,    12,    13,    18,    81,    20,    61,    44,    33,
      18,     3,     4,     5,    65,    16,     8,     9,    66,    43,
      61,    80,    36,     7,     8,     9,    86,    35,    61,    66,
      31,    82,     3,    81,   114,   115,   116,    80,    46,    66,
      81,     3,     4,     5,    81,    65,     8,     9,    81,   109,
      79,   180,    65,   113,    81,    66,    61,     3,     4,     5,
      65,    13,     8,     9,    66,    75,    76,    66,    20,    66,
      81,    65,    96,    65,    66,     3,    65,    85,    65,    81,
     160,    65,    81,    67,    81,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    65,   164,   141,    34,    35,    36,    37,
      38,    39,    40,    41,   174,    61,    44,    66,    16,    65,
      61,    83,     3,     4,     5,    69,   162,     8,     9,    73,
      74,    29,    81,    10,    11,   215,   216,    35,    66,     3,
       4,     5,    61,    41,     8,     9,    14,    15,    46,    78,
      64,    68,   212,   213,   214,   169,    70,    80,    81,    77,
     217,   217,   222,   145,   146,   225,   147,   148,   228,    16,
      34,    35,    36,    37,    38,    39,    40,    41,   153,   154,
      44,    83,    28,    80,    65,    49,    50,    51,    54,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      61,    65,     3,     4,     5,     3,    66,     8,     9,   149,
     150,   151,   152,     3,     3,    65,    52,    61,   155,     3,
       4,     5,   156,   158,     8,     9,   157,   159,    52,    43,
     169,    85,    18,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,     3,     4,     5,    -1,     3,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,     8,     9,     3,     4,     5,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    49,    50,    51,    65,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    28,    61,    -1,    -1,    -1,    65,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    34,    35,    36,    37,    38,    39,    40,    41,
      44,    65,    85,   104,   105,   108,   109,   110,   124,   125,
     126,   127,   109,     0,   105,   127,    61,   106,   107,   109,
     105,    62,   104,   105,   117,   118,    65,    82,   125,   127,
      66,   109,    61,    81,    28,   117,   118,     3,     4,     5,
       8,     9,    49,    50,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    63,    65,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   102,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   109,   104,   117,     3,    66,   105,   111,   112,   113,
       3,    83,    88,    99,   103,   107,   100,   114,   117,    80,
      88,    88,   103,    80,    65,    65,    65,   115,    65,     3,
      61,    61,    61,   102,   102,     7,     8,     9,    65,    67,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   101,    69,    73,    74,    64,    70,    10,    11,    12,
      13,    75,    76,    14,    15,    68,    77,    78,    16,    17,
      79,    61,    81,    63,   119,    63,   115,   109,    66,    81,
      66,    81,    83,   115,    80,   115,   102,   102,   102,    54,
     120,    61,    61,    66,     3,    66,     3,   100,    88,    88,
      88,    89,    89,    90,    90,    91,    91,    91,    91,    92,
      92,    93,    94,    95,    96,    97,   102,   100,    63,   112,
       3,   115,    66,    66,    66,    65,   120,    80,   115,   115,
     115,   102,    66,   102,    99,    52,    66,   115,    66,   115,
      61,   115
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    92,
      92,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   127,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       3,     2,     2,     1,     2,     2,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     4,     4,     3,     1,     3,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     2,
       1,     2,     4,     3,     3,     2
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
#line 75 "src/c_parser.y" /* yacc.c:1646  */
    { prog_root = (yyvsp[0].unit); }
#line 1521 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Identifier( *(yyvsp[0].string_value) ); }
#line 1527 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 79 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Constant( *(yyvsp[0].string_value) ); }
#line 1533 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringLiteral( *(yyvsp[0].string_value) ); }
#line 1539 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixEmpty( (yyvsp[-2].expr), NULL ); }
#line 1545 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixPeriod( (yyvsp[-2].expr), new Identifier(*(yyvsp[0].string_value)) ); }
#line 1551 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixPtrOp( (yyvsp[-2].expr), new Identifier(*(yyvsp[0].string_value) ) ); }
#line 1557 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixIncOp( (yyvsp[-1].expr), NULL ); }
#line 1563 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixDecOp( (yyvsp[-1].expr), NULL); }
#line 1569 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 95 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryIncExpression( (yyvsp[0].expr) ); }
#line 1575 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryDecExpression( (yyvsp[0].expr) ); }
#line 1581 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new MultiplyMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1587 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DivideMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1593 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ModMultiplicative( (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1599 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AddAdditive( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1605 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SubAdditive( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1611 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 123 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LeftOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1617 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new RightOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1623 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 129 "src/c_parser.y" /* yacc.c:1646  */
    { std::cout << "LE!" << std::endl; (yyval.expr) = new StrictLessThanExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1629 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StrictGreaterThanExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1635 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 131 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LessEqualExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1641 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GreaterEqualExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1647 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 137 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new EqualOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1653 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 138 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NotEqualOpExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1659 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 143 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AndExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1665 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 148 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new XorExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1671 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 153 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OrExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1677 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 158 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalAndExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1683 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 163 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalOrExpression ( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1689 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 169 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ConditionalExpression ( (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1695 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignmentExpression ( (yyvsp[-2].expr), *(yyvsp[-1].string_value), (yyvsp[0].expr) ); }
#line 1701 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 193 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new MainExpression( (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1707 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 201 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new MainDeclaration( (yyvsp[-1].dltr), NULL); }
#line 1713 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 202 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new MainDeclaration( (yyvsp[-2].dltr), (yyvsp[-1].dltr)); }
#line 1719 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 206 "src/c_parser.y" /* yacc.c:1646  */
    { }
#line 1725 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 207 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationSpecifier( (yyvsp[-1].expr), (yyvsp[0].dltr) ); }
#line 1731 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new InitDeclarationList(); (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1737 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 212 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1743 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 216 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new InitDeclarator( (yyvsp[0].dltr), NULL ); }
#line 1749 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 217 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new InitDeclarator( (yyvsp[-2].dltr), (yyvsp[0].expr) ); }
#line 1755 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 221 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1761 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 222 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1767 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 223 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1773 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 224 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1779 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 225 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1785 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 226 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1791 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 227 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1797 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 228 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1803 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 229 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TypeSpecifierExpression( *(yyvsp[0].string_value) ); }
#line 1809 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new IdentifierDeclarator( new Identifier( *(yyvsp[0].string_value) ) ); }
#line 1815 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new BracketedDeclarator( (yyvsp[-1].dltr) ); }
#line 1821 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-3].dltr), (yyvsp[-1].expr) ); }
#line 1827 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 241 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-2].dltr), NULL );}
#line 1833 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 242 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ExpressionDeclarator( (yyvsp[-3].dltr), (yyvsp[-1].expr) ); }
#line 1839 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 243 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ParameterTypeDeclarator( (yyvsp[-3].dltr), (yyvsp[-1].dltr) ); }
#line 1845 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 244 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new EmptyDeclarator( (yyvsp[-2].dltr) );}
#line 1851 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 248 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ParamDeclarationList(); (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1857 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 249 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1863 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 253 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ParameterDeclaration( (yyvsp[-1].dltr), (yyvsp[0].dltr) ); }
#line 1869 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 254 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new ParameterDeclaration( (yyvsp[0].dltr), NULL ); }
#line 1875 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 258 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ExpressionList(); (yyval.expr)->AddItem(new Identifier( *(yyvsp[0].string_value) ) ); }
#line 1881 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 259 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr)->AddItem(new Identifier( *(yyvsp[0].string_value) ) ); }
#line 1887 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 263 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Initializer( (yyvsp[0].expr), NULL ); }
#line 1893 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 276 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IdentifierStatement( new Identifier( *(yyvsp[-2].string_value) ), (yyvsp[0].stmt) ); }
#line 1899 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 277 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseStatement( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1905 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 278 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DefaultStatement( (yyvsp[0].stmt) ); }
#line 1911 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 282 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( NULL, NULL ); }
#line 1917 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 283 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( (yyvsp[-1].stmt), NULL ); }
#line 1923 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 284 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( NULL, (yyvsp[-1].dltr) ); }
#line 1929 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 285 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CompoundStatement( (yyvsp[-1].stmt), (yyvsp[-2].dltr) ); }
#line 1935 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 289 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr) = new DeclarationList(); (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1941 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 290 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.dltr)->AddItem( (yyvsp[0].dltr) ); }
#line 1947 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 294 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new StatementList(); (yyval.stmt)->AddItem( (yyvsp[0].stmt) ); }
#line 1953 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 295 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt)->AddItem( (yyvsp[0].stmt) ); }
#line 1959 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 299 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExpressionStatement( NULL ); }
#line 1965 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 300 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExpressionStatement( (yyvsp[-1].expr) ); }
#line 1971 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 305 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfSelection( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1977 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 306 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfElseSelection( (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt) ); }
#line 1983 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 307 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SwitchSelection( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1989 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 311 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileIteration( (yyvsp[-2].expr), (yyvsp[0].stmt) ); }
#line 1995 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 312 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DoWhileIteration( (yyvsp[-5].stmt), (yyvsp[-2].expr) ); }
#line 2001 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 313 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForNoExprIteration( (yyvsp[-3].stmt), (yyvsp[-2].stmt), (yyvsp[0].stmt) ); }
#line 2007 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 314 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForExprIteration( (yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[0].stmt), (yyvsp[-2].expr)); }
#line 2013 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 318 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new GotoStatement( new Identifier( *(yyvsp[-1].string_value) ) ); }
#line 2019 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 319 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ContinueStatement( NULL ); }
#line 2025 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 320 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BreakStatement( NULL ); }
#line 2031 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 321 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnStatement( NULL ); }
#line 2037 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 322 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnExprStatement( (yyvsp[-1].expr) ); }
#line 2043 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 326 "src/c_parser.y" /* yacc.c:1646  */
    { }
#line 2049 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 327 "src/c_parser.y" /* yacc.c:1646  */
    { }
#line 2055 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 331 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.edln) = new ExternalDeclaration( (yyvsp[0].fdfn), NULL ); }
#line 2061 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 332 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.edln) = new ExternalDeclaration( NULL, (yyvsp[0].dltr) ); }
#line 2067 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 333 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.edln) = new ExternalDeclaration( (yyvsp[0].fdfn), (yyvsp[-1].dltr) ); }
#line 2073 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 337 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinitionList(); (yyval.fdfn)->AddItem( (yyvsp[0].fdfn) ); }
#line 2079 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 338 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn)->AddItem( (yyvsp[0].fdfn) ); }
#line 2085 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 341 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinitionActual( (yyvsp[-3].dltr), (yyvsp[-2].dltr), (yyvsp[-1].dltr), (yyvsp[0].stmt) ); }
#line 2091 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 342 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinitionActual( (yyvsp[-2].dltr), (yyvsp[-1].dltr), NULL, (yyvsp[0].stmt) ); }
#line 2097 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 343 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinitionActual( NULL, (yyvsp[-2].dltr), (yyvsp[-1].dltr), (yyvsp[0].stmt) ); }
#line 2103 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 344 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fdfn) = new FunctionDefinitionActual( NULL, (yyvsp[-1].dltr), NULL, (yyvsp[0].stmt) ); }
#line 2109 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2113 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 349 "src/c_parser.y" /* yacc.c:1906  */


const Unit *prog_root; // match variable defined earlier

const Unit *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
