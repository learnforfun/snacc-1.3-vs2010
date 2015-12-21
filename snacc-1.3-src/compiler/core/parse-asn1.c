/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 63 "core/parse-asn1.y"


#include "snacc.h"

#if STDC_HEADERS || HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif
#include <stdio.h>

#include "asn-incl.h"
#include "mem.h"
#include "asn1module.h"
#include "lib-types.h"
#include "snacc-util.h"
#include "exports.h"
#include "parser.h"
#include "lex-stuff.h"

/*
 * smallErrG
 *    used for small errors that should prevent code generation but not
 *    prevent the later error checking passes
 */
int smallErrG = FALSE;

/*
 * firstTimeThroughG
 *    used incase the asn1.lex was compiled with flex in which
 *    case the lexical analyzer must be reset for every ASN.1 file
 *    parsed, except the first
 */
static int firstTimeThroughG = TRUE;

/*
 *  modulePtrG
 *    used to hold the parsed value.  The root of the parse tree.
 */
Module *modulePtrG;


/*
 * oidElmtValDefsG
 *    used to hold integer values that are defined as arc numbers
 *    the modules object identifiers.
 * eg. FOO-MODULE { joint-iso-ccitt dod (2) foo (2) 3 2 } DEFINITIONS ::=
 *     would put dod/2 and foo/2 in the oidElmtValDefsG list
 * Note: only some oid's (modules name/import list module names)
 *       are parsed by the yacc code.  The rest are parsed later
 *       due to ambiguities that arise without type info.
 */
ValueDefList *oidElmtValDefsG = NULL;


/*
 * ApplTag
 *   used to hold APPLICATION tags that have been defined in
 *   a module.  This permits checking for the the error of
 *   using the same APPLICATION tag in 1 module.  The
 *   ApplTags list (appTagsG) is emptied for each module.
 */
typedef struct ApplTag
{
    unsigned long int lineNo;
    unsigned long int tagCode;
    struct ApplTag *next;
} ApplTag;

ApplTag *applTagsG  = NULL;

/*
 * Protos for ApplTag related stuff. These are defined at the
 * end  of this file
 */
void PushApplTag PROTO ((unsigned long int tagCode, unsigned long int lineNo));
void FreeApplTags();



/*
 * the following are globals to simplify disparity between
 * productions and produced data structure
 */

/*
 * these are used in the ValueRange subtype production
 */
static int      valueRangeUpperEndInclusiveG;
static int      valueRangeLowerEndInclusiveG;

/*
 * used to set exports flag in Type/value defs
 * exportListG holds the explicitly exported elements.
 * see SetExports routine in export.c
 */
ExportElmt *exportListG = NULL;
int         exportsParsedG;


/*
 * globals for the APPLICATION-CONTEXT macro productions
 */
static ValueList *rosAcSymmetricAsesG;
static ValueList *rosAcResponderConsumerOfG;
static ValueList *rosAcInitiatorConsumerOfG;

/*
 * used with MTSAS Extension macro
 * set to NULL for the initial parse.
 */
static AsnBool *mtsasCriticalForSubmissionG = NULL;
static AsnBool *mtsasCriticalForTransferG = NULL;
static AsnBool *mtsasCriticalForDeliveryG = NULL;

/*
 * Asn PORT macro globals
 */
static TypeOrValueList *asnConsumerG;
static TypeOrValueList *asnSupplierG;


/*
 * parseErrCountG
 *   used to prevent too many cascade errors
 */
int parseErrCountG = 0;
#define MAX_ERR 50
#define PARSE_ERROR()\
    parseErrCountG++;\
    modulePtrG->status = MOD_ERROR;\
    if (parseErrCountG > MAX_ERR)\
    {\
        fprintf (stderr, "Ackkkkk! too many errors - bye!\n");\
        exit (1);\
    }




/* Line 268 of yacc.c  */
#line 212 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BSTRING_SYM = 258,
     HSTRING_SYM = 259,
     CSTRING_SYM = 260,
     UCASEFIRST_IDENT_SYM = 261,
     LCASEFIRST_IDENT_SYM = 262,
     NAMEDMACRO_SYM = 263,
     MACRODEFBODY_SYM = 264,
     BRACEBAL_SYM = 265,
     NUMBER_ERANGE = 266,
     NUMBER_SYM = 267,
     SNACC_ATTRIBUTES = 268,
     DOT_SYM = 269,
     COMMA_SYM = 270,
     LEFTBRACE_SYM = 271,
     RIGHTBRACE_SYM = 272,
     LEFTPAREN_SYM = 273,
     RIGHTPAREN_SYM = 274,
     LEFTBRACKET_SYM = 275,
     RIGHTBRACKET_SYM = 276,
     LESSTHAN_SYM = 277,
     MINUS_SYM = 278,
     GETS_SYM = 279,
     BAR_SYM = 280,
     TAGS_SYM = 281,
     BOOLEAN_SYM = 282,
     INTEGER_SYM = 283,
     BIT_SYM = 284,
     STRING_SYM = 285,
     OCTET_SYM = 286,
     NULL_SYM = 287,
     SEQUENCE_SYM = 288,
     OF_SYM = 289,
     SET_SYM = 290,
     IMPLICIT_SYM = 291,
     CHOICE_SYM = 292,
     ANY_SYM = 293,
     OBJECT_IDENTIFIER_SYM = 294,
     OPTIONAL_SYM = 295,
     DEFAULT_SYM = 296,
     COMPONENTS_SYM = 297,
     UNIVERSAL_SYM = 298,
     APPLICATION_SYM = 299,
     PRIVATE_SYM = 300,
     TRUE_SYM = 301,
     FALSE_SYM = 302,
     BEGIN_SYM = 303,
     END_SYM = 304,
     DEFINITIONS_SYM = 305,
     EXPLICIT_SYM = 306,
     ENUMERATED_SYM = 307,
     EXPORTS_SYM = 308,
     IMPORTS_SYM = 309,
     REAL_SYM = 310,
     INCLUDES_SYM = 311,
     MIN_SYM = 312,
     MAX_SYM = 313,
     SIZE_SYM = 314,
     FROM_SYM = 315,
     WITH_SYM = 316,
     COMPONENT_SYM = 317,
     PRESENT_SYM = 318,
     ABSENT_SYM = 319,
     DEFINED_SYM = 320,
     BY_SYM = 321,
     PLUS_INFINITY_SYM = 322,
     MINUS_INFINITY_SYM = 323,
     SEMI_COLON_SYM = 324,
     IA5STRING_SYM = 325,
     PRINTABLESTRING_SYM = 326,
     NUMERICSTRING_SYM = 327,
     TELETEXSTRING_SYM = 328,
     T61STRING_SYM = 329,
     VIDEOTEXSTRING_SYM = 330,
     VISIBLESTRING_SYM = 331,
     ISO646STRING_SYM = 332,
     GRAPHICSTRING_SYM = 333,
     GENERALSTRING_SYM = 334,
     GENERALIZEDTIME_SYM = 335,
     UTCTIME_SYM = 336,
     EXTERNAL_SYM = 337,
     OBJECTDESCRIPTOR_SYM = 338,
     OPERATION_SYM = 339,
     ARGUMENT_SYM = 340,
     RESULT_SYM = 341,
     ERRORS_SYM = 342,
     LINKED_SYM = 343,
     ERROR_SYM = 344,
     PARAMETER_SYM = 345,
     BIND_SYM = 346,
     BINDERROR_SYM = 347,
     UNBIND_SYM = 348,
     UNBINDERROR_SYM = 349,
     ASE_SYM = 350,
     OPERATIONS_SYM = 351,
     CONSUMERINVOKES_SYM = 352,
     SUPPLIERINVOKES_SYM = 353,
     AC_SYM = 354,
     ASES_SYM = 355,
     REMOTE_SYM = 356,
     INITIATOR_SYM = 357,
     RESPONDER_SYM = 358,
     ABSTRACTSYNTAXES_SYM = 359,
     CONSUMER_SYM = 360,
     EXTENSIONS_SYM = 361,
     CHOSEN_SYM = 362,
     EXTENSION_SYM = 363,
     CRITICAL_SYM = 364,
     FOR_SYM = 365,
     DELIVERY_SYM = 366,
     SUBMISSION_SYM = 367,
     TRANSFER_SYM = 368,
     EXTENSIONATTRIBUTE_SYM = 369,
     TOKEN_SYM = 370,
     TOKENDATA_SYM = 371,
     SECURITYCATEGORY_SYM = 372,
     OBJECT_SYM = 373,
     PORTS_SYM = 374,
     BOXC_SYM = 375,
     BOXS_SYM = 376,
     PORT_SYM = 377,
     ABSTRACTOPS_SYM = 378,
     REFINE_SYM = 379,
     AS_SYM = 380,
     RECURRING_SYM = 381,
     VISIBLE_SYM = 382,
     PAIRED_SYM = 383,
     ABSTRACTBIND_SYM = 384,
     ABSTRACTUNBIND_SYM = 385,
     TO_SYM = 386,
     ABSTRACTERROR_SYM = 387,
     ABSTRACTOPERATION_SYM = 388,
     ALGORITHM_SYM = 389,
     ENCRYPTED_SYM = 390,
     SIGNED_SYM = 391,
     SIGNATURE_SYM = 392,
     PROTECTED_SYM = 393,
     OBJECTTYPE_SYM = 394,
     SYNTAX_SYM = 395,
     ACCESS_SYM = 396,
     STATUS_SYM = 397,
     DESCRIPTION_SYM = 398,
     REFERENCE_SYM = 399,
     INDEX_SYM = 400,
     DEFVAL_SYM = 401
   };
#endif
/* Tokens.  */
#define BSTRING_SYM 258
#define HSTRING_SYM 259
#define CSTRING_SYM 260
#define UCASEFIRST_IDENT_SYM 261
#define LCASEFIRST_IDENT_SYM 262
#define NAMEDMACRO_SYM 263
#define MACRODEFBODY_SYM 264
#define BRACEBAL_SYM 265
#define NUMBER_ERANGE 266
#define NUMBER_SYM 267
#define SNACC_ATTRIBUTES 268
#define DOT_SYM 269
#define COMMA_SYM 270
#define LEFTBRACE_SYM 271
#define RIGHTBRACE_SYM 272
#define LEFTPAREN_SYM 273
#define RIGHTPAREN_SYM 274
#define LEFTBRACKET_SYM 275
#define RIGHTBRACKET_SYM 276
#define LESSTHAN_SYM 277
#define MINUS_SYM 278
#define GETS_SYM 279
#define BAR_SYM 280
#define TAGS_SYM 281
#define BOOLEAN_SYM 282
#define INTEGER_SYM 283
#define BIT_SYM 284
#define STRING_SYM 285
#define OCTET_SYM 286
#define NULL_SYM 287
#define SEQUENCE_SYM 288
#define OF_SYM 289
#define SET_SYM 290
#define IMPLICIT_SYM 291
#define CHOICE_SYM 292
#define ANY_SYM 293
#define OBJECT_IDENTIFIER_SYM 294
#define OPTIONAL_SYM 295
#define DEFAULT_SYM 296
#define COMPONENTS_SYM 297
#define UNIVERSAL_SYM 298
#define APPLICATION_SYM 299
#define PRIVATE_SYM 300
#define TRUE_SYM 301
#define FALSE_SYM 302
#define BEGIN_SYM 303
#define END_SYM 304
#define DEFINITIONS_SYM 305
#define EXPLICIT_SYM 306
#define ENUMERATED_SYM 307
#define EXPORTS_SYM 308
#define IMPORTS_SYM 309
#define REAL_SYM 310
#define INCLUDES_SYM 311
#define MIN_SYM 312
#define MAX_SYM 313
#define SIZE_SYM 314
#define FROM_SYM 315
#define WITH_SYM 316
#define COMPONENT_SYM 317
#define PRESENT_SYM 318
#define ABSENT_SYM 319
#define DEFINED_SYM 320
#define BY_SYM 321
#define PLUS_INFINITY_SYM 322
#define MINUS_INFINITY_SYM 323
#define SEMI_COLON_SYM 324
#define IA5STRING_SYM 325
#define PRINTABLESTRING_SYM 326
#define NUMERICSTRING_SYM 327
#define TELETEXSTRING_SYM 328
#define T61STRING_SYM 329
#define VIDEOTEXSTRING_SYM 330
#define VISIBLESTRING_SYM 331
#define ISO646STRING_SYM 332
#define GRAPHICSTRING_SYM 333
#define GENERALSTRING_SYM 334
#define GENERALIZEDTIME_SYM 335
#define UTCTIME_SYM 336
#define EXTERNAL_SYM 337
#define OBJECTDESCRIPTOR_SYM 338
#define OPERATION_SYM 339
#define ARGUMENT_SYM 340
#define RESULT_SYM 341
#define ERRORS_SYM 342
#define LINKED_SYM 343
#define ERROR_SYM 344
#define PARAMETER_SYM 345
#define BIND_SYM 346
#define BINDERROR_SYM 347
#define UNBIND_SYM 348
#define UNBINDERROR_SYM 349
#define ASE_SYM 350
#define OPERATIONS_SYM 351
#define CONSUMERINVOKES_SYM 352
#define SUPPLIERINVOKES_SYM 353
#define AC_SYM 354
#define ASES_SYM 355
#define REMOTE_SYM 356
#define INITIATOR_SYM 357
#define RESPONDER_SYM 358
#define ABSTRACTSYNTAXES_SYM 359
#define CONSUMER_SYM 360
#define EXTENSIONS_SYM 361
#define CHOSEN_SYM 362
#define EXTENSION_SYM 363
#define CRITICAL_SYM 364
#define FOR_SYM 365
#define DELIVERY_SYM 366
#define SUBMISSION_SYM 367
#define TRANSFER_SYM 368
#define EXTENSIONATTRIBUTE_SYM 369
#define TOKEN_SYM 370
#define TOKENDATA_SYM 371
#define SECURITYCATEGORY_SYM 372
#define OBJECT_SYM 373
#define PORTS_SYM 374
#define BOXC_SYM 375
#define BOXS_SYM 376
#define PORT_SYM 377
#define ABSTRACTOPS_SYM 378
#define REFINE_SYM 379
#define AS_SYM 380
#define RECURRING_SYM 381
#define VISIBLE_SYM 382
#define PAIRED_SYM 383
#define ABSTRACTBIND_SYM 384
#define ABSTRACTUNBIND_SYM 385
#define TO_SYM 386
#define ABSTRACTERROR_SYM 387
#define ABSTRACTOPERATION_SYM 388
#define ALGORITHM_SYM 389
#define ENCRYPTED_SYM 390
#define SIGNED_SYM 391
#define SIGNATURE_SYM 392
#define PROTECTED_SYM 393
#define OBJECTTYPE_SYM 394
#define SYNTAX_SYM 395
#define ACCESS_SYM 396
#define STATUS_SYM 397
#define DESCRIPTION_SYM 398
#define REFERENCE_SYM 399
#define INDEX_SYM 400
#define DEFVAL_SYM 401




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 210 "core/parse-asn1.y"

    int              intVal;
    unsigned int     uintVal;
    char            *charPtr;
    Type            *typePtr;
    NamedType       *namedTypePtr;
    NamedTypeList   *namedTypeListPtr;
    Value           *valuePtr;
    NamedValue      *namedValuePtr;
    SubtypeValue    *subtypeValuePtr;
    Subtype         *subtypePtr;
    ModuleId        *moduleId;
    OID             *oidPtr;
    OidList         *oidListPtr;
    TypeDef         *typeDefPtr;
    TypeDefList     *typeDefListPtr;
    ValueDef        *valueDefPtr;
    ValueDefList    *valueDefListPtr;
    ExportElmt      *exportList;
    ImportModule    *importModulePtr;
    ImportModuleList *importModuleListPtr;
    ImportElmt      *importElmtPtr;
    ImportElmtList  *importElmtListPtr;
    Tag             *tagPtr;
    TagList         *tagListPtr;
    Constraint      *constraintPtr;
    ConstraintList  *constraintListPtr;
    InnerSubtype    *innerSubtypePtr;
    ValueList       *valueListPtr;
    TypeOrValueList *typeOrValueListPtr;
    TypeOrValue     *typeOrValuePtr;
    AsnPort         *asnPortPtr;
    AsnPortList     *asnPortListPtr;
    AttributeList   *attrList;



