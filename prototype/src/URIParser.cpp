//
// URIParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:12 2008 morgan armand
// Last update Tue Aug 12 16:55:14 2008 caner candan
//

#include <sstream>
#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod, HttpRequest* request)
  : ABNFParser(prod), _request(request)
{
  std::cout << _request << std::endl;
}

URIParser::~URIParser()
{
}

bool	URIParser::readHierPart()
{
  DEBUG_ENTER;
  if ((TEXT("//") &&
       this->readAuthority() &&
       this->readPathAbempty()) ||
      this->readPathAbsolute() ||
      this->readPathRootless() ||
      this->readPathEmpty())
    DEBUG_RETURN (true);
  DEBUG_RETURN (false);
}

bool	URIParser::readAbsoluteURI()
{
  DEBUG_ENTER;
  this->save();
  if (this->readScheme() &&
      CHAR(':') &&
      this->readHierPart() &&
      this->readAbsoluteURIOpt())
    DEBUG_RETURN (true);
  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readAbsoluteURIOpt()
{
  DEBUG_ENTER;
  this->save();
  if (CHAR('?') && this->readQuery())
    DEBUG_RETURN (true);
  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readScheme()
{
  DEBUG_ENTER;
  if (!this->readALPHA())
    DEBUG_RETURN (false);
  while (ALPHA || DIGIT ||
	 CHAR('+') || CHAR('-') || CHAR('.'));
  DEBUG_RETURN (true);
}

bool	URIParser::readAuthority()
{
  std::string	host;

  DEBUG_ENTER;
  if (!(this->readAuthorityOpt1() &&
	this->readHost(host) &&
	this->readAuthorityOpt2()))
    return (false);
  this->_request->getHttpUrl().getHost().setHost(host);
  return (true);
}

bool	URIParser::readAuthorityOpt1()
{
  DEBUG_ENTER;
  this->save();
  if (this->readUserInfo() && CHAR('@'))
    DEBUG_RETURN (true);
  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readAuthorityOpt2()
{
  std::string	port;

  DEBUG_ENTER;
  this->save();
  if (CHAR(':') && this->readPort(port))
    {
      std::stringstream	ss(port);
      int		portInt;

      ss >> portInt;
      this->_request->getHttpUrl().getHost().setPort(portInt);
      DEBUG_RETURN (true);
    }
  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readUserInfo()
{
  DEBUG_ENTER;
  while (this->readUnreserved() ||
	 this->readPctEncoded() ||
	 this->readSubDelims() ||
	 CHAR(':'));
  DEBUG_RETURN (true);
}

bool	URIParser::readHost(std::string& extract)
{
  DEBUG_ENTER;
  this->prepare();

  if  (this->readIPLiteral() ||
       this->readIPv4address() ||
       this->readRegName())
    {
      this->extract(extract);
      this->consume();
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPort(std::string& extract)
{
  DEBUG_ENTER;
  this->prepare();
  while (this->readDIGIT());
  this->extract(extract);
  this->consume();
  DEBUG_RETURN (true);
}

bool	URIParser::readIPLiteral()
{
  DEBUG_ENTER;
  DEBUG_RETURN(CHAR('[') &&
	       (this->readIPv6address() ||
		this->readIPvFuture()) &&
	       CHAR(']'));
}

bool	URIParser::readIPvFuture()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::readIPv6address()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::readIPv4address()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readDecOctet() && CHAR('.') &&
		this->readDecOctet() && CHAR('.') &&
		this->readDecOctet() && CHAR('.') &&
		this->readDecOctet());
}

bool	URIParser::readDecOctet()
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
	       (TEXT("25") &&
		RANGE('0', '5')));
}

bool	URIParser::readRegName()
{
  DEBUG_ENTER;
  while (this->readUnreserved() ||
	 this->readPctEncoded() ||
	 this->readSubDelims());
  DEBUG_RETURN (true);
}

bool	URIParser::readPath()
{
  DEBUG_ENTER;
  DEBUG_RETURN(this->readPathAbempty() ||
	       this->readPathAbsolute() ||
	       this->readPathNoScheme() ||
	       this->readPathRootless() ||
	       this->readPathEmpty());
}

bool	URIParser::readPathAbempty()
{
  std::string	path;

  DEBUG_ENTER;
  this->prepare();
  while (this->readPathAbemptyPart2());
  this->extract(path);
  this->consume();
  this->_request->setPath(path);
  DEBUG_RETURN (true);
}

bool	URIParser::readPathAbemptyPart2()
{
  DEBUG_ENTER;
  this->save();

  if (CHAR('/') &&
      this->readSegment())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readPathAbsolute()
{
  std::string	path;

  DEBUG_ENTER;
  this->prepare();

  if (CHAR('/') &&
      this->readPathAbsoluteOpt())
    {
      this->extract(path);
      this->consume();
      this->_request->setPath(path);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPathAbsoluteOpt()
{
  DEBUG_ENTER;
  if (this->readSegmentNz())
    while(this->readPathAbsolutePart2());
  DEBUG_RETURN (true);
}

bool	URIParser::readPathAbsolutePart2()
{
  DEBUG_ENTER;
  this->save();

  if (CHAR('/') &&
      this->readSegment())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readPathNoScheme()
{
  DEBUG_ENTER;
  if (this->readSegmentNzNc())
    {
      while (this->readPathNoSchemePart2());
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPathNoSchemePart2()
{
  DEBUG_ENTER;
  this->save();

  if (CHAR('/') &&
      this->readSegment())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readPathRootless()
{
  std::string	path;

  DEBUG_ENTER;
  this->prepare();

  if (this->readSegmentNz())
    {
      while (this->readPathRootlessPart2());
      this->extract(path);
      this->consume();
      this->_request->setPath(path);
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPathRootlessPart2()
{
  DEBUG_ENTER;
  this->save();

  if (CHAR('/') &&
      this->readSegment())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readPathEmpty()
{
  NOT_IMPLEMENTED;
}

bool	URIParser::readSegment()
{
  DEBUG_ENTER;
  while (this->readPchar());
  DEBUG_RETURN (true);
}

bool	URIParser::readSegmentNz()
{
  DEBUG_ENTER;
  if (!this->readPchar())
    DEBUG_RETURN (false);
  while (this->readPchar());
  DEBUG_RETURN (true);
}

bool	URIParser::readSegmentNzNc()
{
  int	i;

  DEBUG_ENTER;
  i = 0;
  while (this->readUnreserved() &&
	 this->readPctEncoded() &&
	 this->readSubDelims() &&
	 CHAR('@'))
    i++;
  DEBUG_RETURN (i > 0);
}

bool	URIParser::readPchar()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readUnreserved() ||
		this->readPctEncoded() ||
		this->readSubDelims() ||
		CHAR(':') ||
		CHAR('@'));
}

bool	URIParser::readQuery()
{
  DEBUG_ENTER;
  while (this->readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  DEBUG_RETURN (true);
}

bool	URIParser::readFragment()
{
  DEBUG_ENTER;
  while (this->readPchar() ||
	 CHAR('/') ||
	 CHAR('?'));
  DEBUG_RETURN (true);
}

bool	URIParser::readPctEncoded()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR('%') &&
		HEXDIG &&
		HEXDIG);
}

bool	URIParser::readUnreserved()
{
  DEBUG_ENTER;
  DEBUG_RETURN(ALPHA ||
	       DIGIT ||
	       CHAR('-') ||
	       CHAR('.') ||
	       CHAR('_') ||
	       CHAR('~'));
}

bool	URIParser::readReserved()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readGenDelims() ||
		this->readSubDelims());
}

bool	URIParser::readGenDelims()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR(':') || CHAR('/') ||
		CHAR('?') || CHAR('#') ||
		CHAR('[') || CHAR(']') ||
		CHAR('@'));
}

bool	URIParser::readSubDelims()
{
  DEBUG_ENTER;
  DEBUG_RETURN (CHAR('!') || CHAR('$') ||
		CHAR('&') || CHAR('\'') ||
		CHAR('(') || CHAR(')') ||
		CHAR('*') || CHAR('+') ||
		CHAR(',') || CHAR(';') ||
		CHAR('='));
}
