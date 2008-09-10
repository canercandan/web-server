#ifndef _RESPONSE_H_
# define _RESPONSE_H_

# include "IResponse.hpp"
# include "Request.h"

namespace	ZenZiAPI
{
  class		Response : public IResponse, public Request
  {
  public:
    void			setStatusCode(int code);
    const std::string&		getStatusCode();

    void			setStatusMessage(const std::string& message);
    const std::string&		getStatusMessage();

    std::string			buildResponse();
    void			resetHeaders();

  private:
    std::string			_code;
    std::string			_message;
  };
}

#endif // !_RESPONSE_H_
