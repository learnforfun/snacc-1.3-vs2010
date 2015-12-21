//   NOTE: this is a machine generated file--editing not recommended
//
// asn-useful.C - class member functions for ASN.1 module ASN-USEFUL
//
//   This file was generated by snacc on Mon Dec 21 20:44:41 2015
//   UBC snacc written by Mike Sample
//   A couple of enhancements made by IBM European Networking Center


#include "asn-incl.h"
#include "asn-useful.h"

//------------------------------------------------------------------------------
// value defs


//------------------------------------------------------------------------------
// class member definitions:

AsnType *ObjectDescriptor::Clone() const
{
  return new ObjectDescriptor;
}

AsnLen ObjectDescriptor::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, OD_TAG_CODE);
    return l;
}

void ObjectDescriptor::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, OD_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, OD_TAG_CODE)))
    {
        Asn1Error << "ObjectDescriptor::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 50);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int ObjectDescriptor::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int ObjectDescriptor::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *NumericString::Clone() const
{
  return new NumericString;
}

AsnLen NumericString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, NUMERICSTRING_TAG_CODE);
    return l;
}

void NumericString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, NUMERICSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, NUMERICSTRING_TAG_CODE)))
    {
        Asn1Error << "NumericString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 49);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int NumericString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int NumericString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *PrintableString::Clone() const
{
  return new PrintableString;
}

AsnLen PrintableString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, PRINTABLESTRING_TAG_CODE);
    return l;
}

void PrintableString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, PRINTABLESTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, PRINTABLESTRING_TAG_CODE)))
    {
        Asn1Error << "PrintableString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 48);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int PrintableString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int PrintableString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *TeletexString::Clone() const
{
  return new TeletexString;
}

AsnLen TeletexString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, TELETEXSTRING_TAG_CODE);
    return l;
}

void TeletexString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, TELETEXSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, TELETEXSTRING_TAG_CODE)))
    {
        Asn1Error << "TeletexString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 47);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int TeletexString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int TeletexString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *T61String::Clone() const
{
  return new T61String;
}

AsnLen T61String::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, TELETEXSTRING_TAG_CODE);
    return l;
}

void T61String::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, TELETEXSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, TELETEXSTRING_TAG_CODE)))
    {
        Asn1Error << "T61String::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 46);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int T61String::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int T61String::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *VideotexString::Clone() const
{
  return new VideotexString;
}

AsnLen VideotexString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, VIDEOTEXSTRING_TAG_CODE);
    return l;
}

void VideotexString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, VIDEOTEXSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, VIDEOTEXSTRING_TAG_CODE)))
    {
        Asn1Error << "VideotexString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 45);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int VideotexString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int VideotexString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *IA5String::Clone() const
{
  return new IA5String;
}

AsnLen IA5String::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, IA5STRING_TAG_CODE);
    return l;
}

void IA5String::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, IA5STRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, IA5STRING_TAG_CODE)))
    {
        Asn1Error << "IA5String::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 44);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int IA5String::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int IA5String::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *GraphicString::Clone() const
{
  return new GraphicString;
}

AsnLen GraphicString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, GRAPHICSTRING_TAG_CODE);
    return l;
}

void GraphicString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, GRAPHICSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, GRAPHICSTRING_TAG_CODE)))
    {
        Asn1Error << "GraphicString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 43);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int GraphicString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int GraphicString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *VisibleString::Clone() const
{
  return new VisibleString;
}

AsnLen VisibleString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, VISIBLESTRING_TAG_CODE);
    return l;
}

void VisibleString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, VISIBLESTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, VISIBLESTRING_TAG_CODE)))
    {
        Asn1Error << "VisibleString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 42);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int VisibleString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int VisibleString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *ISO646String::Clone() const
{
  return new ISO646String;
}

AsnLen ISO646String::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, VISIBLESTRING_TAG_CODE);
    return l;
}

void ISO646String::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, VISIBLESTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, VISIBLESTRING_TAG_CODE)))
    {
        Asn1Error << "ISO646String::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 41);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int ISO646String::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int ISO646String::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *GeneralString::Clone() const
{
  return new GeneralString;
}

AsnLen GeneralString::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, GENERALSTRING_TAG_CODE);
    return l;
}

