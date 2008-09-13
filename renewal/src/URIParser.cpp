//
// URIParser.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 15:33:28 2008 caner candan
// Last update Sat Sep 13 22:06:15 2008 caner candan
//

#include <sstream>
#include "URIParser.h"

URIParser::URIParser(Consumer& consumer)
  : _consumer(consumer)
{}

bool	URIParser::run()
{
  return (CHAR('*') ||
	  this->_readAbsoluteURI() ||
	  (this->_readPathAbsolute() &&
	   this->_readPathAbsoluteQuery()) ||
	  this->_readAuthority());
}

bool	URIParser::_readHierPart()
{
  return ((TEXT_("//") &&
	   this->_readAuthority() &&
	   this->_readPathAbempty()) ||
	  this->_readPathAbsolute() ||
	  this->_readPathRootless() ||
	  this->_readPathEmpty());
}

bool	URIParser::_readAbsoluteURI()
{
  this->_consumer.save();
  if (this->_readScheme() &&
      CHAR(':') &&
      this->_readHierPart() &&
      this->_readAbsoluteURIOpt())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	URIParser::_readAbsoluteURIOpt()
{
  this->_consumer.save();
  if (CHAR('?') && this->_readQuery())
    return (true);
  this->_consumer.back();
  return (true);
}

bool	URIParser::_readScheme()
{
  if (!ALPHA)
    return (false);
  while (ALPHA || DIGIT ||
	 CHAR('+') || CHAR('-') || CHAR('.'));
  return (true);
}

bool	URIParser::_readAuthority()
{
  return(this->_readAuthorityOpt1() &&
	 this->_readHost() &&
	 this->_readAuthorityOpt2());
}

bool	URIParser::_readAuthorityOpt1()
{
  this->_consumer.save();
  if (this->_readUserInfo() && CHAR('@'))
    return (true);
  this->_consumer.back();
  return (true);
}

bool	URIParser::_readAuthorityOpt2()
{
  this->_consumer.save();
  if (CHAR(':') && this->_readPort())
    return (true);
  this->_consumer.back();
  return (true);
}

bool	URIParser::_readUserInfo()
{
  while (this->_readUnreserved() ||
	 this->_readPctEncoded() ||
	 this->_readSubDelims() ||
	 CHAR(':'));
  return (true);
}

bool	URIParser::_readHost()
{
  std::string	host;

  this->_consumer.prepare();
  if  (this->_readIPLiteral() ||
       this->_readIPv4address() ||
       this->_readRegName())
    {
      this->_consumer.extract(host);
      this->_consumer.consume();
      this->_setHost(host);
      return (true);
    }
  return (false);
}

bool	URIParser::_readPort()
{
  std::string	port;

  this->_consumer.prepare();
  while (DIGIT);
  this->_consumer.extract(port);
  this->_consumer.consume();
  this->_setPort(port);
  return (true);
}

bool	URIParser::_readIPLiteral()
{
  return(CHAR('[') &&
	 (this->_readIPv6address() ||
	  this->_readIPvFuture()) &&
	 CHAR(']'));
}

bool	URIParser::_readIPvFuture()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::_readIPv6address()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::_readIPv4address()
{
  return (this->_readDecOctet() && CHAR('.') &&
	  this->_readDecOctet() && CHAR('.') &&
	  this->_readDecOctet() && CHAR('.') &&
	  this->_readDecOctet());
}

bool	URIParser::_readDecOctet()
{
  return(DIGIT ||
	 RANGE('1', '9') &&
	 DIGIT ||
	 (CHAR('1') &&
	  DIGIT &&
	  DIGIT) ||
	 (CHAR('2') &&
	  RANGE('0', '4') &&
	  DIGIT) ||
	 (TEXT_("25") &&
	  RANGE('0', '5')));
}

bool	URIParser::_readRegName()
{
  while (this->_readUnreserved() ||
	 this->_readPctEncoded() ||
	 this->_readSubDelims());
  return (true);
}

bool	URIParser::_readPath()
{
  return(this->_readPathAbempty() ||
	 this->_readPathAbsolute() ||
	 this->_readPathNoScheme() ||
	 this->_readPathRootless() ||
	 this->_readPathEmpty());
}

bool	URIParser::_readPathAbempty()
{
  std::string	path;

  this->_consumer.prepare();
  while (this->_readPathAbemptyPart2());
  this->_consumer.extract(path);
  this->_consumer.consume();
  this->_setPath(path);
  return (true);
}

bool	URIParser::_readPathAbemptyPart2()
{
  this->_consumer.save();
  if (CHAR('/') &&
      this->_readSegment())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	URIParser::_readPathAbsolute()
{
  std::string	path;

  this->_consumer.prepare();
  if (CHAR('/') &&
      this->_readPathAbsoluteOpt())
    {
      this->_consumer.extract(path);
      this->_consumer.consume();
      this->_setPath(path);
      return (true);
    }
  return (false);
}

bool	URIParser::_readPathAbsoluteQuery()
{
  if (CHAR('?'))
    this->_readQuery();
  return (true);
}

bool	URIParser::_readPathAbsoluteOpt()
{
  if (this->_readSegmentNz())
    while(this->_readPathAbsolutePart2());
  return (true);
}

bool	URIParser::_readPathAbsolutePart2()
{
  this->_consumer.save();
  if (CHAR('/') &&
      this->_readSegment())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	URIParser::_readPathNoScheme()
{
  if (this->_readSegmentNzNc())
    {
      while (this->_readPathNoSchemePart2());
      return (true);
    }
  return (false);
}

bool	URIParser::_readPathNoSchemePart2()
{
  this->_consumer.save();
  if (CHAR('/') &&
      this->_readSegment())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	URIParser::_readPathRootless()
{
  std::string	path;

  this->_consumer.prepare();
  if (this->_readSegmentNz())
    {
      while (this->_readPathRootlessPart2());
      this->_consumer.extract(path);
      this->_consumer.consume();
      this->_setPath(path);
      return (true);
    }
  return (false);
}

bool	URIParser::_readPathRootlessPart2()
{
  this->_consumer.save();
  if (CHAR('/') &&
      this->_readSegment())
    return (true);
  this->_consumer.back();
  return (false);
}

bool	URIParser::_readPathEmpty()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::_readSegment()
{
  while (this->_readPchar());
  return (true);
}

bool	URIParser::_readSegmentNz()
{
  if (!this->_readPchar())
    return (false);
  while (this->_readPchar());
  return (true);
}

bool	URIParser::_readSegmentNzNc()
{
  int	i;

  for (i = 0;
       (this->_readUnreserved() &&
	this->_readPctEncoded() &&
	this->_readSubDelims() &&
	CHAR('@'));
       i++);
  return (i > 0);
}

bool	URIParser::_readPchar()
{
  return (this->_readUnreserved() ||
	  this->_readPctEncoded() ||
	  this->_readSubDelims() ||
	  CHAR(':') ||
	  CHAR('@'));
}

bool	URIParser::_readQuery()
{
  this->_consumer.prepare();
  while (this->_readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  this->_setQuery(this->_consumer.extract());
  return (true);
}

bool	URIParser::_readFragment()
{
  while (this->_readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  return (true);
}

bool	URIParser::_readPctEncoded()
{
  return (CHAR('%') &&
	  HEXDIG &&
	  HEXDIG);
}

bool	URIParser::_readUnreserved()
{
  return(ALPHA ||
	 DIGIT ||
	 CHAR('-') ||
	 CHAR('.') ||
	 CHAR('_') ||
	 CHAR('~'));
}

bool	URIParser::_readReserved()
{
  return (this->_readGenDelims() ||
	  this->_readSubDelims());
}

bool	URIParser::_readGenDelims()
{
  return (CHAR(':') || CHAR('/') ||
	  CHAR('?') || CHAR('#') ||
	  CHAR('[') || CHAR(']') ||
	  CHAR('@'));
}

bool	URIParser::_readSubDelims()
{
  return (CHAR('!') || CHAR('$') ||
	  CHAR('&') || CHAR('\'') ||
	  CHAR('(') || CHAR(')') ||
	  CHAR('*') || CHAR('+') ||
	  CHAR(',') || CHAR(';') ||
	  CHAR('='));
}
