//
// ABNFParser.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Thu Aug  7 11:18:32 2008 morgan armand
// Last update Fri Aug  8 11:57:25 2008 caner candan
//

#ifndef __ABNFPARSER_H__
# define __ABNFPARSER_H__

# include "HttpConsumer.h"

# define TRY(expr)	({			\
      int	pos;				\
      						\
      DEBUG_ENTER();				\
      pos = this->getPos();			\
      std::cout << "pos before: " << pos << std::endl;	\
      expr;					\
      this->setPos(pos);			\
      DEBUG_RETURN(false);			\
    })


# define RULE(expr)	(TRY({			\
	this->_deep++;				\
	if (expr)				\
	  {					\
	    this->_deep--;			\
	    if (!this->_deep)			\
	      this->consume();			\
	    DEBUG_RETURN(true);			\
	  }					\
      })					\
    )

# define CONSUME(data, expr)	(TRY({		\
	this->_deep++;				\
	if (expr)				\
	  {					\
	    std::cout << "pos after: " << pos << std::endl;	\
	    this->extract(pos);		\
	    this->_deep--;			\
	    if (!this->_deep)			\
	      this->consume();			\
	    DEBUG_RETURN(true);			\
	  }					\
      })					\
    )

# define LOOP(expr)	(TRY({			\
	while (expr);				\
	this->consume();			\
	DEBUG_RETURN(true);			\
      })					\
    )

# define LOOP1(expr)	(TRY({			\
	int	i;				\
						\
	for (i = 0; expr; i++);			\
	if (i > 0)				\
	  {					\
	    this->consume();			\
	    DEBUG_RETURN(true);			\
	  }					\
      })					\
    )

/*
# define BOOL(expr)	(TRY({			\
	if (expr)				\
	  this->consume();			\
	else					\
	  this->setPos(pos);			\
	DEBUG_RETURN(true);			\
      })					\
    )
*/

# define BOOL(expr)	(expr || true)

# define DEBUG_PARSER		true

# define DEBUG_ENTER()		(Debug::enter(__FUNCTION__, this->getBuf(), this->_deep))
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
  void	enter(const char* func, const std::string& buf,
	      const unsigned int& deep);
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
