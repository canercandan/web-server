//
// Response.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 16:44:00 2008 majdi toumi
// Last update Sun Sep 14 20:19:13 2008 caner candan
//

#include <sstream>
#include <iostream>
#include <fstream>
#include "Response.h"
#include "FluxString.h"
#include "Consumer.h"
#include "Config.h"

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
  std::string	response;

  uri.run();

  Config*	config = Config::getInstance();
  FileInfo	info(config->getParam("document_root") + uri.getPath());

  response = this->_generateResponse(info);
  if (this->getMethod() == "HEAD")
    {
      response += "\r\n";
      return (response);
    }
  return (response + this->_sendMessageBody(info));
}

void	Response::resetHeaders()
{}

std::string	Response::_sendMessageBody(FileInfo& info)
{
  Config*	config = Config::getInstance();

  if (info.isGood() && info.getType() == FileInfo::FILE)
    return (info.getContent());
  if (info.isGood() && info.getType() == FileInfo::DIR)
    {}
  //return (this->_generateListingDirectoryHTML(info));

  FileInfo	infoErr(config->getParam("document_root")
			+ config->getParam("file_404"));

  if (infoErr.isGood())
    return (infoErr.getContent());
  return ("<h1>File not found</h1>");
}

std::string	Response::_generateListingDirectoryHTML(FileInfo& info)
{
  FileInfo::listDir&	listDir = info.getListDir();
  std::string		response;

  response += "<h1>Index of ";
  response += info.getPath();
  response += "</h1><ul>";
  for (FileInfo::listDir::iterator
	 it = listDir.begin(),
	 end = listDir.end();
       it != end; ++it)
    {
      FileInfo		checkDir
	(FileInfo(Config::getInstance()->getParam("document_root")
		  + '/' + info.getPath() + *it));
      std::string	slashDir;

      if (checkDir.isGood() && checkDir.getType() == FileInfo::DIR)
	slashDir = '/';
      response +=
	"<li><a href=\"" + *it + slashDir + "\">"
	+ *it + slashDir + "</a></li>";
    }
  response += "</ul>";
  return (response);
}

std::string	Response::_generateResponse(FileInfo& info)
{
  std::string	statusLine;
  std::string	content;

  statusLine = this->_createStatusLine();
  content = //this->_createGeneralHeader()
    //+ this->_createResponseHeader()
    this->_createEntityHeader(info);
  return (statusLine +
	  content + "\r\n");
}

std::string	Response::_createStatusLine()
{
  std::stringstream	ss;

  //this->_code = this->findStatusCode();
  this->setStatusCode(200);
  this->setStatusMessage("coucou");
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

  ss << "Location:" << config->getParam("location") << "\r\n"
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
