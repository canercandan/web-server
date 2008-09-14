#include <iostream>
#include "AutoIndex.h"
#include "FluxString.h"
#include "Consumer.h"
#include "URIParser.h"

AutoIndex::AutoIndex()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

AutoIndex::~AutoIndex()
{}

bool	AutoIndex::onLoad()
{
  std::cout << "AutoIndex loading..." << std::endl;
  return (true);
}

void	AutoIndex::onUnLoad()
{
  std::cout << "AutoIndex unloading..." << std::endl;
}

const AutoIndex::listCallback&	AutoIndex::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&AutoIndex::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::VERY_FIRST;
  return (this->_listCallback);
}

bool	AutoIndex::run(ZenZiAPI::ITools& tools)
{
  std::cout << "AutoIndex is running..." << std::endl;

  ZenZiAPI::IRequest*	request = &tools.message().request();
  ZenZiAPI::IConfig*	config = &tools.config();
  FluxString		flux(request->getUri());
  Consumer		consumer(flux);
  URIParser		uri(consumer);

  uri.run();

  FileInfo	info(config->getParam("document_root")
		     + uri.getPath());

  if (info.isGood() && info.getType() == FileInfo::DIR)
    tools.data(new std::string(this->_listingDirectory(tools, info)));
  return (true);
}

std::string	AutoIndex::_listingDirectory(ZenZiAPI::ITools& tools,
					    FileInfo& info)
{
  ZenZiAPI::IConfig*	config = &tools.config();
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
	(FileInfo(config->getParam("document_root")
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

extern "C"
{
  AutoIndex*	create()
  {
    return (new AutoIndex);
  }

  void		destroy(void* p)
  {
    delete static_cast<AutoIndex*>(p);
  }
}
