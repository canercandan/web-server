#ifndef __IPARSER_H__
# define __IPARSER_H__

# include "IRoot.h"
# include "Consumer.h"
# include "IRequest.h"

//! IParser
class	IParser : public IRoot
{
public:
  //! undef
  virtual IParser(Consumer* consumer, IRequest* request){}
  virtual ~IParser(){}
};

#endif //! __IPARSER_H__
