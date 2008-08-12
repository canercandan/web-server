//
// HttpResponse.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Tue Aug  5 16:33:37 2008 morgan armand
// Last update Tue Aug 12 16:56:59 2008 caner candan
//

#include <sstream>
#include "HttpResponse.h"

HttpResponse::HttpResponse(HttpRequest* req, const ZiaConfiguration& conf)
  : _req(req), _conf(conf)
{}

HttpResponse::~HttpResponse()
{
}

void		HttpResponse::sendResponse(Socket* sck)
{
  std::string	status_line;
  std::string	header;

  std::cout << "[debug sendResponse]:" << std::endl;
  this->generateMapResponse();
  status_line = generateStatusLine();
  header = generateHeader();
  std::cout << "Status line = " << status_line << std::endl;
  std::cout << "Header = " << header << std::endl;

  sck->send(status_line.c_str(), status_line.length());
  sck->send(header.c_str(), header.length());
  sck->send("\r\n", 2);
  std::ifstream *infile = generateMessageBody();
  if (infile->is_open())
    {
      while (infile->good())
	{
	  char c = infile->get();
	  sck->send(&c, 1);
	}
      infile->close();
    }
  else
    {
      sck->send("<h1>File not found</h1>", 23);
    }
}

void		HttpResponse::generateMapResponse()
{
  this->_map_response["100"] = "Continue";
  this->_map_response["101"] = "Switching Protocols";

  this->_map_response["200"] = "OK";
  this->_map_response["201"] = "Created";
  this->_map_response["202"] = "Accepted";
  this->_map_response["203"] = "Non-Authoritative Information";
  this->_map_response["204"] = "No Content";
  this->_map_response["205"] = "Reset Content";
  this->_map_response["206"] = "Partial Content";

  this->_map_response["300"] = "Multiple Choices";
  this->_map_response["301"] = "Moved Permanently";
  this->_map_response["302"] = "Found";
  this->_map_response["303"] = "See Other";
  this->_map_response["304"] = "Not Modified";
  this->_map_response["305"] = "Use Proxy";
  this->_map_response["307"] = "Temporary Redirect";

  this->_map_response["400"] = "Bad Request";
  this->_map_response["401"] = "Unauthorized";
  this->_map_response["402"] = "Payment Required";
  this->_map_response["403"] = "Forbidden";
  this->_map_response["404"] = "Not Found";
  this->_map_response["405"] = "Method Not Allowed";
  this->_map_response["406"] = "Not Acceptable";
  this->_map_response["407"] = "Proxy Authentication Required";
  this->_map_response["408"] = "Request Time-out";
  this->_map_response["409"] = "Conflict";
  this->_map_response["410"] = "Gone";

  this->_map_response["411"] = "Length Required";
  this->_map_response["412"] = "Precondition Failed";
  this->_map_response["413"] = "Request Entity Too Large";
  this->_map_response["414"] = "Request-URI Too Large";
  this->_map_response["414"] = "Unsupported Media Type";
  this->_map_response["416"] = "Requested range not satisfiable";
  this->_map_response["417"] = "Expectation Failed";

  this->_map_response["500"] = "Internal Server Error";
  this->_map_response["501"] = "Not Implemented";
  this->_map_response["502"] = "Bad Gateway";
  this->_map_response["503"] = "Service Unavailable";
  this->_map_response["504"] = "Gateway Time-out";
  this->_map_response["505"] = "HTTP Version not supported";
}

std::string	HttpResponse::generateHeader()
{
  return ("Content-Type: text/html\r\n");
}

std::string		HttpResponse::generateStatusLine()
{
  std::stringstream			ss;
  std::string				status_code;

  status_code = this->findStatusCode();
  ss << "HTTP/"
     << this->_req->getVersionProtocol().getMajor()
     << "."
     << this->_req->getVersionProtocol().getMinor()
     << " "
     << status_code
     << " "
     << this->_map_response[status_code]
     << "\r\n";
  return (ss.str());
}

std::string	HttpResponse::findStatusCode()
{
  return ("202");
}

std::ifstream*	HttpResponse::generateMessageBody()
{
  std::cout << "[debug generate message body]" << std::endl;

  std::ifstream* infile = new std::ifstream();
  std::string	file(this->_conf.getDocumentRoot());

  file += this->_req->getPath();
  std::cout << "file = " << file << std::endl;
  infile->open(file.c_str());
  return (infile);
}

