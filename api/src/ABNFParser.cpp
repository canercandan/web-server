#include <string>
#include <iostream>
#include "ABNFParser.h"

using namespace	ziApi;

// -----------------------REMOVE ME --------------------------
namespace	Debug
{
  static int	indent = 0;

  void	enter(const char* func, const std::string& buf)
  {
    int	i;

    if (DEBUG_ACTIVE)
      {
	for (i = 0; i < indent; i++)
	  std::cout << ' ';
	std::cout << '[' << func << "] ["
		  << buf << ']' << std::endl;
      }
    indent++;
  }

  bool	leave(const char* func, bool ret)
  {
    int	i;

    if (DEBUG_ACTIVE)
      {
	for (i = 0; i < indent; i++)
	  std::cout << ' ';
	std::cout << '[' << func << " -> "
		  << ret << ']' << std::endl;
      }
    indent--;
    return (ret);
  }
};
// -----------------------REMOVE ME --------------------------

ABNFParser::ABNFParser(const Consumer& consumer,
		       const IRequest& request)
  : Parser(consumer, request)
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
