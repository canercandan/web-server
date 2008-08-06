//
// ABNFParser.h for ABNFParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 11:00:54 2008 caner candan
// Last update Wed Aug  6 12:39:02 2008 caner candan
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
	return (true);				\
      }						\
      this->setPos(pos);			\
      return (false);				\
    })

# define ZERO_OR_ONE(expr)	({		\
      TRY(expr);				\
      return (true);				\
    })

# define ZERO_OR_MORE(expr)	({		\
      while (TRY(expr));			\
      return (true);				\
    })

# define ONE_OR_MORE(expr)	({		\
      if (!TRY(expr))				\
	return (false);				\
						\
      while (TRY(expr));			\
      return (true);				\
    })

# define DEBUG_PARSER		true

# define DEBUG_ENTER()		(Debug::enter(__FUNCTION__, this->getBuf()))
# define DEBUG_RETURN(ret)	return (Debug::leave(__FUNCTION__, (ret)))

namespace Debug
{
  void	enter(const char* func, const std::string& buf);
  bool	leave(const char* func, bool retn);

  int	indent = 0;
};

class	ABNFParser : public HttpConsumer
{
public:
  ABNFParser(HttpProducer* prod);
  ~ABNFParser();

  bool	readAlpha();
  bool	readDigit();
  bool	readHexdig();

protected:
  unsigned int	_deep;
};

#endif // !__ABNFPARSER_H__
