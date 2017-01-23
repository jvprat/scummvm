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
     UNARY = 258,
     CASTREF = 259,
     VOID = 260,
     VAR = 261,
     POINT = 262,
     RECT = 263,
     ARRAY = 264,
     OBJECT = 265,
     INT = 266,
     THEENTITY = 267,
     THEENTITYWITHID = 268,
     FLOAT = 269,
     BLTIN = 270,
     BLTINNOARGS = 271,
     BLTINNOARGSORONE = 272,
     BLTINONEARG = 273,
     BLTINARGLIST = 274,
     TWOWORDBUILTIN = 275,
     ID = 276,
     STRING = 277,
     HANDLER = 278,
     SYMBOL = 279,
     ENDCLAUSE = 280,
     tPLAYACCEL = 281,
     tDOWN = 282,
     tELSE = 283,
     tNLELSIF = 284,
     tEXIT = 285,
     tFRAME = 286,
     tGLOBAL = 287,
     tGO = 288,
     tIF = 289,
     tINTO = 290,
     tLOOP = 291,
     tMACRO = 292,
     tMOVIE = 293,
     tNEXT = 294,
     tOF = 295,
     tPREVIOUS = 296,
     tPUT = 297,
     tREPEAT = 298,
     tSET = 299,
     tTHEN = 300,
     tTO = 301,
     tWHEN = 302,
     tWITH = 303,
     tWHILE = 304,
     tNLELSE = 305,
     tFACTORY = 306,
     tMETHOD = 307,
     tOPEN = 308,
     tPLAY = 309,
     tDONE = 310,
     tINSTANCE = 311,
     tGE = 312,
     tLE = 313,
     tGT = 314,
     tLT = 315,
     tEQ = 316,
     tNEQ = 317,
     tAND = 318,
     tOR = 319,
     tNOT = 320,
     tMOD = 321,
     tAFTER = 322,
     tBEFORE = 323,
     tCONCAT = 324,
     tCONTAINS = 325,
     tSTARTS = 326,
     tCHAR = 327,
     tITEM = 328,
     tLINE = 329,
     tWORD = 330,
     tSPRITE = 331,
     tINTERSECTS = 332,
     tWITHIN = 333,
     tON = 334,
     tME = 335
   };
#endif
/* Tokens.  */
#define UNARY 258
#define CASTREF 259
#define VOID 260
#define VAR 261
#define POINT 262
#define RECT 263
#define ARRAY 264
#define OBJECT 265
#define INT 266
#define THEENTITY 267
#define THEENTITYWITHID 268
#define FLOAT 269
#define BLTIN 270
#define BLTINNOARGS 271
#define BLTINNOARGSORONE 272
#define BLTINONEARG 273
#define BLTINARGLIST 274
#define TWOWORDBUILTIN 275
#define ID 276
#define STRING 277
#define HANDLER 278
#define SYMBOL 279
#define ENDCLAUSE 280
#define tPLAYACCEL 281
#define tDOWN 282
#define tELSE 283
#define tNLELSIF 284
#define tEXIT 285
#define tFRAME 286
#define tGLOBAL 287
#define tGO 288
#define tIF 289
#define tINTO 290
#define tLOOP 291
#define tMACRO 292
#define tMOVIE 293
#define tNEXT 294
#define tOF 295
#define tPREVIOUS 296
#define tPUT 297
#define tREPEAT 298
#define tSET 299
#define tTHEN 300
#define tTO 301
#define tWHEN 302
#define tWITH 303
#define tWHILE 304
#define tNLELSE 305
#define tFACTORY 306
#define tMETHOD 307
#define tOPEN 308
#define tPLAY 309
#define tDONE 310
#define tINSTANCE 311
#define tGE 312
#define tLE 313
#define tGT 314
#define tLT 315
#define tEQ 316
#define tNEQ 317
#define tAND 318
#define tOR 319
#define tNOT 320
#define tMOD 321
#define tAFTER 322
#define tBEFORE 323
#define tCONCAT 324
#define tCONTAINS 325
#define tSTARTS 326
#define tCHAR 327
#define tITEM 328
#define tLINE 329
#define tWORD 330
#define tSPRITE 331
#define tINTERSECTS 332
#define tWITHIN 333
#define tON 334
#define tME 335




/* Copy the first part of user declarations.  */
#line 49 "engines/director/lingo/lingo-gr.y"

#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "common/hash-str.h"

#include "director/lingo/lingo.h"
#include "director/lingo/lingo-gr.h"

extern int yylex();
extern int yyparse();

using namespace Director;
void yyerror(const char *s) {
	g_lingo->_hadError = true;
	warning("%s at line %d col %d", s, g_lingo->_linenumber, g_lingo->_colnumber);
}

