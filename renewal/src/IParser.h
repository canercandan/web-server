//
// IParser.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 21:15:01 2008 caner candan
// Last update Tue Sep 23 11:55:34 2008 caner candan
//

#ifndef __IPARSER_H__
# define __IPARSER_H__

# include <string>
# include <iostream>

# define PCHAR(a)	(this->_consumer.peekChar(a))
# define CHAR(a)	(this->_consumer.readChar(a))

# define PRANGE(a, b)	(this->_consumer.peekRange((a), (b)))
# define RANGE(a, b)	(this->_consumer.readRange((a), (b)))

# define TEXT_(a)		(this->_consumer.readText(a))

# define CHAR_R(a)		(this->_consumer.readChar(a))
# define INTEGER_R(a)		(this->_consumer.readInteger(a))
# define IDENTIFIER_R(a)	(this->_consumer.readIdentifier(a))
# define RANGE_R(a, b, c)	(this->_consumer.readRange((a), (b), (c)))
# define TEXT_R(a, b)		(this->_consumer.readText((a), (b)))

# define IDENTIFIER	this->_consumer.readIdentifier()
# define INTEGER	this->_consumer.readInteger()

# define ALPHA		(RANGE('A', 'Z') || RANGE('a', 'z'))
# define CR		CHAR('\r')
# define LF		CHAR('\n')
# define CRLF		(CR && LF)
# define DIGIT		RANGE('0', '9')
# define HEXDIG		(DIGIT || RANGE('A', 'F'))
# define SP		CHAR(' ')
# define LWS		SP

# define SHARP(a)	while (LWS && CHAR(',') && LWS && (a))

# ifndef DEBUG
#  define NOT_IMPLEMENTED	return (false);
# else
#  define NOT_IMPLEMENTED				\
  if (DEBUG)						\
    std::cout << __FUNCTION__				\
	      << " NOT IMPLEMENTED" << std::endl;	\
  return (false);
# endif

class	IParser
{
public:
  virtual ~IParser(){}

  virtual bool	run() = 0;
};

#endif //! __IPARSER_H__