void GeneralString::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, GENERALSTRING_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, GENERALSTRING_TAG_CODE)))
    {
        Asn1Error << "GeneralString::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 40);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int GeneralString::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int GeneralString::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *UTCTime::Clone() const
{
  return new UTCTime;
}

AsnLen UTCTime::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, UTCTIME_TAG_CODE);
    return l;
}

void UTCTime::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, UTCTIME_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, UTCTIME_TAG_CODE)))
    {
        Asn1Error << "UTCTime::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 39);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int UTCTime::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int UTCTime::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

AsnType *GeneralizedTime::Clone() const
{
  return new GeneralizedTime;
}

AsnLen GeneralizedTime::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, GENERALIZEDTIME_TAG_CODE);
    return l;
}

void GeneralizedTime::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnTag tag;
    AsnLen elmtLen1;

    if (((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, PRIM, GENERALIZEDTIME_TAG_CODE))
        && (tag != MAKE_TAG_ID (UNIV, CONS, GENERALIZEDTIME_TAG_CODE)))
    {
        Asn1Error << "GeneralizedTime::BDec: ERROR - wrong tag" << endl;
        longjmp (env, 38);
    }
    elmtLen1 = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int GeneralizedTime::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int GeneralizedTime::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

EXTERNALChoice::EXTERNALChoice()
{
  choiceId = single_ASN1_typeCid;
#if TCL
  single_ASN1_type = new AsnOcts;
#else
  single_ASN1_type = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

EXTERNALChoice::EXTERNALChoice (const EXTERNALChoice &)
{
  Asn1Error << "use of incompletely defined EXTERNALChoice::EXTERNALChoice (const EXTERNALChoice &)" << endl;
  abort();
}

EXTERNALChoice::~EXTERNALChoice()
{
  switch (choiceId)
  {
    case single_ASN1_typeCid:
      delete single_ASN1_type;
      break;
    case octet_alignedCid:
      delete octet_aligned;
      break;
    case arbitraryCid:
      delete arbitrary;
      break;
  } // end of switch
} // end of destructor

AsnType *EXTERNALChoice::Clone() const
{
  return new EXTERNALChoice;
}

#if SNACC_DEEP_COPY
EXTERNALChoice &EXTERNALChoice::operator = (const EXTERNALChoice &that)
#else // SNACC_DEEP_COPY
EXTERNALChoice &EXTERNALChoice::operator = (const EXTERNALChoice &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    switch (choiceId)
    {
      case single_ASN1_typeCid:
        delete single_ASN1_type;
        break;
      case octet_alignedCid:
        delete octet_aligned;
        break;
      case arbitraryCid:
        delete arbitrary;
        break;
    }
    switch (choiceId = that.choiceId)
    {
      case single_ASN1_typeCid:
        single_ASN1_type = new AsnOcts;
        *single_ASN1_type = *that.single_ASN1_type;
        break;
      case octet_alignedCid:
        octet_aligned = new AsnOcts;
        *octet_aligned = *that.octet_aligned;
        break;
      case arbitraryCid:
        arbitrary = new AsnBits;
        *arbitrary = *that.arbitrary;
        break;
    }
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined EXTERNALChoice &EXTERNALChoice::operator = (const EXTERNALChoice &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
  return *this;
#endif // SNACC_DEEP_COPY
}

AsnLen
EXTERNALChoice::BEncContent (BUF_TYPE b)
{
  AsnLen l;
  switch (choiceId)
  {
    case single_ASN1_typeCid:
      BEncEocIfNec (b);
      l = single_ASN1_type->BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, OCTETSTRING_TAG_CODE);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 0);
      break;

    case octet_alignedCid:
      l = octet_aligned->BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, CNTX, PRIM, 1);
      break;

    case arbitraryCid:
      l = arbitrary->BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, CNTX, PRIM, 2);
      break;

  } // end switch
  return l;
} // EXTERNALChoice::BEncContent