void checkEnd(Common::String *token, const char *expect, bool required) {
	if (required) {
		if (token->compareToIgnoreCase(expect)) {
			Common::String err = Common::String::format("end mismatch. Expected %s but got %s", expect, token->c_str());
			yyerror(err.c_str());
		}
	}

	delete token;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 79 "engines/director/lingo/lingo-gr.y"
{
	Common::String *s;
	int i;
	double f;
	int e[2];	// Entity + field
	int code;
	int narg;	/* number of arguments */
	Common::Array<double> *arr;
}
/* Line 193 of yacc.c.  */
#line 296 "engines/director/lingo/lingo-gr.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 309 "engines/director/lingo/lingo-gr.cpp"

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
#define YYFINAL  114
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1635

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  335

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   335

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      88,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    87,    82,     2,
      89,    90,    85,    83,    95,    84,     2,    86,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      92,    81,    91,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    93,     2,    94,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    14,    15,    17,    19,
      21,    23,    25,    30,    35,    40,    45,    50,    56,    61,
      66,    72,    74,    76,    78,    80,    88,    99,   111,   115,
     123,   134,   145,   152,   163,   174,   175,   179,   182,   184,
     187,   189,   196,   198,   205,   207,   211,   215,   218,   222,
     224,   226,   227,   228,   229,   232,   235,   239,   241,   243,
     245,   247,   249,   254,   256,   258,   261,   263,   267,   271,
     275,   279,   283,   287,   291,   295,   299,   303,   307,   311,
     314,   318,   322,   326,   330,   333,   336,   340,   344,   349,
     354,   359,   366,   371,   378,   383,   390,   395,   402,   405,
     407,   409,   412,   414,   417,   420,   423,   426,   428,   433,
     436,   441,   448,   453,   456,   460,   462,   466,   468,   472,
     475,   478,   481,   484,   488,   491,   494,   496,   500,   503,
     506,   509,   513,   516,   517,   521,   522,   531,   534,   535,
     544,   545,   546,   557,   558,   560,   564,   569,   570,   573,
     574,   576,   580,   582
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      97,     0,    -1,    97,    98,    99,    -1,    99,    -1,     1,
      98,    -1,    88,    -1,    -1,   127,    -1,   119,    -1,   134,
      -1,   100,    -1,   102,    -1,    42,   118,    35,    21,    -1,
      42,   118,    67,   118,    -1,    42,   118,    68,   118,    -1,
      44,    21,    81,   118,    -1,    44,    12,    81,   118,    -1,
      44,    13,   118,    81,   118,    -1,    44,    21,    46,   118,
      -1,    44,    12,    46,   118,    -1,    44,    13,   118,    46,
     118,    -1,   118,    -1,   119,    -1,   101,    -1,   103,    -1,
     110,    89,   109,    90,   116,   115,    25,    -1,   111,    81,
     118,   115,    46,   118,   115,   116,   115,    25,    -1,   111,
      81,   118,   115,    27,    46,   118,   115,   116,   115,    25,
      -1,   117,   118,   115,    -1,   112,   109,    45,    98,   116,
     115,    25,    -1,   112,   109,    45,    98,   116,   115,    50,
     116,   115,    25,    -1,   112,   109,    45,    98,   116,   115,
     114,   105,   115,    25,    -1,   112,   109,    45,   114,   101,
     115,    -1,   112,   109,    45,   114,   101,   115,    50,   114,
     101,   115,    -1,   112,   109,    45,   114,   101,   115,   106,
     115,   104,   115,    -1,    -1,    50,   114,   101,    -1,   105,
     108,    -1,   108,    -1,   106,   107,    -1,   107,    -1,   113,
     109,    45,   114,   102,   115,    -1,   106,    -1,   113,   109,
      45,   114,   116,   115,    -1,   118,    -1,   118,    81,   118,
      -1,    89,   109,    90,    -1,    43,    49,    -1,    43,    48,
      21,    -1,    34,    -1,    29,    -1,    -1,    -1,    -1,   116,
      98,    -1,   116,   102,    -1,    47,    21,    45,    -1,    11,
      -1,    14,    -1,    24,    -1,    22,    -1,    16,    -1,    21,
      89,   135,    90,    -1,    21,    -1,    12,    -1,    13,   118,
      -1,   100,    -1,   118,    83,   118,    -1,   118,    84,   118,
      -1,   118,    85,   118,    -1,   118,    86,   118,    -1,   118,
      66,   118,    -1,   118,    91,   118,    -1,   118,    92,   118,
      -1,   118,    62,   118,    -1,   118,    57,   118,    -1,   118,
      58,   118,    -1,   118,    63,   118,    -1,   118,    64,   118,
      -1,    65,   118,    -1,   118,    82,   118,    -1,   118,    69,
     118,    -1,   118,    70,   118,    -1,   118,    71,   118,    -1,
      83,   118,    -1,    84,   118,    -1,    89,   118,    90,    -1,
      93,   135,    94,    -1,    76,   118,    77,   118,    -1,    76,
     118,    78,   118,    -1,    72,   118,    40,   118,    -1,    72,
     118,    46,   118,    40,   118,    -1,    73,   118,    40,   118,
      -1,    73,   118,    46,   118,    40,   118,    -1,    74,   118,
      40,   118,    -1,    74,   118,    46,   118,    40,   118,    -1,
      75,   118,    40,   118,    -1,    75,   118,    46,   118,    40,
     118,    -1,    42,   118,    -1,   122,    -1,   125,    -1,    30,
      43,    -1,    30,    -1,    32,   120,    -1,    56,   121,    -1,
      18,   118,    -1,    17,   118,    -1,    17,    -1,    19,    89,
     135,    90,    -1,    19,   135,    -1,    80,    89,    21,    90,
      -1,    80,    89,    21,    95,   135,    90,    -1,    53,   118,
      48,   118,    -1,    53,   118,    -1,    20,    21,   135,    -1,
      21,    -1,   120,    95,    21,    -1,    21,    -1,   121,    95,
      21,    -1,    33,    36,    -1,    33,    39,    -1,    33,    41,
      -1,    33,   123,    -1,    33,   123,   124,    -1,    33,   124,
      -1,    31,   118,    -1,   118,    -1,    40,    38,   118,    -1,
      38,   118,    -1,    54,    55,    -1,    54,   123,    -1,    54,
     123,   124,    -1,    54,   124,    -1,    -1,    26,   126,   135,
      -1,    -1,    37,    21,   128,   114,   132,    98,   133,   116,
      -1,    51,    21,    -1,    -1,    52,    21,   129,   114,   132,
      98,   133,   116,    -1,    -1,    -1,    79,    21,   130,   114,
     131,   132,    98,   133,   116,    25,    -1,    -1,    21,    -1,
     132,    95,    21,    -1,   132,    98,    95,    21,    -1,    -1,
      21,   136,    -1,    -1,   118,    -1,   135,    95,   118,    -1,
     118,    -1,   135,    95,   118,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   118,   119,   122,   127,   128,   129,   130,
     131,   132,   135,   141,   142,   143,   149,   157,   165,   171,
     179,   188,   189,   191,   192,   197,   210,   228,   242,   250,
     260,   272,   284,   294,   304,   315,   316,   319,   320,   323,
     324,   327,   335,   336,   344,   345,   346,   348,   350,   356,
     362,   369,   371,   373,   374,   375,   378,   384,   385,   388,
     391,   394,   397,   400,   404,   411,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   451,   452,
     453,   454,   455,   457,   458,   459,   462,   465,   468,   469,
     470,   471,   472,   473,   474,   477,   478,   481,   482,   493,
     494,   495,   496,   499,   502,   507,   508,   511,   512,   515,
     516,   519,   522,   525,   525,   555,   555,   561,   564,   564,
     569,   570,   569,   580,   581,   582,   583,   585,   589,   597,
     598,   599,   602,   603
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNARY", "CASTREF", "VOID", "VAR",
  "POINT", "RECT", "ARRAY", "OBJECT", "INT", "THEENTITY",
  "THEENTITYWITHID", "FLOAT", "BLTIN", "BLTINNOARGS", "BLTINNOARGSORONE",
  "BLTINONEARG", "BLTINARGLIST", "TWOWORDBUILTIN", "ID", "STRING",
  "HANDLER", "SYMBOL", "ENDCLAUSE", "tPLAYACCEL", "tDOWN", "tELSE",
  "tNLELSIF", "tEXIT", "tFRAME", "tGLOBAL", "tGO", "tIF", "tINTO", "tLOOP",
  "tMACRO", "tMOVIE", "tNEXT", "tOF", "tPREVIOUS", "tPUT", "tREPEAT",
  "tSET", "tTHEN", "tTO", "tWHEN", "tWITH", "tWHILE", "tNLELSE",
  "tFACTORY", "tMETHOD", "tOPEN", "tPLAY", "tDONE", "tINSTANCE", "tGE",
  "tLE", "tGT", "tLT", "tEQ", "tNEQ", "tAND", "tOR", "tNOT", "tMOD",
  "tAFTER", "tBEFORE", "tCONCAT", "tCONTAINS", "tSTARTS", "tCHAR", "tITEM",
  "tLINE", "tWORD", "tSPRITE", "tINTERSECTS", "tWITHIN", "tON", "tME",
  "'='", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'\\n'", "'('", "')'",
  "'>'", "'<'", "'['", "']'", "','", "$accept", "program", "nl",
  "programline", "asgn", "stmtoneliner", "stmt", "ifstmt",
  "elsestmtoneliner", "elseifstmt", "elseifstmtoneliner",
  "elseifstmtoneliner1", "elseifstmt1", "cond", "repeatwhile",
  "repeatwith", "if", "elseif", "begin", "end", "stmtlist", "when", "expr",
  "func", "globallist", "instancelist", "gotofunc", "gotoframe",
  "gotomovie", "playfunc", "@1", "defn", "@2", "@3", "@4", "@5", "argdef",
  "argstore", "macro", "arglist", "nonemptyarglist", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,    61,    38,    43,    45,    42,    47,    37,    10,    40,
      41,    62,    60,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    97,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   108,   109,   109,   109,   110,   111,   112,
     113,   114,   115,   116,   116,   116,   117,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   125,   126,   125,   128,   127,   127,   129,   127,
     130,   131,   127,   132,   132,   132,   132,   133,   134,   135,
     135,   135,   136,   136
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     0,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     5,     4,     4,
       5,     1,     1,     1,     1,     7,    10,    11,     3,     7,
      10,    10,     6,    10,    10,     0,     3,     2,     1,     2,
       1,     6,     1,     6,     1,     3,     3,     2,     3,     1,
       1,     0,     0,     0,     2,     2,     3,     1,     1,     1,
       1,     1,     4,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     2,     2,     3,     3,     4,     4,
       4,     6,     4,     6,     4,     6,     4,     6,     2,     1,
       1,     2,     1,     2,     2,     2,     2,     1,     4,     2,
       4,     6,     4,     2,     3,     1,     3,     1,     3,     2,
       2,     2,     2,     3,     2,     2,     1,     3,     2,     2,
       2,     3,     2,     0,     3,     0,     8,     2,     0,     8,
       0,     0,    10,     0,     1,     3,     4,     0,     2,     0,
       1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    57,    64,     0,    58,    61,   107,     0,   149,
       0,    63,    60,    59,   133,   102,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,     0,     3,    66,    23,    11,    24,     0,     0,     0,
       0,    21,     8,    99,   100,     7,     9,     5,     4,    63,
       0,    66,    65,   106,   105,   149,   150,   109,   149,   149,
     152,     0,   148,   149,   101,   115,   103,     0,   119,     0,
     120,     0,   121,   126,   122,   124,   135,    98,     0,    47,
       0,     0,     0,     0,   137,   138,   113,   129,   130,   132,
     117,   104,    79,     0,     0,     0,     0,     0,   140,     0,
      84,    85,     0,     0,     1,     6,     0,     0,     0,     0,
      44,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,     0,
     150,     0,     0,   114,     0,     0,   134,     0,   125,   128,
       0,   123,    51,     0,     0,     0,    48,     0,     0,     0,
       0,     0,    56,    51,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    86,
      87,     2,     0,    52,     0,     0,    51,     0,    28,    75,
      76,    74,    77,    78,    71,    81,    82,    83,    80,    67,
      68,    69,    70,    72,    73,   108,   151,    62,   153,   116,
     127,   143,    12,    13,    14,    19,    16,     0,     0,    18,
      15,   143,   112,   118,    90,     0,    92,     0,    94,     0,
      96,     0,    88,    89,   141,   110,   149,    53,     0,    46,
      53,     0,    45,   144,     0,    20,    17,     0,     0,     0,
       0,     0,   143,     0,    52,     0,     0,    52,    52,    22,
       0,   147,   147,    91,    93,    95,    97,     0,   111,    54,
      55,     0,     0,    52,    51,    32,   145,     0,    53,    53,
     147,    25,    52,    53,    29,    53,     0,    50,    51,    52,
      40,     0,   146,   136,   139,    53,    53,    52,    52,    52,
      42,    38,     0,     0,    39,    35,     0,     0,    52,     0,
       0,    37,     0,     0,    52,    51,    52,    51,   142,     0,
      26,    30,    31,    51,    33,     0,    34,     0,    27,    53,
      36,    52,    52,    41,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,   269,    42,    61,    44,   270,    46,   316,   299,
     300,   290,   301,   119,    47,    48,    49,   291,   211,   188,
     254,    50,    51,   259,    76,   101,    53,    84,    85,    54,
      73,    55,   152,   163,   177,   252,   244,   278,    56,   144,
      72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -241
static const yytype_int16 yypact[] =
{
     288,   -17,  -241,  -241,   963,  -241,  -241,   963,   963,  1029,
      35,   371,  -241,  -241,  -241,    21,    54,   862,  -241,    68,
     963,    58,    74,    76,    81,    87,   963,   928,    88,   963,
     963,   963,   963,   963,   963,    91,   -10,   963,   963,   963,
     963,     2,  -241,     3,  -241,  -241,  -241,    24,    33,  1054,
     963,  1543,  -241,  -241,  -241,  -241,  -241,  -241,  -241,    27,
     963,  -241,  1543,  1543,  1543,   963,  1543,    25,   963,   963,
    1347,    47,  -241,   963,  -241,  -241,    50,   963,  -241,   963,
    -241,    83,  -241,  1543,    65,  -241,  -241,   143,   126,  -241,
     -32,   963,   -24,   103,  -241,  -241,  1316,  -241,    65,  -241,
    -241,    55,   -33,   340,  1093,  1125,  1157,  1419,  -241,   131,
     -33,   -33,  1481,   -70,  -241,   456,  1054,   963,  1054,   108,
    1512,  1543,   963,   963,   963,   963,   963,   963,   963,   963,
     963,   963,   963,   963,   963,   963,   963,   963,   963,   143,
    1481,   -23,   963,    25,    -7,   963,    25,   136,  1543,  1543,
     963,  -241,  -241,   139,   963,   963,  -241,   963,   963,   765,
     963,   963,  -241,  -241,   963,  -241,   142,   963,   963,   963,
     963,   963,   963,   963,   963,   963,   963,  -241,     6,  -241,
    -241,  -241,    77,  1543,    90,  1450,   -17,   963,  -241,   825,
     825,   825,   -33,   -33,   -33,  1543,   825,   825,  1023,   130,
     130,   -33,   -33,  1543,  1543,  -241,  1543,  -241,  1383,  -241,
    1543,   145,  -241,  1543,  1543,  1543,  1543,   963,   963,  1543,
    1543,   145,  1543,  -241,  1543,  1189,  1543,  1221,  1543,  1253,
    1543,  1285,  1543,  1543,  -241,  -241,   963,  -241,    -4,  -241,
    -241,   788,  1543,  -241,   -11,  1543,  1543,   -11,   963,   963,
     963,   963,   145,     9,   622,   118,   963,   622,  -241,  -241,
     161,    89,    89,  1543,  1543,  1543,  1543,   -11,  -241,  -241,
    -241,   160,   963,  1543,    -5,   -13,  -241,   165,  -241,  -241,
      89,  -241,  1543,  -241,  -241,  -241,   158,  -241,  -241,   158,
    -241,  1054,  -241,   622,   622,  -241,  -241,   622,   622,   158,
     158,  -241,  1054,   788,  -241,   141,   147,   539,   622,   170,
     172,  -241,   177,   159,  -241,  -241,  -241,  -241,  -241,   178,
    -241,  -241,  -241,  -241,  -241,   788,  -241,   705,  -241,   705,
    -241,  -241,   622,  -241,  -241
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,    12,    93,     7,  -240,     0,  -241,  -241,  -241,
     -58,  -235,   -69,  -112,  -241,  -241,  -241,  -239,  -134,   -34,
    -185,  -241,     1,    26,  -241,  -241,  -241,   204,   -16,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -206,  -218,  -241,     8,
    -241
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -152
static const yytype_int16 yytable[] =
{
      45,   258,   114,   -10,   182,    62,   184,    43,    63,    64,
      66,    99,    70,    58,   157,   247,   287,    67,    83,    71,
     284,    87,   160,   255,   180,   142,    52,    96,    83,   221,
     102,   103,   104,   105,   106,   107,   128,   288,   110,   111,
     112,    66,   256,   234,   279,   285,   267,   302,   113,   158,
     120,   121,   241,   115,   304,   257,    68,   161,   136,   137,
     302,   139,   295,   314,    74,   304,   140,   205,   151,    66,
     140,    57,   142,   141,    66,    75,   143,    57,   148,   109,
     149,   146,   165,   207,   260,   330,    90,    91,   142,    86,
      57,   -10,   159,   293,   294,    92,   235,    93,   297,   268,
     298,   236,    94,    79,   142,    81,    88,    89,    95,   100,
     307,   308,   108,   116,   117,    45,   138,   120,   183,   185,
     142,   150,    43,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    66,
     286,    52,   145,   206,   332,   147,   208,   156,   162,   238,
     166,   210,   178,   186,   303,   213,   214,   209,   215,   216,
     212,   219,   220,   223,   272,   222,   243,   237,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   153,   306,
     239,   325,   276,   327,   277,   281,   292,   287,   242,   329,
     313,   315,   317,   125,   126,   320,   127,   321,   240,   128,
     122,   123,   322,   328,   323,   124,   125,   126,   181,   127,
     154,   155,   128,   129,   130,   134,   135,   289,   245,   246,
     271,   136,   137,   274,   275,   131,   132,   133,   134,   135,
     311,    98,     0,     0,   136,   137,     0,    66,     0,   283,
       0,     0,     0,     0,   253,     0,     0,     0,   296,   263,
     264,   265,   266,     0,     0,   305,   261,   273,     0,   262,
       0,     0,     0,   309,   310,   312,     0,     0,     0,     0,
       0,     0,     0,   282,   319,     0,     0,     0,     0,   280,
     324,     0,   326,     0,     0,     0,     0,     0,    -6,     1,
       0,     0,   120,     0,     0,     0,     0,   333,   334,     2,
       3,     4,     5,   120,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,    14,     0,     0,     0,    15,     0,
      16,    17,    18,     0,     0,    19,     0,   331,     0,   331,
      20,    21,    22,     0,     0,    23,     0,     0,     0,    24,
      25,    26,    27,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,    34,     0,     0,    35,    36,     0,
       0,    37,    38,     0,     0,     0,    -6,    39,     0,     0,
     167,    40,     2,     3,     4,     5,   168,     6,     0,     0,
       0,     0,    59,    12,     0,    13,     0,   122,   123,     0,
       0,     0,   124,   125,   126,     0,   127,     0,     0,   128,
     129,   130,     0,    60,     0,    22,     0,     0,     0,     0,
       0,     0,   131,   132,   133,   134,   135,     0,     0,     0,
       0,   136,   137,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    30,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,    37,    38,     0,     0,     0,     0,
      69,     0,     0,     0,    40,     0,  -149,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,    14,     0,     0,     0,    15,     0,    16,    17,
      18,     0,     0,    19,     0,     0,     0,     0,    20,    21,
      22,     0,     0,    23,     0,     0,     0,    24,    25,    26,
      27,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,    30,    31,
      32,    33,    34,     0,     0,    35,    36,     0,     0,    37,
      38,     0,     0,     0,     0,    39,     0,     0,     0,    40,
       2,     3,     4,     5,     0,     6,     7,     8,     9,    10,
      59,    12,     0,    13,   318,    14,     0,     0,     0,    15,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,     0,     0,    23,     0,     0,     0,
       0,     0,    26,    27,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,     0,     0,     0,    36,
       0,     0,    37,    38,     0,     0,     0,    57,    39,     0,
       0,     0,    40,     2,     3,     4,     5,     0,     6,     7,
       8,     9,    10,    59,    12,     0,    13,     0,    14,     0,
       0,     0,    15,     0,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,     0,     0,    23,
       0,     0,     0,     0,     0,    26,    27,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    34,     0,
       0,     0,    36,     0,     0,    37,    38,     0,     0,     0,
      57,    39,     0,     0,     0,    40,     2,     3,     4,     5,
       0,     6,     7,     8,     9,    10,    59,    12,     0,    13,
       0,    14,     0,     0,     0,    15,     0,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,    20,    21,    22,
       0,     0,    23,     0,     0,     0,     0,     0,    26,    27,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    30,    31,    32,
      33,    34,     0,     0,     0,    36,     0,     0,    37,    38,
       0,     0,     0,     0,    39,     0,     0,     0,    40,     2,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    59,
      12,   217,    13,     0,    14,     0,     0,     0,    15,     0,
      16,    17,   122,   123,     0,     0,     0,   124,   125,   126,
      20,   127,    22,     0,   128,   129,   130,     0,     0,     0,
       0,    26,    27,     0,    28,     0,   218,   131,   132,   133,
     134,   135,     0,    29,     0,     0,   136,   137,     0,     0,
      30,    31,    32,    33,    34,     0,     0,     0,    36,     0,
       0,    37,    38,     2,     3,     4,     5,    39,     6,     0,
       0,    40,     0,    59,    12,     0,    13,     0,   125,   126,
       0,   127,     0,    77,   128,     0,     0,     0,    78,     0,
      79,    80,    81,    82,    60,     0,    22,   131,   132,   133,
     134,   135,     0,     0,     0,     0,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    34,     2,
       3,     4,     5,     0,     6,    37,    38,     0,     0,    59,
      12,    39,    13,     0,     0,    40,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,    79,     0,    81,     0,
      60,     0,    22,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     0,    97,    59,    12,     0,    13,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      30,    31,    32,    33,    34,    60,     0,    22,     0,     0,
       0,    37,    38,     0,     0,     0,     0,    39,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,    30,    31,    32,    33,    34,
       2,     3,     4,     5,     0,     6,    37,    38,     0,     0,
      59,    12,    39,    13,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     0,
       6,    60,     0,    22,     0,    59,    12,     0,    13,     0,
       0,     0,     0,     0,     0,     0,   125,   126,     0,   127,
       0,     0,   128,     0,    29,     0,    60,     0,    22,     0,
       0,    30,    31,    32,    33,    34,   132,   133,   134,   135,
       0,     0,    37,    38,   136,   137,     0,     0,    65,    29,
       0,     0,    40,     0,     0,     0,    30,    31,    32,    33,
      34,     0,     0,   169,     0,     0,     0,    37,    38,   170,
       0,     0,     0,   118,     0,     0,     0,    40,     0,     0,
     122,   123,     0,     0,     0,   124,   125,   126,     0,   127,
       0,     0,   128,   129,   130,   171,     0,     0,     0,     0,
       0,   172,     0,     0,     0,   131,   132,   133,   134,   135,
       0,     0,   122,   123,   136,   137,     0,   124,   125,   126,
       0,   127,     0,     0,   128,   129,   130,   173,     0,     0,
       0,     0,     0,   174,     0,     0,     0,   131,   132,   133,
     134,   135,     0,     0,   122,   123,   136,   137,     0,   124,
     125,   126,     0,   127,     0,     0,   128,   129,   130,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,     0,     0,   122,   123,   136,   137,
       0,   124,   125,   126,     0,   127,     0,     0,   128,   129,
     130,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   133,   134,   135,     0,     0,   122,   123,
     136,   137,     0,   124,   125,   126,     0,   127,     0,     0,
     128,   129,   130,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,     0,     0,
     122,   123,   136,   137,     0,   124,   125,   126,     0,   127,
       0,     0,   128,   129,   130,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,   134,   135,
       0,     0,   122,   123,   136,   137,     0,   124,   125,   126,
       0,   127,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,   131,   132,   133,
     134,   135,     0,   122,   123,     0,   136,   137,   124,   125,
     126,     0,   127,     0,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,   134,   135,     0,   122,   123,     0,   136,   137,   124,
     125,   126,     0,   127,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,     0,     0,     0,     0,   136,   137,
     122,   123,  -150,     0,     0,   124,   125,   126,     0,   127,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,   134,   135,
       0,     0,     0,     0,   136,   137,   122,   123,  -151,     0,
       0,   124,   125,   126,     0,   127,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,   175,   176,     0,     0,
       0,   131,   132,   133,   134,   135,     0,   122,   123,     0,
     136,   137,   124,   125,   126,     0,   127,     0,     0,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   131,   132,   133,   134,   135,     0,   122,   123,
     179,   136,   137,   124,   125,   126,     0,   127,     0,     0,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,     0,   122,
     123,   179,   136,   137,   124,   125,   126,     0,   127,     0,
       0,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   131,   132,   133,   134,   135,     0,
     122,   123,     0,   136,   137,   124,   125,   126,     0,   127,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,   134,   135,
       0,     0,     0,     0,   136,   137
};

static const yytype_int16 yycheck[] =
{
       0,   241,     0,     0,   116,     4,   118,     0,     7,     8,
       9,    27,    11,     1,    46,   221,    29,     9,    17,    11,
      25,    20,    46,    27,    94,    95,     0,    26,    27,   163,
      29,    30,    31,    32,    33,    34,    69,    50,    37,    38,
      39,    40,    46,   177,   262,    50,   252,   286,    40,    81,
      49,    50,   186,    41,   289,   240,    21,    81,    91,    92,
     299,    60,   280,   303,    43,   300,    65,    90,    84,    68,
      69,    88,    95,    65,    73,    21,    68,    88,    77,    89,
      79,    73,    98,    90,    95,   325,    12,    13,    95,    21,
      88,    88,    91,   278,   279,    21,    90,    21,   283,    90,
     285,    95,    21,    38,    95,    40,    48,    49,    21,    21,
     295,   296,    21,    89,    81,   115,    89,   116,   117,   118,
      95,    38,   115,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     274,   115,    95,   142,   329,    95,   145,    21,    45,   183,
      95,   150,    21,    45,   288,   154,   155,    21,   157,   158,
      21,   160,   161,    21,    46,   164,    21,    90,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    35,   291,
      90,   315,    21,   317,    95,    25,    21,    29,   187,   323,
     302,    50,    45,    63,    64,    25,    66,    25,   186,    69,
      57,    58,    25,    25,    45,    62,    63,    64,   115,    66,
      67,    68,    69,    70,    71,    85,    86,   275,   217,   218,
     254,    91,    92,   257,   258,    82,    83,    84,    85,    86,
     299,    27,    -1,    -1,    91,    92,    -1,   236,    -1,   273,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,   282,   248,
     249,   250,   251,    -1,    -1,   289,   244,   256,    -1,   247,
      -1,    -1,    -1,   297,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,   308,    -1,    -1,    -1,    -1,   267,
     314,    -1,   316,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,   331,   332,    11,
      12,    13,    14,   302,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    -1,    -1,    37,    -1,   327,    -1,   329,
      42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    -1,    -1,    -1,    88,    89,    -1,    -1,
      40,    93,    11,    12,    13,    14,    46,    16,    -1,    -1,
      -1,    -1,    21,    22,    -1,    24,    -1,    57,    58,    -1,
      -1,    -1,    62,    63,    64,    -1,    66,    -1,    -1,    69,
      70,    71,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    91,    92,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    93,    -1,    95,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    53,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    -1,    -1,    -1,    88,    89,    -1,
      -1,    -1,    93,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    80,    -1,    -1,    83,    84,    -1,    -1,    -1,
      88,    89,    -1,    -1,    -1,    93,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    46,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,
      32,    33,    57,    58,    -1,    -1,    -1,    62,    63,    64,
      42,    66,    44,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    53,    54,    -1,    56,    -1,    81,    82,    83,    84,
      85,    86,    -1,    65,    -1,    -1,    91,    92,    -1,    -1,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    -1,
      -1,    83,    84,    11,    12,    13,    14,    89,    16,    -1,
      -1,    93,    -1,    21,    22,    -1,    24,    -1,    63,    64,
      -1,    66,    -1,    31,    69,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    -1,    44,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    11,
      12,    13,    14,    -1,    16,    83,    84,    -1,    -1,    21,
      22,    89,    24,    -1,    -1,    93,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    55,    21,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    42,    -1,    44,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      11,    12,    13,    14,    -1,    16,    83,    84,    -1,    -1,
      21,    22,    89,    24,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    42,    -1,    44,    -1,    21,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    66,
      -1,    -1,    69,    -1,    65,    -1,    42,    -1,    44,    -1,
      -1,    72,    73,    74,    75,    76,    83,    84,    85,    86,
      -1,    -1,    83,    84,    91,    92,    -1,    -1,    89,    65,
      -1,    -1,    93,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    -1,    40,    -1,    -1,    -1,    83,    84,    46,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    -1,    -1,
      57,    58,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    69,    70,    71,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    57,    58,    91,    92,    -1,    62,    63,    64,
      -1,    66,    -1,    -1,    69,    70,    71,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    -1,    57,    58,    91,    92,    -1,    62,
      63,    64,    -1,    66,    -1,    -1,    69,    70,    71,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    -1,    57,    58,    91,    92,
      -1,    62,    63,    64,    -1,    66,    -1,    -1,    69,    70,
      71,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    -1,    57,    58,
      91,    92,    -1,    62,    63,    64,    -1,    66,    -1,    -1,
      69,    70,    71,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,
      57,    58,    91,    92,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    69,    70,    71,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    57,    58,    91,    92,    -1,    62,    63,    64,
      -1,    66,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    57,    58,    -1,    91,    92,    62,    63,
      64,    -1,    66,    -1,    -1,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    57,    58,    -1,    91,    92,    62,
      63,    64,    -1,    66,    -1,    -1,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,    92,
      57,    58,    95,    -1,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    57,    58,    95,    -1,
      -1,    62,    63,    64,    -1,    66,    -1,    -1,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    57,    58,    -1,
      91,    92,    62,    63,    64,    -1,    66,    -1,    -1,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    -1,    57,    58,
      90,    91,    92,    62,    63,    64,    -1,    66,    -1,    -1,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    57,
      58,    90,    91,    92,    62,    63,    64,    -1,    66,    -1,
      -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    -1,
      57,    58,    -1,    91,    92,    62,    63,    64,    -1,    66,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    91,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    12,    13,    14,    16,    17,    18,    19,
      20,    21,    22,    24,    26,    30,    32,    33,    34,    37,
      42,    43,    44,    47,    51,    52,    53,    54,    56,    65,
      72,    73,    74,    75,    76,    79,    80,    83,    84,    89,
      93,    97,    99,   100,   101,   102,   103,   110,   111,   112,
     117,   118,   119,   122,   125,   127,   134,    88,    98,    21,
      42,   100,   118,   118,   118,    89,   118,   135,    21,    89,
     118,   135,   136,   126,    43,    21,   120,    31,    36,    38,
      39,    40,    41,   118,   123,   124,    21,   118,    48,    49,
      12,    13,    21,    21,    21,    21,   118,    55,   123,   124,
      21,   121,   118,   118,   118,   118,   118,   118,    21,    89,
     118,   118,   118,   135,     0,    98,    89,    81,    89,   109,
     118,   118,    57,    58,    62,    63,    64,    66,    69,    70,
      71,    82,    83,    84,    85,    86,    91,    92,    89,   118,
     118,   135,    95,   135,   135,    95,   135,    95,   118,   118,
      38,   124,   128,    35,    67,    68,    21,    46,    81,   118,
      46,    81,    45,   129,    48,   124,    95,    40,    46,    40,
      46,    40,    46,    40,    46,    77,    78,   130,    21,    90,
      94,    99,   109,   118,   109,   118,    45,    81,   115,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,    90,   118,    90,   118,    21,
     118,   114,    21,   118,   118,   118,   118,    46,    81,   118,
     118,   114,   118,    21,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   114,    90,    95,    90,   115,    90,
      98,   114,   118,    21,   132,   118,   118,   132,    40,    40,
      40,    40,   131,   135,   116,    27,    46,   116,   101,   119,
      95,    98,    98,   118,   118,   118,   118,   132,    90,    98,
     102,   115,    46,   118,   115,   115,    21,    95,   133,   133,
      98,    25,   118,   115,    25,    50,   114,    29,    50,   106,
     107,   113,    21,   116,   116,   133,   115,   116,   116,   105,
     106,   108,   113,   114,   107,   115,   109,   116,   116,   115,
     115,   108,   115,   109,   101,    50,   104,    45,    25,   115,
      25,    25,    25,    45,   115,   114,   115,   114,    25,   114,
     101,   102,   116,   115,   115
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
        case 4:
#line 119 "engines/director/lingo/lingo-gr.y"
    { yyerrok; ;}
    break;

  case 5:
#line 122 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->_linenumber++;
		g_lingo->_colnumber = 1;
	;}
    break;

  case 10:
#line 131 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_xpop); ;}
    break;

  case 12:
#line 135 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(4) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(2) - (4)].code);
		delete (yyvsp[(4) - (4)].s); ;}
    break;

  case 13:
#line 141 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code1(g_lingo->c_after); ;}
    break;

  case 14:
#line 142 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code1(g_lingo->c_before); ;}
    break;

  case 15:
#line 143 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(2) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(4) - (4)].code);
		delete (yyvsp[(2) - (4)].s); ;}
    break;

  case 16:
