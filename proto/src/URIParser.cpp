//
// URIParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:12 2008 morgan armand
// Last update Fri Aug  8 21:47:50 2008 morgan armand
//

#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod)
  : ABNFParser(prod)
{
}

URIParser::~URIParser()
{
}

bool	URIParser::readHierPart()
{
  DEBUG_ENTER;
  if ((this->readText("//") &&
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
      this->readChar(':') &&
      this->readHierPart() &&
      this->readAbsoluteURIOpt())
    {
      DEBUG_RETURN (true);
    }
  this->back();
  DEBUG_RETURN (false);
}

bool	URIParser::readAbsoluteURIOpt()
{
  DEBUG_ENTER;
  this->save();

  if (this->readChar('?') &&
      this->readQuery())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readScheme()
{
  DEBUG_ENTER;
  if (!this->readALPHA())
    DEBUG_RETURN (false);

  while (this->readALPHA() ||
	 this->readDIGIT() ||
	 this->readChar('+') ||
	 this->readChar('-') ||
	 this->readChar('.'));
  DEBUG_RETURN (true);
}

bool	URIParser::readAuthority()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readAuthorityOpt1() &&
	  this->readHost() &&
	  this->readAuthorityOpt2());
}

bool	URIParser::readAuthorityOpt1()
{
  DEBUG_ENTER;
  this->save();

  if (this->readUserInfo() &&
      this->readChar('@'))
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readAuthorityOpt2()
{
  DEBUG_ENTER;
  this->save();

  if (this->readChar(':') &&
      this->readPort())
    DEBUG_RETURN (true);

  this->back();
  DEBUG_RETURN (true);
}

bool	URIParser::readUserInfo()
{
  DEBUG_ENTER;
  while (this->readUnreserved() ||
	 this->readPctEncoded() ||
	 this->readSubDelims() ||
	 this->readChar(':'));
  DEBUG_RETURN (true);
}

bool	URIParser::readHost()
{
  std::string	host;

  DEBUG_ENTER;
  this->prepare();

  if  (this->readIPLiteral() ||
       this->readIPv4address() ||
       this->readRegName())
    {
      this->extract(host);
      this->consume();
      std::cout << "HOST: " << host << std::endl;
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPort()
{
  std::string	port;

  DEBUG_ENTER;
  this->prepare();
  while (this->readDIGIT());
  this->extract(port);
  this->consume();
  std::cout << "PORT: " << port << std::endl;
  DEBUG_RETURN (true);
}

bool	URIParser::readIPLiteral()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readChar('[') &&
	  (this->readIPv6address() ||
	   this->readIPvFuture()) &&
	  this->readChar(']'));
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
  DEBUG_RETURN (this->readDecOctet() && this->readChar('.') &&
	  this->readDecOctet() && this->readChar('.') &&
	  this->readDecOctet() && this->readChar('.') &&
	  this->readDecOctet());
}

bool	URIParser::readDecOctet()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readDIGIT() ||
	  (this->readRange('1', '9') &&
	   this->readDIGIT()) ||
	  (this->readChar('1') &&
	   this->readDIGIT() &&
	   this->readDIGIT()) ||
	  (this->readChar('2') &&
	   this->readRange('0', '4') &&
	   this->readDIGIT()) ||
	  (this->readText("25") &&
	   this->readRange('0', '5')));
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
  DEBUG_RETURN (this->readPathAbempty() ||
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
  DEBUG_RETURN (true);
}

bool	URIParser::readPathAbemptyPart2()
{
  DEBUG_ENTER;
  this->save();

  if (this->readChar('/') &&
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

  if (this->readChar('/') &&
      this->readPathAbsoluteOpt())
    {
      this->extract(path);
      this->consume();
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

  if (this->readChar('/') &&
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

  if (this->readChar('/') &&
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
      DEBUG_RETURN (true);
    }
  DEBUG_RETURN (false);
}

bool	URIParser::readPathRootlessPart2()
{
  DEBUG_ENTER;
  this->save();

  if (this->readChar('/') &&
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
	 this->readChar('@'))
    i++;
  DEBUG_RETURN (i > 0);
}

bool	URIParser::readPchar()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readUnreserved() ||
		this->readPctEncoded() ||
		this->readSubDelims() ||
		this->readChar(':') ||
		this->readChar('@'));
}

bool	URIParser::readQuery()
{
  DEBUG_ENTER;
  while (this->readPchar() ||
	 this->readChar('/') ||
	 this->readChar('?'));
  DEBUG_RETURN (true);
}

bool	URIParser::readFragment()
{
  DEBUG_ENTER;
  while (this->readPchar() ||
	 this->readChar('/') ||
	 this->readChar('?'));
  DEBUG_RETURN (true);
}

bool	URIParser::readPctEncoded()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readChar('%') &&
		this->readHEXDIG() &&
		this->readHEXDIG());
}

bool	URIParser::readUnreserved()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readALPHA() ||
		this->readDIGIT() ||
		this->readChar('-') ||
		this->readChar('.') ||
		this->readChar('_') ||
		this->readChar('~'));
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
  DEBUG_RETURN (this->readChar(':') || this->readChar('/') ||
		this->readChar('?') || this->readChar('#') ||
		this->readChar('[') || this->readChar(']') ||
		this->readChar('@'));
}

bool	URIParser::readSubDelims()
{
  DEBUG_ENTER;
  DEBUG_RETURN (this->readChar('!') || this->readChar('$') ||
		this->readChar('&') || this->readChar('\'') ||
		this->readChar('(') || this->readChar(')') ||
		this->readChar('*') || this->readChar('+') ||
		this->readChar(',') || this->readChar(';') ||
		this->readChar('='));
}
