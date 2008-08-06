//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Wed Aug  6 19:25:46 2008 caner candan
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
       (CHAR('?') && readQuery()) && // []
       (CHAR('#') && readFragment())); // []
}

bool	URIParser::readHierPart()
{
  RULE((readText("//") && // ()
	readAuthority() &&
	readPathAbempty()) ||
       readPathAbsolute() ||
       readPathRootless() ||
       readPathEmpty());
}

bool	URIParser::readURIReference()
{
  RULE(readURI() || readRelativeRef());
}

bool	URIParser::readAbsoluteURI()
{
  RULE(readScheme() && CHAR(':') &&
       readHierPart() &&
       (CHAR('?') && readQuery())); // []
}

bool	URIParser::readRelativeRef()
{
  RULE(readRelativePart() &&
       (CHAR('?') && readQuery()) && // []
       (CHAR('#') && readFragment())); // []
}

bool	URIParser::readRelativePart()
{
  RULE((readText("//") && // ()
	readAuthority() &&
	readPathAbempty()) ||
       readPathAbsolute() ||
       readPathNoscheme() ||
       readPathEmpty());
}

bool	URIParser::readScheme()
{
  RULE(ALPHA &&
       (ALPHA || DIGIT || CHAR('+') || // *()
	CHAR('-') || CHAR('.')));
}

bool	URIParser::readAuthority()
{
  RULE((readUserinfo() && CHAR('@')) && // []
       readHost() &&
       (CHAR(':') && readPort())); // []
}

bool	URIParser::readUserinfo()
{
  RULE(readUnreserved() || // *()
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
  RULE(DIGIT); // *()
}

bool	URIParser::readIPLiteral()
{
  RULE(CHAR('[') &&
       (readIPv6address() || readIPvFuture()) && // ()
       CHAR(']'));
}

bool	URIParser::readIPvFuture()
{
  RULE(CHAR('v') &&
       (HEXDIG) && // 1*()
       CHAR('.') &&
       (readUnreserved() || // 1*()
	readSubDelims() ||
	CHAR(':')));
}

bool	URIParser::readIPv6address()
{
  RULE(false);
}

bool	URIParser::readH16()
{
  RULE(HEXDIG); // 1*4()
}

bool	URIParser::readLs32()
{
  RULE((readH16() && CHAR(':') && readH16()) || // ()
       readIPv4address());
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
       (RANGE('1', '9') && DIGIT) || // ()
       (CHAR('1') && DIGIT && DIGIT) || // ()
       (CHAR('2') && RANGE('0', '4') && DIGIT) || // ()
       (readText("25") && RANGE('0', '5'))); // ()
}

bool	URIParser::readRegName()
{
  RULE(readUnreserved() || // *()
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
  RULE(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathAbsolute()
{
  RULE(CHAR('/') &&
       (readSegmentNz() && // []
	(CHAR('/') && readSegment()))); // *()
}

bool	URIParser::readPathNoscheme()
{
  RULE(readSegmentNzNc() &&
       (CHAR('/') && readSegment())); // *()
}

bool	URIParser::readPathRootless()
{
  RULE(readSegmentNz() &&
       (CHAR('/') && readSegment())); // *()
}

bool	URIParser::readPathEmpty()
{
  RULE(true);
}

bool	URIParser::readSegment()
{
  RULE(readPchar()); // *()
}

bool	URIParser::readSegmentNz()
{
  RULE(readPchar()); // 1*()
}

bool	URIParser::readSegmentNzNc()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR('@')); // 1*()
}

bool	URIParser::readPchar()
{
  RULE(readUnreserved() || readPctEncoded() ||
       readSubDelims() || CHAR(':') ||
       CHAR('@'));
}

bool	URIParser::readQuery()
{
  RULE(readPchar() || CHAR('/') || CHAR('?')); // *()
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