/* Line 293 of yacc.c  */
#line 578 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 590 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  188
/* YYNRULES -- Number of rules.  */
#define YYNRULES  396
/* YYNRULES -- Number of states.  */
#define YYNSTATES  671

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   401

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    17,    20,    22,    25,
      27,    29,    33,    35,    39,    43,    45,    47,    49,    51,
      56,    60,    64,    66,    68,    70,    73,    75,    80,    84,
      86,    88,    90,    92,    95,    97,    99,   102,   105,   107,
     109,   110,   117,   121,   127,   129,   131,   138,   143,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   173,   175,   177,   179,   181,   183,   185,
     188,   191,   193,   195,   197,   202,   204,   208,   213,   218,
     220,   222,   225,   228,   233,   235,   238,   244,   246,   248,
     252,   256,   259,   262,   264,   270,   272,   275,   279,   283,
     288,   292,   296,   300,   303,   307,   313,   316,   318,   323,
     327,   330,   334,   338,   343,   345,   347,   349,   351,   353,
     355,   357,   362,   364,   367,   372,   377,   381,   383,   387,
     389,   391,   393,   395,   397,   399,   401,   404,   409,   411,
     414,   416,   419,   421,   423,   425,   427,   430,   433,   437,
     441,   443,   445,   447,   451,   459,   461,   465,   468,   470,
     473,   475,   477,   479,   481,   483,   485,   491,   493,   495,
     497,   499,   504,   506,   508,   510,   512,   514,   516,   518,
     519,   523,   525,   527,   529,   531,   533,   535,   538,   542,
     545,   547,   549,   551,   553,   555,   557,   562,   567,   569,
     571,   573,   575,   577,   579,   581,   583,   584,   586,   588,
     590,   593,   595,   597,   599,   601,   603,   605,   607,   609,
     611,   613,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   645,   647,   649,
     651,   653,   655,   657,   659,   661,   663,   665,   667,   669,
     671,   673,   675,   677,   679,   681,   683,   685,   687,   689,
     691,   693,   696,   701,   704,   706,   709,   711,   713,   715,
     720,   722,   727,   729,   732,   735,   737,   742,   745,   747,
     750,   752,   755,   757,   762,   765,   767,   770,   774,   779,
     784,   786,   791,   793,   795,   804,   809,   817,   819,   825,
     827,   830,   837,   839,   846,   848,   853,   855,   857,   861,
     868,   870,   872,   874,   878,   880,   882,   884,   888,   890,
     892,   897,   899,   902,   904,   908,   910,   912,   916,   918,
     920,   922,   924,   927,   929,   932,   934,   937,   939,   942,
     945,   950,   952,   954,   958,   961,   963,   965,   967,   970,
     972,   977,   979,   981,   984,   987,   992,   997,  1002,  1004,
    1008,  1011,  1013,  1016,  1018,  1022,  1026,  1028,  1032,  1034,
    1038,  1040,  1043,  1047,  1052,  1054,  1057,  1061,  1066,  1068,
    1071,  1074,  1078,  1081,  1084,  1087,  1090,  1102,  1104,  1106,
    1109,  1110,  1113,  1114,  1119,  1120,  1125
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,    -1,    -1,   152,    50,   151,   150,    24,
      48,   154,    49,    -1,    51,    26,    -1,    36,    26,    -1,
     250,    -1,   248,   153,    -1,   237,    -1,   250,    -1,   155,
     158,   164,    -1,   250,    -1,    53,   156,    69,    -1,    53,
       1,    69,    -1,   250,    -1,   157,    -1,   250,    -1,   163,
      -1,   157,    15,   148,   163,    -1,    54,   159,    69,    -1,
      54,     1,    69,    -1,   250,    -1,   160,    -1,   250,    -1,
     160,   161,    -1,   161,    -1,   162,    60,   148,   152,    -1,
     162,    15,   163,    -1,   163,    -1,   249,    -1,   247,    -1,
     254,    -1,   164,   165,    -1,   165,    -1,   166,    -1,   166,
      69,    -1,     1,    69,    -1,   169,    -1,   227,    -1,    -1,
       8,    24,    48,   148,   167,     9,    -1,     8,    24,   168,
      -1,     8,    24,   248,    14,   168,    -1,   249,    -1,   254,
      -1,   249,    24,   251,   148,   172,   251,    -1,   248,    14,
     148,   249,    -1,   170,    -1,   249,    -1,   253,    -1,   173,
      -1,   171,    -1,   204,    -1,   175,    -1,   176,    -1,   182,
      -1,   184,    -1,   186,    -1,   190,    -1,   192,    -1,   193,
      -1,   194,    -1,   197,    -1,   198,    -1,   202,    -1,   203,
      -1,   180,    -1,   181,    -1,    31,    30,    -1,   247,   172,
      -1,   172,    -1,    27,    -1,    28,    -1,    28,    16,   177,
      17,    -1,   178,    -1,   177,    15,   178,    -1,   247,    18,
     179,    19,    -1,   247,    18,   229,    19,    -1,    12,    -1,
      11,    -1,    23,    12,    -1,    23,    11,    -1,    52,    16,
     177,    17,    -1,    55,    -1,    29,    30,    -1,    29,    30,
      16,   183,    17,    -1,   177,    -1,    32,    -1,    33,   148,
      16,    -1,   185,   187,    17,    -1,   185,    17,    -1,   188,
     251,    -1,   189,    -1,   188,    15,   251,   148,   189,    -1,
     174,    -1,   174,    40,    -1,   174,    41,   236,    -1,    42,
      34,   172,    -1,   247,    42,    34,   172,    -1,    33,    34,
     172,    -1,    35,   148,    16,    -1,   191,   187,    17,    -1,
     191,    17,    -1,    35,    34,   172,    -1,    37,   148,    16,
     195,    17,    -1,   196,   251,    -1,   174,    -1,   196,    15,
     251,   174,    -1,   247,    22,   172,    -1,   199,   172,    -1,
     199,    36,   172,    -1,   199,    51,   172,    -1,    20,   201,
     200,    21,    -1,   246,    -1,   229,    -1,    43,    -1,    44,
      -1,    45,    -1,   250,    -1,    38,    -1,    38,    65,    66,
     247,    -1,    39,    -1,   172,   205,    -1,    35,   215,    34,
     172,    -1,    33,   215,    34,   172,    -1,    18,   206,    19,
      -1,   207,    -1,   206,    25,   207,    -1,   208,    -1,   209,
      -1,   210,    -1,   216,    -1,   215,    -1,   217,    -1,   228,
      -1,    56,   172,    -1,   211,    14,    14,   212,    -1,   213,
      -1,   213,    22,    -1,   214,    -1,    22,   214,    -1,   228,
      -1,    57,    -1,   228,    -1,    58,    -1,    59,   205,    -1,
      60,   205,    -1,    61,    62,   218,    -1,    61,    42,   219,
      -1,   205,    -1,   220,    -1,   221,    -1,    16,   222,    17,
      -1,    16,    14,    14,    14,    15,   222,    17,    -1,   223,
      -1,   222,    15,   223,    -1,   247,   224,    -1,   224,    -1,
     225,   226,    -1,   205,    -1,   250,    -1,    63,    -1,    64,
      -1,   250,    -1,    40,    -1,   247,   172,    24,   148,   228,
      -1,   231,    -1,   229,    -1,   230,    -1,   247,    -1,   248,
      14,   148,   247,    -1,   233,    -1,   235,    -1,   234,    -1,
     179,    -1,   244,    -1,   243,    -1,   245,    -1,    -1,    16,
     232,    10,    -1,    46,    -1,    47,    -1,    67,    -1,    68,
      -1,    32,    -1,   228,    -1,   247,   228,    -1,    16,   238,
      17,    -1,   238,   239,    -1,   239,    -1,   240,    -1,   241,
      -1,   242,    -1,   246,    -1,   247,    -1,   247,    18,   240,
      19,    -1,   247,    18,   229,    19,    -1,     3,    -1,     4,
      -1,     5,    -1,    12,    -1,    11,    -1,     7,    -1,     6,
      -1,     6,    -1,    -1,   252,    -1,   250,    -1,    13,    -1,
     252,    13,    -1,   255,    -1,   262,    -1,   264,    -1,   268,
      -1,   270,    -1,   275,    -1,   290,    -1,   284,    -1,   295,
      -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,   304,
      -1,   308,    -1,   317,    -1,   319,    -1,   321,    -1,   322,
      -1,   323,    -1,   324,    -1,   327,    -1,   326,    -1,   325,
      -1,   328,    -1,    84,    -1,    89,    -1,    91,    -1,    93,
      -1,    95,    -1,    99,    -1,   108,    -1,   106,    -1,   114,
      -1,   115,    -1,   116,    -1,   117,    -1,   118,    -1,   122,
      -1,   124,    -1,   129,    -1,   130,    -1,   133,    -1,   132,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,    84,   256,    -1,   257,   258,   260,   261,
      -1,    85,   174,    -1,   250,    -1,    86,   259,    -1,   250,
      -1,   174,    -1,   250,    -1,    87,    16,   287,    17,    -1,
     250,    -1,    88,    16,   287,    17,    -1,   250,    -1,    89,
     263,    -1,    90,   174,    -1,   250,    -1,    91,   265,   266,
     267,    -1,    85,   174,    -1,   250,    -1,    86,   174,    -1,
     250,    -1,    92,   174,    -1,   250,    -1,    93,   265,   266,
     269,    -1,    94,   174,    -1,   250,    -1,    95,   271,    -1,
      95,   272,   273,    -1,    96,    16,   274,    17,    -1,    97,
      16,   274,    17,    -1,   250,    -1,    98,    16,   274,    17,
      -1,   250,    -1,   286,    -1,    99,   276,    91,   172,    93,
     172,   277,   282,    -1,   100,    16,   286,    17,    -1,   101,
      96,    16,   228,    17,   278,   279,    -1,   250,    -1,    96,
      34,    16,   286,    17,    -1,   250,    -1,   280,   281,    -1,
     102,   105,    34,    16,   286,    17,    -1,   250,    -1,   103,
     105,    34,    16,   286,    17,    -1,   250,    -1,   104,    16,
     283,    17,    -1,   250,    -1,   237,    -1,   283,    15,   237,
      -1,   106,   107,    60,    16,   285,    17,    -1,   286,    -1,
     250,    -1,   228,    -1,   286,    15,   228,    -1,   288,    -1,
     250,    -1,   289,    -1,   288,    15,   289,    -1,   172,    -1,
     228,    -1,   108,   174,   291,   292,    -1,   108,    -1,    41,
     228,    -1,   250,    -1,   109,   110,   293,    -1,   250,    -1,
     294,    -1,   293,    15,   294,    -1,   112,    -1,   113,    -1,
     111,    -1,   114,    -1,   114,   172,    -1,   115,    -1,   115,
     172,    -1,   116,    -1,   116,   172,    -1,   117,    -1,   117,
     172,    -1,   118,   300,    -1,   119,    16,   301,    17,    -1,
     250,    -1,   302,    -1,   301,    15,   302,    -1,   228,   303,
      -1,   120,    -1,   121,    -1,   250,    -1,   122,   305,    -1,
     122,    -1,   123,    16,   288,    17,    -1,   306,    -1,   307,
      -1,   306,   307,    -1,   307,   306,    -1,    97,    16,   288,
      17,    -1,    98,    16,   288,    17,    -1,   124,   316,   125,
     309,    -1,   310,    -1,   309,    15,   310,    -1,   311,   312,
      -1,   316,    -1,   316,   126,    -1,   313,    -1,   312,    15,
     313,    -1,   228,   303,   314,    -1,   127,    -1,   128,    61,
     315,    -1,   316,    -1,   315,    15,   316,    -1,   228,    -1,
     129,   318,    -1,   129,   318,   172,    -1,   131,    16,   301,
      17,    -1,   250,    -1,   130,   320,    -1,   130,   320,   172,
      -1,    60,    16,   301,    17,    -1,   250,    -1,   133,   256,
      -1,   132,   263,    -1,   134,    90,   172,    -1,   135,   172,
      -1,   136,   172,    -1,   137,   172,    -1,   138,   172,    -1,
     139,   140,   172,   141,   329,   142,   330,   331,   332,   333,
     334,    -1,   247,    -1,   247,    -1,   143,   228,    -1,    -1,
     144,   228,    -1,    -1,   145,    16,   288,    17,    -1,    -1,
     146,    16,   228,    17,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   458,   458,   463,   461,   498,   499,   500,   508,   517,
     518,   522,   523,   527,   537,   544,   548,   549,   553,   560,
     570,   571,   576,   580,   581,   585,   589,   597,   608,   618,
     632,   633,   634,   648,   649,   653,   654,   655,   663,   677,
     690,   690,   731,   747,   773,   774,   782,   803,   818,   819,
     830,   831,   832,   833,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     859,   865,   873,   880,   885,   894,   899,   907,   914,   923,
     930,   936,   947,   956,   965,   972,   977,   985,   991,   998,
    1003,  1018,  1033,  1047,  1052,  1070,  1071,  1076,  1090,  1096,
    1108,  1124,  1128,  1142,  1158,  1172,  1189,  1202,  1207,  1223,
    1238,  1263,  1304,  1314,  1332,  1337,  1346,  1347,  1348,  1349,
    1354,  1358,  1368,  1376,  1385,  1398,  1415,  1422,  1437,  1450,
    1451,  1452,  1453,  1454,  1455,  1459,  1467,  1476,  1491,  1496,
    1504,  1509,  1517,  1518,  1526,  1527,  1535,  1545,  1554,  1560,
    1569,  1584,  1585,  1589,  1598,  1608,  1613,  1621,  1626,  1631,
    1640,  1641,  1645,  1646,  1647,  1648,  1661,  1673,  1674,  1678,
    1679,  1693,  1708,  1709,  1710,  1711,  1717,  1725,  1733,  1741,
    1741,  1759,  1765,  1775,  1781,  1792,  1802,  1807,  1817,  1844,
    1853,  1859,  1860,  1881,  1886,  1894,  1899,  1917,  1939,  1943,
    1947,  1951,  1958,  1967,  1971,  1975,  1978,  1986,  1987,  1991,
    1996,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,
    2017,  2018,  2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,  2031,  2032,  2036,  2037,  2038,  2039,
    2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,  2048,  2049,
    2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,
    2060,  2069,  2073,  2089,  2090,  2094,  2095,  2100,  2101,  2106,
    2110,  2116,  2120,  2132,  2146,  2147,  2156,  2170,  2171,  2176,
    2177,  2182,  2183,  2192,  2207,  2208,  2217,  2225,  2238,  2246,
    2250,  2255,  2259,  2264,  2273,  2297,  2305,  2310,  2320,  2324,
    2328,  2332,  2336,  2340,  2344,  2348,  2352,  2357,  2362,  2375,
    2389,  2390,  2394,  2399,  2407,  2408,  2412,  2417,  2425,  2431,
    2444,  2461,  2474,  2475,  2479,  2480,  2485,  2486,  2490,  2495,
    2500,  2514,  2523,  2539,  2547,  2562,  2571,  2587,  2596,  2618,
    2628,  2632,  2636,  2641,  2649,  2658,  2663,  2668,  2681,  2691,
    2700,  2704,  2710,  2716,  2722,  2731,  2738,  2754,  2761,  2762,
    2766,  2770,  2771,  2775,  2776,  2780,  2787,  2788,  2793,  2794,
    2798,  2811,  2820,  2833,  2837,  2847,  2857,  2871,  2875,  2884,
    2896,  2909,  2920,  2932,  2943,  2957,  2967,  2993,  3015,  3036,
    3037,  3041,  3042,  3046,  3050,  3054,  3058
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BSTRING_SYM", "HSTRING_SYM",
  "CSTRING_SYM", "UCASEFIRST_IDENT_SYM", "LCASEFIRST_IDENT_SYM",
  "NAMEDMACRO_SYM", "MACRODEFBODY_SYM", "BRACEBAL_SYM", "NUMBER_ERANGE",
  "NUMBER_SYM", "SNACC_ATTRIBUTES", "DOT_SYM", "COMMA_SYM",
  "LEFTBRACE_SYM", "RIGHTBRACE_SYM", "LEFTPAREN_SYM", "RIGHTPAREN_SYM",
  "LEFTBRACKET_SYM", "RIGHTBRACKET_SYM", "LESSTHAN_SYM", "MINUS_SYM",
  "GETS_SYM", "BAR_SYM", "TAGS_SYM", "BOOLEAN_SYM", "INTEGER_SYM",
  "BIT_SYM", "STRING_SYM", "OCTET_SYM", "NULL_SYM", "SEQUENCE_SYM",
  "OF_SYM", "SET_SYM", "IMPLICIT_SYM", "CHOICE_SYM", "ANY_SYM",
  "OBJECT_IDENTIFIER_SYM", "OPTIONAL_SYM", "DEFAULT_SYM", "COMPONENTS_SYM",
  "UNIVERSAL_SYM", "APPLICATION_SYM", "PRIVATE_SYM", "TRUE_SYM",
  "FALSE_SYM", "BEGIN_SYM", "END_SYM", "DEFINITIONS_SYM", "EXPLICIT_SYM",
  "ENUMERATED_SYM", "EXPORTS_SYM", "IMPORTS_SYM", "REAL_SYM",
  "INCLUDES_SYM", "MIN_SYM", "MAX_SYM", "SIZE_SYM", "FROM_SYM", "WITH_SYM",
  "COMPONENT_SYM", "PRESENT_SYM", "ABSENT_SYM", "DEFINED_SYM", "BY_SYM",
  "PLUS_INFINITY_SYM", "MINUS_INFINITY_SYM", "SEMI_COLON_SYM",
  "IA5STRING_SYM", "PRINTABLESTRING_SYM", "NUMERICSTRING_SYM",
  "TELETEXSTRING_SYM", "T61STRING_SYM", "VIDEOTEXSTRING_SYM",
  "VISIBLESTRING_SYM", "ISO646STRING_SYM", "GRAPHICSTRING_SYM",
  "GENERALSTRING_SYM", "GENERALIZEDTIME_SYM", "UTCTIME_SYM",
  "EXTERNAL_SYM", "OBJECTDESCRIPTOR_SYM", "OPERATION_SYM", "ARGUMENT_SYM",
  "RESULT_SYM", "ERRORS_SYM", "LINKED_SYM", "ERROR_SYM", "PARAMETER_SYM",
  "BIND_SYM", "BINDERROR_SYM", "UNBIND_SYM", "UNBINDERROR_SYM", "ASE_SYM",
  "OPERATIONS_SYM", "CONSUMERINVOKES_SYM", "SUPPLIERINVOKES_SYM", "AC_SYM",
  "ASES_SYM", "REMOTE_SYM", "INITIATOR_SYM", "RESPONDER_SYM",
  "ABSTRACTSYNTAXES_SYM", "CONSUMER_SYM", "EXTENSIONS_SYM", "CHOSEN_SYM",
  "EXTENSION_SYM", "CRITICAL_SYM", "FOR_SYM", "DELIVERY_SYM",
  "SUBMISSION_SYM", "TRANSFER_SYM", "EXTENSIONATTRIBUTE_SYM", "TOKEN_SYM",
  "TOKENDATA_SYM", "SECURITYCATEGORY_SYM", "OBJECT_SYM", "PORTS_SYM",
  "BOXC_SYM", "BOXS_SYM", "PORT_SYM", "ABSTRACTOPS_SYM", "REFINE_SYM",
  "AS_SYM", "RECURRING_SYM", "VISIBLE_SYM", "PAIRED_SYM",
  "ABSTRACTBIND_SYM", "ABSTRACTUNBIND_SYM", "TO_SYM", "ABSTRACTERROR_SYM",
  "ABSTRACTOPERATION_SYM", "ALGORITHM_SYM", "ENCRYPTED_SYM", "SIGNED_SYM",
  "SIGNATURE_SYM", "PROTECTED_SYM", "OBJECTTYPE_SYM", "SYNTAX_SYM",
  "ACCESS_SYM", "STATUS_SYM", "DESCRIPTION_SYM", "REFERENCE_SYM",
  "INDEX_SYM", "DEFVAL_SYM", "$accept", "LineNo", "ModuleDefinition",
  "$@1", "TagDefault", "ModuleIdentifier", "AssignedIdentifier",
  "ModuleBody", "Exports", "SymbolsExported", "ExportSymbolList",
  "Imports", "SymbolsImported", "SymbolsFromModuleList",
  "SymbolsFromModule", "SymbolList", "Symbol", "AssignmentList",
  "AssignmentOrError", "Assignment", "$@2", "MacroReference",
  "TypeAssignment", "ExternalTypeReference", "DefinedType", "Type",
  "BuiltinType", "NamedType", "BooleanType", "IntegerType",
  "NamedNumberList", "NamedNumber", "SignedNumber", "EnumeratedType",
  "RealType", "BitStringType", "NamedBitList", "NullType",
  "SequenceOpening", "SequenceType", "ElementTypes", "ElementTypeList",
  "ElementType", "SequenceOfType", "SetOpening", "SetType", "SetOfType",
  "ChoiceType", "AlternativeTypes", "AlternativeTypeList", "SelectionType",
  "TaggedType", "Tag", "ClassNumber", "Class", "AnyType",
  "ObjectIdentifierType", "Subtype", "SubtypeSpec", "SubtypeValueSetList",
  "SubtypeValueSet", "SingleValue", "ContainedSubtype", "ValueRange",
  "LowerEndPoint", "UpperEndPoint", "LowerEndValue", "UpperEndValue",
  "SizeConstraint", "PermittedAlphabet", "InnerTypeConstraints",
  "SingleTypeConstraint", "MultipleTypeConstraints", "FullSpecification",
  "PartialSpecification", "TypeConstraints", "NamedConstraint",
  "Constraint", "ValueConstraint", "PresenceConstraint", "ValueAssignment",
  "Value", "DefinedValue", "ExternalValueReference", "BuiltinValue", "$@3",
  "BooleanValue", "SpecialRealValue", "NullValue", "NamedValue",
  "ObjectIdentifierValue", "ObjIdComponentList", "ObjIdComponent",
  "NumberForm", "NameForm", "NameAndNumberForm", "BinaryString",
  "HexString", "CharString", "number", "identifier", "modulereference",
  "typereference", "empty", "SnaccAttributes", "SnaccAttributeCommentList",
  "DefinedMacroType", "DefinedMacroName", "RosOperationMacroType",
  "RosOperationMacroBody", "RosOpArgument", "RosOpResult",
  "RosOpResultType", "RosOpErrors", "RosOpLinkedOps", "RosErrorMacroType",
  "RosErrParameter", "RosBindMacroType", "RosBindArgument",
  "RosBindResult", "RosBindError", "RosUnbindMacroType", "RosUnbindError",
  "RosAseMacroType", "RosAseSymmetricAse", "RosAseConsumerInvokes",
  "RosAseSupplierInvokes", "RosAseOperationList", "RosAcMacroType",
  "RosAcNonRoElements", "RosAcRoElements", "RosAcSymmetricAses",
  "RosAcAsymmetricAses", "RosAcInitiatorConsumerOf",
  "RosAcResponderConsumerOf", "RosAcAbstractSyntaxes", "OidList",
  "MtsasExtensionsMacroType", "PossiblyEmptyValueList", "ValueList",
  "PossiblyEmptyTypeOrValueList", "TypeOrValueList", "TypeOrValue",
  "MtsasExtensionMacroType", "MtsasExtDefaultVal", "MtsasExtCritical",
  "MtsasExtCriticalityList", "MtsasExtCriticality",
  "MtsasExtensionAttributeMacroType", "MtsasTokenMacroType",
  "MtsasTokenDataMacroType", "MtsasSecurityCategoryMacroType",
  "AsnObjectMacroType", "AsnPorts", "AsnPortList", "AsnPort",
  "AsnPortType", "AsnPortMacroType", "AsnOperations", "AsnConsumer",
  "AsnSupplier", "AsnRefineMacroType", "AsnComponentList", "AsnComponent",
  "AsnObjectSpec", "AsnPortSpecList", "AsnPortSpec", "AsnPortStatus",
  "AsnObjectList", "AsnObject", "AsnAbstractBindMacroType",
  "AsnAbstractBindPorts", "AsnAbstractUnbindMacroType",
  "AsnAbstractUnbindPorts", "AsnAbstractOperationMacroType",
  "AsnAbstractErrorMacroType", "AfAlgorithmMacroType",
  "AfEncryptedMacroType", "AfSignedMacroType", "AfSignatureMacroType",
  "AfProtectedMacroType", "SnmpObjectTypeMacroType", "SnmpAccess",
  "SnmpStatus", "SnmpDescrPart", "SnmpReferPart", "SnmpIndexPart",
  "SnmpDefValPart", 0
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   147,   148,   150,   149,   151,   151,   151,   152,   153,
     153,   154,   154,   155,   155,   155,   156,   156,   157,   157,
     158,   158,   158,   159,   159,   160,   160,   161,   162,   162,
     163,   163,   163,   164,   164,   165,   165,   165,   166,   166,
     167,   166,   166,   166,   168,   168,   169,   170,   171,   171,
     172,   172,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     174,   174,   175,   176,   176,   177,   177,   178,   178,   179,
     179,   179,   179,   180,   181,   182,   182,   183,   184,   185,
     186,   186,   187,   188,   188,   189,   189,   189,   189,   189,
     190,   191,   192,   192,   193,   194,   195,   196,   196,   197,
     198,   198,   198,   199,   200,   200,   201,   201,   201,   201,
     202,   202,   203,   204,   204,   204,   205,   206,   206,   207,
     207,   207,   207,   207,   207,   208,   209,   210,   211,   211,
     212,   212,   213,   213,   214,   214,   215,   216,   217,   217,
     218,   219,   219,   220,   221,   222,   222,   223,   223,   224,
     225,   225,   226,   226,   226,   226,   227,   228,   228,   229,
     229,   230,   231,   231,   231,   231,   231,   231,   231,   232,
     231,   233,   233,   234,   234,   235,   236,   236,   237,   238,
     238,   239,   239,   239,   240,   241,   242,   242,   243,   244,
     245,   246,   246,   247,   248,   249,   250,   251,   251,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   255,   256,   257,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   263,   263,   264,   265,   265,   266,
     266,   267,   267,   268,   269,   269,   270,   270,   271,   272,
     272,   273,   273,   274,   275,   276,   277,   277,   278,   278,
     279,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   289,
     290,   290,   291,   291,   292,   292,   293,   293,   294,   294,
     294,   295,   295,   296,   296,   297,   297,   298,   298,   299,
     300,   300,   301,   301,   302,   303,   303,   303,   304,   304,
     305,   305,   305,   305,   305,   306,   307,   308,   309,   309,
     310,   311,   311,   312,   312,   313,   314,   314,   315,   315,
     316,   317,   317,   318,   318,   319,   319,   320,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     331,   332,   332,   333,   333,   334,   334
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     2,     2,     1,     2,     1,
       1,     3,     1,     3,     3,     1,     1,     1,     1,     4,
       3,     3,     1,     1,     1,     2,     1,     4,     3,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     1,
       0,     6,     3,     5,     1,     1,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     4,     1,     3,     4,     4,     1,
       1,     2,     2,     4,     1,     2,     5,     1,     1,     3,
       3,     2,     2,     1,     5,     1,     2,     3,     3,     4,
       3,     3,     3,     2,     3,     5,     2,     1,     4,     3,
       2,     3,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     2,     4,     4,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     2,
       1,     2,     1,     1,     1,     1,     2,     2,     3,     3,
       1,     1,     1,     3,     7,     1,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     2,     1,     2,     1,     1,     1,     4,
       1,     4,     1,     2,     2,     1,     4,     2,     1,     2,
       1,     2,     1,     4,     2,     1,     2,     3,     4,     4,
       1,     4,     1,     1,     8,     4,     7,     1,     5,     1,
       2,     6,     1,     6,     1,     4,     1,     1,     3,     6,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       4,     1,     2,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     1,     2,     2,
       4,     1,     1,     3,     2,     1,     1,     1,     2,     1,
       4,     1,     1,     2,     2,     4,     4,     4,     1,     3,
       2,     1,     2,     1,     3,     3,     1,     3,     1,     3,
       1,     2,     3,     4,     1,     2,     3,     4,     1,     2,
       2,     3,     2,     2,     2,     2,    11,     1,     1,     2,
       0,     2,     0,     4,     0,     4,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   204,     0,     0,   206,     1,   206,     0,     8,     9,
      10,     0,     0,     3,     7,   203,   202,   201,     0,   190,
     191,   192,   193,   194,   195,     6,     5,     0,   188,   189,
       0,     0,     0,   169,     0,   170,     0,   206,   197,   196,
       2,     0,     0,   206,    15,     0,     0,   205,   236,   237,
     238,   239,   240,   241,   243,   242,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   254,   253,   255,   256,   257,
     258,   259,   260,     0,    16,    18,    31,    30,    17,    32,
       4,     0,     0,    22,   171,    14,    13,     2,     0,     0,
      23,    26,     0,    29,    24,     0,     0,     0,    34,    35,
      38,    39,     0,     0,     0,    21,    20,    25,     0,     2,
      37,     0,    33,    36,   205,   206,    72,    73,     0,     0,
      88,     2,     2,     2,   120,   122,     0,    84,   206,   206,
     206,   206,   206,     0,     0,   321,   331,   333,   335,   337,
     206,   349,     0,   206,   206,   206,   206,     0,     0,     0,
       0,     0,     0,    48,    52,     0,    51,    54,    55,    67,
      68,    56,    57,     0,    58,    59,     0,    60,    61,    62,
      63,    64,     0,    65,    66,    53,     0,     0,    49,    50,
     211,   212,   213,   214,   215,   216,   218,   217,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   234,   233,   232,   235,   206,    19,    28,     0,     2,
      42,     0,    44,    45,   116,   117,   118,     0,   119,     0,
      85,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   261,   206,     0,   275,   273,     0,
     278,   206,   206,     0,     0,   290,   286,   206,     0,     0,
       0,    71,   206,     0,   332,   334,   336,   338,     0,   341,
     339,     0,     0,     0,   348,   351,   352,   198,   199,   200,
      80,    79,   179,     0,   185,   181,   182,   183,   184,   175,
     370,   168,   167,   172,   174,   173,   177,   176,   178,     0,
       0,   374,   371,     0,   378,   375,   380,   379,     0,   382,
     383,   384,   385,     0,     0,     2,   123,    91,     0,    95,
       0,   206,    93,     0,   103,     0,     0,     0,   110,     0,
       2,   209,   208,     2,   207,    27,    40,     0,     0,   115,
     114,     0,    75,     0,     0,   100,   146,    89,     0,   104,
     101,     0,     0,     0,     0,   263,   206,   266,   206,   274,
     277,     0,   280,   206,   206,     0,     0,     0,   292,   287,
       0,     0,     0,     0,   323,   206,    70,     0,     0,     0,
       0,   353,   354,     0,    82,    81,     0,     0,   372,     0,
     376,   381,     0,     0,   143,     0,     0,     0,   127,   129,
     130,   131,     0,   138,   133,   132,   134,   135,     0,     0,
      96,     0,    90,   206,    92,     0,   102,   111,   112,   109,
       0,     0,   210,     0,    43,   113,     0,    74,     0,    87,
       0,   125,   124,   107,     0,   206,   121,    83,   267,   268,
     265,     0,   270,   206,   279,     0,   282,   276,     0,   285,
     283,   312,     0,   293,     0,     0,     0,     0,   206,   322,
       0,   325,   320,   206,     0,   342,    88,   318,   319,   170,
       0,     0,   316,     0,     0,   180,   357,   358,     0,   361,
       0,     0,     0,   136,   147,     0,     0,   126,     0,     0,
     139,   166,    98,   186,    97,   170,     2,     0,    47,   206,
      41,    76,     0,     0,    86,   105,   206,   106,   206,     0,
     272,   262,   281,   284,   288,     0,   289,     0,   295,     0,
     311,     0,   310,     0,   345,   346,   347,   344,     0,   340,
       2,     0,   355,   356,   350,     0,   206,   360,   363,   362,
     373,   377,   387,     0,   206,   149,   151,   152,   150,   148,
     128,     0,   187,     0,    99,    46,    77,    78,     0,   315,
       0,   314,   206,   313,   291,   206,   309,   330,   328,   329,
     324,   326,   343,     0,   317,   359,     0,     0,     0,     0,
     160,     0,   155,   158,   206,   206,   161,     0,   145,   137,
     140,   144,    94,   108,   269,     0,     0,   297,   206,     0,
     366,     0,   365,   364,   388,   390,     0,   206,   153,   165,
     162,   163,   159,   164,   157,   141,   271,     0,     0,   306,
     294,   327,     0,     0,   392,     0,   156,     0,     0,   367,
     368,   389,     0,   394,   206,     0,   307,     0,     0,   391,
       0,   396,     0,   206,     0,   305,   369,     0,     0,   386,
     154,     0,   299,   206,   308,     0,     0,     0,     0,   302,
     296,   206,   393,     0,     0,     0,     0,   304,   300,   395,
       0,     0,     0,   298,     0,     0,     0,     0,   301,     0,
     303
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    45,     2,    27,    13,     3,     8,    42,    43,    73,
      74,    82,    89,    90,    91,    92,    93,    97,    98,    99,
     413,   210,   100,   153,   154,   251,   156,   309,   157,   158,
     331,   332,   279,   159,   160,   161,   420,   162,   163,   164,
     310,   311,   312,   165,   166,   167,   168,   169,   424,   425,
     170,   171,   172,   328,   217,   173,   174,   175,   306,   387,
     388,   389,   390,   391,   392,   579,   393,   580,   394,   395,
     396,   539,   535,   536,   537,   571,   572,   573,   574,   602,
     101,   441,   281,    33,   282,   373,   283,   284,   285,   484,
       9,    18,    19,    20,    21,    22,   286,   287,   288,    23,
      35,   177,   178,   322,   323,   324,   179,    79,   180,   234,
     235,   348,   430,   433,   501,   181,   238,   182,   241,   353,
     437,   183,   440,   184,   246,   247,   359,   442,   185,   249,
     588,   643,   650,   651,   658,   610,   627,   186,   511,   443,
     550,   551,   462,   187,   365,   452,   560,   561,   188,   189,
     190,   191,   192,   260,   454,   455,   517,   193,   264,   265,
     266,   194,   466,   467,   468,   527,   528,   592,   619,   469,
     195,   292,   196,   295,   197,   198,   199,   200,   201,   202,
     203,   204,   533,   595,   614,   623,   631,   639
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -595
static const yytype_int16 yypact[] =
{
      21,  -595,    36,     3,    47,  -595,    24,    93,  -595,  -595,
    -595,    40,    44,  -595,  -595,  -595,  -595,  -595,   109,  -595,
    -595,  -595,  -595,  -595,    64,  -595,  -595,    69,  -595,  -595,
     132,    31,    78,  -595,    83,  -595,    74,    53,  -595,  -595,
    -595,   720,    60,    68,    84,   160,   115,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,   119,   157,  -595,  -595,  -595,  -595,  -595,
    -595,   895,   129,  -595,  -595,  -595,  -595,  -595,   127,   131,
    2047,  -595,     4,  -595,  -595,   147,   194,    25,  -595,   166,
    -595,  -595,  1991,   210,  2047,  -595,  -595,  -595,  2047,  -595,
    -595,  2104,  -595,  -595,   223,   102,  -595,   222,   211,   212,
    -595,   -12,   -11,  -595,   175,  -595,   227,  -595,   161,   155,
     163,   163,    22,   150,   142,  1991,  1991,  1991,  1991,  1991,
     133,   -77,   558,   120,   193,   155,   161,   167,  1991,  1991,
    1991,  1991,   116,  -595,  -595,    43,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  1257,  -595,  -595,  1391,  -595,  -595,  -595,
    -595,  -595,  1511,  -595,  -595,  -595,   232,   241,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,   245,  -595,  -595,    21,  -595,
    -595,   247,  -595,  -595,  -595,  -595,  -595,   132,  -595,   160,
     243,  -595,  1991,   244,   248,   229,  1991,   249,   234,   250,
     204,   160,  1991,  -595,  -595,   183,  1991,  -595,  -595,  1991,
    -595,   185,   185,   256,   261,  -595,  -595,   180,   263,   189,
     237,   244,   251,  1751,   244,   244,   244,   244,   278,  -595,
    -595,   283,   284,   285,  -595,   205,   213,  -595,  -595,  -595,
    -595,  -595,  -595,   203,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,   190,
     291,  -595,  1991,   292,  -595,  1991,  -595,  -595,  1991,   244,
     244,   244,   244,  1991,   279,  -595,  -595,  -595,   286,   100,
     302,    81,  -595,  1631,  -595,   304,  1991,  1991,   244,  1991,
    -595,  -595,  -595,  -595,   309,  -595,  -595,  2160,   303,  -595,
    -595,   114,  -595,   305,   160,   244,  -595,  -595,  1991,   244,
    -595,  1991,  1991,   160,   136,  -595,  1991,  -595,   240,  -595,
    -595,  1991,  -595,   236,   235,   558,   558,   314,  -595,  -595,
     558,  1991,   315,   558,  -595,   224,   244,   558,  1123,  1123,
    1123,  -595,  -595,   322,  -595,  -595,   558,   558,   244,   558,
     244,   244,    -7,  1991,  -595,   244,     9,    61,  -595,  -595,
    -595,  -595,   320,   319,  -595,  -595,  -595,    27,   558,  1991,
    -595,   558,  -595,   245,  -595,   308,  -595,   244,   244,   244,
     331,  1991,  -595,   334,  -595,  -595,   160,  -595,   101,   329,
     328,   244,   244,  -595,   332,   139,  -595,  -595,  -595,  -595,
    -595,   335,  -595,   260,  -595,  1991,  -595,  -595,  1991,  -595,
    -595,  -595,   333,   337,   336,   558,   140,    -1,   558,  -595,
     252,  -595,  -595,    86,   141,  -595,  -595,   244,  -595,   232,
     340,   145,  -595,   148,   149,  -595,   342,  -595,   558,   238,
     153,   156,   160,   244,  -595,   345,   244,  -595,   279,   344,
    -595,  -595,   244,  -595,  -595,   558,  -595,  1991,  -595,    16,
    -595,  -595,   346,   347,  -595,  -595,   245,  -595,  1123,   355,
    -595,  -595,  -595,  -595,  -595,   558,  -595,   356,  -595,  1991,
    -595,   357,   337,    37,  -595,  -595,  -595,  -595,   558,  -595,
    -595,  1123,  -595,  -595,  -595,   558,    86,   360,  -595,  -595,
    -595,  -595,  -595,   230,    58,  -595,  -595,  -595,  -595,  -595,
    -595,  1039,  -595,  1871,   244,  -595,  -595,  -595,  1991,  -595,
     361,   365,  1123,  -595,  -595,    -2,  -595,  -595,  -595,  -595,
     367,  -595,  -595,   221,  -595,  -595,   103,   558,   160,   369,
    -595,   164,  -595,  -595,    -5,   244,  -595,   449,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,   368,   288,  -595,   282,    37,
    -595,   326,  -595,  -595,  -595,   246,   374,    55,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,   375,   379,  -595,
    -595,  -595,   558,   558,   262,   381,  -595,   558,    47,   390,
    -595,  -595,   558,   264,    55,   373,  -595,   165,   558,  -595,
     391,   266,   168,   317,    47,  -595,  -595,  1123,   394,  -595,
    -595,   380,  -595,   318,  -595,   178,   558,   400,   312,  -595,
    -595,   316,  -595,   404,   558,   388,   323,  -595,  -595,  -595,
     182,   407,   395,  -595,   558,   408,   188,   558,  -595,   195,
    -595
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -595,   -84,  -595,  -595,  -595,   217,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,   341,  -595,   -23,  -595,   338,  -595,
    -595,   105,  -595,  -595,  -595,   -94,  -595,  -122,  -595,  -595,
    -219,    14,    15,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
     268,  -595,  -106,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -216,  -595,
     -40,  -595,  -595,  -595,  -595,  -595,  -595,  -138,   111,  -595,
    -595,  -595,  -595,  -595,  -595,  -184,  -156,  -133,  -595,  -595,
    -595,   170,   -15,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -594,  -595,   425,   414,  -595,  -595,  -595,  -595,  -595,   233,
     569,     0,   -13,    46,  -302,  -595,  -595,  -101,  -595,   300,
    -595,  -595,  -595,  -595,  -595,  -595,   306,  -595,   339,   207,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -342,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -358,
    -105,  -364,   -64,  -595,  -595,  -595,  -595,  -130,  -595,  -595,
    -595,  -595,  -595,  -595,  -166,   -56,   -63,  -595,  -595,   198,
     201,  -595,  -595,   -58,  -595,  -595,   -98,  -595,  -595,  -141,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595,
    -595,  -595,  -595,  -595,  -595,  -595,  -595,  -595
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -207
static const yytype_int16 yytable[] =
{
       4,   289,   446,   104,   461,   463,   464,   336,   155,   404,
     213,   304,   344,   252,   444,    32,   304,   304,    75,   108,
     261,   262,   222,   226,   626,   208,    95,     1,    77,   321,
      36,    47,    15,    96,   304,   599,     5,   224,   227,   229,
     644,  -142,   254,   255,   256,   257,   263,   223,   223,  -142,
      10,   475,    14,     6,   299,   300,   301,   302,   600,   601,
      11,   304,    15,     7,   109,    15,    25,   305,    77,   103,
      26,   476,   569,   304,   -11,    12,   304,    77,   318,    37,
     477,   206,    30,    44,   103,   207,   478,    78,    40,    83,
     512,    77,   509,    31,   321,    77,   403,    38,   212,   586,
      15,   486,    39,   507,    16,    17,    41,     1,    15,    80,
     345,   211,   270,   271,   349,   419,    15,   350,   243,   244,
      16,    17,    81,   497,   273,   326,    28,    94,   335,   416,
      95,   417,   339,   -12,   472,    47,    15,    96,     1,    15,
     400,   401,    36,    16,    17,   214,   215,   216,   557,   558,
     559,   416,   321,   427,   496,   505,   518,   508,   519,   366,
     521,   218,   522,   521,   521,   523,   524,    15,   518,   474,
     530,   518,    87,   531,   233,   237,   240,   240,   245,   597,
     634,   598,   635,   597,    85,   640,   259,   545,    86,   291,
     294,   237,   233,   521,   548,   652,   105,   505,   378,   663,
     106,   380,   329,   505,   381,   668,   514,   515,     4,   382,
     505,   470,   670,   471,   374,   375,   110,    36,   111,   366,
     423,   398,   407,   408,   428,   409,   213,    47,    15,   434,
     590,   591,   225,   228,   205,   113,   410,  -204,   219,   411,
     230,   220,   221,   231,   421,   236,   232,   422,   239,   250,
     248,   290,   258,   293,   319,   320,   303,   298,   321,   334,
     538,   327,   304,   338,   337,   340,   342,   447,   341,   346,
     343,   351,   355,   645,   457,   457,   457,   356,   357,   360,
     361,   347,   267,   268,   269,     1,    15,   352,   352,   473,
     270,   271,   363,   358,   367,   272,   660,   362,   364,   368,
     369,   370,   273,   262,    36,   482,   666,   377,   379,   669,
     261,   274,   280,   502,   212,   376,   503,   489,   570,   402,
     399,   406,   412,   418,   415,   275,   276,   431,   435,   438,
     445,   448,   465,   450,   479,   383,   384,    47,   223,   385,
     386,   480,   487,   490,   416,   494,   277,   278,   499,   495,
     504,   498,   505,   506,   520,    36,    36,   525,   541,   570,
      36,   534,   513,    36,   529,   546,   547,    36,   460,   460,
     460,   552,   568,   554,   556,   567,    36,    36,   584,    36,
     521,   570,   589,   596,   607,   606,   608,   612,   615,   613,
     633,   617,   429,   544,   432,   618,   624,   488,    36,   436,
     439,    36,   543,   493,   457,   628,   622,   637,   570,   630,
     646,   451,   638,   641,   647,   555,   654,   655,    36,   656,
     648,   659,   661,   664,   667,   325,   583,   457,   662,   665,
     491,   107,   414,   492,   315,   112,   563,   582,   540,   605,
     632,   616,   604,    29,    34,    36,   297,   585,    36,   354,
     330,   296,   267,   268,   269,     1,    15,   564,   457,   611,
     270,   271,   562,   566,   372,   272,   371,   565,    36,   593,
     242,   620,   273,     0,   397,     0,     0,     0,    36,   500,
       0,   274,     0,     0,     0,    36,     0,   636,     0,     0,
       0,     0,     0,     0,   510,   275,   276,     0,   460,   516,
       0,     0,     0,     0,     0,    36,     0,   578,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   278,    36,     0,
       0,   460,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,   449,     0,     0,     0,   453,   458,   458,
     458,    36,     0,   457,   549,     0,   280,   453,     0,   453,
     488,     0,   460,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   268,   269,     1,    15,     0,    36,   481,   270,
     271,   483,   516,     0,   272,     0,    24,    36,     0,     0,
     576,   273,     0,     0,     0,     0,     0,    24,     0,     0,
     274,     0,     0,     0,     0,     0,     0,     0,   549,     0,
       0,   587,     0,     0,   275,   276,     0,     0,     0,     0,
      76,     0,    36,    36,    84,     0,     0,    36,     0,     0,
     603,   576,    36,     0,     0,   277,   278,     0,    36,     0,
       0,     0,     0,     0,   609,     0,     0,   460,   526,     0,
       0,     0,     0,   576,     0,     0,    36,     0,   397,     0,
      76,   102,     0,     0,    36,   542,     0,     0,     0,    76,
       0,     0,     0,     0,    36,     0,   102,    36,   458,     0,
     576,   176,     0,    76,     0,   553,     0,    76,     0,   642,
       0,     0,     0,     0,     0,     0,     0,     0,   453,   649,
       0,   458,     0,     0,     0,   280,     0,   657,     0,     0,
       0,     0,     0,     0,   253,   176,   176,   176,   176,     0,
       0,   581,     0,     0,     0,     0,     0,   176,   176,   176,
     176,    46,   458,     0,     0,     0,    47,    15,     0,     0,
       0,     0,   313,     0,     0,   313,     0,   526,     0,     0,
       0,   176,     0,     0,     0,     0,     0,   581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   621,     0,     0,     0,   625,   333,  -206,
       0,   176,   629,     0,     0,   176,     0,     0,   280,     0,
     333,   253,     0,     0,    48,   253,     0,   458,   253,    49,
       0,    50,     0,    51,     0,    52,   653,     0,     0,    53,
       0,     0,   176,     0,     0,     0,    54,     0,    55,     0,
       0,     0,     0,     0,    56,    57,    58,    59,    60,     0,
       0,     0,    61,     0,    62,     0,     0,     0,     0,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,   176,     0,     0,   176,     0,     0,   176,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,   176,   176,     0,   176,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,    47,    15,   333,     0,     0,     0,   176,     0,     0,
     176,   253,   426,     0,     0,   253,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,   459,   459,   459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -206,     0,     0,     0,   176,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     176,     0,     0,     0,    49,   333,    50,     0,    51,     0,
      52,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,    54,     0,    55,   253,     0,     0,   253,     0,    56,
      57,    58,    59,    60,     0,     0,     0,    61,     0,    62,
       0,     0,     0,     0,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,   532,   267,   268,   269,     1,    15,     0,     0,     0,
     270,   271,     0,     0,     0,   272,   176,     0,     0,     0,
       0,   577,   273,     0,     0,     0,     0,   459,     0,     0,
       0,   274,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,   275,   276,     0,     0,     0,
     459,     0,     0,     0,     0,     0,     0,   578,     0,     0,
       0,     0,     0,   575,     0,     0,   277,   278,     0,     0,
       0,     0,   313,     0,     0,     0,     0,   253,     0,     0,
       0,   459,     0,     0,     0,     0,   267,   268,   269,   114,
      15,     0,    84,     0,   270,   271,     0,   594,     0,   272,
       0,     0,     0,   115,     0,     0,   273,     0,     0,     0,
     116,   117,   118,     0,   119,   456,   121,     0,   122,     0,
     123,   124,   125,     0,     0,     0,   575,     0,     0,   275,
     276,     0,     0,     0,     0,   126,     0,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   278,     0,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,   128,     0,     0,
       0,     0,   129,     0,   130,     0,   131,     0,   132,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,   134,
       0,   135,     0,     0,     0,     0,     0,   136,   137,   138,
     139,   140,     0,     0,     0,   141,     0,   142,     0,     0,
       0,     0,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   114,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,   118,     0,   119,   120,
     121,     0,   122,     0,   123,   124,   125,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,     0,   129,     0,   130,     0,
     131,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,   134,     0,   135,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   140,     0,     0,     0,   141,
       0,   142,     0,     0,     0,     0,   143,   144,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   114,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   314,     0,
       0,   115,     0,     0,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,   123,   124,
     125,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,   141,     0,   142,     0,   114,    15,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   115,     0,     0,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,   316,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,   141,     0,   142,     0,   114,    15,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   115,     0,   319,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,   123,   124,
     125,     0,     0,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,   141,     0,   142,     0,   114,    15,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   115,     0,   319,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,   141,     0,   142,     0,   114,    15,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   115,     0,     0,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,   123,   124,
     125,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
       0,     0,     0,   141,     0,   142,     0,   114,    15,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   115,     0,     0,     0,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,    47,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     129,     0,   130,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,   134,     0,   135,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
     114,     0,     0,   141,     0,   142,     0,     0,     0,     0,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,    48,     0,     0,     0,     0,    49,     0,    50,     0,
      51,     0,    52,     0,     0,     0,    53,     0,     0,     0,
       0,     0,   209,    54,     0,    55,     0,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    47,     0,     0,    61,
       0,    62,     0,     0,     0,     0,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    48,     0,
       0,     0,     0,    49,     0,    50,     0,    51,     0,    52,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,    55,     0,     0,     0,     0,     0,    56,    57,
      58,    59,    60,     0,     0,     0,    61,     0,    62,     0,
       0,     0,     0,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    48,     0,     0,     0,     0,    49,
       0,    50,     0,    51,     0,    52,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    54,     0,    55,     0,
       0,     0,     0,     0,    56,    57,    58,    59,    60,     0,
       0,     0,    61,     0,    62,     0,     0,     0,     0,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-595))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   142,   360,    87,   368,   369,   370,   223,   102,   311,
     111,    18,   231,   135,   356,    30,    18,    18,    41,    15,
      97,    98,    34,    34,   618,   109,     1,     6,    41,    13,
      30,     6,     7,     8,    18,    40,     0,   121,   122,   123,
     634,    14,   136,   137,   138,   139,   123,    59,    59,    22,
       4,    42,     6,    50,   148,   149,   150,   151,    63,    64,
      36,    18,     7,    16,    60,     7,    26,    24,    81,    82,
      26,    62,    14,    18,    49,    51,    18,    90,   172,    48,
      19,   104,    18,    37,    97,   108,    25,    41,    14,    43,
     448,   104,    93,    24,    13,   108,    15,    19,   111,   101,
       7,   403,    19,   445,    11,    12,    53,     6,     7,    49,
     232,   111,    11,    12,   236,   334,     7,   239,    96,    97,
      11,    12,    54,   425,    23,   209,    17,    81,   222,    15,
       1,    17,   226,    49,   141,     6,     7,     8,     6,     7,
      40,    41,   142,    11,    12,    43,    44,    45,   111,   112,
     113,    15,    13,    17,    15,    15,    15,    17,    17,   253,
      15,   115,    17,    15,    15,    17,    17,     7,    15,   385,
      17,    15,    15,    17,   128,   129,   130,   131,   132,    15,
      15,    17,    17,    15,    69,    17,   140,   489,    69,   143,
     144,   145,   146,    15,   496,    17,    69,    15,   292,    17,
      69,   295,   217,    15,   298,    17,   120,   121,   208,   303,
      15,   377,    17,   379,    11,    12,    69,   217,    24,   313,
     342,   305,   316,   317,   346,   319,   327,     6,     7,   351,
     127,   128,   121,   122,    24,    69,   320,    14,    16,   323,
      65,    30,    30,    16,   338,    90,    85,   341,    85,   107,
     100,   131,   119,    60,    22,    14,   140,    90,    13,    16,
     476,    14,    18,    34,    16,    16,    16,   361,    34,    86,
      66,    86,    16,   637,   368,   369,   370,    16,    98,    16,
      91,   235,     3,     4,     5,     6,     7,   241,   242,   383,
      11,    12,    41,   247,    16,    16,   654,    60,   252,    16,
      16,    16,    23,    98,   304,   399,   664,    16,    16,   667,
      97,    32,   142,   435,   327,   125,   438,   411,   534,    17,
      34,    17,    13,    18,    21,    46,    47,    87,    92,    94,
      16,    16,    10,   109,    14,    56,    57,     6,    59,    60,
      61,    22,    34,     9,    15,    17,    67,    68,    88,    17,
      17,    16,    15,    17,    14,   355,   356,    15,    14,   575,
     360,    16,   110,   363,   126,    19,    19,   367,   368,   369,
     370,    16,   142,    17,    17,    15,   376,   377,    17,   379,
      15,   597,    15,    14,    96,    17,   104,    61,    14,   143,
      17,    16,   346,   487,   348,    16,    15,   410,   398,   353,
     354,   401,   486,   418,   498,    15,   144,    16,   624,   145,
      16,   365,   146,    96,    34,   509,    16,   105,   418,   103,
     102,    17,    34,    16,    16,   208,   548,   521,   105,    34,
     416,    90,   327,   418,   166,    97,   520,   543,   478,   577,
     624,   597,   575,    18,    30,   445,   146,   552,   448,   242,
     217,   145,     3,     4,     5,     6,     7,   521,   552,   589,
      11,    12,   518,   526,   266,    16,   265,   525,   468,   567,
     131,   612,    23,    -1,   304,    -1,    -1,    -1,   478,   433,
      -1,    32,    -1,    -1,    -1,   485,    -1,   628,    -1,    -1,
      -1,    -1,    -1,    -1,   448,    46,    47,    -1,   498,   453,
      -1,    -1,    -1,    -1,    -1,   505,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,   518,    -1,
      -1,   521,    -1,    -1,    -1,   525,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363,    -1,    -1,    -1,   367,   368,   369,
     370,   541,    -1,   637,   498,    -1,   376,   377,    -1,   379,
     563,    -1,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,   567,   398,    11,
      12,   401,   526,    -1,    16,    -1,     7,   577,    -1,    -1,
     534,    23,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,
      -1,   555,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      41,    -1,   612,   613,    45,    -1,    -1,   617,    -1,    -1,
     574,   575,   622,    -1,    -1,    67,    68,    -1,   628,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   637,   468,    -1,
      -1,    -1,    -1,   597,    -1,    -1,   646,    -1,   478,    -1,
      81,    82,    -1,    -1,   654,   485,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,   664,    -1,    97,   667,   498,    -1,
     624,   102,    -1,   104,    -1,   505,    -1,   108,    -1,   633,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,   643,
      -1,   521,    -1,    -1,    -1,   525,    -1,   651,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,   541,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,     1,   552,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,    -1,   163,    -1,    -1,   166,    -1,   567,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    -1,    -1,   577,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   612,   613,    -1,    -1,    -1,   617,   219,    69,
      -1,   222,   622,    -1,    -1,   226,    -1,    -1,   628,    -1,
     231,   232,    -1,    -1,    84,   236,    -1,   637,   239,    89,
      -1,    91,    -1,    93,    -1,    95,   646,    -1,    -1,    99,
      -1,    -1,   253,    -1,    -1,    -1,   106,    -1,   108,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,   292,    -1,    -1,   295,    -1,    -1,   298,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   313,    -1,    -1,   316,   317,    -1,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,     6,     7,   334,    -1,    -1,    -1,   338,    -1,    -1,
     341,   342,   343,    -1,    -1,   346,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     361,    -1,    -1,    -1,    -1,    -1,    -1,   368,   369,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,   399,    -1,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
     411,    -1,    -1,    -1,    89,   416,    91,    -1,    93,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,   108,   435,    -1,    -1,   438,    -1,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   472,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,   487,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,   498,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
     521,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,   534,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,   548,    -1,    -1,
      -1,   552,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   563,    -1,    11,    12,    -1,   568,    -1,    16,
      -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      37,    38,    39,    -1,    -1,    -1,   597,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   637,    84,    -1,    -1,
      -1,    -1,    89,    -1,    91,    -1,    93,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,    -1,   124,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    91,    -1,
      93,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,   108,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,    -1,     6,     7,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,    -1,     6,     7,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,    -1,     6,     7,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,    -1,     6,     7,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,    -1,   124,    -1,     6,     7,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
       6,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,    84,    -1,    -1,    -1,    -1,    89,    -1,    91,    -1,
      93,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    48,   106,    -1,   108,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,     6,    -1,    -1,   122,
      -1,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    91,    -1,    93,    -1,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,   122,    -1,   124,    -1,
      -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,    84,    -1,    -1,    -1,    -1,    89,
      -1,    91,    -1,    93,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,   108,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,   129,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     6,   149,   152,   248,     0,    50,    16,   153,   237,
     250,    36,    51,   151,   250,     7,    11,    12,   238,   239,
     240,   241,   242,   246,   247,    26,    26,   150,    17,   239,
      18,    24,   229,   230,   240,   247,   248,    48,    19,    19,
      14,    53,   154,   155,   250,   148,     1,     6,    84,    89,
      91,    93,    95,    99,   106,   108,   114,   115,   116,   117,
     118,   122,   124,   129,   130,   132,   133,   134,   135,   136,
     137,   138,   139,   156,   157,   163,   247,   249,   250,   254,
      49,    54,   158,   250,   247,    69,    69,    15,     1,   159,
     160,   161,   162,   163,   250,     1,     8,   164,   165,   166,
     169,   227,   247,   249,   148,    69,    69,   161,    15,    60,
      69,    24,   165,    69,     6,    20,    27,    28,    29,    31,
      32,    33,    35,    37,    38,    39,    52,    55,    84,    89,
      91,    93,    95,    99,   106,   108,   114,   115,   116,   117,
     118,   122,   124,   129,   130,   132,   133,   134,   135,   136,
     137,   138,   139,   170,   171,   172,   173,   175,   176,   180,
     181,   182,   184,   185,   186,   190,   191,   192,   193,   194,
     197,   198,   199,   202,   203,   204,   247,   248,   249,   253,
     255,   262,   264,   268,   270,   275,   284,   290,   295,   296,
     297,   298,   299,   304,   308,   317,   319,   321,   322,   323,
     324,   325,   326,   327,   328,    24,   163,   163,   148,    48,
     168,   248,   249,   254,    43,    44,    45,   201,   250,    16,
      30,    30,    34,    59,   148,   215,    34,   148,   215,   148,
      65,    16,    85,   250,   256,   257,    90,   250,   263,    85,
     250,   265,   265,    96,    97,   250,   271,   272,   100,   276,
     107,   172,   174,   247,   172,   172,   172,   172,   119,   250,
     300,    97,    98,   123,   305,   306,   307,     3,     4,     5,
      11,    12,    16,    23,    32,    46,    47,    67,    68,   179,
     228,   229,   231,   233,   234,   235,   243,   244,   245,   316,
     131,   250,   318,    60,   250,   320,   263,   256,    90,   172,
     172,   172,   172,   140,    18,    24,   205,    17,    42,   174,
     187,   188,   189,   247,    17,   187,    36,    51,   172,    22,
      14,    13,   250,   251,   252,   152,   148,    14,   200,   229,
     246,   177,   178,   247,    16,   172,   205,    16,    34,   172,
      16,    34,    16,    66,   177,   174,    86,   250,   258,   174,
     174,    86,   250,   266,   266,    16,    16,    98,   250,   273,
      16,    91,    60,    41,   250,   291,   172,    16,    16,    16,
      16,   307,   306,   232,    11,    12,   125,    16,   172,    16,
     172,   172,   172,    56,    57,    60,    61,   206,   207,   208,
     209,   210,   211,   213,   215,   216,   217,   228,   148,    34,
      40,    41,    17,    15,   251,    42,    17,   172,   172,   172,
     148,   148,    13,   167,   168,    21,    15,    17,    18,   177,
     183,   172,   172,   174,   195,   196,   247,    17,   174,   250,
     259,    87,   250,   260,   174,    92,   250,   267,    94,   250,
     269,   228,   274,   286,   274,    16,   286,   172,    16,   228,
     109,   250,   292,   228,   301,   302,    32,   172,   228,   247,
     248,   288,   289,   288,   288,    10,   309,   310,   311,   316,
     301,   301,   141,   172,   205,    42,    62,    19,    25,    14,
      22,   228,   172,   228,   236,   247,   251,    34,   249,   172,
       9,   178,   179,   229,    17,    17,    15,   251,    16,    88,
     250,   261,   174,   174,    17,    15,    17,   274,    17,    93,
     250,   285,   286,   110,   120,   121,   250,   303,    15,    17,
      14,    15,    17,    17,    17,    15,   228,   312,   313,   126,
      17,    17,   247,   329,    16,   219,   220,   221,   205,   218,
     207,    14,   228,   148,   172,   251,    19,    19,   251,   250,
     287,   288,    16,   228,    17,   172,    17,   111,   112,   113,
     293,   294,   302,   148,   289,   310,   303,    15,   142,    14,
     205,   222,   223,   224,   225,   247,   250,    22,    58,   212,
     214,   228,   189,   174,    17,   287,   101,   250,   277,    15,
     127,   128,   314,   313,   247,   330,    14,    15,    17,    40,
      63,    64,   226,   250,   224,   214,    17,    96,   104,   250,
     282,   294,    61,   143,   331,    14,   223,    16,    16,   315,
     316,   228,   144,   332,    15,   228,   237,   283,    15,   228,
     145,   333,   222,    17,    15,    17,   316,    16,   146,   334,
      17,    96,   250,   278,   237,   288,    16,    34,   102,   250,
     279,   280,    17,   228,    16,   105,   103,   250,   281,    17,
     286,    34,   105,    17,    16,    34,   286,    16,    17,   286,
      17
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
        case 2:

