//
// ABNFParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Fri Aug  8 16:02:26 2008 morgan armand
// Last update Fri Aug  8 21:33:17 2008 caner candan
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

#define CHAR(a)		(readChar(a))
#define RANGE(a, b)	(readRange((a), (b)))
#define TEXT(a)		(readText(a))

#define CHAR_R(a)		(readChar(a))
#define INTEGER_R(a)		(readInteger(a))
#define IDENTIFIER_R(a)		(readIdentifier(a))
#define RANGE_R(a, b, c)	(readRange((a), (b), (c)))
#define TEXT_R(a, b)		(readText((a), (b)))

#define	ALPHA		(readALPHA())
#define CR		(readCR())
#define CRLF		(readCRLF())
#define DIGIT		(readDIGIT())
#define HEXDIG		(readHEXDIG())
#define IDENTIFIER	(readIdentifier())
#define INTEGER		(readInteger())
#define LF		(readLF())
#define SP		(readSP())

class	ABNFParser : public HttpConsumer
{
public:
  ABNFParser(HttpProducer* prod);
  ~ABNFParser();

  bool	readALPHA();
  bool	readCR();
  bool	readCRLF();
  bool	readDIGIT();
  bool	readHEXDIG();
  bool	readLF();
  bool	readSP();
};

#endif // !__ABNF_PARSER_H__
