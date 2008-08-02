//
// URIParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 14:34:26 2008 morgan armand
// Last update Sat Aug  2 18:54:36 2008 caner candan
//

#include <iostream>
#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod)
  : HttpConsumer(prod)
{}

bool	URIParser::readRequestURI()
{
  return (this->readChar('*')		||
	  this->readAbsoluteURI()	||
	  this->readAbsPath()		||
	  this->readAuthority());
}

bool	URIParser::readAbsoluteURI()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URIParser::readAbsPath()
{
  return (this->readChar('/') &&
	  this->readPathSegments());
}

bool	URIParser::readAuthority()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (false);
}

bool	URIParser::readPathSegments()
{
  if (!this->readSegment())
    return (false);
  while (this->readChar('/'))
    this->readSegment();
  return (true);
}

bool	URIParser::readSegment()
{
  while (this->readPchar());
  while (this->readChar(';') && this->readParam());
  return (true);
}

bool	URIParser::readPchar()
{
  return (this->readUnreserved()	||
	  this->readEscaped()		||
	  this->readChar(':')		||
	  this->readChar('@')		||
	  this->readChar('&')		||
	  this->readChar('=')		||
	  this->readChar('+')		||
	  this->readChar('$')		||
	  this->readChar(','));
}

bool	URIParser::readParam()
{
  while (this->readPchar());
  return (true);
}

bool	URIParser::readUnreserved()
{
  return (this->readAlphanum() ||
	  this->readMark());
}

bool	URIParser::readEscaped()
{
  return (readChar('%')	&&
	  readHex()	&&
	  readHex());
}

bool	URIParser::readAlphanum()
{
  return (false);
}

bool	URIParser::readMark()
{
  return (this->readChar('-')	||
	  this->readChar('_')	||
	  this->readChar('.')	||
	  this->readChar('!')	||
	  this->readChar('~')	||
	  this->readChar('*')	||
	  this->readChar('\'')	||
	  this->readChar('(')	||
	  this->readChar(')'));
}

bool	URIParser::readHex()
{
  return (this->readDigit()		||
	  this->readRange('A', 'F')	||
	  this->readRange('a', 'f'));
}

bool	URIParser::readDigit()
{
  return (this->readRange('0', '9'));
}
