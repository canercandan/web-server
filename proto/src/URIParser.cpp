//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Thu Aug  7 11:56:05 2008 morgan armand
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
       readURI1() &&
       readURI2());
}

bool	URIParser::readURI1()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readURI2()
{
  BOOL(CHAR('#') && readFragment());
}

bool	URIParser::readHierPart()
{
  RULE(readHierPart1() ||
       readPathAbsolute() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readHierPart1()
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
       readAbsoluteURI1());
}

bool	URIParser::readAbsoluteURI1()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readRelativeRef()
{
  RULE(readRelativePart() &&
       readRelativeRef1() &&
       readRelativeRef2());
}

bool	URIParser::readRelativeRef1()
{
  BOOL(CHAR('?') && readQuery());
}

bool	URIParser::readRelativeRef2()
{
  BOOL(CHAR('#') && readFragment());
}

bool	URIParser::readRelativePart()
{
  RULE(readRelativePart1() ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathEmpty());
}

bool	URIParser::readRelativePart1()
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
  LOOP(ALPHA || DIGIT || CHAR('+') || // *()
       CHAR('-') || CHAR('.'));
}

bool	URIParser::readAuthority()
{
  RULE(readAuthority1() &&
       readHost() &&
       readAuthority2());
}

bool	URIParser::readAuthority1()
{
  BOOL(readUserinfo() && CHAR('@'));
}


bool	URIParser::readAuthority2()
{
  BOOL(CHAR(':') && readPort());
}

bool	URIParser::readUserinfo()
{
  LOOP(readUnreserved() || // *()
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
       readIPLiteral1() &&
       CHAR(']'));
}

bool	URIParser::readIPLiteral1()
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
  LOOP1(HEXDIG); // 1*()
}

bool	URIParser::readIPvFutureLoop2()
{
  LOOP1(readUnreserved() || // 1*()
	readSubDelims() ||
	CHAR(':'));
}

bool	URIParser::readIPv6address()
{
  RULE(false);
}

bool	URIParser::readH16()
{
  RULE(HEXDIG && HEXDIG && HEXDIG && HEXDIG); // 1*4()
}

bool	URIParser::readLs32()
{
  RULE(readLs321() ||
       readIPv4address());
}

bool	URIParser::readLs321()
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
       readDecOctet1() ||
       readDecOctet2() ||
       readDecOctet3() ||
       readDecOctet4());
}

bool	URIParser::readDecOctet1()
{
  RULE(RANGE('1', '9') && DIGIT);
}

bool	URIParser::readDecOctet2()
{
  RULE(CHAR('1') && DIGIT && DIGIT);
}

bool	URIParser::readDecOctet3()
{
  RULE(CHAR('2') && RANGE('0', '4') && DIGIT);
}

bool	URIParser::readDecOctet4()
{
  RULE(readText("25") && RANGE('0', '5'));
}

bool	URIParser::readRegName()
{
  LOOP(readUnreserved() || // *()
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
  LOOP(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathAbsolute()
{
  RULE(CHAR('/') &&
       readPathAbsolute1());
}

bool	URIParser::readPathAbsolute1()
{
  BOOL(readSegmentNz() &&
       readPathAbsoluteLoop());
}

bool	URIParser::readPathAbsoluteLoop()
{
  LOOP(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathNoscheme()
{
  RULE(readSegmentNzNc() &&
       readPathNoschemeLoop());
}

bool	URIParser::readPathNoschemeLoop()
{
  LOOP(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathRootless()
{
  RULE(readSegmentNz() &&
       readPathRootlessLoop());
}

bool	URIParser::readPathRootlessLoop()
{
  LOOP(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathEmpty()
{
  RULE(true);
}

bool	URIParser::readSegment()
{
  LOOP(readPchar()); // *()
}

bool	URIParser::readSegmentNz()
{
  LOOP1(readPchar()); // 1*()
}

bool	URIParser::readSegmentNzNc()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSegmentNzNcLoop());
}

bool	URIParser::readSegmentNzNcLoop()
{
  LOOP1(readSubDelims() || CHAR('@')); // 1*()
}

bool	URIParser::readPchar()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR(':') ||
       CHAR('@'));
}

bool	URIParser::readQuery()
{
  LOOP(readPchar() || CHAR('/') || CHAR('?')); // *()
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