/* Line 1806 of yacc.c  */
#line 458 "core/parse-asn1.y"
    { (yyval.intVal) = myLineNoG; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 463 "core/parse-asn1.y"
    { modulePtrG->tagDefault = (yyvsp[(3) - (3)].intVal); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 468 "core/parse-asn1.y"
    {
         modulePtrG->modId      = (yyvsp[(1) - (8)].moduleId);

         /*
          * Set exported flags in type/value defs as appropriate
          */
         SetExports (modulePtrG, exportListG, exportsParsedG);

         /* clean up */

         /* Free Application tag list */
         FreeApplTags();

         /*
          * Add values defined in any parsed object identifiers.
          * Only the Module name and some macro oids have been parsed,
          * the rest are just "{...}" strings at this point
          * (they will be parsed in later)
          */
         modulePtrG->valueDefs =
             AsnListConcat (modulePtrG->valueDefs, oidElmtValDefsG);

         /*
          * free list head only
          */
         Free (oidElmtValDefsG);
     }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 498 "core/parse-asn1.y"
    { (yyval.intVal) = EXPLICIT_TAGS; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 499 "core/parse-asn1.y"
    { (yyval.intVal) = IMPLICIT_TAGS; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 501 "core/parse-asn1.y"
    {
        /* default is EXPLICIT TAGS */
        (yyval.intVal) = EXPLICIT_TAGS;
    }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 509 "core/parse-asn1.y"
    {
        (yyval.moduleId) = MT (ModuleId);
        (yyval.moduleId)->name = (yyvsp[(1) - (2)].charPtr);
        (yyval.moduleId)->oid = (yyvsp[(2) - (2)].oidPtr);
    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 518 "core/parse-asn1.y"
    { (yyval.oidPtr) = NULL; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 528 "core/parse-asn1.y"
    {
        /*
         *  allows differentiation between "EXPORTS;"
         *         (in which no exports allowed)
         *  and when the EXPORTS symbol does not appear
         *         (then all are exported)
         */
        exportsParsedG = TRUE;
    }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 538 "core/parse-asn1.y"
    {
        PARSE_ERROR();
        exportsParsedG = FALSE;
        exportListG = NULL;
        yyerrok;
    }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 544 "core/parse-asn1.y"
    { exportsParsedG = FALSE; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 548 "core/parse-asn1.y"
    { exportListG = (yyvsp[(1) - (1)].exportList); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 549 "core/parse-asn1.y"
    { exportListG = NULL; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 554 "core/parse-asn1.y"
    {
        (yyval.exportList) = MT (ExportElmt);
        (yyval.exportList)->name = (yyvsp[(1) - (1)].charPtr);
        (yyval.exportList)->lineNo = myLineNoG;
        (yyval.exportList)->next = NULL;
    }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 561 "core/parse-asn1.y"
    {
        (yyval.exportList) = MT (ExportElmt);
        (yyval.exportList)->name = (yyvsp[(4) - (4)].charPtr);
        (yyval.exportList)->next = (yyvsp[(1) - (4)].exportList);
        (yyval.exportList)->lineNo = (yyvsp[(3) - (4)].intVal);
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 572 "core/parse-asn1.y"
    {
       PARSE_ERROR();
       yyerrok;
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 580 "core/parse-asn1.y"
    { modulePtrG->imports = (yyvsp[(1) - (1)].importModuleListPtr); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 586 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(2) - (2)].importModulePtr),(yyvsp[(1) - (2)].importModuleListPtr));
    }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 590 "core/parse-asn1.y"
    {
        (yyval.importModuleListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].importModulePtr), (yyval.importModuleListPtr));
    }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 598 "core/parse-asn1.y"
    {
        (yyval.importModulePtr) = MT (ImportModule);
        (yyval.importModulePtr)->modId   = (yyvsp[(4) - (4)].moduleId);
        (yyval.importModulePtr)->lineNo = (yyvsp[(3) - (4)].intVal);
        (yyval.importModulePtr)->importElmts = (yyvsp[(1) - (4)].importElmtListPtr);
    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 609 "core/parse-asn1.y"
    {
        ImportElmt *ie;

        ie = MT (ImportElmt);
        ie->name = (yyvsp[(3) - (3)].charPtr);
        ie->lineNo = myLineNoG;
        APPEND (ie, (yyvsp[(1) - (3)].importElmtListPtr));
        (yyval.importElmtListPtr) = (yyvsp[(1) - (3)].importElmtListPtr);
    }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 619 "core/parse-asn1.y"
    {
        ImportElmt *ie;

        /* called for the first element only, so create list head */
        (yyval.importElmtListPtr) = NEWLIST();
        ie = MT (ImportElmt);
        ie->name = (yyvsp[(1) - (1)].charPtr);
        ie->lineNo = myLineNoG;
        APPEND (ie, (yyval.importElmtListPtr));
    }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 635 "core/parse-asn1.y"
    {
        /*
         * hack to make DefinedMacroNames "freeable"
         * like idents and typeref
         */
        (yyval.charPtr) = Malloc (strlen ((yyvsp[(1) - (1)].charPtr))+1);
        strcpy ((yyval.charPtr), (yyvsp[(1) - (1)].charPtr));
    }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 656 "core/parse-asn1.y"
    {
        PARSE_ERROR();
        yyerrok;
    }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 664 "core/parse-asn1.y"
    {
        /*
         * a macro may produce a null type
         */
        if ((yyvsp[(1) - (1)].typeDefPtr) != NULL)
        {
            /*
             * add to head of  type def list
             */
            APPEND ((yyvsp[(1) - (1)].typeDefPtr), modulePtrG->typeDefs);
        }

    }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 678 "core/parse-asn1.y"
    {
        /*
         * a macro may produce a null value
         */
        if ((yyvsp[(1) - (1)].valueDefPtr) != NULL)
        {
            /*
             * add to head of value def list
             */
            APPEND ((yyvsp[(1) - (1)].valueDefPtr), modulePtrG->valueDefs);
        }
    }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 690 "core/parse-asn1.y"
    { LexBeginMacroDefContext(); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 692 "core/parse-asn1.y"
    {
        TypeDef *tmpTypeDef;

        /*
         *  LEXICAL TIE IN!!
         * create macro type to eliminate import resolution
         * errors msgs from other modules importing the macro.
         * (hopefully) Only the import list will link with
         * these type defs.
         * keeps macro def around incase of future processing needs
         *
         * NOTE: MACRODEFBODY_SYM returns the macro def body with
         * with "BEGIN" at the begininning and "END" at the end
         */

        /*
         * put lexical analyzer back in normal state
         */
        /*  BEGIN (INITIAL);  */
        LexBeginInitialContext();

        tmpTypeDef = MT (TypeDef);
        SetupType (&tmpTypeDef->type, BASICTYPE_MACRODEF, (yyvsp[(4) - (6)].intVal));
        tmpTypeDef->definedName = (yyvsp[(1) - (6)].charPtr);

        /*
         * keeps the macro def body
         * (all text between & including the BEGIN and END)
         * as a simple string - incase you want to fart around with
         * it.
         */
        tmpTypeDef->type->basicType->a.macroDef = (yyvsp[(6) - (6)].charPtr);

        /*
         * put in type list
         */
        APPEND (tmpTypeDef, modulePtrG->typeDefs);

    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 732 "core/parse-asn1.y"
    {
        TypeDef *tmpTypeDef;

        tmpTypeDef = MT (TypeDef);
        SetupType (&tmpTypeDef->type, BASICTYPE_MACRODEF, myLineNoG);
        tmpTypeDef->definedName = (yyvsp[(1) - (3)].charPtr);

        tmpTypeDef->type->basicType->a.macroDef = (yyvsp[(3) - (3)].charPtr);

        /*
         * put in type list
         */
        APPEND (tmpTypeDef, modulePtrG->typeDefs);

    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 748 "core/parse-asn1.y"
    {
        TypeDef *tmpTypeDef;

        tmpTypeDef = MT (TypeDef);
        SetupType (&tmpTypeDef->type, BASICTYPE_MACRODEF, myLineNoG);
        tmpTypeDef->definedName = (yyvsp[(1) - (5)].charPtr);

        tmpTypeDef->type->basicType->a.macroDef =
               (MyString) Malloc (strlen ((yyvsp[(3) - (5)].charPtr)) + strlen ((yyvsp[(5) - (5)].charPtr)) + 2);

        strcpy (tmpTypeDef->type->basicType->a.macroDef, (yyvsp[(3) - (5)].charPtr));
        strcat (tmpTypeDef->type->basicType->a.macroDef, ".");
        strcat (tmpTypeDef->type->basicType->a.macroDef, (yyvsp[(5) - (5)].charPtr));

       /*
         * put in type list
         */
        APPEND (tmpTypeDef, modulePtrG->typeDefs);

        Free ((yyvsp[(3) - (5)].charPtr));
        Free ((yyvsp[(5) - (5)].charPtr));
    }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 783 "core/parse-asn1.y"
    {
        /*
         * a macro type may produce a null type
         */
        if ((yyvsp[(5) - (6)].typePtr) != NULL)
        {
            (yyval.typeDefPtr) = MT (TypeDef);
            (yyval.typeDefPtr)->type =  (yyvsp[(5) - (6)].typePtr);
            (yyval.typeDefPtr)->type->lineNo = (yyvsp[(4) - (6)].intVal);
            (yyval.typeDefPtr)->type->attrList = (yyvsp[(6) - (6)].attrList);
            (yyval.typeDefPtr)->definedName = (yyvsp[(1) - (6)].charPtr);
            (yyval.typeDefPtr)->attrList = (yyvsp[(3) - (6)].attrList);
        }
        else
            (yyval.typeDefPtr) = NULL;
    }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 804 "core/parse-asn1.y"
    {
        /* allocate a Type with basic type of ImportTypeRef */
        SetupType (&(yyval.typePtr), BASICTYPE_IMPORTTYPEREF, (yyvsp[(3) - (4)].intVal));
        (yyval.typePtr)->basicType->a.importTypeRef = MT (TypeRef);
        (yyval.typePtr)->basicType->a.importTypeRef->typeName = (yyvsp[(4) - (4)].charPtr);
        (yyval.typePtr)->basicType->a.importTypeRef->moduleName = (yyvsp[(1) - (4)].charPtr);

        /* add entry to this module's import list */
        AddPrivateImportElmt (modulePtrG, (yyvsp[(4) - (4)].charPtr), (yyvsp[(1) - (4)].charPtr), (yyvsp[(3) - (4)].intVal));
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 818 "core/parse-asn1.y"
    { (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 820 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_LOCALTYPEREF, myLineNoG);
        (yyval.typePtr)->basicType->a.localTypeRef = MT (TypeRef);
        (yyval.typePtr)->basicType->a.localTypeRef->typeName = (yyvsp[(1) - (1)].charPtr);
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 853 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_OCTETSTRING, myLineNoG);
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 860 "core/parse-asn1.y"
    {
        (yyval.namedTypePtr) = MT (NamedType);
        (yyval.namedTypePtr)->type = (yyvsp[(2) - (2)].typePtr);
        (yyval.namedTypePtr)->fieldName = (yyvsp[(1) - (2)].charPtr);
    }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 866 "core/parse-asn1.y"
    {
        (yyval.namedTypePtr) = MT (NamedType);
        (yyval.namedTypePtr)->type = (yyvsp[(1) - (1)].typePtr);
    }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 874 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_BOOLEAN, myLineNoG);
    }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 881 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_INTEGER, myLineNoG);
        (yyval.typePtr)->basicType->a.integer = NEWLIST();  /* empty list */
    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 886 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_INTEGER, myLineNoG);
        (yyval.typePtr)->basicType->a.integer = (yyvsp[(3) - (4)].valueDefListPtr);
    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 895 "core/parse-asn1.y"
    {
        (yyval.valueDefListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].valueDefPtr), (yyval.valueDefListPtr));
    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 900 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(3) - (3)].valueDefPtr),(yyvsp[(1) - (3)].valueDefListPtr));
        (yyval.valueDefListPtr) = (yyvsp[(1) - (3)].valueDefListPtr);
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 908 "core/parse-asn1.y"
    {
        (yyval.valueDefPtr) = MT (ValueDef);
        (yyval.valueDefPtr)->definedName = (yyvsp[(1) - (4)].charPtr);
        SetupValue (&(yyval.valueDefPtr)->value, BASICVALUE_INTEGER, myLineNoG);
        (yyval.valueDefPtr)->value->basicValue->a.integer = (yyvsp[(3) - (4)].intVal);
    }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 915 "core/parse-asn1.y"
    {
        (yyval.valueDefPtr) = MT (ValueDef);
        (yyval.valueDefPtr)->definedName = (yyvsp[(1) - (4)].charPtr);
        (yyval.valueDefPtr)->value = (yyvsp[(3) - (4)].valuePtr);
    }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 924 "core/parse-asn1.y"
    {
	if ((yyvsp[(1) - (1)].uintVal)>0x7FFFFFFF) {
	    yyerror("Warning: positive signed number out of range");
	    (yyval.intVal) = 0x7FFFFFFF;
	}
    }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 931 "core/parse-asn1.y"
    {
	yyerror ("Warning: positive signed number out of range");
	(yyval.intVal) = 0x7FFFFFFF;
	/* modulePtrG->status = MOD_ERROR; */
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 937 "core/parse-asn1.y"
    {
	if ((yyvsp[(2) - (2)].uintVal)>0x80000000) {
	    yyerror("Warning: negative signed number out of range");
	    (yyval.intVal) = -0x80000000;
	} else if ((yyvsp[(2) - (2)].uintVal)==0x80000000) {
	    (yyval.intVal) = -0x80000000;
	} else {
	    (yyval.intVal) = -(yyvsp[(2) - (2)].uintVal);
	}
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 948 "core/parse-asn1.y"
    {
	yyerror ("Warning: negative signed number out of range");
	(yyval.intVal) = -0x80000000;
	/* modulePtrG->status = MOD_ERROR; */
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 957 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_ENUMERATED, myLineNoG);
        (yyval.typePtr)->basicType->a.enumerated = (yyvsp[(3) - (4)].valueDefListPtr);
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 966 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_REAL, myLineNoG);
    }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 973 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_BITSTRING, myLineNoG);
        (yyval.typePtr)->basicType->a.bitString = NEWLIST(); /* empty list */
    }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 978 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_BITSTRING, myLineNoG);
        (yyval.typePtr)->basicType->a.bitString = (yyvsp[(4) - (5)].valueDefListPtr);
    }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 992 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_NULL, myLineNoG);
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 999 "core/parse-asn1.y"
    { (yyval.intVal) = (yyvsp[(2) - (3)].intVal); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1004 "core/parse-asn1.y"
    {
        NamedType *n;

        SetupType (&(yyval.typePtr), BASICTYPE_SEQUENCE, (yyvsp[(1) - (3)].intVal));

        if (AsnListCount ((AsnList*)(yyvsp[(2) - (3)].namedTypeListPtr)) != 0)
        {
            n = (NamedType*) FIRST_LIST_ELMT ((AsnList*)(yyvsp[(2) - (3)].namedTypeListPtr));
            n->type->lineNo = (yyvsp[(1) - (3)].intVal);
        }

        (yyval.typePtr)->basicType->a.sequence = (yyvsp[(2) - (3)].namedTypeListPtr);

    }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1019 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_SEQUENCE, (yyvsp[(1) - (2)].intVal));

        /* set up empty list for SEQ with no elmts */
        (yyval.typePtr)->basicType->a.sequence = AsnListNew (sizeof (void*));
    }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1034 "core/parse-asn1.y"
    {
        NamedType *lastElmt;

        if ((yyvsp[(2) - (2)].attrList) != NULL)
        {
            lastElmt = (NamedType*)LAST_LIST_ELMT ((yyvsp[(1) - (2)].namedTypeListPtr));
            lastElmt->type->attrList = (yyvsp[(2) - (2)].attrList);
        }
        (yyval.namedTypeListPtr) = (yyvsp[(1) - (2)].namedTypeListPtr);
    }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1048 "core/parse-asn1.y"
    {
        (yyval.namedTypeListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].namedTypePtr),(yyval.namedTypeListPtr));
    }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1053 "core/parse-asn1.y"
    {
        NamedType *lastElmt;

        if ((yyvsp[(3) - (5)].attrList) != NULL)
        {
            lastElmt = (NamedType*)LAST_LIST_ELMT ((yyvsp[(1) - (5)].namedTypeListPtr));
            lastElmt->type->attrList = (yyvsp[(3) - (5)].attrList);
        }

       APPEND ((yyvsp[(5) - (5)].namedTypePtr), (yyvsp[(1) - (5)].namedTypeListPtr));
       lastElmt = (NamedType*)LAST_LIST_ELMT ((yyvsp[(1) - (5)].namedTypeListPtr));
       lastElmt->type->lineNo = (yyvsp[(4) - (5)].intVal);
       (yyval.namedTypeListPtr) = (yyvsp[(1) - (5)].namedTypeListPtr);
    }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1072 "core/parse-asn1.y"
    {
        (yyval.namedTypePtr) = (yyvsp[(1) - (2)].namedTypePtr);
        (yyval.namedTypePtr)->type->optional = TRUE;
    }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1077 "core/parse-asn1.y"
    {
        /*
         * this rules uses NamedValue instead of Value
         * for the stupid choice value syntax (fieldname value)
         * it should be like a set/seq value (ie with
         * enclosing { }
         */
        (yyval.namedTypePtr) = (yyvsp[(1) - (3)].namedTypePtr);
        (yyval.namedTypePtr)->type->defaultVal = (yyvsp[(3) - (3)].namedValuePtr);
        /*
         * could link value to the elmt type here (done in link_types.c)
         */
    }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1091 "core/parse-asn1.y"
    {
        (yyval.namedTypePtr) = MT (NamedType);
        SetupType (&(yyval.namedTypePtr)->type, BASICTYPE_COMPONENTSOF, myLineNoG);
        (yyval.namedTypePtr)->type->basicType->a.componentsOf = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1097 "core/parse-asn1.y"
    {
        (yyval.namedTypePtr) = MT (NamedType);
        SetupType (&(yyval.namedTypePtr)->type, BASICTYPE_COMPONENTSOF, myLineNoG);
        (yyval.namedTypePtr)->fieldName = (yyvsp[(1) - (4)].charPtr);
        (yyval.namedTypePtr)->type->basicType->a.componentsOf = (yyvsp[(4) - (4)].typePtr);
    }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1109 "core/parse-asn1.y"
    {
        NamedType *n;

        /* does not use SEQUENCE == SEQ OF ANY abrev*/
        SetupType (&(yyval.typePtr), BASICTYPE_SEQUENCEOF, myLineNoG);

        /* grab line number from first elmt */
        if ((yyvsp[(3) - (3)].typePtr) != NULL)
            (yyval.typePtr)->lineNo = (yyvsp[(3) - (3)].typePtr)->lineNo - 1;

        (yyval.typePtr)->basicType->a.sequenceOf = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1124 "core/parse-asn1.y"
    { (yyval.intVal) = (yyvsp[(2) - (3)].intVal); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1129 "core/parse-asn1.y"
    {
        NamedType *n;

        SetupType (&(yyval.typePtr), BASICTYPE_SET, (yyvsp[(1) - (3)].intVal));

        /* reset first elmt's line number */
        if (AsnListCount ((AsnList*)(yyvsp[(2) - (3)].namedTypeListPtr)) != 0)
        {
            n = (NamedType*)FIRST_LIST_ELMT ((AsnList*)(yyvsp[(2) - (3)].namedTypeListPtr));
            n->type->lineNo = (yyvsp[(1) - (3)].intVal);
        }
        (yyval.typePtr)->basicType->a.set = (yyvsp[(2) - (3)].namedTypeListPtr);
    }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1143 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_SET, (yyvsp[(1) - (2)].intVal));

        /* set up empty elmt list for SET */
        (yyval.typePtr)->basicType->a.set = AsnListNew (sizeof (void*));
    }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1159 "core/parse-asn1.y"
    {
       /* does not allow SET == SET OF ANY Abrev */
        SetupType (&(yyval.typePtr), BASICTYPE_SETOF, myLineNoG);

        if ((yyvsp[(3) - (3)].typePtr) != NULL)
            (yyval.typePtr)->lineNo = (yyvsp[(3) - (3)].typePtr)->lineNo;

        (yyval.typePtr)->basicType->a.setOf = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1173 "core/parse-asn1.y"
    {
        NamedType *n;

        SetupType (&(yyval.typePtr), BASICTYPE_CHOICE, (yyvsp[(2) - (5)].intVal));

        (yyval.typePtr)->basicType->a.choice = (yyvsp[(4) - (5)].namedTypeListPtr);

        if (AsnListCount ((yyvsp[(4) - (5)].namedTypeListPtr)) != 0)
        {
            n = (NamedType*)FIRST_LIST_ELMT ((yyvsp[(4) - (5)].namedTypeListPtr));
            n->type->lineNo = (yyvsp[(2) - (5)].intVal);
        }
    }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1190 "core/parse-asn1.y"
    {
        NamedType *lastElmt;
        if ((yyvsp[(2) - (2)].attrList) != NULL)
        {
            lastElmt = (NamedType*)LAST_LIST_ELMT ((yyvsp[(1) - (2)].namedTypeListPtr));
            lastElmt->type->attrList = (yyvsp[(2) - (2)].attrList);
        }
        (yyval.namedTypeListPtr) = (yyvsp[(1) - (2)].namedTypeListPtr);
    }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1203 "core/parse-asn1.y"
    {
        (yyval.namedTypeListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].namedTypePtr), (yyval.namedTypeListPtr));
    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1208 "core/parse-asn1.y"
    {
        NamedType *lastElmt;

        if ((yyvsp[(3) - (4)].attrList) != NULL)
        {
            lastElmt = (NamedType*)LAST_LIST_ELMT ((yyvsp[(1) - (4)].namedTypeListPtr));
            lastElmt->type->attrList = (yyvsp[(3) - (4)].attrList);
        }
        APPEND ((yyvsp[(4) - (4)].namedTypePtr),(yyvsp[(1) - (4)].namedTypeListPtr));
        (yyval.namedTypeListPtr) = (yyvsp[(1) - (4)].namedTypeListPtr);
    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1224 "core/parse-asn1.y"
    {
        /*
         * the selection type should be replaced after
         * link with actual type
         */
        SetupType (&(yyval.typePtr), BASICTYPE_SELECTION, myLineNoG);

        (yyval.typePtr)->basicType->a.selection = MT (SelectionType);
        (yyval.typePtr)->basicType->a.selection->typeRef = (yyvsp[(3) - (3)].typePtr);
        (yyval.typePtr)->basicType->a.selection->fieldName = (yyvsp[(1) - (3)].charPtr);
    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1239 "core/parse-asn1.y"
    {
        Tag *tag;

        /* remove next tag if any  && IMPLICIT_TAGS */
 	if ((modulePtrG->tagDefault == IMPLICIT_TAGS) &&
            ((yyvsp[(2) - (2)].typePtr)->tags != NULL) && !LIST_EMPTY ((yyvsp[(2) - (2)].typePtr)->tags))
        {
            tag = (Tag*)FIRST_LIST_ELMT ((yyvsp[(2) - (2)].typePtr)->tags); /* set curr to first */
	    AsnListFirst ((yyvsp[(2) - (2)].typePtr)->tags); /* set curr to first elmt */
            AsnListRemove ((yyvsp[(2) - (2)].typePtr)->tags);      /* remove first elmt */

            /*
             * set implicit if implicitly tagged built in type (ie not ref)
             * (this simplifies the module ASN.1 printer (print.c))
             */
            if (tag->tclass == UNIV)
                 (yyvsp[(2) - (2)].typePtr)->implicit = TRUE;

            Free (tag);
        }

        PREPEND ((yyvsp[(1) - (2)].tagPtr), (yyvsp[(2) - (2)].typePtr)->tags);
        (yyval.typePtr) = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1264 "core/parse-asn1.y"
    {
        Tag *tag;

        /* remove next tag if any */
 	if (((yyvsp[(3) - (3)].typePtr)->tags != NULL) && !LIST_EMPTY ((yyvsp[(3) - (3)].typePtr)->tags))
        {
            tag = (Tag*)FIRST_LIST_ELMT ((yyvsp[(3) - (3)].typePtr)->tags); /* set curr to first */
	    AsnListFirst ((yyvsp[(3) - (3)].typePtr)->tags); /* set curr to first elmt */
            AsnListRemove ((yyvsp[(3) - (3)].typePtr)->tags);      /* remove first elmt */

            if (tag->tclass == UNIV)
                 (yyvsp[(3) - (3)].typePtr)->implicit = TRUE;

            Free (tag);
        }

        /*
         * must check after linking that implicitly tagged
         * local/import type refs are not untagged choice/any etc
         */
        else if (((yyvsp[(3) - (3)].typePtr)->basicType->choiceId == BASICTYPE_IMPORTTYPEREF) ||
                 ((yyvsp[(3) - (3)].typePtr)->basicType->choiceId == BASICTYPE_LOCALTYPEREF) ||
                 ((yyvsp[(3) - (3)].typePtr)->basicType->choiceId == BASICTYPE_SELECTION))
            (yyvsp[(3) - (3)].typePtr)->implicit = TRUE;

        /*
         *  all other implicitly tagable types should have tags
         *  to remove - if this else clause fires then it is
         *  probably a CHOICE or ANY type
         */
        else
        {
            PrintErrLoc (modulePtrG->asn1SrcFileName, (yyvsp[(3) - (3)].typePtr)->lineNo);
            fprintf (stderr, "ERROR - attempt to implicitly reference untagged type\n");
            smallErrG = 1;
        }

        PREPEND ((yyvsp[(1) - (3)].tagPtr), (yyvsp[(3) - (3)].typePtr)->tags);
        (yyval.typePtr) = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1305 "core/parse-asn1.y"
    {
        /* insert tag at head of list */
        (yyvsp[(1) - (3)].tagPtr)->explicit = TRUE;
        PREPEND ((yyvsp[(1) - (3)].tagPtr), (yyvsp[(3) - (3)].typePtr)->tags);
        (yyval.typePtr) = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1315 "core/parse-asn1.y"
    {
        (yyval.tagPtr) = (yyvsp[(3) - (4)].tagPtr);
        (yyval.tagPtr)->tclass = (yyvsp[(2) - (4)].intVal);
        (yyval.tagPtr)->explicit = FALSE; /* default to false */

        /*
         *  keep track of APPLICATION Tags per module
         *  should only be used once
         */
        if ((yyvsp[(2) - (4)].intVal) == APPL)
        {
            PushApplTag ((yyval.tagPtr)->code, myLineNoG);
        }
    }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1333 "core/parse-asn1.y"
    {
        (yyval.tagPtr) = MT (Tag);
        (yyval.tagPtr)->code = (yyvsp[(1) - (1)].intVal);
    }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1338 "core/parse-asn1.y"
    {
        (yyval.tagPtr) = MT (Tag);
        (yyval.tagPtr)->code = NO_TAG_CODE;
        (yyval.tagPtr)->valueRef = (yyvsp[(1) - (1)].valuePtr);
    }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1346 "core/parse-asn1.y"
    { (yyval.intVal) = UNIV; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1347 "core/parse-asn1.y"
    { (yyval.intVal) = APPL; }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1348 "core/parse-asn1.y"
    { (yyval.intVal) = PRIV; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1349 "core/parse-asn1.y"
    { (yyval.intVal) = CNTX; }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1355 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_ANY, myLineNoG);
    }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1359 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_ANYDEFINEDBY, myLineNoG);
        (yyval.typePtr)->basicType->a.anyDefinedBy = MT (AnyDefinedByType);
        (yyval.typePtr)->basicType->a.anyDefinedBy->fieldName = (yyvsp[(4) - (4)].charPtr);
    }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1369 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_OID, myLineNoG);
    }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1377 "core/parse-asn1.y"
    {
        /*
         * append new subtype list to existing one (s) if any
         * with AND relation
         */
        AppendSubtype (&(yyvsp[(1) - (2)].typePtr)->subtypes, (yyvsp[(2) - (2)].subtypePtr), SUBTYPE_AND);
        (yyval.typePtr) = (yyvsp[(1) - (2)].typePtr);
    }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1386 "core/parse-asn1.y"
    {
        Subtype *s;

        SetupType (&(yyval.typePtr), BASICTYPE_SETOF, myLineNoG);
        (yyval.typePtr)->basicType->a.setOf = (yyvsp[(4) - (4)].typePtr);

        /* add size constraint */
        s = MT (Subtype);
        s->choiceId = SUBTYPE_SINGLE;
        s->a.single = (yyvsp[(2) - (4)].subtypeValuePtr);
        AppendSubtype (&(yyval.typePtr)->subtypes, s, SUBTYPE_AND);
    }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1399 "core/parse-asn1.y"
    {
        Subtype *s;

        SetupType (&(yyval.typePtr), BASICTYPE_SEQUENCEOF, myLineNoG);
        (yyval.typePtr)->basicType->a.sequenceOf = (yyvsp[(4) - (4)].typePtr);

        /* add size constraint */
        s = MT (Subtype);
        s->choiceId = SUBTYPE_SINGLE;
        s->a.single = (yyvsp[(2) - (4)].subtypeValuePtr);
        AppendSubtype (&(yyval.typePtr)->subtypes, s, SUBTYPE_AND);
    }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1416 "core/parse-asn1.y"
    {
        (yyval.subtypePtr) = (yyvsp[(2) - (3)].subtypePtr);
    }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1423 "core/parse-asn1.y"
    {
        Subtype *s;

        /* OR relation between all elmts of in  ValueSetList */

        (yyval.subtypePtr) = MT (Subtype);
        (yyval.subtypePtr)->choiceId = SUBTYPE_OR;
        (yyval.subtypePtr)->a.or = NEWLIST();

        s = MT (Subtype);
        s->choiceId = SUBTYPE_SINGLE;
        s->a.single = (yyvsp[(1) - (1)].subtypeValuePtr);
        APPEND (s, (yyval.subtypePtr)->a.or);
    }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1438 "core/parse-asn1.y"
    {
        Subtype *s;
        s = MT (Subtype);
        s->choiceId = SUBTYPE_SINGLE;
        s->a.single = (yyvsp[(3) - (3)].subtypeValuePtr);
        APPEND (s, (yyvsp[(1) - (3)].subtypePtr)->a.or);
        (yyval.subtypePtr) = (yyvsp[(1) - (3)].subtypePtr);
    }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1460 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_SINGLEVALUE;
        (yyval.subtypeValuePtr)->a.singleValue = (yyvsp[(1) - (1)].valuePtr);
    }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1468 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_CONTAINED;
        (yyval.subtypeValuePtr)->a.contained = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1477 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_VALUERANGE;
        (yyval.subtypeValuePtr)->a.valueRange = MT (ValueRangeSubtype);
        (yyval.subtypeValuePtr)->a.valueRange->lowerEndInclusive =
            valueRangeLowerEndInclusiveG;
        (yyval.subtypeValuePtr)->a.valueRange->upperEndInclusive =
            valueRangeUpperEndInclusiveG;
        (yyval.subtypeValuePtr)->a.valueRange->lowerEndValue  = (yyvsp[(1) - (4)].valuePtr);
        (yyval.subtypeValuePtr)->a.valueRange->upperEndValue = (yyvsp[(4) - (4)].valuePtr);
    }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1492 "core/parse-asn1.y"
    {
       (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr);
       valueRangeLowerEndInclusiveG = TRUE;
    }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1497 "core/parse-asn1.y"
    {
       (yyval.valuePtr) = (yyvsp[(1) - (2)].valuePtr);
       valueRangeLowerEndInclusiveG = FALSE;
    }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1505 "core/parse-asn1.y"
    {
       (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr);
       valueRangeUpperEndInclusiveG = TRUE;
    }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1510 "core/parse-asn1.y"
    {
       (yyval.valuePtr) = (yyvsp[(2) - (2)].valuePtr);
       valueRangeUpperEndInclusiveG = FALSE;
    }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1517 "core/parse-asn1.y"
    { (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1519 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_SPECIALINTEGER, myLineNoG);
        (yyval.valuePtr)->basicValue->a.specialInteger =  MIN_INT;
    }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1526 "core/parse-asn1.y"
    { (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1528 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_SPECIALINTEGER, myLineNoG);
        (yyval.valuePtr)->basicValue->a.specialInteger =  MAX_INT;
    }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1536 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_SIZECONSTRAINT;
        (yyval.subtypeValuePtr)->a.sizeConstraint = (yyvsp[(2) - (2)].subtypePtr);
    }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1546 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_PERMITTEDALPHABET;
        (yyval.subtypeValuePtr)->a.permittedAlphabet = (yyvsp[(2) - (2)].subtypePtr);
    }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1555 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_INNERSUBTYPE;
        (yyval.subtypeValuePtr)->a.innerSubtype = (yyvsp[(3) - (3)].innerSubtypePtr);
    }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1561 "core/parse-asn1.y"
    {
        (yyval.subtypeValuePtr) = MT (SubtypeValue);
        (yyval.subtypeValuePtr)->choiceId = SUBTYPEVALUE_INNERSUBTYPE;
        (yyval.subtypeValuePtr)->a.innerSubtype = (yyvsp[(3) - (3)].innerSubtypePtr);
    }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1570 "core/parse-asn1.y"
    {
        Constraint *constraint;

        /* this constrains the elmt of setof or seq of */
        (yyval.innerSubtypePtr) = MT (InnerSubtype);
        (yyval.innerSubtypePtr)->constraintType = SINGLE_CT;
        (yyval.innerSubtypePtr)->constraints = NEWLIST();
        constraint = MT (Constraint);
        APPEND (constraint, (yyval.innerSubtypePtr)->constraints);
        constraint->valueConstraints = (yyvsp[(1) - (1)].subtypePtr);
    }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1590 "core/parse-asn1.y"
    {
        (yyval.innerSubtypePtr) = MT (InnerSubtype);
        (yyval.innerSubtypePtr)->constraintType = FULL_CT;
        (yyval.innerSubtypePtr)->constraints = (yyvsp[(2) - (3)].constraintListPtr);
    }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1599 "core/parse-asn1.y"
    {
        (yyval.innerSubtypePtr) = MT (InnerSubtype);
        (yyval.innerSubtypePtr)->constraintType = PARTIAL_CT;
        (yyval.innerSubtypePtr)->constraints = (yyvsp[(6) - (7)].constraintListPtr);
    }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1609 "core/parse-asn1.y"
    {
        (yyval.constraintListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].constraintPtr), (yyval.constraintListPtr));
    }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1614 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(3) - (3)].constraintPtr), (yyvsp[(1) - (3)].constraintListPtr));
        (yyval.constraintListPtr) = (yyvsp[(1) - (3)].constraintListPtr);
    }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1622 "core/parse-asn1.y"
    {
        (yyval.constraintPtr) = (yyvsp[(2) - (2)].constraintPtr);
        (yyval.constraintPtr)->fieldRef = (yyvsp[(1) - (2)].charPtr);
    }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1632 "core/parse-asn1.y"
    {
        (yyval.constraintPtr) = MT (Constraint);
        (yyval.constraintPtr)->presenceConstraint = (yyvsp[(2) - (2)].intVal);
        (yyval.constraintPtr)->valueConstraints = (yyvsp[(1) - (2)].subtypePtr);
    }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1640 "core/parse-asn1.y"
    { (yyval.subtypePtr) = (yyvsp[(1) - (1)].subtypePtr); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1641 "core/parse-asn1.y"
    { (yyval.subtypePtr) = NULL; }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1645 "core/parse-asn1.y"
    { (yyval.intVal) = PRESENT_CT; }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1646 "core/parse-asn1.y"
    { (yyval.intVal) = ABSENT_CT; }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1647 "core/parse-asn1.y"
    { (yyval.intVal) = EMPTY_CT; }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1648 "core/parse-asn1.y"
    { (yyval.intVal) = OPTIONAL_CT; }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1662 "core/parse-asn1.y"
    {
        (yyval.valueDefPtr) = MT (ValueDef);
        (yyval.valueDefPtr)->definedName = (yyvsp[(1) - (5)].charPtr);
        (yyval.valueDefPtr)->value = (yyvsp[(5) - (5)].valuePtr);
        (yyval.valueDefPtr)->value->lineNo = (yyvsp[(4) - (5)].intVal);
        (yyval.valueDefPtr)->value->type = (yyvsp[(2) - (5)].typePtr);
    }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1678 "core/parse-asn1.y"
    { (yyval.valuePtr) =  (yyvsp[(1) - (1)].valuePtr); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1680 "core/parse-asn1.y"
    {
        /*
         * for parse, may be set to BASICVALUE_IMPORTEDTYPEREF
         * by linker
         */
        SetupValue (&(yyval.valuePtr), BASICVALUE_LOCALVALUEREF, myLineNoG);
        (yyval.valuePtr)->basicValue->a.localValueRef = MT (ValueRef);
        (yyval.valuePtr)->basicValue->a.localValueRef->valueName = (yyvsp[(1) - (1)].charPtr);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
   }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1694 "core/parse-asn1.y"
    {
        /* Alloc value with basicValue of importValueRef */
        SetupValue (&(yyval.valuePtr), BASICVALUE_IMPORTVALUEREF, (yyvsp[(3) - (4)].intVal));
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.importValueRef = MT (ValueRef);
        (yyval.valuePtr)->basicValue->a.importValueRef->valueName = (yyvsp[(4) - (4)].charPtr);
        (yyval.valuePtr)->basicValue->a.importValueRef->moduleName = (yyvsp[(1) - (4)].charPtr);

        /* add entry to this module's import list */
        AddPrivateImportElmt (modulePtrG, (yyvsp[(4) - (4)].charPtr), (yyvsp[(1) - (4)].charPtr), (yyvsp[(3) - (4)].intVal));
    }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1712 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_INTEGER, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.integer = (yyvsp[(1) - (1)].intVal);
    }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1718 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_ASCIIHEX, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.asciiHex = MT (AsnOcts);
        (yyval.valuePtr)->basicValue->a.asciiHex->octs = (yyvsp[(1) - (1)].charPtr);
        (yyval.valuePtr)->basicValue->a.asciiHex->octetLen = strlen ((yyvsp[(1) - (1)].charPtr));
    }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1726 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_ASCIIBITSTRING, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.asciiBitString = MT (AsnOcts);
        (yyval.valuePtr)->basicValue->a.asciiBitString->octs = (yyvsp[(1) - (1)].charPtr);
        (yyval.valuePtr)->basicValue->a.asciiBitString->octetLen = strlen ((yyvsp[(1) - (1)].charPtr));
    }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1734 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_ASCIITEXT, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.asciiText = MT (AsnOcts);
        (yyval.valuePtr)->basicValue->a.asciiText->octs = (yyvsp[(1) - (1)].charPtr);
        (yyval.valuePtr)->basicValue->a.asciiText->octetLen = strlen ((yyvsp[(1) - (1)].charPtr));
    }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1741 "core/parse-asn1.y"
    { LexBeginBraceBalContext(); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1742 "core/parse-asn1.y"
    {
        /*
         *  LEXICAL TIE IN!!
         * string returned by BRACEBAL_SYM has
         * the $1 '{' prepended and includes everything
         * upto and including '}' that balances $1
         */
        LexBeginInitialContext();
        SetupValue (&(yyval.valuePtr), BASICVALUE_VALUENOTATION, myLineNoG);
        (yyval.valuePtr)->basicValue->a.valueNotation = MT (AsnOcts);
        (yyval.valuePtr)->basicValue->a.valueNotation->octs = (yyvsp[(3) - (3)].charPtr);
        (yyval.valuePtr)->basicValue->a.valueNotation->octetLen = strlen ((yyvsp[(3) - (3)].charPtr));
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
    }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1760 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_BOOLEAN, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.boolean =  TRUE;
    }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1766 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_BOOLEAN, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.boolean = FALSE;
    }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1776 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_SPECIALREAL, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.specialReal =  PLUS_INFINITY_REAL;
    }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1782 "core/parse-asn1.y"
    {
        SetupValue (&(yyval.valuePtr), BASICVALUE_SPECIALREAL, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
        (yyval.valuePtr)->basicValue->a.specialReal = MINUS_INFINITY_REAL;
    }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1793 "core/parse-asn1.y"
    {
        /* create a NULL value  */
        SetupValue (&(yyval.valuePtr), BASICVALUE_NULL, myLineNoG);
        (yyval.valuePtr)->valueType = BASICTYPE_UNKNOWN;
    }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1803 "core/parse-asn1.y"
    {
        (yyval.namedValuePtr) = MT (NamedValue);
        (yyval.namedValuePtr)->value = (yyvsp[(1) - (1)].valuePtr);
    }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1808 "core/parse-asn1.y"
    {
        (yyval.namedValuePtr) = MT (NamedValue);
        (yyval.namedValuePtr)->value = (yyvsp[(2) - (2)].valuePtr);
        (yyval.namedValuePtr)->fieldName = (yyvsp[(1) - (2)].charPtr);
    }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1818 "core/parse-asn1.y"
    {
        /*
         * example OID setup
         *
         * for { ccitt foo (1) bar bell (bunt) 2 }
         *
         * ccitt
         *   - arcnum is set to number from oid table (oid.c)
         * foo (1)
         *   - sets up a new value def foo defined as 1
         *   - makes oid valueref a value ref to foo (doesn't link it tho)
         * bar
         *   - makes oid valueref a value ref to bar (doesn't link it tho)
         * bell (bunt)
         *   - sets up a new value def bell defined as a val ref to bunt
         *   - makes oid valueref a value ref to bell (doesn't link it tho)
         * 2
         *  - arcnum is set to 2
         */

        (yyval.oidPtr) = (yyvsp[(2) - (3)].oidPtr);
    }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1845 "core/parse-asn1.y"
    {
        OID *o;
        /* append component */
        for (o = (yyvsp[(1) - (2)].oidPtr); o->next != NULL; o = o->next)
	    ;
        o->next = (yyvsp[(2) - (2)].oidPtr);
        (yyval.oidPtr) = (yyvsp[(1) - (2)].oidPtr);
    }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1861 "core/parse-asn1.y"
    {
        Value *newVal;
        /*
         * if the arcName is a defined arc name like
         * ccitt or iso etc, fill in the arc number.
         * otherwise make a value ref to that named value
         */
        (yyval.oidPtr) = MT (OID);

        (yyval.oidPtr)->arcNum = OidArcNameToNum ((yyvsp[(1) - (1)].charPtr));
        if ((yyval.oidPtr)->arcNum == NULL_OID_ARCNUM)
        {
            /* set up value ref to named value */
            SetupValue (&newVal, BASICVALUE_LOCALVALUEREF, myLineNoG);
            newVal->basicValue->a.localValueRef = MT (ValueRef);
            newVal->valueType = BASICTYPE_INTEGER;
            newVal->basicValue->a.localValueRef->valueName = (yyvsp[(1) - (1)].charPtr);
            (yyval.oidPtr)->valueRef = newVal;
        }
    }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1887 "core/parse-asn1.y"
    {
        (yyval.oidPtr) = MT (OID);
        (yyval.oidPtr)->arcNum = (yyvsp[(1) - (1)].intVal);
    }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1900 "core/parse-asn1.y"
    {
        Value *newVal;

        (yyval.oidPtr) = (yyvsp[(3) - (4)].oidPtr);

        /* shared refs to named numbers name */
        SetupValue (&newVal, BASICVALUE_INTEGER, myLineNoG);
        newVal->basicValue->a.integer = (yyval.oidPtr)->arcNum;
        newVal->valueType = BASICTYPE_INTEGER;
        AddNewValueDef (oidElmtValDefsG, (yyvsp[(1) - (4)].charPtr), newVal);

        SetupValue (&newVal, BASICVALUE_LOCALVALUEREF, myLineNoG);
        newVal->basicValue->a.localValueRef = MT (ValueRef);
        newVal->basicValue->a.localValueRef->valueName = (yyvsp[(1) - (4)].charPtr);

        (yyval.oidPtr)->valueRef = newVal;
    }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1918 "core/parse-asn1.y"
    {
        Value *newVal;

        /* shared refs to named numbers name */
        (yyval.oidPtr) = MT (OID);
        (yyval.oidPtr)->arcNum = NULL_OID_ARCNUM;

        AddNewValueDef (oidElmtValDefsG, (yyvsp[(1) - (4)].charPtr), (yyvsp[(3) - (4)].valuePtr));

        SetupValue (&newVal, BASICVALUE_LOCALVALUEREF, myLineNoG);
        newVal->basicValue->a.localValueRef = MT (ValueRef);
        newVal->basicValue->a.localValueRef->valueName = (yyvsp[(1) - (4)].charPtr);

        (yyval.oidPtr)->valueRef = newVal;
    }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 1952 "core/parse-asn1.y"
    {
	if ((yyvsp[(1) - (1)].uintVal)>0x7FFFFFFF) {
	    yyerror("Warning: number out of range");
	    (yyval.intVal) = 0x7FFFFFFF;
	}
	}
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 1959 "core/parse-asn1.y"
    {
	yyerror ("Warning: number out of range");
	(yyval.intVal) = 0x7FFFFFFF;
	/* modulePtrG->status = MOD_ERROR; */
	}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1987 "core/parse-asn1.y"
    {(yyval.attrList) = NULL;}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1992 "core/parse-asn1.y"
    {
        (yyval.attrList) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].charPtr),(yyval.attrList));
    }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1997 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(2) - (2)].charPtr),(yyvsp[(1) - (2)].attrList));
        (yyval.attrList) = (yyvsp[(1) - (2)].attrList);
    }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 2036 "core/parse-asn1.y"
    { (yyval.charPtr) = "OPERATION"; }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 2037 "core/parse-asn1.y"
    { (yyval.charPtr) = "ERROR"; }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 2038 "core/parse-asn1.y"
    { (yyval.charPtr) = "BIND"; }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 2039 "core/parse-asn1.y"
    { (yyval.charPtr) = "UNBIND"; }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 2040 "core/parse-asn1.y"
    { (yyval.charPtr) = "APPLICATION-SERVICE-ELEMENT"; }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2041 "core/parse-asn1.y"
    { (yyval.charPtr) = "APPLICATION-CONTEXT"; }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2042 "core/parse-asn1.y"
    { (yyval.charPtr) = "EXTENSION"; }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 2043 "core/parse-asn1.y"
    { (yyval.charPtr) = "EXTENSIONS"; }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 2044 "core/parse-asn1.y"
    { (yyval.charPtr) = "EXTENSION-ATTRIBUTE"; }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2045 "core/parse-asn1.y"
    { (yyval.charPtr) = "TOKEN"; }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 2046 "core/parse-asn1.y"
    { (yyval.charPtr) = "TOKEN-DATA"; }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2047 "core/parse-asn1.y"
    { (yyval.charPtr) = "SECURITY-CATEGORY"; }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 2048 "core/parse-asn1.y"
    { (yyval.charPtr) = "OBJECT"; }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2049 "core/parse-asn1.y"
    { (yyval.charPtr) = "PORT"; }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2050 "core/parse-asn1.y"
    { (yyval.charPtr) = "REFINE"; }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2051 "core/parse-asn1.y"
    { (yyval.charPtr) = "ABSTRACT-BIND"; }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2052 "core/parse-asn1.y"
    { (yyval.charPtr) = "ABSTRACT-UNBIND"; }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2053 "core/parse-asn1.y"
    { (yyval.charPtr) = "ABSTRACT-OPERATION"; }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2054 "core/parse-asn1.y"
    { (yyval.charPtr) = "ABSTRACT-ERROR"; }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2055 "core/parse-asn1.y"
    { (yyval.charPtr) = "ALGORITHM"; }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2056 "core/parse-asn1.y"
    { (yyval.charPtr) = "ENCRYPTED"; }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2057 "core/parse-asn1.y"
    { (yyval.charPtr) = "SIGNED"; }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2058 "core/parse-asn1.y"
    { (yyval.charPtr) = "SIGNATURE"; }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2059 "core/parse-asn1.y"
    { (yyval.charPtr) = "PROTECTED"; }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2060 "core/parse-asn1.y"
    { (yyval.charPtr) = "OBJECT-TYPE"; }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 2069 "core/parse-asn1.y"
    { (yyval.typePtr) = (yyvsp[(2) - (2)].typePtr); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 2074 "core/parse-asn1.y"
    {
        RosOperationMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSOPERATION, myLineNoG);
        r = (yyval.typePtr)->basicType->a.macroType->a.rosOperation  =
            MT (RosOperationMacroType);
        r->arguments = (yyvsp[(1) - (4)].namedTypePtr);
        r->result    = (yyvsp[(2) - (4)].namedTypePtr);
        r->errors    = (yyvsp[(3) - (4)].typeOrValueListPtr);
        r->linkedOps = (yyvsp[(4) - (4)].typeOrValueListPtr);
    }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2089 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 2090 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 2094 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2095 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2101 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2107 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = (yyvsp[(3) - (4)].typeOrValueListPtr);
    }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2110 "core/parse-asn1.y"
    { (yyval.typeOrValueListPtr) = NULL; }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 2117 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = (yyvsp[(3) - (4)].typeOrValueListPtr);
    }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 2120 "core/parse-asn1.y"
    { (yyval.typeOrValueListPtr) = NULL; }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 2133 "core/parse-asn1.y"
    {
        RosErrorMacroType *r;
        /*
         * defines error macro type
         */
        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSERROR, myLineNoG);
        r = (yyval.typePtr)->basicType->a.macroType->a.rosError = MT (RosErrorMacroType);
        r->parameter = (yyvsp[(2) - (2)].namedTypePtr);
    }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 2146 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 2147 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 2157 "core/parse-asn1.y"
    {
        RosBindMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSBIND, myLineNoG);

        r = (yyval.typePtr)->basicType->a.macroType->a.rosBind = MT (RosBindMacroType);
        r->argument  = (yyvsp[(2) - (4)].namedTypePtr);
        r->result = (yyvsp[(3) - (4)].namedTypePtr);
        r->error  = (yyvsp[(4) - (4)].namedTypePtr);
    }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 2170 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 2171 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 2176 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 2177 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 2182 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 2183 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 2193 "core/parse-asn1.y"
    {
        RosBindMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSUNBIND, myLineNoG);

        r = (yyval.typePtr)->basicType->a.macroType->a.rosUnbind = MT (RosBindMacroType);
        r->argument = (yyvsp[(2) - (4)].namedTypePtr);
        r->result = (yyvsp[(3) - (4)].namedTypePtr);
        r->error  = (yyvsp[(4) - (4)].namedTypePtr);
    }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 2207 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = (yyvsp[(2) - (2)].namedTypePtr); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 2208 "core/parse-asn1.y"
    { (yyval.namedTypePtr) = NULL; }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 2218 "core/parse-asn1.y"
    {
        RosAseMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSASE, myLineNoG);
        r = (yyval.typePtr)->basicType->a.macroType->a.rosAse  = MT (RosAseMacroType);
        r->operations = (yyvsp[(2) - (2)].valueListPtr);
    }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 2226 "core/parse-asn1.y"
    {
        RosAseMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSASE, myLineNoG);
        r = (yyval.typePtr)->basicType->a.macroType->a.rosAse  = MT (RosAseMacroType);
        r->consumerInvokes = (yyvsp[(2) - (3)].valueListPtr);
        r->supplierInvokes = (yyvsp[(3) - (3)].valueListPtr);
    }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 2239 "core/parse-asn1.y"
    {
        (yyval.valueListPtr) = (yyvsp[(3) - (4)].valueListPtr);
    }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 2247 "core/parse-asn1.y"
    {
        (yyval.valueListPtr) = (yyvsp[(3) - (4)].valueListPtr);
    }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 2250 "core/parse-asn1.y"
    { (yyval.valueListPtr) = NULL; }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 2256 "core/parse-asn1.y"
    {
        (yyval.valueListPtr) = (yyvsp[(3) - (4)].valueListPtr);
    }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 2259 "core/parse-asn1.y"
    { (yyval.valueListPtr) = NULL; }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 2279 "core/parse-asn1.y"
    {
        RosAcMacroType *r;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ROSAC, myLineNoG);
        r = (yyval.typePtr)->basicType->a.macroType->a.rosAc = MT (RosAcMacroType);
        r->nonRoElements = (yyvsp[(2) - (8)].valueListPtr);
        r->bindMacroType = (yyvsp[(4) - (8)].typePtr);
        r->unbindMacroType = (yyvsp[(6) - (8)].typePtr);
        r->remoteOperations = (yyvsp[(7) - (8)].valuePtr);
        r->operationsOf = rosAcSymmetricAsesG;
        r->initiatorConsumerOf = rosAcInitiatorConsumerOfG;
        r->responderConsumerOf = rosAcResponderConsumerOfG;
        r->abstractSyntaxes = (yyvsp[(8) - (8)].oidListPtr);
    }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 2298 "core/parse-asn1.y"
    {
        (yyval.valueListPtr) = (yyvsp[(3) - (4)].valueListPtr);
    }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 2307 "core/parse-asn1.y"
    {
        (yyval.valuePtr) = (yyvsp[(4) - (7)].valuePtr);
    }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 2311 "core/parse-asn1.y"
    {
        (yyval.valuePtr) = NULL;
        rosAcSymmetricAsesG = NULL;
        rosAcInitiatorConsumerOfG = NULL;
        rosAcResponderConsumerOfG = NULL;
    }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 2321 "core/parse-asn1.y"
    {
        rosAcSymmetricAsesG = (yyvsp[(4) - (5)].valueListPtr);
    }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 2324 "core/parse-asn1.y"
    { rosAcSymmetricAsesG = NULL; }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 2333 "core/parse-asn1.y"
    {
        rosAcInitiatorConsumerOfG = (yyvsp[(5) - (6)].valueListPtr);
    }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 2336 "core/parse-asn1.y"
    { rosAcInitiatorConsumerOfG = NULL; }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 2341 "core/parse-asn1.y"
    {
        rosAcResponderConsumerOfG = (yyvsp[(5) - (6)].valueListPtr);
    }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 2344 "core/parse-asn1.y"
    { rosAcResponderConsumerOfG = NULL; }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 2349 "core/parse-asn1.y"
    {
        (yyval.oidListPtr) = (yyvsp[(3) - (4)].oidListPtr);
    }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 2352 "core/parse-asn1.y"
    { (yyval.oidListPtr) = NULL; }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 2358 "core/parse-asn1.y"
    {
        (yyval.oidListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].oidPtr),(yyval.oidListPtr));
    }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 2363 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(3) - (3)].oidPtr), (yyvsp[(1) - (3)].oidListPtr));
        (yyval.oidListPtr) = (yyvsp[(1) - (3)].oidListPtr);
    }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 2377 "core/parse-asn1.y"
    {
          MtsasExtensionsMacroType *m;

          SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASEXTENSIONS, myLineNoG);
          m = (yyval.typePtr)->basicType->a.macroType->a.mtsasExtensions =
              MT (MtsasExtensionsMacroType);
          m->extensions = (yyvsp[(5) - (6)].valueListPtr);
      }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 2390 "core/parse-asn1.y"
    { (yyval.valueListPtr) = NULL; }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 2395 "core/parse-asn1.y"
    {
         (yyval.valueListPtr) = NEWLIST();
         APPEND ((yyvsp[(1) - (1)].valuePtr), (yyval.valueListPtr));
     }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 2400 "core/parse-asn1.y"
    {
         APPEND ((yyvsp[(3) - (3)].valuePtr),(yyvsp[(1) - (3)].valueListPtr));
         (yyval.valueListPtr) = (yyvsp[(1) - (3)].valueListPtr);
     }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 2408 "core/parse-asn1.y"
    { (yyval.typeOrValueListPtr) = NULL; }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 2413 "core/parse-asn1.y"
    {
         (yyval.typeOrValueListPtr) = NEWLIST();
         APPEND ((yyvsp[(1) - (1)].typeOrValuePtr), (yyval.typeOrValueListPtr));
     }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 2418 "core/parse-asn1.y"
    {
         APPEND ((yyvsp[(3) - (3)].typeOrValuePtr),(yyvsp[(1) - (3)].typeOrValueListPtr));
         (yyval.typeOrValueListPtr) = (yyvsp[(1) - (3)].typeOrValueListPtr);
     }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 2426 "core/parse-asn1.y"
    {
         (yyval.typeOrValuePtr) = MT (TypeOrValue);
         (yyval.typeOrValuePtr)->choiceId = TYPEORVALUE_TYPE;
         (yyval.typeOrValuePtr)->a.type = (yyvsp[(1) - (1)].typePtr);
     }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 2432 "core/parse-asn1.y"
    {
         (yyval.typeOrValuePtr) = MT (TypeOrValue);
         (yyval.typeOrValuePtr)->choiceId = TYPEORVALUE_VALUE;
         (yyval.typeOrValuePtr)->a.value = (yyvsp[(1) - (1)].valuePtr);
     }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 2445 "core/parse-asn1.y"
    {
        MtsasExtensionMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASEXTENSION, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasExtension =
            MT (MtsasExtensionMacroType);
        m->elmtType = (yyvsp[(2) - (4)].namedTypePtr);
        m->defaultValue = (yyvsp[(3) - (4)].valuePtr);
        m->criticalForSubmission = mtsasCriticalForSubmissionG;
        m->criticalForTransfer = mtsasCriticalForTransferG;
        m->criticalForDelivery = mtsasCriticalForDeliveryG;

        mtsasCriticalForSubmissionG = NULL;  /* set up for next parse */
        mtsasCriticalForTransferG = NULL;
        mtsasCriticalForDeliveryG = NULL;
    }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 2462 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASEXTENSION, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.mtsasExtension =
            MT (MtsasExtensionMacroType);
        /*
         * all fields are NULL in the MtsasExtensionsMacroType
         * for this production
         */
    }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2474 "core/parse-asn1.y"
    { (yyval.valuePtr) = (yyvsp[(2) - (2)].valuePtr); }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2475 "core/parse-asn1.y"
    { (yyval.valuePtr) = NULL; }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2491 "core/parse-asn1.y"
    {
        mtsasCriticalForSubmissionG = MT (AsnBool);
        *mtsasCriticalForSubmissionG = TRUE;
    }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 2496 "core/parse-asn1.y"
    {
        mtsasCriticalForTransferG = MT (AsnBool);
        *mtsasCriticalForTransferG = TRUE;
    }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 2501 "core/parse-asn1.y"
    {
        mtsasCriticalForDeliveryG = MT (AsnBool);
        *mtsasCriticalForDeliveryG = TRUE;
    }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 2515 "core/parse-asn1.y"
    {
        MtsasExtensionAttributeMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASEXTENSIONATTRIBUTE, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasExtensionAttribute =
            MT (MtsasExtensionAttributeMacroType);
        m->type = NULL;
    }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2524 "core/parse-asn1.y"
    {
        MtsasExtensionAttributeMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASEXTENSIONATTRIBUTE, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasExtensionAttribute =
            MT (MtsasExtensionAttributeMacroType);
        m->type = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2540 "core/parse-asn1.y"
    {
        MtsasTokenMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASTOKEN, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasToken = MT (MtsasTokenMacroType);
        m->type = NULL;
    }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2548 "core/parse-asn1.y"
    {
        MtsasTokenMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASTOKEN, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasToken = MT (MtsasTokenMacroType);
        m->type = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2563 "core/parse-asn1.y"
    {
        MtsasTokenDataMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASTOKENDATA, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasTokenData =
            MT (MtsasTokenDataMacroType);
        m->type = NULL;
    }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2572 "core/parse-asn1.y"
    {
        MtsasTokenDataMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASTOKENDATA, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasTokenData =
            MT (MtsasTokenDataMacroType);
        m->type = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2588 "core/parse-asn1.y"
    {
        MtsasSecurityCategoryMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASSECURITYCATEGORY, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasSecurityCategory =
            MT (MtsasSecurityCategoryMacroType);
        m->type = NULL;
    }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2597 "core/parse-asn1.y"
    {
        MtsasSecurityCategoryMacroType *m;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_MTSASSECURITYCATEGORY, myLineNoG);
        m = (yyval.typePtr)->basicType->a.macroType->a.mtsasSecurityCategory =
            MT (MtsasSecurityCategoryMacroType);
        m->type = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2619 "core/parse-asn1.y"
    {
        AsnObjectMacroType *a;
        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNOBJECT, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnObject = MT (AsnObjectMacroType);
        a->ports = (yyvsp[(2) - (2)].asnPortListPtr);
    }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2629 "core/parse-asn1.y"
    {
        (yyval.asnPortListPtr) = (yyvsp[(3) - (4)].asnPortListPtr);
    }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2632 "core/parse-asn1.y"
    { (yyval.asnPortListPtr) = NULL; }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2637 "core/parse-asn1.y"
    {
        (yyval.asnPortListPtr) = NEWLIST();
        APPEND ((yyvsp[(1) - (1)].asnPortPtr), (yyval.asnPortListPtr));
    }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2642 "core/parse-asn1.y"
    {
        APPEND ((yyvsp[(3) - (3)].asnPortPtr), (yyvsp[(1) - (3)].asnPortListPtr));
        (yyval.asnPortListPtr) = (yyvsp[(1) - (3)].asnPortListPtr);
    }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2650 "core/parse-asn1.y"
    {
        (yyval.asnPortPtr) = MT (AsnPort);
        (yyval.asnPortPtr)->portValue = (yyvsp[(1) - (2)].valuePtr);
        (yyval.asnPortPtr)->portType = (yyvsp[(2) - (2)].intVal);
    }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2659 "core/parse-asn1.y"
    {
        /* [C] consumer */
        (yyval.intVal) = CONSUMER_PORT;
    }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2664 "core/parse-asn1.y"
    {
        /* [S] supplier */
        (yyval.intVal) = SUPPLIER_PORT;
    }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2669 "core/parse-asn1.y"
    {
       /* symmetric */
        (yyval.intVal) = SYMMETRIC_PORT;
    }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2682 "core/parse-asn1.y"
    {
        AsnPortMacroType *a;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNPORT, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnPort = MT (AsnPortMacroType);
        a->abstractOps = (yyvsp[(2) - (2)].typeOrValueListPtr);
        a->consumerInvokes = asnConsumerG;
        a->supplierInvokes = asnSupplierG;
    }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2692 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNPORT, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.asnPort = MT (AsnPortMacroType);
    }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2701 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = (yyvsp[(3) - (4)].typeOrValueListPtr);
    }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 2705 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = NULL;
        asnConsumerG = (yyvsp[(1) - (1)].typeOrValueListPtr);
        asnSupplierG = NULL;
    }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 2711 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = NULL;
        asnConsumerG = (yyvsp[(1) - (1)].typeOrValueListPtr);
        asnSupplierG = NULL;
    }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 2717 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = NULL;
        asnConsumerG = (yyvsp[(1) - (2)].typeOrValueListPtr);
        asnSupplierG = NULL;
    }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 2723 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = NULL;
        asnConsumerG = (yyvsp[(1) - (2)].typeOrValueListPtr);
        asnSupplierG = NULL;
    }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 2732 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = (yyvsp[(3) - (4)].typeOrValueListPtr);
    }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 2739 "core/parse-asn1.y"
    {
        (yyval.typeOrValueListPtr) = (yyvsp[(3) - (4)].typeOrValueListPtr);
    }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 2755 "core/parse-asn1.y"
    {
        SetupType (&(yyval.typePtr), BASICTYPE_UNKNOWN, myLineNoG);
    }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2781 "core/parse-asn1.y"
    {
       (yyval.intVal) = 0; /* just to quiet yacc warning */
    }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2799 "core/parse-asn1.y"
    {
        (yyval.intVal) = 0; /* just to quiet yacc warning */
    }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 2812 "core/parse-asn1.y"
    {
        AsnAbstractBindMacroType *a;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNABSTRACTBIND, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnAbstractBind =
            MT (AsnAbstractBindMacroType);
        a->ports = (yyvsp[(2) - (2)].asnPortListPtr);
    }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2821 "core/parse-asn1.y"
    {
        AsnAbstractBindMacroType *a;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNABSTRACTBIND, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnAbstractBind =
            MT (AsnAbstractBindMacroType);
        a->ports = (yyvsp[(2) - (3)].asnPortListPtr);
        a->type = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2834 "core/parse-asn1.y"
    {
        (yyval.asnPortListPtr) = (yyvsp[(3) - (4)].asnPortListPtr);
    }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2837 "core/parse-asn1.y"
    { (yyval.asnPortListPtr) = NULL; }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2848 "core/parse-asn1.y"
    {
        AsnAbstractBindMacroType *a;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNABSTRACTUNBIND, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnAbstractUnbind =
            MT (AsnAbstractBindMacroType);

        a->ports = (yyvsp[(2) - (2)].asnPortListPtr);
    }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2858 "core/parse-asn1.y"
    {
        AsnAbstractBindMacroType *a;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNABSTRACTUNBIND, myLineNoG);
        a = (yyval.typePtr)->basicType->a.macroType->a.asnAbstractUnbind =
            MT (AsnAbstractBindMacroType);

        a->ports = (yyvsp[(2) - (3)].asnPortListPtr);
        a->type = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2872 "core/parse-asn1.y"
    {
        (yyval.asnPortListPtr) = (yyvsp[(3) - (4)].asnPortListPtr);
    }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2875 "core/parse-asn1.y"
    { (yyval.asnPortListPtr) = NULL; }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2885 "core/parse-asn1.y"
    {
       (yyval.typePtr) = (yyvsp[(2) - (2)].typePtr);
       (yyvsp[(2) - (2)].typePtr)->basicType->a.macroType->choiceId = MACROTYPE_ASNABSTRACTOPERATION;
    }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2897 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_ASNABSTRACTERROR, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.asnAbstractError = MT (RosErrorMacroType);
        (yyval.typePtr)->basicType->a.macroType->a.asnAbstractError->parameter = (yyvsp[(2) - (2)].namedTypePtr);
    }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 2910 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_AFALGORITHM, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.afAlgorithm = (yyvsp[(3) - (3)].typePtr);
    }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2921 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_AFENCRYPTED, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.afEncrypted = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2933 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_AFSIGNED, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.afSigned = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2944 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_AFSIGNATURE, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.afSignature = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2958 "core/parse-asn1.y"
    {
        SetupMacroType (&(yyval.typePtr), MACROTYPE_AFPROTECTED, myLineNoG);
        (yyval.typePtr)->basicType->a.macroType->a.afProtected = (yyvsp[(2) - (2)].typePtr);
    }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2975 "core/parse-asn1.y"
    {
        SnmpObjectTypeMacroType *s;

        SetupMacroType (&(yyval.typePtr), MACROTYPE_SNMPOBJECTTYPE, myLineNoG);
        s = (yyval.typePtr)->basicType->a.macroType->a.snmpObjectType =
            MT (SnmpObjectTypeMacroType);

        s->syntax = (yyvsp[(3) - (11)].typePtr);
        s->access = (yyvsp[(5) - (11)].intVal);
        s->status = (yyvsp[(7) - (11)].intVal);
        s->description = (yyvsp[(8) - (11)].valuePtr);
        s->reference = (yyvsp[(9) - (11)].valuePtr);
        s->index = (yyvsp[(10) - (11)].typeOrValueListPtr);
        s->defVal = (yyvsp[(11) - (11)].valuePtr);
    }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2994 "core/parse-asn1.y"
    {
        if (strcmp ((yyvsp[(1) - (1)].charPtr), "read-only") == 0)
            (yyval.intVal) = SNMP_READ_ONLY;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "read-write") == 0)
            (yyval.intVal) = SNMP_READ_WRITE;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "write-only") == 0)
            (yyval.intVal) = SNMP_WRITE_ONLY;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "not-accessible") == 0)
            (yyval.intVal) = SNMP_NOT_ACCESSIBLE;
        else
        {
            yyerror ("ACCESS field of SNMP OBJECT-TYPE MACRO can only be one of \"read-write\", \"write-only\" or \"not-accessible\"");
            (yyval.intVal) = -1;
            modulePtrG->status = MOD_ERROR;
        }
        Free ((yyvsp[(1) - (1)].charPtr));
   }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 3016 "core/parse-asn1.y"
    {
        if (strcmp ((yyvsp[(1) - (1)].charPtr), "mandatory") == 0)
            (yyval.intVal) = SNMP_MANDATORY;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "optional") == 0)
            (yyval.intVal) = SNMP_OPTIONAL;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "obsolete") == 0)
            (yyval.intVal) = SNMP_OBSOLETE;
        else if (strcmp ((yyvsp[(1) - (1)].charPtr), "deprecated") == 0)
            (yyval.intVal) = SNMP_DEPRECATED;
        else
        {
            yyerror ("STATUS field of SNMP OBJECT-TYPE MACRO can only be one of \"optional\", \"obsolete\" or \"deprecated\"");
            (yyval.intVal) = -1;
            modulePtrG->status = MOD_ERROR;
        }
        Free ((yyvsp[(1) - (1)].charPtr));
   }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 3036 "core/parse-asn1.y"
    { (yyval.valuePtr) = (yyvsp[(2) - (2)].valuePtr); }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 3037 "core/parse-asn1.y"
    { (yyval.valuePtr) = NULL; }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 3041 "core/parse-asn1.y"
    { (yyval.valuePtr) = (yyvsp[(2) - (2)].valuePtr); }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 3042 "core/parse-asn1.y"
    { (yyval.valuePtr) = NULL; }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 3047 "core/parse-asn1.y"
    {
       (yyval.typeOrValueListPtr)  = (yyvsp[(3) - (4)].typeOrValueListPtr);
   }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 3050 "core/parse-asn1.y"
    { (yyval.typeOrValueListPtr) = NULL; }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 3055 "core/parse-asn1.y"
    {
       (yyval.valuePtr)  = (yyvsp[(3) - (4)].valuePtr);
   }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 3058 "core/parse-asn1.y"
    { (yyval.valuePtr) = NULL; }
    break;



