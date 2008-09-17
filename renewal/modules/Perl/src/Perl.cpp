#include <iostream>
#include "Perl.h"
#include "FluxString.h"
#include "Consumer.h"

Perl::Perl()
  : _listCallback(ZenZiAPI::hookPointsNumber)
{}

Perl::~Perl()
{}

bool	Perl::onLoad()
{
  std::cout << "Perl loading..." << std::endl;
  return (true);
}

void	Perl::onUnLoad()
{
  std::cout << "Perl unloading..." << std::endl;
}

const Perl::listCallback&	Perl::getCallbacks()
{
  this->_listCallback[ZenZiAPI::FILESYSTEM].first =
    static_cast<IModule::p_callback>(&Perl::run);
  this->_listCallback[ZenZiAPI::FILESYSTEM].second = ZenZiAPI::VERY_FIRST;
  return (this->_listCallback);
}

bool	Perl::run(ZenZiAPI::ITools& tools)
{
  std::cout << "Perl is running..." << std::endl;

  ZenZiAPI::IRequest*	request = &tools.message().request();
  ZenZiAPI::IConfig*	config = &tools.config();
  FluxString		flux(request->getUri());
  Consumer		consumer(flux);
  URIParser		uri(consumer);

  uri.run();

  FileInfo	info(config->getParam("document_root")
		     + uri.getPath());

  if (info.isGood() && info.getType() == FileInfo::DIR)
    tools.data(new std::string(this->_listingDirectory(tools, info, uri)));
  return (true);
}

std::string	Perl::_listingDirectory(ZenZiAPI::ITools& tools,
					     FileInfo& info,
					     URIParser& uri)
{
  ZenZiAPI::IConfig*	config = &tools.config();
  FileInfo::listDir&	listDir = info.getListDir();
  std::string		response;

  response += "<h1>Index of ";
  response += uri.getPath();
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
  EXPORT Perl*	create()
  {
    return (new Perl);
  }

  EXPORT void		destroy(void* p)
  {
    delete static_cast<Perl*>(p);
  }
}
