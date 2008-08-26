#ifndef __IPARSER_H__
# define __IPARSER_H__

# include "IServer.h"
# include "Consumer.h"
# include "IRequest.h"

//! IParser
class IParser : IServer
{
public:
  virtual IParser(Consumer* consumer, IRequest* request){}
  virtual ~IParser(){}
};

#endif //! __IPARSER_H__