#line 149 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (4)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (4)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(4) - (4)].code); ;}
    break;

  case 17:
#line 157 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_swap);
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (5)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (5)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(5) - (5)].code); ;}
    break;

  case 18:
#line 165 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(2) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(4) - (4)].code);
		delete (yyvsp[(2) - (4)].s); ;}
    break;

  case 19:
#line 171 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (4)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (4)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(4) - (4)].code); ;}
    break;

  case 20:
#line 179 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_swap);
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (5)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (5)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(5) - (5)].code); ;}
    break;

  case 21:
#line 188 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_xpop); ;}
    break;

  case 25:
#line 197 "engines/director/lingo/lingo-gr.y"
    {
		inst body = 0, end = 0;
		WRITE_UINT32(&body, (yyvsp[(5) - (7)].code));
		WRITE_UINT32(&end, (yyvsp[(6) - (7)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (7)].code) + 1] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (7)].code) + 2] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(7) - (7)].s), "repeat", true); ;}
    break;

  case 26:
#line 210 "engines/director/lingo/lingo-gr.y"
    {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[(3) - (10)].code));
		WRITE_UINT32(&finish, (yyvsp[(6) - (10)].code));
		WRITE_UINT32(&body, (yyvsp[(8) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (10)].code));
		WRITE_UINT32(&inc, 1);
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = init;	/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = finish;/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 4] = inc;	/* increment */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 5] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(10) - (10)].s), "repeat", true); ;}
    break;

  case 27:
