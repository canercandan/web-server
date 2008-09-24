//
// Response.h for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:43:56 2008 majdi toumi
// Last update Wed Sep 24 18:20:15 2008 caner candan
//

#ifndef __RESPONSE_H__
# define __RESPONSE_H__

# include <map>
# include "IResponse.hpp"
# include "Request.h"
# include "FileInfo.h"
# include "URIParser.h"
# include "Socket.h"

# ifdef WIN32
#  pragma warning(disable : 4250)
# endif

class	Response : public Request, public ZenZiAPI::IResponse
{
  typedef std::map<int, std::string>	mapResponse;
public:
  Response();

  void			setStatusCode(int code);
  const std::string&	getStatusCode();

  void			setStatusMessage(const std::string& message);
  const std::string&	getStatusMessage();

  std::string		buildResponse();
  void			resetHeaders();
  void			sendFile(Socket*);
private:
  void	_generateMapResponse();

  std::string	_generateResponse(FileInfo&);
  std::string	_sendMessageBody(FileInfo&);
  std::string	_generateListingDirectoryHTML(FileInfo&);

  std::string	_createStatusLine();
  std::string	_createGeneralHeader();
  std::string	_createResponseHeader();
  std::string	_createEntityHeader(FileInfo&);
private:
  std::string	_resource;
  mapResponse	_mapResponse;
  std::string	_code;
  std::string	_message;
};

#endif /* !__RESPONSE_H__ */
