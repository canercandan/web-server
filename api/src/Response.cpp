#include <fstream>
#include "Response.h"

using namespace ziApi;

Response::Response(IRequest* request)
  : _request(request)
{}

IModule::State	Response::accept(const IModule::Event& event,
				 IModule* module)
{
  return (module->affect(event, this));
}

IRequest*	Response::getRequest() const
{
  return (this->_request);
}

void	Response::buildResponse()
{}

void	Response::sendResponse(ISocket* sck)
{
  this->_currentFile = new FileInfo(Config::getInstance()->getValue("document_root") + this->_request->getUrlPath());
  std::ifstream infile;
  if (this->_currentFile->isGood())
    {
      switch (this->_currentFile->getType())
	{
	case FileInfo::FILE:
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
	case FileInfo::DIR:
	  {
	    _generateListingDirectoryHTML(sck);
	    break;
	  }
	default:
	  this->_buffer = "<h1>File not found</h1>";
	  sck->send(this->_buffer);
	}
    }
  else
    {
      this->_buffer = "<h1>File not found</h1>";
      sck->send(this->_buffer);
    }
}

void	Response::appendBuf(const std::string& s)
{
  this->_buffer.append(s);
}

void	Response::prependBuf(const std::string& s)
{
  this->_buffer = s + this->_buffer;
}

void	Response::_generateListingDirectoryHTML(ISocket* sck)
{
  std::list<std::string>	listDir = this->_currentFile->getListDir();
  bool				errSend = false;

  this->_buffer = "<h1>Index of ";
  this->_buffer += this->_request->getUrlPath();
  this->_buffer += "</h1><ul>";
  if (sck->send(this->_buffer) <= 0)
    return;
  std::list<std::string>::iterator	it;
  std::list<std::string>::iterator	end = listDir.end();
  std::string				slashDir;
  for (it = listDir.begin(); it != end; ++it)
    {
      FileInfo checkDir = FileInfo(Config::getInstance()->getValue("document_root") + SLASH + this->_request->getUrlPath() + *it);
      if (checkDir.isGood() == true && checkDir.getType() == FileInfo::DIR)
	slashDir = SLASH;
      else
	slashDir = "";
      this->_buffer = "<li><a href=\"" + *it + slashDir + "\">"
	+ *it + slashDir + "</a></li>";
      if (sck->send(this->_buffer) <= 0)
	{
	  errSend = true;
	  break;
	}
    }
  if (errSend != false)
    {
      this->_buffer = "</ul>";
      sck->send(this->_buffer);
    }
}