#line 228 "engines/director/lingo/lingo-gr.y"
    {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[(3) - (11)].code));
		WRITE_UINT32(&finish, (yyvsp[(7) - (11)].code));
		WRITE_UINT32(&body, (yyvsp[(9) - (11)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (11)].code));
		WRITE_UINT32(&inc, -1);
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 1] = init;	/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 2] = finish;/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 3] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 4] = inc;	/* increment */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 5] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(11) - (11)].s), "repeat", true); ;}
    break;

  case 28:
#line 242 "engines/director/lingo/lingo-gr.y"
    {
			inst end = 0;
			WRITE_UINT32(&end, (yyvsp[(3) - (3)].code));
			g_lingo->code1(STOP);
			(*g_lingo->_currentScript)[(yyvsp[(1) - (3)].code) + 1] = end;
		;}
    break;

  case 29:
#line 250 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (7)].code));
		WRITE_UINT32(&end, (yyvsp[(6) - (7)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (7)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (7)].code) + 3] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(7) - (7)].s), "if", true);

		g_lingo->processIf(0, 0); ;}
    break;

  case 30:
#line 260 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(8) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(10) - (10)].s), "if", true);

		g_lingo->processIf(0, 0); ;}
    break;

  case 31:
#line 272 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(7) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end;	/* end, if cond fails */

		checkEnd((yyvsp[(10) - (10)].s), "if", true);

		g_lingo->processIf(0, (yyvsp[(9) - (10)].code)); ;}
    break;

  case 32:
