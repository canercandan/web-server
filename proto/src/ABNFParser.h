//
// ABNFParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:26 2008 morgan armand
// Last update Fri Aug  8 20:26:05 2008 morgan armand
//

#ifndef __ABNF_PARSER_H__
#define __ABNF_PARSER_H__

#include <iostream>
#include "HttpConsumer.h"

// -----------------------REMOVE ME --------------------------
#define DEBUG_ACTIVE		1
#define DEBUG_ENTER		(Debug::enter(__FUNCTION__, this->getBuf()))
#define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, ret))

namespace	Debug
{
  void	enter(const char* func, const std::string& buf);
  bool	leave(const char* func, bool ret);
};

#define NOT_IMPLEMENTED		({		\
      std::cout << __FUNCTION__			\
		<< " NOT IMPLEMENTED"		\
		<< std::endl;			\
      return (false);				\
    })
// -----------------------REMOVE ME --------------------------

class	ABNFParser : public HttpConsumer
{
public:
  ABNFParser(HttpProducer* prod);
  ~ABNFParser();

  bool	readALPHA();
  //  bool	readBit();
  bool	readCR();
  bool	readCRLF();
  //  bool	readCTL();
  bool	readDIGIT();
  //  bool	readDquote();
  bool	readHEXDIG();
  //  bool	readHtab();
  bool	readLF();
  //  bool	readLWSP();
  //  bool	readOctet();
  bool	readSP();
  //  bool	readVChar();
  //  bool	readWSP();
};

#endif // !__ABNF_PARSER_H__