void EXTERNALChoice::BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnLen elmtLen1;
  switch (tag)
  {
    case MAKE_TAG_ID (CNTX, CONS, 0):
      tag = BDecTag (b, bytesDecoded, env);
      if ((tag != MAKE_TAG_ID (UNIV, PRIM, OCTETSTRING_TAG_CODE))
          && (tag != MAKE_TAG_ID (UNIV, CONS, OCTETSTRING_TAG_CODE)))
      {
         Asn1Error << "Unexpected Tag" << endl;
         longjmp (env, 37);
      }

      elmtLen1 = BDecLen (b, bytesDecoded, env);
      choiceId = single_ASN1_typeCid;
      single_ASN1_type = new AsnOcts;
        single_ASN1_type->BDecContent (b, tag, elmtLen1, bytesDecoded, env);
      if (elmtLen0 == INDEFINITE_LEN)
        BDecEoc (b, bytesDecoded, env);
      break;

    case MAKE_TAG_ID (CNTX, PRIM, 1):
    case MAKE_TAG_ID (CNTX, CONS, 1):
      choiceId = octet_alignedCid;
      octet_aligned = new AsnOcts;
        octet_aligned->BDecContent (b, tag, elmtLen0, bytesDecoded, env);
      break;

    case MAKE_TAG_ID (CNTX, PRIM, 2):
    case MAKE_TAG_ID (CNTX, CONS, 2):
      choiceId = arbitraryCid;
      arbitrary = new AsnBits;
        arbitrary->BDecContent (b, tag, elmtLen0, bytesDecoded, env);
      break;

    default:
      Asn1Error << "ERROR - unexpected tag in CHOICE" << endl;
      longjmp (env, 36);
      break;
  } // end switch
} // EXTERNALChoice::BDecContent


AsnLen EXTERNALChoice::BEnc (BUF_TYPE b)
{
    AsnLen l;
    l = BEncContent (b);
    return l;
}

void EXTERNALChoice::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
    AsnLen elmtLen;
    AsnTag tag;

    /*  CHOICEs are a special case - grab identifying tag */
    /*  this allows easier handling of nested CHOICEs */
    tag = BDecTag (b, bytesDecoded, env);
    elmtLen = BDecLen (b, bytesDecoded, env);
    BDecContent (b, tag, elmtLen, bytesDecoded, env);
}

int EXTERNALChoice::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int EXTERNALChoice::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

void EXTERNALChoice::Print (ostream &os) const
{
  switch (choiceId)
  {
    case single_ASN1_typeCid:
      os << "single-ASN1-type ";
      if (single_ASN1_type)
        os << *single_ASN1_type;
      else
        os << "-- void3 --\n";
      break;

    case octet_alignedCid:
      os << "octet-aligned ";
      if (octet_aligned)
        os << *octet_aligned;
      else
        os << "-- void3 --\n";
      break;

    case arbitraryCid:
      os << "arbitrary ";
      if (arbitrary)
        os << *arbitrary;
      else
        os << "-- void3 --\n";
      break;

  } // end of switch
} // EXTERNALChoice::Print

EXTERNAL::EXTERNAL()
{
  direct_reference = NULL;
  indirect_reference = NULL;
  data_value_descriptor = NULL;
#if TCL
  encoding = new EXTERNALChoice;
#else
  encoding = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

EXTERNAL::EXTERNAL (const EXTERNAL &)
{
  Asn1Error << "use of incompletely defined EXTERNAL::EXTERNAL (const EXTERNAL &)" << endl;
  abort();
}

EXTERNAL::~EXTERNAL()
{
  delete direct_reference;
  delete indirect_reference;
  delete data_value_descriptor;
  delete encoding;
}

AsnType *EXTERNAL::Clone() const
{
  return new EXTERNAL;
}

#if SNACC_DEEP_COPY
EXTERNAL &EXTERNAL::operator = (const EXTERNAL &that)
#else // SNACC_DEEP_COPY
EXTERNAL &EXTERNAL::operator = (const EXTERNAL &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    if (that.direct_reference)
    {
      if (!direct_reference)
        direct_reference = new AsnOid;
      *direct_reference = *that.direct_reference;
    }
    else
    {
      delete direct_reference;
      direct_reference = NULL;
    }
    if (that.indirect_reference)
    {
      if (!indirect_reference)
        indirect_reference = new AsnInt;
      *indirect_reference = *that.indirect_reference;
    }
    else
    {
      delete indirect_reference;
      indirect_reference = NULL;
    }
    if (that.data_value_descriptor)
    {
      if (!data_value_descriptor)
        data_value_descriptor = new ObjectDescriptor;
      *data_value_descriptor = *that.data_value_descriptor;
    }
    else
    {
      delete data_value_descriptor;
      data_value_descriptor = NULL;
    }
    if (that.encoding)
    {
      if (!encoding)
        encoding = new EXTERNALChoice;
      *encoding = *that.encoding;
    }
    else
    {
      delete encoding;
      encoding = NULL;
    }
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined EXTERNAL &EXTERNAL::operator = (const EXTERNAL &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
  return *this;
#endif // SNACC_DEEP_COPY
}

AsnLen
EXTERNAL::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

    l = encoding->BEncContent (b);
    totalLen += l;

  if (NOT_NULL (data_value_descriptor))
  {
    l = data_value_descriptor->BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, OD_TAG_CODE);
    totalLen += l;
  }

  if (NOT_NULL (indirect_reference))
  {
    l = indirect_reference->BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;

    l += BEncTag1 (b, UNIV, PRIM, INTEGER_TAG_CODE);
    totalLen += l;
  }

  if (NOT_NULL (direct_reference))
  {
    l = direct_reference->BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, OID_TAG_CODE);
    totalLen += l;
  }

  return totalLen;
} // EXTERNAL::BEncContent