#line 284 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (6)].code));
		WRITE_UINT32(&else1, 0);
		WRITE_UINT32(&end, (yyvsp[(6) - (6)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, 0); ;}
    break;

  case 33:
#line 294 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(8) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, 0); ;}
    break;

  case 34:
#line 304 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(6) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, (yyvsp[(10) - (10)].code)); ;}
    break;

  case 35:
#line 315 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = 0; ;}
    break;

  case 36:
#line 316 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (3)].code); ;}
    break;

  case 41:
#line 327 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (6)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 1] = then;	/* thenpart */

		g_lingo->codeLabel((yyvsp[(1) - (6)].code)); ;}
    break;

  case 43:
#line 336 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (6)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 1] = then;	/* thenpart */

		g_lingo->codeLabel((yyvsp[(1) - (6)].code)); ;}
    break;

  case 44:
#line 344 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(STOP); ;}
    break;

  case 45:
#line 345 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code2(g_lingo->c_eq, STOP); ;}
    break;

  case 47:
#line 348 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code3(g_lingo->c_repeatwhilecode, STOP, STOP); ;}
    break;

  case 48:
#line 350 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code3(g_lingo->c_repeatwithcode, STOP, STOP);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str());
		delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 49:
#line 356 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(0);  // Do not skip end
		g_lingo->codeLabel(0); ;}
    break;

  case 50:
