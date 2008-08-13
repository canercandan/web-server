//
// ABNFParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:37 2008 morgan armand
// Last update Wed Aug 13 12:53:48 2008 caner candan
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
