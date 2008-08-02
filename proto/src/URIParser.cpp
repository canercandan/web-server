//
// URIParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Sat Aug  2 14:34:26 2008 morgan armand
// Last update Sat Aug  2 16:39:55 2008 caner candan
//

#include <iostream>
#include "URIParser.h"

URIParser::URIParser(HttpProducer* prod)
  : HttpConsumer(prod)
{
}

bool	URIParser::readRequestURI()
{
  if (this->readChar('*')	||
      this->readAbsoluteURI()	||
      this->readAbsPath()	||
      this->readAuthority())
    return (true);
  return (false);
}

bool	URIParser::readAbsoluteURI()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (true);
}

bool	URIParser::readAbsPath()
{
  if (this->readChar('/') &&
      this->readPathSegments())
    return (true);
  return (false);
}

bool	URIParser::readAuthority()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (true);
}

bool	URIParser::readPathSegments()
{
  // TODO: Implementation
  std::cerr << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;
  return (true);
}