#line 362 "engines/director/lingo/lingo-gr.y"
    {
		inst skipEnd;
		WRITE_UINT32(&skipEnd, 1); // We have to skip end to avoid multiple executions
		(yyval.code) = g_lingo->code1(g_lingo->c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(skipEnd); ;}
    break;

  case 51:
#line 369 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 52:
#line 371 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(STOP); (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 53:
#line 373 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 56:
#line 378 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_whencode);
		g_lingo->code1(STOP);
		g_lingo->codeString((yyvsp[(2) - (3)].s)->c_str());
		delete (yyvsp[(2) - (3)].s); ;}
    break;

  case 57:
#line 384 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->codeConst((yyvsp[(1) - (1)].i)); ;}
    break;

  case 58:
#line 385 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_fconstpush);
		g_lingo->codeFloat((yyvsp[(1) - (1)].f)); ;}
    break;

  case 59:
#line 388 "engines/director/lingo/lingo-gr.y"
    {											// D3
		(yyval.code) = g_lingo->code1(g_lingo->c_symbolpush);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); ;}
    break;

  case 60:
#line 391 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_stringpush);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); ;}
    break;

  case 61:
#line 394 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->_builtins[*(yyvsp[(1) - (1)].s)]->u.func);
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 62:
#line 397 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->codeFunc((yyvsp[(1) - (4)].s), (yyvsp[(3) - (4)].narg));
		delete (yyvsp[(1) - (4)].s); ;}
    break;

  case 63:
