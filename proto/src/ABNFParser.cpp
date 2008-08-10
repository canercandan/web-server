//
// ABNFParser.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:37 2008 morgan armand
// Last update Fri Aug  8 20:26:56 2008 morgan armand
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
{
}

bool	ABNFParser::readALPHA()
{
  return (this->readRange('A', 'Z') ||
	  this->readRange('a', 'z'));
}

bool	ABNFParser::readCR()
{
  return (this->readChar('\r'));
}

bool	ABNFParser::readCRLF()
{
  return (this->readCR() &&
	  this->readLF());
}

bool	ABNFParser::readDIGIT()
{
  return (this->readRange('0', '9'));
}

bool	ABNFParser::readHEXDIG()
{
  return (this->readDIGIT() ||
	  this->readRange('A', 'F'));
}

bool	ABNFParser::readLF()
{
  return (this->readChar('\n'));
}

bool	ABNFParser::readSP()
{
  return (this->readChar(' '));
}