/* Line 1806 of yacc.c  */
#line 6127 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 3061 "core/parse-asn1.y"


yyerror (s)
char*s;
{
	fprintf (stderr,"file \"%s\", line %d: %s at symbol \"%s\"\n\n", modulePtrG->asn1SrcFileName, myLineNoG, s, yytext);
}


/*
 * given a Module*, the file name associated witht the open
 * FILE *fPtr, InitAsn1Parser sets up the yacc/lex parser
 * to parse an ASN.1 module read from fPtr and write the
 * parse results into the given Module *mod.
 */
int
InitAsn1Parser PARAMS ((mod, fileName, fPtr),
    Module	*mod _AND_
    char	*fileName _AND_
    FILE	*fPtr)
{
    yyin = fPtr;

    /*
     * reset lexical analyzer input file ptr
     * (only do this on succesive calls ow yyrestart seg faults
     */
#ifdef FLEX_IN_USE
    if (!firstTimeThroughG)
        yyrestart (fPtr);

    firstTimeThroughG = FALSE;
#endif


    /*
     * init modulePtr
     */
    memzero (mod, sizeof (Module));
    modulePtrG = mod;
    mod->asn1SrcFileName = fileName;
    mod->status = MOD_NOT_LINKED;
    mod->hasAnys = FALSE;

    /* init lists to empty */
    mod->typeDefs = AsnListNew (sizeof (void*));
    mod->valueDefs = AsnListNew (sizeof (void*));

    /*
     * init export list stuff
     */
    exportListG = NULL;
    exportsParsedG = FALSE;

    /*
     * reset line number to 1
     */
    myLineNoG = 1;

    /*
     * reset error count
     */
    parseErrCountG = 0;

   /*
    * set up list to hold values defined in parsed oids
    */
    oidElmtValDefsG = AsnListNew (sizeof (void *));

    smallErrG = 0;

    return 0;

}  /* InitAsn1Parser */


