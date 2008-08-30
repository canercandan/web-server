#ifndef __PARSER_H__
# define __PARSER_H__

# include "IParser.h"
# include "Consumer.h"
# include "IRequest.h"

namespace	ziApi
{
  //! Parser
  class	Parser : public IParser
  {
  public:
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    Parser(const Consumer& consumer,
	   const IRequest& request);
  protected:
    const Consumer&	_consumer;
    const IRequest&	_request;
  };
};

#endif // !__PARSER_H__
