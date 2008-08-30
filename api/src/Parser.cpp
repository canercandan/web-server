#include "Parser.h"

using namespace ziApi;

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

Parser::Parser(Consumer& consumer,
	       IRequest& request)
  : _consumer(consumer), _request(request)
{}

bool	Parser::readCR()
{
  return (CHAR('\r'));
}

bool	Parser::readLF()
{
  return (CHAR('\n'));
}

bool	Parser::readCRLF()
{
  return (CR && LF);
}

bool	Parser::readAlpha()
{
  return (RANGE('A', 'Z') || RANGE('a', 'z'));
}

bool	Parser::readDigit()
{
  return (RANGE('0', '9'));
}

bool	Parser::readHexdig()
{
  return (DIGIT || RANGE('A', 'F'));
}

bool	Parser::readSP()
{
  return (CHAR(' '));
}
