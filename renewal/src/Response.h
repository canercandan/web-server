#ifndef _RESPONSE_H_
# define _RESPONSE_H_

#include "IResponse.h"

namespace	ZenZiAPI
{
  class		Response : public IResponse, public Request
  {
  public:
    void			statusCode(int code);
    std::string&		statusCode();

    void			statusMessage(const std::string& message);
    const std::string&		statusMessage();

    std::string			buildResponse();
    void			resetHeaders();

  private:
    int				_code;
  };
}

#endif // _RESPONSE_H_
