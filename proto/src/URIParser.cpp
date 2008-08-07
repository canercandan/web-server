//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Thu Aug  7 09:43:28 2008 caner candan
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
       BOOL(CHAR('?') && readQuery()) && // []
       BOOL(CHAR('#') && readFragment())); // []
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
       BOOL(CHAR('?') && readQuery())); // []
}

bool	URIParser::readRelativeRef()
{
  RULE(readRelativePart() &&
       BOOL(CHAR('?') && readQuery()) && // []
       BOOL(CHAR('#') && readFragment())); // []
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
  RULE(ALPHA && readSchemeLoop());
}

bool	URIParser::readSchemeLoop()
{
  LOOP(ALPHA || DIGIT || CHAR('+') || // *()
       CHAR('-') || CHAR('.'));
}

bool	URIParser::readAuthority()
{
  RULE(BOOL(readUserinfo() && CHAR('@')) && // []
       readHost() &&
       BOOL(CHAR(':') && readPort())); // []
}

bool	URIParser::readUserinfo()
{
  RULE(readUserinfoLoop());
}

bool	URIParser::readUserinfoLoop()
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
  RULE(readPortLoop());
}

bool	URIParser::readPortLoop()
{
  LOOP(DIGIT); // *()
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
  RULE(readRegNameLoop());
}

bool	URIParser::readRegNameLoop()
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
  RULE(readPathAbemptyLoop());
}

bool	URIParser::readPathAbemptyLoop()
{
  LOOP(CHAR('/') && readSegment()); // *()
}

bool	URIParser::readPathAbsolute()
{
  RULE(CHAR('/') &&
       BOOL(readSegmentNz() && // []
	    readPathAbsoluteLoop()));
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
  RULE(readSegmentLoop());
}

bool	URIParser::readSegmentLoop()
{
  LOOP(readPchar()); // *()
}

bool	URIParser::readSegmentNz()
{
  RULE(readSegmentNzLoop());
}

bool	URIParser::readSegmentNzLoop()
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
  RULE(readQueryLoop());
}

bool	URIParser::readQueryLoop()
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
