//
// HttpResponse.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:33:37 2008 morgan armand
// Last update Mon Sep  1 11:59:16 2008 florent hochwelker
//

#include <sstream>
#include "HttpResponse.h"
#include "InfoFile.h"

HttpResponse::HttpResponse(HttpRequest* req)
  : _req(req), _currentFile(NULL)
{
  _conf = ZiaConfiguration::getInstance();
}

HttpResponse::~HttpResponse()
{
  if (this->_currentFile != NULL)
    delete this->_currentFile;
}

void		HttpResponse::sendResponse(Socket* sck)
{
  std::string	response;

  this->generateMapResponse();
  response = this->generateResponse();
  if (this->_req->getMethod() == "HEAD")
    {
      response += "\r\n";
      sck->send(response);
    }
  else
    {
      sck->send(response);
      sendMessageBody(sck);
    }
}

void		HttpResponse::generateMapResponse()
{
  this->_map_response[100] = "Continue";
  this->_map_response[101] = "Switching Protocols";

  this->_map_response[200] = "OK";
  this->_map_response[201] = "Created";
  this->_map_response[202] = "Accepted";
  this->_map_response[203] = "Non-Authoritative Information";
  this->_map_response[204] = "No Content";
  this->_map_response[205] = "Reset Content";
  this->_map_response[206] = "Partial Content";

  this->_map_response[300] = "Multiple Choices";
  this->_map_response[301] = "Moved Permanently";
  this->_map_response[302] = "Found";
  this->_map_response[303] = "See Other";
  this->_map_response[304] = "Not Modified";
  this->_map_response[305] = "Use Proxy";
  this->_map_response[307] = "Temporary Redirect";

  this->_map_response[400] = "Bad Request";
  this->_map_response[401] = "Unauthorized";
  this->_map_response[402] = "Payment Required";
  this->_map_response[403] = "Forbidden";
  this->_map_response[404] = "Not Found";
  this->_map_response[405] = "Method Not Allowed";
  this->_map_response[406] = "Not Acceptable";
  this->_map_response[407] = "Proxy Authentication Required";
  this->_map_response[408] = "Request Time-out";
  this->_map_response[409] = "Conflict";
  this->_map_response[410] = "Gone";

  this->_map_response[411] = "Length Required";
  this->_map_response[412] = "Precondition Failed";
  this->_map_response[413] = "Request Entity Too Large";
  this->_map_response[414] = "Request-URI Too Large";
  this->_map_response[414] = "Unsupported Media Type";
  this->_map_response[416] = "Requested range not satisfiable";
  this->_map_response[417] = "Expectation Failed";

  this->_map_response[500] = "Internal Server Error";
  this->_map_response[501] = "Not Implemented";
  this->_map_response[502] = "Bad Gateway";
  this->_map_response[503] = "Service Unavailable";
  this->_map_response[504] = "Gateway Time-out";
  this->_map_response[505] = "HTTP Version not supported";
}

std::string	HttpResponse::generateResponse()
{
  std::string	status_line;
  std::string	content;
  std::cout << "OUVERTURE DE " << this->_conf->getValue("document_root") + this->_req->getPath() << std::endl;
  this->_currentFile = new InfoFile(this->_conf->getValue("document_root") + this->_req->getPath());

  status_line = this->createStatusLine();
  content = this->createGeneralHeader()
    + this->createResponseHeader()
    + this->createEntityHeader();

  return (status_line + content + "\r\n");
}

std::string	HttpResponse::createStatusLine()
{
  std::stringstream	ss;

  this->_status_code = this->findStatusCode();
  this->_status_code = 200;
  ss << "HTTP/"
     << this->_req->getVersionProtocol().getMajor()
     << "."
     << this->_req->getVersionProtocol().getMinor()
     << " "
     << this->_status_code
     << " "
     << this->_map_response[this->_status_code]
     << "\r\n";
  return (ss.str());
}

int		HttpResponse::findStatusCode()
{
  int		code;

  code = this->informationalCode();
  if (code != -1)
    return (code);

  code = this->successfulCode();
  if (code != -1)
    return (code);

  code = this->redirectionCode();
  if (code != -1)
    return (code);

  code = this->clientErrorCode();
  if (code != -1)
    return (code);

  code = this->serverErrorCode();
  if (code != -1)
    return (code);
  return (-1);
}

int		HttpResponse::informationalCode()
{
  if (this->_req->getVersionProtocol().getMajor() == 1)
    return (-1);
  return (-1);
}

int		HttpResponse::successfulCode()
{
  return (200);
}

int		HttpResponse::redirectionCode()
{
  return (-1);
}

int		HttpResponse::clientErrorCode()
{
  return (-1);
}

int		HttpResponse::serverErrorCode()
{
  return (-1);
}

std::string	HttpResponse::createGeneralHeader()
{
  return ("");
}

std::string	HttpResponse::createResponseHeader()
{
  std::stringstream	ss;

  ss << "Location:" << this->_conf->getValue("location") << "\r\n"
     << "Server:" << this->_conf->getValue("name")<< "\r\n";
  return ss.str();
}

void		HttpResponse::sendListingDirectoryHTML(Socket* sck)
{
  std::list<std::string>	*listDir = this->_currentFile->getListDir();
  std::string			buf;
  bool				errSend = false;

  buf = "<h1>Index of ";
  buf += this->_req->getPath();
  buf += "</h1><ul>";
  if (sck->send(buf) <= 0)
    return;
  std::list<std::string>::iterator	it;
  std::list<std::string>::iterator	end = listDir->end();
  std::string				slashDir;
  for (it = listDir->begin(); it != end; ++it)
    {
      InfoFile checkDir = InfoFile(this->_conf->getValue("document_root") + SLASH + this->_req->getPath() + *it);
      if (checkDir.isGood() == true && checkDir.getType() == InfoFile::DIR)
	slashDir = SLASH;
      else
	slashDir = "";
      buf = "<li><a href=\"" + *it + slashDir + "\">"
	+ *it + slashDir + "</a></li>";
      if (sck->send(buf) <= 0)
	{
	  errSend = true;
	  break;
	}
    }
  if (errSend != false)
    {
      buf = "</ul>";
      sck->send(buf);
    }
  delete listDir;
}

std::string		HttpResponse::createEntityHeader()
{
  std::stringstream	ss("");

  if (this->_currentFile->getSize() > 0 &&
      this->_req->getMethod() != "HEAD" &&
      this->_currentFile->getType() != InfoFile::DIR)
    ss << "Content-Length:" << this->_currentFile->getSize() << "\r\n";
  return (ss.str());
}

void		HttpResponse::sendMessageBody(Socket* sck)
{
  std::ifstream infile;
  if (this->_currentFile->isGood())
    {
      switch (this->_currentFile->getType())
	{
	case InfoFile::FILE:
	  {
	    std::string	bufString;
	    infile.open(this->_currentFile->getPath().c_str());
	    if (infile.is_open())
	      {
		std::string	c;
		while (infile.good())
		  {
		    c = infile.get();
		    if (infile.good())
		      if (sck->send(c) <= 0)
			{
			  sck->close();
			  break;
			}
		  }
		infile.close();
	      }
	    break;
	  }
	case InfoFile::DIR:
	  {
	    sendListingDirectoryHTML(sck);
	    break;
	  }
	default:
	  std::string	buf = "<h1>File not found</h1>";
	  sck->send(buf);
	}
    }
  else
    {
      std::string	buf = "<h1>File not found</h1>";
      sck->send(buf);
    }
}
