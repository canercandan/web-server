//
// Response.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:44:00 2008 majdi toumi
// Last update Thu Sep 25 15:02:34 2008 caner candan
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Response.h"
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
	std::map<std::string, std::string>::const_iterator	itb;
	std::map<std::string, std::string>::const_iterator	ite;
	std::string											content;
	std::string											status;
	std::stringstream									ss;
	int													code;
	Config*												config = Config::getInstance();

	status = this->getStatusCode();
	ss << status;
	ss >> code;

	this->setStatusMessage(this->_mapResponse[code]);

	// add standard headers
	this->setHeader("Server", config->getParam("name"));
	//this->setHeader("Connection", "close");

	if (this->isChunk())
		this->setHeader("Transfer-Encoding", "chunked");

	itb = this->_header.begin();
	ite = this->_header.end();

	for (; itb != ite; ++itb)
		content += itb->first + ": " + itb->second + "\r\n";

	return (this->_createStatusLine() + content + "\r\n");

	//return (this->_generateResponse());
	/*
  FluxString	flux(this->getUri());
  Consumer	consumer(flux);
  URIParser	uri(consumer);

  uri.run();

  Config*	config = Config::getInstance();
  _resource = config->getParam("document_root") + uri.getPath();

  FileInfo	info(_resource);

  if (info.isGood() && info.getType() == FileInfo::FILE)
    {
      this->setStatusCode(200);
      this->setStatusMessage(this->_mapResponse[200]);
	  //this->setChunk(true);
  }
  else if (info.isGood() && info.getType() == FileInfo::DIR)
    {
      this->setStatusCode(403);
      this->setStatusMessage(this->_mapResponse[403]);
    }
  else
  {
	  this->setStatusCode(404);
	this->setStatusMessage(this->_mapResponse[404]);
  }

  //if (this->getMethod() == "HEAD")
  return (this->_generateResponse(info) + "\r\n");

  //return (this->_generateResponse(info));
  */
}

void	Response::resetHeaders()
{
  this->_headers.clear();
  this->_header.clear();
}

void	Response::sendFile(Socket* sck)
{
  FileInfo	info(_resource);
  Config*	config = Config::getInstance();

	if (info.isGood() && info.getType() == FileInfo::FILE)
	{

    if (!this->isChunk())
	{
	  this->bodyAppend(info.getContent());
	  return;
	}

    std::ifstream	in(_resource.c_str(), std::ios::binary);
    char		buf[4096];

    if (!in.is_open())
		return;

    in.seekg(0, std::ios::beg);

    while (in.good())
	{
	  int			cc;
	  std::stringstream	ss;
	  std::string		data;

	  in.read(buf, 512);

	  cc = in.gcount();
	  ss << std::hex << cc;

	  data  = ss.str();
	  data += "\r\n";
	  data += std::string(buf, cc);
	  data += "\r\n";

	  sck->send((char *)data.c_str(), data.size());
	}

      // Last chunk
      std::string	last_chunk;

      last_chunk = "0\r\n\r\n";
      sck->send((char *)last_chunk.c_str(), last_chunk.size());

      in.close();
	}
	else if (info.isGood() && info.getType() == FileInfo::DIR)
	{
		this->bodyAppend("<html><head><title>403 Forbidden</title></head><body>"
						"<h1>Forbidden</h1><p>You don't have permission to access"
						+ info.getPath() + "on this server.</p></body></html>");
	}
	else
	{
			std::string	path(config->getParam("document_root") + '/'
		     + config->getParam("file_404"));
	
			FileInfo	infoErr(path);

  
			if (infoErr.isGood())
				bodyAppend(infoErr.getContent());
			else
				bodyAppend(std::string("<h1>File not found</h1>"));
	}
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
	if (this->isChunk())
		return ("Transfer-Encoding: chunked\r\nConnection: close\r\n");
	else
		return ("Connection: close\r\n");
}

std::string	Response::_createResponseHeader()
{
  std::stringstream	ss;
  Config*		config = Config::getInstance();

  ss //<< "Location:" << config->getParam("location") << "\r\n"
    << "Server: " << config->getParam("name") << "\r\n";
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
