#ifndef __ABNFPARSER_H__
# define __ABNFPARSER_H__

# include <string>
# include "IParser.h"

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

# define CHAR(a)	(readChar(a))
# define RANGE(a, b)	(readRange((a), (b)))
# define SHARP(a)	while (LWS && CHAR(',') && LWS && (a))
# define TEXT_(a)	(readText(a))

# define CHAR_R(a)		(readChar(a))
# define INTEGER_R(a)		(readInteger(a))
# define IDENTIFIER_R(a)	(readIdentifier(a))
# define RANGE_R(a, b, c)	(readRange((a), (b), (c)))
# define TEXT_R(a, b)		(readText((a), (b)))

# define ALPHA		readAlpha()

# define CR		readCR()
# define LF		readLF()
# define CRLF		readCRLF()

# define DIGIT		readDigit()
# define HEXDIG		readHexdig()
# define IDENTIFIER	readIdentifier()
# define INTEGER	readInteger()
# define SP		readSP()
# define LWS		SP

namespace	ZapII
{
  //! ABNFParser
  class	ABNFParser : public IParser
  {
  public:
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    ABNFParser(Consumer* consumer, IRequest* request);

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