#line 400 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_eval);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str());
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 64:
#line 404 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(1) - (1)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(1) - (1)].e)[1]);
		g_lingo->code2(e, f); ;}
    break;

  case 65:
#line 411 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(1) - (2)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(1) - (2)].e)[1]);
		g_lingo->code2(e, f); ;}
    break;

  case 67:
#line 418 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_add); ;}
    break;

  case 68:
#line 419 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_sub); ;}
    break;

  case 69:
#line 420 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_mul); ;}
    break;

  case 70:
#line 421 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_div); ;}
    break;

  case 71:
#line 422 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_mod); ;}
    break;

  case 72:
#line 423 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gt); ;}
    break;

  case 73:
#line 424 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_lt); ;}
    break;

  case 74:
#line 425 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_neq); ;}
    break;

  case 75:
#line 426 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_ge); ;}
    break;

  case 76:
#line 427 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_le); ;}
    break;

  case 77:
#line 428 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_and); ;}
    break;

  case 78:
#line 429 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_or); ;}
    break;

  case 79:
#line 430 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_not); ;}
    break;

  case 80:
#line 431 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_ampersand); ;}
    break;

  case 81:
#line 432 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_concat); ;}
    break;

  case 82:
#line 433 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_contains); ;}
    break;

  case 83:
