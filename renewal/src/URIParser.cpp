//
// URIParser.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Fri Sep 12 15:33:28 2008 caner candan
// Last update Fri Sep 12 19:14:09 2008 caner candan
//

#include <sstream>
#include "URIParser.h"

URIParser::URIParser(Consumer& consumer)
  : _consumer(consumer)
{}

bool	URIParser::run()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR('*') ||
		this->_readAbsoluteURI() ||
		(this->_readPathAbsolute() &&
		 this->_readPathAbsoluteQuery()) ||
		this->_readAuthority());
}

bool	URIParser::_readHierPart()
{
  DEBUG_ENTER;
  DEBUG_RETURN ((TEXT_("//") &&
		 this->_readAuthority() &&
		 this->_readPathAbempty()) ||
		this->_readPathAbsolute() ||
		this->_readPathRootless() ||
		this->_readPathEmpty());
}

bool	URIParser::_readAbsoluteURI()
{
  DEBUG_ENTER;
  this->_consumer.save();
  if (this->_readScheme() &&
      CHAR(':') &&
      this->_readHierPart() &&
      this->_readAbsoluteURIOpt())
    DEBUG_RETURN (true);
  this->_consumer.back();
  DEBUG_RETURN (false);
}

bool	URIParser::_readAbsoluteURIOpt()
{
  DEBUG_ENTER;
  this->_consumer.save();
  if (CHAR('?') && this->_readQuery())
    DEBUG_RETURN (true);
  this->_consumer.back();
  DEBUG_RETURN (true);
}

bool	URIParser::_readScheme()
{
  DEBUG_ENTER;
  if (!ALPHA)
    DEBUG_RETURN (false);
  while (ALPHA || DIGIT ||
	 CHAR('+') || CHAR('-') || CHAR('.'));
  DEBUG_RETURN (true);
}

bool	URIParser::_readAuthority()
{
  DEBUG_ENTER;
  DEBUG_RETURN(this->_readAuthorityOpt1() &&
	       this->_readHost() &&
	       this->_readAuthorityOpt2());
}

bool	URIParser::_readAuthorityOpt1()
{
  DEBUG_ENTER;
  this->_consumer.save();
  if (this->_readUserInfo() && CHAR('@'))
    DEBUG_RETURN (true);
  this->_consumer.back();
  DEBUG_RETURN (true);
}

bool	URIParser::_readAuthorityOpt2()
{
  DEBUG_ENTER;
  this->_consumer.save();
  if (CHAR(':') && this->_readPort())
    DEBUG_RETURN (true);
  this->_consumer.back();
  DEBUG_RETURN (true);
}

bool	URIParser::_readUserInfo()
{
  DEBUG_ENTER;
  while (this->_readUnreserved() ||
	 this->_readPctEncoded() ||
	 this->_readSubDelims() ||
	 CHAR(':'));
  DEBUG_RETURN (true);
}

