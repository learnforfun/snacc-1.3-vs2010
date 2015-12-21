/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 380 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


