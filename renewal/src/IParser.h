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

#endif //! __IPARSER_H__
