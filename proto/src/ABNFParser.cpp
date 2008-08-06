//
// ABNFParser.cpp for ABNFParser.cpp in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 11:12:53 2008 caner candan
// Last update Wed Aug  6 12:38:59 2008 caner candan
//

#include <iostream>
#include "ABNFParser.h"

void	Debug::enter(const char* func,
		     const std::string& buf)
{
  int	i;

  for (i = 0; i < indent; i++)
    std::cout << " ";
  indent++;
  std::cout << "[" << func << "]"
	    << " -> " << "[" << buf << "]"
	    << std::endl;
}

bool	Debug::leave(const char* func, bool retn)
{
  int	i;

  indent--;
  for (i = 0; i < indent; i++)
    std::cout << " ";
  std::cout << "[" << func << "]"
	    << " -> " << "["
	    << std::boolalpha << retn << "]"
	    << std::endl;
  return (retn);
}

ABNFParser::ABNFParser(HttpProducer* prod)
  : HttpConsumer(prod)
{}

ABNFParser::~ABNFParser()
{}

bool	ABNFParser::readAlpha()
{return (false);}

bool	ABNFParser::readDigit()
{return (false);}

bool	ABNFParser::readHexdig()
{return (false);}
