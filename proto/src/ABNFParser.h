//
// ABNFParser.h for ABNFParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 11:00:54 2008 caner candan
// Last update Wed Aug  6 17:53:24 2008 caner candan
//

#ifndef __ABNFPARSER_H__
# define __ABNFPARSER_H__

# include "HttpConsumer.h"

# define RULE(expr)	({			\
      int	pos;				\
      						\
      pos = this->getPos();			\
      this->_deep++;				\
      if ((expr)) {				\
	this->_deep--;				\
	if (this->_deep == 0)			\
	  this->consume();			\
	DEBUG_RETURN(true);			\
      }						\
      this->setPos(pos);			\
      DEBUG_RETURN(false);			\
    })

# define ZERO_OR_ONE(expr)	({		\
      RULE(expr);				\
      return (true);				\
    })

# define ZERO_OR_MORE(expr)	({		\
      while (RULE(expr));			\
      return (true);				\
    })

# define ONE_OR_MORE(expr)	({		\
      if (!RULE(expr))				\
	return (false);				\
      while (RULE(expr));			\
      return (true);				\
    })

# define DEBUG_PARSER		true

# define DEBUG_ENTER()		(Debug::enter(__FUNCTION__, this->getBuf()))
# define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, (ret)))

# define RANGE(a, b)	(readRange((a), (b)))
# define CHAR(a)	(readChar(a))

# define ALPHA	(readAlpha())
# define BIT	(readBit())
# define CR	(readCR())
# define CRLF	(readCRLF())
# define DIGIT	(readDigit())
# define DQUOTE	(readDquote())
# define HEXDIG	(readHexdig())
# define HTAB	(readHtab())
# define LF	(readLF())
# define LWSP	(readLWSP())
# define OCTET	(readOctet())
# define SP	(readSP())
# define VCHAR	(readVChar())
# define WSP	(readWSP())

namespace Debug
{
  void	enter(const char* func, const std::string& buf);
  bool	leave(const char* func, bool retn);
};

class	ABNFParser : public HttpConsumer
{
public:
  ABNFParser(HttpProducer* prod);
  ~ABNFParser();

  bool	readAlpha();
  bool	readBit();
  bool	readCR();
  bool	readCRLF();
  bool	readCTL();
  bool	readDigit();
  bool	readDquote();
  bool	readHexdig();
  bool	readHtab();
  bool	readLF();
  bool	readLWSP();
  bool	readOctet();
  bool	readSP();
  bool	readVChar();
  bool	readWSP();
protected:
  unsigned int	_deep;
};

#endif // !__ABNFPARSER_H__
