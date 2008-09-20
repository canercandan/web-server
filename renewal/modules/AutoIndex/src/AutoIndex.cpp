#include <iostream>
#include "AutoIndex.h"
#include "FluxString.h"
#include "Consumer.h"
#include "XmlParser.h"

AutoIndex::AutoIndex()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

AutoIndex::~AutoIndex()
{}

bool	AutoIndex::onLoad()
{
  std::cout << "[mod_autoindex] loading..." << std::endl;
  return (true);
}

void	AutoIndex::onUnLoad()
{
  std::cout << "[mod_autoindex] unloading..." << std::endl;
}

const AutoIndex::listCallback&	AutoIndex::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&AutoIndex::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::FIRST;
  return (this->_listCallback);
}

bool	AutoIndex::run(ZenZiAPI::ITools& tools)
{
  std::cout << "[mod_autoindex] running..." << std::endl;

  ZenZiAPI::IRequest*	request = &tools.message().request();
  ZenZiAPI::IConfig*	config = &tools.config();
  FluxString		flux(request->getUri());
  Consumer		consumer(flux);
  URIParser		uri(consumer);

  uri.run();

  FileInfo	info(config->getParam("document_root")
		     + uri.getPath());

  if (!info.isGood() || !info.getType() == FileInfo::DIR)
    return (false);

  std::cout << "[mod_autoindex] executing" << std::endl;

  request->bodyAppend(this->_listingDirectory(tools, info, uri));
  return (true);
}

std::string	AutoIndex::_listingDirectory(ZenZiAPI::ITools& tools,
					     FileInfo& info,
					     URIParser& uri)
{
  ZenZiAPI::IConfig*	config = &tools.config();
  FileInfo::listDir&	listDir = info.getListDir();
  std::string		response;

  XmlParser		xml(config->getParam("module_directory")
			    + "mod_autoindex.xml");

  std::string	size(xml.xmlGetParam("/autoindex/size[@value]"));
  std::string	fileHidden(xml.xmlGetParam("/autoindex/file_hidden[@enabled]"));

  response +=
    "<html>"
    "<head>"
    "<style><!--"
    "body{"
    "font-size:" + size + ";"
    "}"
    "--></style>"
    "</head>"
    "<body>"
    "<h1>Index of " + uri.getPath() + "</h1>"
    "<ul>";

  for (FileInfo::listDir::iterator
	 it = listDir.begin(),
	 end = listDir.end();
       it != end; ++it)
    {
      std::string	file = *it;

      if (fileHidden != "true")
	if (file != "." && file != "..")
	  if (file[0] == '.')
	    continue;

      std::string	path(info.getPath() + file);

      FileInfo		checkDir(path);

      response += "<li>";

      if (checkDir.getType() == FileInfo::DIR)
	response +=
	  "[D] <a href=\"" + file + '/' + "\">"
	  + file + '/' + "</a>";
      else
	response +=
	  "[F] <a href=\"" + file + "\">"
	  + file + "</a>";
      response += "</li>";
    }

  response +=
    "</ul>"
    "</body>"
    "</html>";

  return (response);
}

extern "C"
{
  EXPORT AutoIndex*	create()
  {
    return (new AutoIndex);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<AutoIndex*>(p);
  }
}
