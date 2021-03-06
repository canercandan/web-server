//
// ABNFParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:37 2008 morgan armand
// Last update Thu Aug 14 11:03:17 2008 caner candan
//

#include "ABNFParser.h"

// -----------------------REMOVE ME --------------------------
namespace	Debug
{
  static int	indent = 0;

  void	enter(const char* func, const std::string& buf)
  {
    if (DEBUG_ACTIVE)
      {
	for (int i = 0; i < indent; i++)
	  std::cout << ' ';

	std::cout << '[' << func << "] ["
		  << buf << ']' << std::endl;
      }
    indent++;
  }

  bool	leave(const char* func, bool ret)
  {
    if (DEBUG_ACTIVE)
      {
	for (int i = 0; i < indent; i++)
	  std::cout << ' ';

	std::cout << '[' << func << " -> "
		  << ret << ']' << std::endl;
      }
    indent--;
    return (ret);
  }
};

// -----------------------REMOVE ME --------------------------

ABNFParser::ABNFParser(HttpProducer* prod)
  : HttpConsumer(prod)
{
}

ABNFParser::~ABNFParser()
{}

bool	ABNFParser::readCR()
{
  return (CHAR('\r'));
}

bool	ABNFParser::readLF()
{
  return (CHAR('\n'));
}

bool	ABNFParser::readCRLF()
{
  return (CR && LF);
}

bool	ABNFParser::readAlpha()
{
  return (RANGE('A', 'Z') || RANGE('a', 'z'));
}

bool	ABNFParser::readDigit()
{
  return (RANGE('0', '9'));
}

bool	ABNFParser::readHexdig()
{
  return (DIGIT || RANGE('A', 'F'));
}

bool	ABNFParser::readSP()
{
  return (CHAR(' '));
}