#line 434 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_starts); ;}
    break;

  case 84:
#line 435 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (2)].code); ;}
    break;

  case 85:
#line 436 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (2)].code); g_lingo->code1(g_lingo->c_negate); ;}
    break;

  case 86:
#line 437 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (3)].code); ;}
    break;

  case 87:
#line 438 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->codeArray((yyvsp[(2) - (3)].narg)); ;}
    break;

  case 88:
#line 439 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_intersects); ;}
    break;

  case 89:
#line 440 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_within); ;}
    break;

  case 90:
#line 441 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_charOf); ;}
    break;

  case 91:
#line 442 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_charToOf); ;}
    break;

  case 92:
#line 443 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_itemOf); ;}
    break;

  case 93:
#line 444 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_itemToOf); ;}
    break;

  case 94:
#line 445 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_lineOf); ;}
    break;

  case 95:
#line 446 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_lineToOf); ;}
    break;

  case 96:
#line 447 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_wordOf); ;}
    break;

  case 97:
#line 448 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_wordToOf); ;}
    break;

  case 98:
#line 451 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_printtop); ;}
    break;

  case 101:
#line 454 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_exitRepeat); ;}
    break;

  case 102:
#line 455 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeConst(0); // Push fake value on stack
							  g_lingo->code1(g_lingo->c_procret); ;}
    break;

  case 105:
#line 459 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->_builtins[*(yyvsp[(1) - (2)].s)]->u.func);
		delete (yyvsp[(1) - (2)].s); ;}
    break;

  case 106:
#line 462 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->_builtins[*(yyvsp[(1) - (2)].s)]->u.func);
		delete (yyvsp[(1) - (2)].s); ;}
    break;

  case 107:
#line 465 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code2(g_lingo->c_voidpush, g_lingo->_builtins[*(yyvsp[(1) - (1)].s)]->u.func);
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 108:
#line 468 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeFunc((yyvsp[(1) - (4)].s), (yyvsp[(3) - (4)].narg)); ;}
    break;

  case 109:
#line 469 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeFunc((yyvsp[(1) - (2)].s), (yyvsp[(2) - (2)].narg)); ;}
    break;

  case 110:
#line 470 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeMe((yyvsp[(3) - (4)].s), 0); ;}
    break;

  case 111:
#line 471 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeMe((yyvsp[(3) - (6)].s), (yyvsp[(5) - (6)].narg)); ;}
    break;

  case 112:
#line 472 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_open); ;}
    break;

  case 113:
#line 473 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code2(g_lingo->c_voidpush, g_lingo->c_open); ;}
    break;

  case 114:
#line 474 "engines/director/lingo/lingo-gr.y"
    { Common::String s(*(yyvsp[(1) - (3)].s)); s += '-'; s += *(yyvsp[(2) - (3)].s); g_lingo->codeFunc(&s, (yyvsp[(3) - (3)].narg)); ;}
    break;

  case 115:
#line 477 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_global); g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 116:
#line 478 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_global); g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str()); delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 117:
#line 481 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_instance); g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 118:
#line 482 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_instance); g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str()); delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 119:
#line 493 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotoloop); ;}
    break;

  case 120:
#line 494 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotonext); ;}
    break;

  case 121:
#line 495 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotoprevious); ;}
    break;

  case 122:
#line 496 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(1);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 123:
#line 499 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(3);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 124:
#line 502 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(2);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 129:
#line 515 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_playdone); ;}
    break;

  case 130:
#line 516 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(1);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 131:
#line 519 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(3);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 132:
#line 522 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(2);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 133:
#line 525 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeSetImmediate(true); ;}
    break;

  case 134:
#line 525 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeSetImmediate(false);
		g_lingo->codeFunc((yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].narg)); ;}
    break;

  case 135:
#line 555 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; g_lingo->_currentFactory.clear(); ;}
    break;

  case 136:
#line 556 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->codeConst(0); // Push fake value on stack
			g_lingo->code1(g_lingo->c_procret);
			g_lingo->define(*(yyvsp[(2) - (8)].s), (yyvsp[(4) - (8)].code), (yyvsp[(5) - (8)].narg));
			g_lingo->_indef = false; ;}
    break;

  case 137:
#line 561 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->codeFactory(*(yyvsp[(2) - (2)].s));
		;}
    break;

  case 138:
#line 564 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; ;}
    break;

  case 139:
#line 565 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->code1(g_lingo->c_procret);
			g_lingo->define(*(yyvsp[(2) - (8)].s), (yyvsp[(4) - (8)].code), (yyvsp[(5) - (8)].narg) + 1, &g_lingo->_currentFactory);
			g_lingo->_indef = false; ;}
    break;

  case 140:
#line 569 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; g_lingo->_currentFactory.clear(); ;}
    break;

  case 141:
#line 570 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_ignoreMe = true; ;}
    break;

  case 142:
#line 570 "engines/director/lingo/lingo-gr.y"
    {
				g_lingo->codeConst(0); // Push fake value on stack
				g_lingo->code1(g_lingo->c_procret);
				g_lingo->define(*(yyvsp[(2) - (10)].s), (yyvsp[(4) - (10)].code), (yyvsp[(6) - (10)].narg));
				g_lingo->_indef = false;
				g_lingo->_ignoreMe = false;

				checkEnd((yyvsp[(10) - (10)].s), (yyvsp[(2) - (10)].s)->c_str(), false);
			;}
    break;

  case 143:
#line 580 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 0; ;}
    break;

  case 144:
#line 581 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(1) - (1)].s)); (yyval.narg) = 1; ;}
    break;

  case 145:
#line 582 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(3) - (3)].s)); (yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;

  case 146:
#line 583 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(4) - (4)].s)); (yyval.narg) = (yyvsp[(1) - (4)].narg) + 1; ;}
    break;

  case 147:
#line 585 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArgStore(); ;}
    break;

  case 148:
#line 589 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_call);
		g_lingo->codeString((yyvsp[(1) - (2)].s)->c_str());
		inst numpar = 0;
		WRITE_UINT32(&numpar, (yyvsp[(2) - (2)].narg));
		g_lingo->code1(numpar); ;}
    break;

  case 149:
#line 597 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 0; ;}
    break;

  case 150:
#line 598 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 1; ;}
    break;

  case 151:
#line 599 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;

  case 152:
#line 602 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 1; ;}
    break;

  case 153:
#line 603 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2936 "engines/director/lingo/lingo-gr.cpp"
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


#line 606 "engines/director/lingo/lingo-gr.y"