/*
 * puts the applicatin tag code, tagCode, and line number it was
 * parsed at into the applTagsG list.  If the APPLICATION tag code
 * is already in the applTagsG list then an error is printed.
 * and the smallErrG flag set to prevent code production.
 */
void
PushApplTag PARAMS ((tagCode, lineNo),
    unsigned long int tagCode _AND_
    unsigned long int lineNo)
{
    ApplTag *l;
    ApplTag *new;
    int wasDefined = 0;

    /* make sure not already in list */
    for (l = applTagsG; l != NULL; l = l->next)
    {
        if (l->tagCode == tagCode)
        {
            PrintErrLoc (modulePtrG->asn1SrcFileName, lineNo);
            fprintf (stderr,"ERROR - APPLICATION tags can be used only once per ASN.1 module.  The tag \"[APPLICATION %d]\" was previously used on line %d.\n", tagCode, l->lineNo);
            wasDefined = 1;
            smallErrG = 1;
        }
    }
    if (!wasDefined)
    {
        new = MT (ApplTag);
        new->lineNo = lineNo;
        new->tagCode = tagCode;
        new->next = applTagsG;
        applTagsG = new;
    }
}  /* PushApplTag */


/*
 * Empties the applTagsG list.  Usually done between modules.
 */
void
FreeApplTags()
{
    ApplTag *l;
    ApplTag *lTmp;

    for (l = applTagsG; l != NULL; )
    {
        lTmp = l->next;
        Free (l);
        l = lTmp;
    }
    applTagsG = NULL;
}  /* FreeApplTags */

