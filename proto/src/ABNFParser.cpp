//
// ABNFParser.cpp for ABNFParser.cpp in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 11:12:53 2008 caner candan
// Last update Fri Aug  8 12:19:55 2008 caner candan
//

#include <iostream>
#include "ABNFParser.h"

static int indent = 0;

void	Debug::enter(const char* func,
		     const std::string& buf,
		     const unsigned int& deep)
{
  int	i;

  for (i = 0; i < indent; i++)
    std::cout << ' ';
  indent++;
  std::cout << '[' << deep << ']'
	    << '[' << func << ']'
	    << " -> " << '[' << buf << ']'
	    << std::endl;
}

bool	Debug::leave(const char* func, bool retn)
{
  int	i;

  indent--;
  for (i = 0; i < indent; i++)
    std::cout << ' ';
  std::cout << '[' << func << ']'
	    << " -> " << '['
	    << std::boolalpha << retn << ']'
	    << std::endl;
  return (retn);
}

ABNFParser::ABNFParser(HttpProducer* prod)
  : HttpConsumer(prod)
{}

ABNFParser::~ABNFParser()
{}

bool	ABNFParser::readAlpha()
{
  RULE(RANGE('A', 'Z') || RANGE('a', 'z'));
}

bool	ABNFParser::readBit()
{
  RULE(RANGE('0', '1'));
}

bool	ABNFParser::readCR()
{
  RULE(CHAR('\r'));
}

bool	ABNFParser::readCRLF()
{
  RULE(CR && LF);
}

bool	ABNFParser::readCTL()
{
  RULE(RANGE(0, 0x1f) || CHAR(0x7f));
}

bool	ABNFParser::readDigit()
{
  RULE(RANGE('0', '9'));
}

bool	ABNFParser::readDquote()
{
  RULE(CHAR('"'));
}

bool	ABNFParser::readHexdig()
{
  RULE(DIGIT || RANGE('A', 'F'));
}

bool	ABNFParser::readHtab()
{
  RULE(CHAR(0x9));
}

bool	ABNFParser::readLF()
{
  RULE(CHAR('\n'));
}

bool	ABNFParser::readLWSP()
{
  RULE(WSP || (CRLF && WSP)); // LOOP
}

bool	ABNFParser::readOctet()
{
  RULE(RANGE(0x0, 0xff));
}

bool	ABNFParser::readSP()
{
  RULE(CHAR(' '));
}

bool	ABNFParser::readVChar()
{
  RULE(RANGE(0x21, 0x7e));
}

bool	ABNFParser::readWSP()
{
  RULE(SP || HTAB);
}
