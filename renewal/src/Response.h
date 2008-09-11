//
// Response.h for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:43:56 2008 majdi toumi
// Last update Thu Sep 11 15:05:33 2008 morgan armand
//

#ifndef __RESPONSE_H__
# define __RESPONSE_H__

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

#endif /* !__RESPONSE_H__ */