bool	URIParser::_readHost()
{
  std::string	host;

  DEBUG_ENTER;
  this->_consumer.prepare();

  if  (this->_readIPLiteral() ||
       this->_readIPv4address() ||
       this->_readRegName())
    {
      this->_consumer.extract(host);
      this->_consumer.consume();
      this->_setHost(host);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::_readPort()
{
  std::string	port;

  DEBUG_ENTER;
  this->_consumer.prepare();
  while (DIGIT);
  this->_consumer.extract(port);
  this->_consumer.consume();
  this->_setPort(port);
  DEBUG_RETURN (true);
}

bool	URIParser::_readIPLiteral()
{
  DEBUG_ENTER;
  DEBUG_RETURN(CHAR('[') &&
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
  DEBUG_ENTER;
  DEBUG_RETURN (this->_readDecOctet() && CHAR('.') &&
		this->_readDecOctet() && CHAR('.') &&
		this->_readDecOctet() && CHAR('.') &&
		this->_readDecOctet());
}

bool	URIParser::_readDecOctet()
{
  DEBUG_ENTER;
  DEBUG_RETURN(DIGIT ||
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
  DEBUG_ENTER;
  while (this->_readUnreserved() ||
	 this->_readPctEncoded() ||
	 this->_readSubDelims());
  DEBUG_RETURN (true);
}

bool	URIParser::_readPath()
{
  DEBUG_ENTER;
  DEBUG_RETURN(this->_readPathAbempty() ||
	       this->_readPathAbsolute() ||
	       this->_readPathNoScheme() ||
	       this->_readPathRootless() ||
	       this->_readPathEmpty());
}

bool	URIParser::_readPathAbempty()
{
  std::string	path;

  DEBUG_ENTER;
  this->_consumer.prepare();
  while (this->_readPathAbemptyPart2());
  this->_consumer.extract(path);
  this->_consumer.consume();
  this->_setPath(path);
  //  this->_request.setUrlPath(path);
  DEBUG_RETURN (true);
}

bool	URIParser::_readPathAbemptyPart2()
{
  DEBUG_ENTER;
  this->_consumer.save();

  if (CHAR('/') &&
      this->_readSegment())
    DEBUG_RETURN (true);

  this->_consumer.back();
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathAbsolute()
{
  std::string	path;

  DEBUG_ENTER;
  this->_consumer.prepare();

  if (CHAR('/') &&
      this->_readPathAbsoluteOpt())
    {
      this->_consumer.extract(path);
      this->_consumer.consume();
      this->_setPath(path);
      //this->_request.setUri(path);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathAbsoluteQuery()
{
  DEBUG_ENTER;
  if (CHAR('?'))
    this->_readQuery();
  DEBUG_RETURN (true);
}

bool	URIParser::_readPathAbsoluteOpt()
{
  DEBUG_ENTER;
  if (this->_readSegmentNz())
    while(this->_readPathAbsolutePart2());
  DEBUG_RETURN (true);
}

bool	URIParser::_readPathAbsolutePart2()
{
  DEBUG_ENTER;
  this->_consumer.save();

  if (CHAR('/') &&
      this->_readSegment())
    DEBUG_RETURN (true);

  this->_consumer.back();
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathNoScheme()
{
  DEBUG_ENTER;
  if (this->_readSegmentNzNc())
    {
      while (this->_readPathNoSchemePart2());
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathNoSchemePart2()
{
  DEBUG_ENTER;
  this->_consumer.save();

  if (CHAR('/') &&
      this->_readSegment())
    DEBUG_RETURN (true);

  this->_consumer.back();
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathRootless()
{
  std::string	path;

  DEBUG_ENTER;
  this->_consumer.prepare();

  if (this->_readSegmentNz())
    {
      while (this->_readPathRootlessPart2());
      this->_consumer.extract(path);
      this->_consumer.consume();
      this->_setPath(path);
      //this->_request.setUri(path);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathRootlessPart2()
{
  DEBUG_ENTER;
  this->_consumer.save();

  if (CHAR('/') &&
      this->_readSegment())
    DEBUG_RETURN (true);

  this->_consumer.back();
  DEBUG_RETURN (false);
}

bool	URIParser::_readPathEmpty()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::_readSegment()
{
  DEBUG_ENTER;
  while (this->_readPchar());
  DEBUG_RETURN (true);
}

bool	URIParser::_readSegmentNz()
{
  DEBUG_ENTER;
  if (!this->_readPchar())
    DEBUG_RETURN (false);
  while (this->_readPchar());
  DEBUG_RETURN (true);
}

bool	URIParser::_readSegmentNzNc()
{
  int	i;

  DEBUG_ENTER;
  i = 0;
  while (this->_readUnreserved() &&
	 this->_readPctEncoded() &&
	 this->_readSubDelims() &&
	 CHAR('@'))
    i++;
  DEBUG_RETURN (i > 0);
}

bool	URIParser::_readPchar()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->_readUnreserved() ||
		this->_readPctEncoded() ||
		this->_readSubDelims() ||
		CHAR(':') ||
		CHAR('@'));
}

bool	URIParser::_readQuery()
{
  DEBUG_ENTER;
  this->_consumer.prepare();
  while (this->_readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  this->_setQuery(this->_consumer.extract());
  //this->_request.setUrlQuery(this->_consumer.extract());
  DEBUG_RETURN (true);
}

bool	URIParser::_readFragment()
{
  DEBUG_ENTER;
  while (this->_readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  DEBUG_RETURN (true);
}

bool	URIParser::_readPctEncoded()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR('%') &&
		HEXDIG &&
		HEXDIG);
}

bool	URIParser::_readUnreserved()
{
  DEBUG_ENTER;
  DEBUG_RETURN(ALPHA ||
	       DIGIT ||
	       CHAR('-') ||
	       CHAR('.') ||
	       CHAR('_') ||
	       CHAR('~'));
}

bool	URIParser::_readReserved()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->_readGenDelims() ||
		this->_readSubDelims());
}

bool	URIParser::_readGenDelims()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR(':') || CHAR('/') ||
		CHAR('?') || CHAR('#') ||
		CHAR('[') || CHAR(']') ||
		CHAR('@'));
}

bool	URIParser::_readSubDelims()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR('!') || CHAR('$') ||
		CHAR('&') || CHAR('\'') ||
		CHAR('(') || CHAR(')') ||
		CHAR('*') || CHAR('+') ||
		CHAR(',') || CHAR(';') ||
		CHAR('='));
}
