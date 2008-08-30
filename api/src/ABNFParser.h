#ifndef __ABNFPARSER_H__
# define __ABNFPARSER_H__

# include <string>
# include "Parser.h"

// -----------------------REMOVE ME --------------------------
#define DEBUG_ACTIVE		0
#define DEBUG_ENTER		Debug::enter(__FUNCTION__, this->getBuf())
#define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, ret))

namespace	Debug
{
  void	enter(const char* func, const std::string& buf);
  bool	leave(const char* func, bool ret);
};

#define NOT_IMPLEMENTED							\
  std::cout << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;		\
  return (false);

// -----------------------REMOVE ME --------------------------

# define CHAR(a)	(this->_consumer.readChar(a))
# define RANGE(a, b)	(this->_consumer.readRange((a), (b)))
# define SHARP(a)	while (LWS && CHAR(',') && LWS && (a))
# define TEXT_(a)	(this->_consumer.readText(a))

# define CHAR_R(a)		(this->_consumer.readChar(a))
# define INTEGER_R(a)		(this->_consumer.readInteger(a))
# define IDENTIFIER_R(a)	(this->_consumer.readIdentifier(a))
# define RANGE_R(a, b, c)	(this->_consumer.readRange((a), (b), (c)))
# define TEXT_R(a, b)		(this->_consumer.readText((a), (b)))

# define ALPHA		this->readAlpha()

# define CR		this->readCR()
# define LF		this->readLF()
# define CRLF		this->readCRLF()

# define DIGIT		this->readDigit()
# define HEXDIG		this->readHexdig()
# define IDENTIFIER	this->readIdentifier()
# define INTEGER	this->readInteger()
# define SP		this->readSP()
# define LWS		SP

namespace	ziApi
{
  //! ABNFParser
  class	ABNFParser : public Parser
  {
  public:
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    ABNFParser(const Consumer& consumer,
	       const IRequest& request);

    //! read a CR character
    bool	readCR();
    //! read a LF character
    bool	readLF();
    //! read CRLF characters
    bool	readCRLF();
    //! read a char between a - z
    bool	readAlpha();
    //! read a char between 0 - 9
    bool	readDigit();
    //! read a char between 0 - 9 and a - f
    bool	readHexdig();
    //! read a space
    bool	readSP();
  };
};

#endif // !__ABNFPARSER_H__
