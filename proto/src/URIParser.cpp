//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Thu Aug  7 12:30:02 2008 morgan armand
//

#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod)
  : ABNFParser(prod)
{}

URIParser::~URIParser()
{}

bool	URIParser::readURI()
{
  RULE(readScheme() && CHAR(':') &&
       readHierPart() &&
       readURIBool1() &&
       readURIBool2());
}

bool	URIParser::readURIBool1()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readURIBool2()
{
  BOOL(CHAR('#') && readFragment());
}

bool	URIParser::readHierPart()
{
  RULE(readHierPartBlock() ||
       readPathAbsolute() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readHierPartBlock()
{
  RULE(readText("//") &&
       readAuthority() &&
       readPathAbempty());
}

bool	URIParser::readURIReference()
{
  RULE(readURI() || readRelativeRef());
}

bool	URIParser::readAbsoluteURI()
{
  RULE(readScheme() && CHAR(':') &&
       readHierPart() &&
       readAbsoluteURIBool());
}

bool	URIParser::readAbsoluteURIBool()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readRelativeRef()
{
  RULE(readRelativePart() &&
       readRelativeRefBool1() &&
       readRelativeRefBool2());
}

bool	URIParser::readRelativeRefBool1()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readRelativeRefBool2()
{
  BOOL(CHAR('#') && readFragment());
}

bool	URIParser::readRelativePart()
{
  RULE(readRelativePartBlock() ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathEmpty());
}

bool	URIParser::readRelativePartBlock()
{
  RULE(readText("//") &&
       readAuthority() &&
       readPathAbempty());
}

bool	URIParser::readScheme()
{
  RULE(ALPHA && readSchemeLoop());
}

bool	URIParser::readSchemeLoop()
{
  LOOP(ALPHA || DIGIT || CHAR('+') ||
       CHAR('-') || CHAR('.'));
}

bool	URIParser::readAuthority()
{
  RULE(readAuthorityBool1() &&
       readHost() &&
       readAuthorityBool2());
}

bool	URIParser::readAuthorityBool1()
{
  BOOL(readUserinfo() && CHAR('@'));
}


bool	URIParser::readAuthorityBool2()
{
  BOOL(CHAR(':') && readPort());
}

bool	URIParser::readUserinfo()
{
  LOOP(readUnreserved() ||
       readPctEncoded() ||
       readSubDelims() ||
       CHAR(':'));
}

bool	URIParser::readHost()
{
  RULE(readIPLiteral() ||
       readIPv4address() ||
       readRegName());
}

bool	URIParser::readPort()
{
  LOOP(DIGIT);
}

bool	URIParser::readIPLiteral()
{
  RULE(CHAR('[') &&
       readIPLiteralBlock() &&
       CHAR(']'));
}

bool	URIParser::readIPLiteralBlock()
{
  RULE(readIPv6address() || readIPvFuture());
}

bool	URIParser::readIPvFuture()
{
  RULE(CHAR('v') &&
       readIPvFutureLoop1() &&
       CHAR('.') &&
       readIPvFutureLoop2());
}

bool	URIParser::readIPvFutureLoop1()
{
  LOOP1(HEXDIG);
}

bool	URIParser::readIPvFutureLoop2()
{
  LOOP1(readUnreserved() ||
	readSubDelims() ||
	CHAR(':'));
}

bool	URIParser::readIPv6address()
{
  RULE(false);
}

bool	URIParser::readH16()
{
  RULE(HEXDIG && HEXDIG && HEXDIG && HEXDIG);
}

bool	URIParser::readLs32()
{
  RULE(readLs32Block() ||
       readIPv4address());
}

bool	URIParser::readLs32Block()
{
  RULE(readH16() && CHAR(':') && readH16());
}

bool	URIParser::readIPv4address()
{
  RULE(readDecOctet() && CHAR('.') &&
       readDecOctet() && CHAR('.') &&
       readDecOctet() && CHAR('.') &&
       readDecOctet());
}

bool	URIParser::readDecOctet()
{
  RULE(DIGIT ||
       readDecOctetBlock1() ||
       readDecOctetBlock2() ||
       readDecOctetBlock3() ||
       readDecOctetBlock4());
}

bool	URIParser::readDecOctetBlock1()
{
  RULE(RANGE('1', '9') && DIGIT);
}

bool	URIParser::readDecOctetBlock2()
{
  RULE(CHAR('1') && DIGIT && DIGIT);
}

bool	URIParser::readDecOctetBlock3()
{
  RULE(CHAR('2') && RANGE('0', '4') && DIGIT);
}

bool	URIParser::readDecOctetBlock4()
{
  RULE(readText("25") && RANGE('0', '5'));
}

bool	URIParser::readRegName()
{
  LOOP(readUnreserved() ||
       readPctEncoded() ||
       readSubDelims());
}

bool	URIParser::readPath()
{
  RULE(readPathAbempty() ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readPathAbempty()
{
  LOOP(CHAR('/') && readSegment());
}

bool	URIParser::readPathAbsolute()
{
  RULE(CHAR('/') &&
       readPathAbsoluteBool());
}

bool	URIParser::readPathAbsoluteBool()
{
  BOOL(readSegmentNz() &&
       readPathAbsoluteLoop());
}

bool	URIParser::readPathAbsoluteLoop()
{
  LOOP(CHAR('/') && readSegment());
}

bool	URIParser::readPathNoscheme()
{
  RULE(readSegmentNzNc() &&
       readPathNoschemeLoop());
}

bool	URIParser::readPathNoschemeLoop()
{
  LOOP(CHAR('/') && readSegment());
}

bool	URIParser::readPathRootless()
{
  RULE(readSegmentNz() &&
       readPathRootlessLoop());
}

bool	URIParser::readPathRootlessLoop()
{
  LOOP(CHAR('/') && readSegment());
}

bool	URIParser::readPathEmpty()
{
  RULE(true);
}

bool	URIParser::readSegment()
{
  LOOP(readPchar());
}

bool	URIParser::readSegmentNz()
{
  LOOP1(readPchar());
}

bool	URIParser::readSegmentNzNc()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSegmentNzNcLoop());
}

bool	URIParser::readSegmentNzNcLoop()
{
  LOOP1(readSubDelims() || CHAR('@'));
}

bool	URIParser::readPchar()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR(':') ||
       CHAR('@'));
}

bool	URIParser::readQuery()
{
  LOOP(readPchar() || CHAR('/') || CHAR('?'));
}

bool	URIParser::readFragment()
{
  RULE(readQuery());
}

bool	URIParser::readPctEncoded()
{
  RULE(CHAR('%') && HEXDIG && HEXDIG);
}

bool	URIParser::readUnreserved()
{
  RULE(ALPHA || DIGIT || CHAR('-') || CHAR('.') ||
       CHAR('_') || CHAR('~'));
}

bool	URIParser::readReserved()
{
  RULE(readGenDelims() || readSubDelims());
}

bool	URIParser::readGenDelims()
{
  RULE(CHAR(':') || CHAR('/') || CHAR('?') ||
       CHAR('#') || CHAR('[') || CHAR(']') ||
       CHAR('@'));
}

bool	URIParser::readSubDelims()
{
  RULE(CHAR('!') || CHAR('$') || CHAR('&') ||
       CHAR('\'') || CHAR('(') || CHAR(')') ||
       CHAR('*') || CHAR('+') || CHAR(',') ||
       CHAR(';') || CHAR('='));
}
