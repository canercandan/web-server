//
// Response.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:44:00 2008 majdi toumi
// Last update Sun Sep 21 11:16:14 2008 caner candan
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Response.h"
#include "FluxString.h"
#include "Consumer.h"
#include "Config.h"

Response::Response()
{
  _generateMapResponse();
  setStatusCode(200);
  setStatusMessage(_mapResponse[200]);
}

void	Response::_generateMapResponse()
{
  _mapResponse[100] = "Continue";
  _mapResponse[101] = "Switching Protocols";

  _mapResponse[200] = "OK";
  _mapResponse[201] = "Created";
  _mapResponse[202] = "Accepted";
  _mapResponse[203] = "Non-Authoritative Information";
  _mapResponse[204] = "No Content";
  _mapResponse[205] = "Reset Content";
  _mapResponse[206] = "Partial Content";

  _mapResponse[300] = "Multiple Choices";
  _mapResponse[301] = "Moved Permanently";
  _mapResponse[302] = "Found";
  _mapResponse[303] = "See Other";
  _mapResponse[304] = "Not Modified";
  _mapResponse[305] = "Use Proxy";
  _mapResponse[307] = "Temporary Redirect";

  _mapResponse[400] = "Bad Request";
  _mapResponse[401] = "Unauthorized";
  _mapResponse[402] = "Payment Required";
  _mapResponse[403] = "Forbidden";
  _mapResponse[404] = "Not Found";
  _mapResponse[405] = "Method Not Allowed";
  _mapResponse[406] = "Not Acceptable";
  _mapResponse[407] = "Proxy Authentication Required";
  _mapResponse[408] = "Request Time-out";
  _mapResponse[409] = "Conflict";
  _mapResponse[410] = "Gone";

  _mapResponse[411] = "Length Required";
  _mapResponse[412] = "Precondition Failed";
  _mapResponse[413] = "Request Entity Too Large";
  _mapResponse[414] = "Request-URI Too Large";
  _mapResponse[414] = "Unsupported Media Type";
  _mapResponse[416] = "Requested range not satisfiable";
  _mapResponse[417] = "Expectation Failed";

  _mapResponse[500] = "Internal Server Error";
  _mapResponse[501] = "Not Implemented";
  _mapResponse[502] = "Bad Gateway";
  _mapResponse[503] = "Service Unavailable";
  _mapResponse[504] = "Gateway Time-out";
  _mapResponse[505] = "HTTP Version not supported";
}

void	Response::setStatusCode(int code)
{
  std::stringstream	ss;

  ss << code;
  this->_code = ss.str();
}

const std::string&	Response::getStatusCode()
{
  return (this->_code);
}

void	Response::setStatusMessage(const std::string& message)
{
  this->_message = message;
}

const std::string&	Response::getStatusMessage()
{
  return (this->_message);
}

std::string	Response::buildResponse()
{
  FluxString	flux(this->getUri());
  Consumer	consumer(flux);
  URIParser	uri(consumer);

  uri.run();

  Config*	config = Config::getInstance();
  std::string	resource = config->getParam("document_root") + uri.getPath();

  //#ifdef WIN32
  //  std::replace(resource.begin(), resource.end(), '/', '\\');
  //#endif
  FileInfo	info(resource);

  if (this->getMethod() == "HEAD")
    return (this->_generateResponse(info) + "\r\n");

  std::string	response(this->_sendMessageBody(info));

  return (this->_generateResponse(info) + response);
}

void	Response::resetHeaders()
{}

std::string	Response::_sendMessageBody(FileInfo& info)
{
  Config*	config = Config::getInstance();

  if (info.isGood() && info.getType() == FileInfo::FILE)
    {
      this->setStatusCode(200);
      this->setStatusMessage(this->_mapResponse[200]);
      return (info.getContent());
    }
  if (info.isGood() && info.getType() == FileInfo::DIR)
    {
      this->setStatusCode(403);
      this->setStatusMessage(this->_mapResponse[403]);
      return ("<h1>Permission denied</h1>");
    }

  std::string	path(config->getParam("document_root") + '/'
		     + config->getParam("file_404"));
//#ifdef WIN32
//  std::replace(path.begin(), path.end(), '/', '\\');
//#endif
  std::cout << "debug: [" << path << ']' << std::endl;

  FileInfo	infoErr(path);

  this->setStatusCode(404);
  this->setStatusMessage(this->_mapResponse[404]);
  if (infoErr.isGood())
    return (infoErr.getContent());
  return ("<h1>File not found</h1>");
}

std::string	Response::_generateResponse(FileInfo& info)
{
  std::string	statusLine;
  std::string	content;

  statusLine = this->_createStatusLine();
  content = this->_createGeneralHeader()
    + this->_createResponseHeader()
    + this->_createEntityHeader(info);
  return (statusLine +
	  content + "\r\n");
}

std::string	Response::_createStatusLine()
{
  std::stringstream	ss;

  ss << this->getHTTPVersion()
     << " "
     << this->getStatusCode()
     << " "
     << this->getStatusMessage()
     << "\r\n";
  return (ss.str());
}

std::string	Response::_createGeneralHeader()
{
  return ("");
}

std::string	Response::_createResponseHeader()
{
  std::stringstream	ss;
  Config*		config = Config::getInstance();

  ss //<< "Location:" << config->getParam("location") << "\r\n"
    << "Server:" << config->getParam("name") << "\r\n";
  return (ss.str());
}

std::string	Response::_createEntityHeader(FileInfo& info)
{
  std::stringstream	ss("");

  if (info.getSize() > 0 &&
      this->getMethod() != "HEAD" &&
      info.getType() != FileInfo::DIR)
    ss << "Content-Length:" << info.getSize() << "\r\n";
  return (ss.str());
}
