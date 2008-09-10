//
// Request.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 15:49:20 2008 caner candan
// Last update Wed Sep 10 15:51:49 2008 caner candan
//

#ifndef __REQUEST_H__
# define __REQUEST_H__

# include <map>
# include <string>
# include "IRequest.hpp"

class	Request : public ZenZiAPI::IRequest
{
public:
  const std::string&		HTTPVersion();
  void				HTTPVersion(const std::string& version);

  const std::string&		method();
  void				method(const std::string & http_method);

  const std::string&		uri();
  void				uri(std::string&  field);

  const std::map<std::string, std::string>&	getHeaders(const std::string& field);
  void				setHeaders(const std::string& field,
					   std::map<std::string, std::string>& headers);

  const std::string&		getHeader(const std::string& field, const std::string& key);
  void				setHeader(const std::string& field, const std::string& key,
					  const std::string& value);\

  const std::string&		getHeader(const std::string& header);
  void				setHeader(const std::string& field, const std::string& value);

  const std::string&		body();
  void				body(const std::string& body);

  void				bodyAppend(const std::string& body);
  void				bodyAppend(char* body, unsigned int size = 0);

  bool				chunked() const;
  void				chunked(bool isChunked);
private:
  std::string					_version;
  std::string					_method;
  std::string					_uri;
  std::map<std::string, std::map<std::string, std::string> >	_headers;
  std::map<std::string, std::string>				_header;
  std::string					_body;
  bool					_isChunked;
};

#endif // __REQUEST_H__
