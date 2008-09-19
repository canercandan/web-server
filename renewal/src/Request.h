//
// Request.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 15:49:20 2008 caner candan
// Last update Fri Sep 19 02:23:54 2008 caner candan
//

#ifndef __REQUEST_H__
# define __REQUEST_H__

# include <map>
# include <string>
# include "IRequest.hpp"

class	Request : public virtual ZenZiAPI::IRequest
{
public:
  Request();

  const std::string&	getHTTPVersion();
  void			setHTTPVersion(const std::string& version);

  const std::string&	getMethod();
  void			setMethod(const std::string & http_method);

  const std::string&	getUri();
  void			setUri(const std::string& http_uri);

  const std::map<std::string, std::string>&	getHeaders(const std::string& field);
  void						setHeaders(const std::string& field,
							   std::map<std::string, std::string>& headers);

  const std::string&	getHeader(const std::string& field,
				  const std::string& key);
  void			setHeader(const std::string& field,
				  const std::string& key,
				  const std::string& value);

  const std::string&	getHeader(const std::string& header);
  void			setHeader(const std::string& field,
				  const std::string& value);

  const std::string&	getBody();
  void			setBody(const std::string& body);

  void	bodyAppend(const std::string& body);
  void	bodyAppend(char* body, unsigned int size = 0);

  bool	isChunk() const;
  void	setChunk(bool isChunked);
private:
  std::string	_version;
  std::string	_method;
  std::string	_uri;
  std::map<std::string, std::map<std::string, std::string> >	_headers;
  std::map<std::string, std::string>				_header;
  std::string	_body;
  bool		_isChunked;
};

#endif // __REQUEST_H__
