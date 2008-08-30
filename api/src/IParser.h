#ifndef __IPARSER_H__
# define __IPARSER_H__

# include <string>
# include <iostream>
# include "IRoot.h"

# define PCHAR(a)	(this->_consumer->peekChar(a))
# define CHAR(a)	(this->_consumer->readChar(a))

# define PRANGE(a, b)	(this->_consumer->peekRange((a), (b)))
# define RANGE(a, b)	(this->_consumer->readRange((a), (b)))

# define TEXT_(a)		(this->_consumer->readText(a))

# define CHAR_R(a)		(this->_consumer->readChar(a))
# define INTEGER_R(a)		(this->_consumer->readInteger(a))
# define IDENTIFIER_R(a)	(this->_consumer->readIdentifier(a))
# define RANGE_R(a, b, c)	(this->_consumer->readRange((a), (b), (c)))
# define TEXT_R(a, b)		(this->_consumer->readText((a), (b)))

# define IDENTIFIER	this->_consumer->readIdentifier()
# define INTEGER	this->_consumer->readInteger()

# define ALPHA		(RANGE('A', 'Z') || RANGE('a', 'z'))
# define CR		CHAR('\r')
# define LF		CHAR('\n')
# define CRLF		(CR && LF)
# define DIGIT		RANGE('0', '9')
# define HEXDIG		(DIGIT || RANGE('A', 'F'))
# define SP		CHAR(' ')
# define LWS		SP

# define SHARP(a)	while (LWS && CHAR(',') && LWS && (a))

namespace	ziApi
{
  //! IParser
  class	IParser : public IRoot
  {
  public:
    //! undef
    virtual ~IParser(){}

    virtual bool	run() = 0;
  };
};

// -----------------------REMOVE ME --------------------------

#define DEBUG_ACTIVE		0
#define DEBUG_ENTER		Debug::enter(__FUNCTION__, this->_consumer->getBuf())
#define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, ret))

#define NOT_IMPLEMENTED							\
  std::cout << __FUNCTION__ << " NOT IMPLEMENTED" << std::endl;		\
  return (false);

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

#endif //! __IPARSER_H__