void EXTERNAL::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded, env);

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, OID_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    direct_reference = new AsnOid;
    direct_reference->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, INTEGER_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    indirect_reference = new AsnInt;
    indirect_reference->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, OD_TAG_CODE))
    || (tag1 == MAKE_TAG_ID (UNIV, CONS, OD_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    data_value_descriptor = new ObjectDescriptor;
    data_value_descriptor->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 0))
    || (tag1 == MAKE_TAG_ID (CNTX, PRIM, 1))
    || (tag1 == MAKE_TAG_ID (CNTX, CONS, 1))
    || (tag1 == MAKE_TAG_ID (CNTX, PRIM, 2))
    || (tag1 == MAKE_TAG_ID (CNTX, CONS, 2)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    encoding = new EXTERNALChoice;
    encoding->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    longjmp (env, 35);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded, env);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    Asn1Error << "ERROR - Length discrepancy on sequence." << endl;
    longjmp (env, 34);
  }
  else
    return;
} // EXTERNAL::BDecContent

AsnLen EXTERNAL::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, EXTERNAL_TAG_CODE);
  return l;
}

void EXTERNAL::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, EXTERNAL_TAG_CODE))
  {
    Asn1Error << "EXTERNAL::BDec: ERROR - wrong tag" << endl;
    longjmp (env, 33);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

int EXTERNAL::BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded)
{
    bytesEncoded = BEnc (b);
    return !b.WriteError();
}

int EXTERNAL::BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded)
{
    ENV_TYPE env;
    int val;

    bytesDecoded = 0;
    if ((val = setjmp (env)) == 0)
    {
         BDec (b, bytesDecoded, env);
         return !b.ReadError();
    }
    else
        return false;
}

void EXTERNAL::Print (ostream &os) const
{
  os << "{ -- SEQUENCE --" << endl;
  indentG += stdIndentG;

  if (NOT_NULL (direct_reference))
  {
    Indent (os, indentG);
    os << "direct-reference ";
    os << *direct_reference;
  }
  else
  {
    Indent (os, indentG);
    os << "direct-reference ";
    os << "-- void --";
    os << "," << endl;
  }

  if (NOT_NULL (indirect_reference))
  {
    Indent (os, indentG);
    os << "indirect-reference ";
    os << *indirect_reference;
  }
  else
  {
    Indent (os, indentG);
    os << "indirect-reference ";
    os << "-- void --";
    os << "," << endl;
  }

  if (NOT_NULL (data_value_descriptor))
  {
    Indent (os, indentG);
    os << "data-value-descriptor ";
    os << *data_value_descriptor;
  }
  else
  {
    Indent (os, indentG);
    os << "data-value-descriptor ";
    os << "-- void --";
    os << "," << endl;
  }

  if (NOT_NULL (encoding))
  {
    Indent (os, indentG);
    os << "encoding ";
    os << *encoding;
  }
  else
  {
    Indent (os, indentG);
    os << "encoding ";
    os << "-- void --";
    os << endl;
  }

  os << endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
} // EXTERNAL::Print


