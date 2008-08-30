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
    Parser(Consumer* consumer, IRequest* request);

  protected:
    Consumer*	_consumer;
    IRequest*	_request;
  };
};

#endif // !__PARSER_H__
