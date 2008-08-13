//
// HttpResponse.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:33:37 2008 morgan armand
// Last update Tue Aug 12 06:45:17 2008 florent hochwelker
//

#include <sstream>
#include "HttpResponse.h"
#include "InfoFile.h"

HttpResponse::HttpResponse(HttpRequest* req)
  : _req(req)
{
  _conf = ZiaConfiguration::getInstance();
}

HttpResponse::~HttpResponse()
{
}

void		HttpResponse::sendResponse(Socket* sck)
{
  std::string	response;

  std::cout << "[debug sendResponse]:" << std::endl;
  this->generateMapResponse();
  response = this->generateResponse();
  std::cout << "response => [\n" << response << "]" << std::endl;
  sck->send(response);
  sendMessageBody(sck);
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
  std::string	general_header("");
  std::string	response_header("");
  std::string	entity_header("");
  std::string	content;

  status_line = this->createStatusLine();
  general_header = this->createGeneralHeader();

  content = ((general_header != "") ? general_header
	     : (response_header != "") ? response_header
	     : (entity_header != "") ? entity_header : "");
  content = ((content != "") ? content + "\r\n" : content);

  std::cout << "Status line = " << status_line << std::endl;
  std::cout << "general_header = " << general_header << std::endl;
  std::cout << "response_header = " << response_header << std::endl;
  std::cout << "entity_header = " << entity_header << std::endl;

  return (status_line + "Content-Type: text/html\r\n" + "\r\n");
  return (status_line + "\r\n" + content);
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

  ss << "Location:" << this->_conf->getValue("location")
     << "Server:" << this->_conf->getValue("name")
    ;
  return (ss.str());
}

void		HttpResponse::sendListingDirectoryHTML(InfoFile& info, Socket* sck)
{
  std::list<std::string>	*listDir = info.getListDir();
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
      InfoFile checkDir = InfoFile(this->_conf->getValue("document_root") + "/" + this->_req->getPath() + *it);
      if (checkDir.isGood() == true && checkDir.getType() == InfoFile::DIR)
	slashDir = "/";
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

std::string	HttpResponse::createEntityHeader()
{
  std::stringstream	ss;

  // FIXME: 407-Allow,
  //   ss << "Content-Lenght:" << this->_req.getContentLength()
  //     ;
  return (ss.str());
}

void		HttpResponse::sendMessageBody(Socket* sck)
{
  std::ifstream infile;
  std::cout << "[debug generate message body]" << std::endl;
  std::string	file(this->_conf->getValue("document_root"));
  file += this->_req->getPath();
  std::cout << "file = " << file << std::endl;
  InfoFile	info(file);
  if (info.isGood())
    {
      switch (info.getType())
	{
	case InfoFile::FILE:
	  {
	    infile.open(file.c_str());
	    if (infile.is_open())
	      {
		std::string	c;
		while (infile.good())
		  {
		    c = infile.get();
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
	    sendListingDirectoryHTML(info, sck);
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
