//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Wed Aug  6 19:28:14 2008 caner candan
//

#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod)
  : ABNFParser(prod)
{}

URIParser::~URIParser()
{}

bool	URIParser::readURI()
{
  DEBUG_ENTER();
  RULE(readScheme() && CHAR(':') &&
       readHierPart() &&
       (CHAR('?') && readQuery()) && // []
       (CHAR('#') && readFragment())); // []
}

bool	URIParser::readHierPart()
{
  DEBUG_ENTER();
  RULE((readText("//") && // ()
	readAuthority() &&
	readPathAbempty()) ||
       readPathAbsolute() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readURIReference()
{
  DEBUG_ENTER();
  RULE(readURI() || readRelativeRef());
}

bool	URIParser::readAbsoluteURI()
{
  DEBUG_ENTER();
  RULE(readScheme() && CHAR(':') &&
       readHierPart() &&
       (CHAR('?') && readQuery())); // []
}

bool	URIParser::readRelativeRef()
{
  DEBUG_ENTER();
  RULE(readRelativePart() &&
       (CHAR('?') && readQuery()) && // []
       (CHAR('#') && readFragment())); // []
}

bool	URIParser::readRelativePart()
{
  DEBUG_ENTER();
  RULE((readText("//") && // ()
	readAuthority() &&
	readPathAbempty()) ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathEmpty());
}

bool	URIParser::readScheme()
{
  DEBUG_ENTER();
  RULE(ALPHA &&
       (ALPHA || DIGIT || CHAR('+') || // *()
	CHAR('-') || CHAR('.')));
}

bool	URIParser::readAuthority()
{
  DEBUG_ENTER();
  RULE((readUserinfo() && CHAR('@')) && // []
       readHost() &&
       (CHAR(':') && readPort())); // []
}

bool	URIParser::readUserinfo()
{
  DEBUG_ENTER();
  RULE(readUnreserved() || // *()
       readPctEncoded() ||
       readSubDelims() ||
       CHAR(':'));
}

bool	URIParser::readHost()
{
  DEBUG_ENTER();
  RULE(readIPLiteral() ||
       readIPv4address() ||
       readRegName());
}

bool	URIParser::readPort()
{
  DEBUG_ENTER();
  RULE(DIGIT); // *()
}

bool	URIParser::readIPLiteral()
{
  DEBUG_ENTER();
  RULE(CHAR('[') &&
       (readIPv6address() || readIPvFuture()) && // ()
       CHAR(']'));
}

bool	URIParser::readIPvFuture()
{
  DEBUG_ENTER();
  RULE(CHAR('v') &&
       (HEXDIG) && // 1*()
       CHAR('.') &&
       (readUnreserved() || // 1*()
	readSubDelims() ||
	CHAR(':')));
}

bool	URIParser::readIPv6address()
{
  DEBUG_ENTER();
  RULE(false);
}

bool	URIParser::readH16()
{
  DEBUG_ENTER();
  RULE(HEXDIG); // 1*4()
}

bool	URIParser::readLs32()
{
  DEBUG_ENTER();
  RULE((readH16() && CHAR(':') && readH16()) || // ()
       readIPv4address());
}

bool	URIParser::readIPv4address()
{
  DEBUG_ENTER();
  RULE(readDecOctet() && CHAR('.') &&
       readDecOctet() && CHAR('.') &&
       readDecOctet() && CHAR('.') &&
       readDecOctet());
}

bool	URIParser::readDecOctet()
{
  DEBUG_ENTER();
  RULE(DIGIT ||
       (RANGE('1', '9') && DIGIT) || // ()
       (CHAR('1') && DIGIT && DIGIT) || // ()
       (CHAR('2') && RANGE('0', '4') && DIGIT) || // ()
       (readText("25") && RANGE('0', '5'))); // ()
}

bool	URIParser::readRegName()
{
  DEBUG_ENTER();
  RULE(readUnreserved() || // *()
       readPctEncoded() ||
       readSubDelims());
}

bool	URIParser::readPath()
{
  DEBUG_ENTER();
  RULE(readPathAbempty() ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readPathAbempty()
{
  DEBUG_ENTER();
  RULE(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathAbsolute()
{
  DEBUG_ENTER();
  RULE(CHAR('/') &&
       (readSegmentNz() && // []
	(CHAR('/') && readSegment()))); // *()
}

bool	URIParser::readPathNoscheme()
{
  DEBUG_ENTER();
  RULE(readSegmentNzNc() &&
       (CHAR('/') && readSegment())); // *()
}

bool	URIParser::readPathRootless()
{
  DEBUG_ENTER();
  RULE(readSegmentNz() &&
       (CHAR('/') && readSegment())); // *()
}

bool	URIParser::readPathEmpty()
{
  DEBUG_ENTER();
  RULE(true);
}

bool	URIParser::readSegment()
{
  DEBUG_ENTER();
  RULE(readPchar()); // *()
}

bool	URIParser::readSegmentNz()
{
  DEBUG_ENTER();
  RULE(readPchar()); // 1*()
}

bool	URIParser::readSegmentNzNc()
{
  DEBUG_ENTER();
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR('@')); // 1*()
}

bool	URIParser::readPchar()
{
  DEBUG_ENTER();
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR(':') ||
       CHAR('@'));
}

bool	URIParser::readQuery()
{
  DEBUG_ENTER();
  RULE(readPchar() || CHAR('/') || CHAR('?')); // *()
}

bool	URIParser::readFragment()
{
  DEBUG_ENTER();
  RULE(readQuery());
}

bool	URIParser::readPctEncoded()
{
  DEBUG_ENTER();
  RULE(CHAR('%') && HEXDIG && HEXDIG);
}

bool	URIParser::readUnreserved()
{
  DEBUG_ENTER();
  RULE(ALPHA || DIGIT || CHAR('-') || CHAR('.') ||
       CHAR('_') || CHAR('~'));
}

bool	URIParser::readReserved()
{
  DEBUG_ENTER();
  RULE(readGenDelims() || readSubDelims());
}

bool	URIParser::readGenDelims()
{
  DEBUG_ENTER();
  RULE(CHAR(':') || CHAR('/') || CHAR('?') ||
       CHAR('#') || CHAR('[') || CHAR(']') ||
       CHAR('@'));
}

bool	URIParser::readSubDelims()
{
  DEBUG_ENTER();
  RULE(CHAR('!') || CHAR('$') || CHAR('&') ||
       CHAR('\'') || CHAR('(') || CHAR(')') ||
       CHAR('*') || CHAR('+') || CHAR(',') ||
       CHAR(';') || CHAR('='));
}
