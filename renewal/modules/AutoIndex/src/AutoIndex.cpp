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

  XmlParser	xml(config->getParam("module_directory")
		    + "mod_autoindex.xml");

  std::string	indexEnabled(xml.xmlGetParam("/autoindex/index", "enabled"));

  if (indexEnabled == "true")
    {
      XmlParser::listParam	list(xml.xmlGetListParam("//autoindex/index"));

      for (XmlParser::listParam::iterator
	     it = list.begin(),
	     end = list.end();
	   it != end; ++it)
	{
	  XmlParser::listAttribute	attr = *it;

	  for (FileInfo::listDir::iterator
		 it = listDir.begin(),
		 end = listDir.end();
	       it != end; ++it)
	    {
	      std::string	sFile(*it);

	      if (attr["value"] == sFile)
		{
		  FileInfo	iFile(info.getPath() + sFile);

		  return (iFile.getContent());
		}
	    }
	}
    }

  std::string	textSize(xml.xmlGetParam("/autoindex/text_size", "value"));
  std::string	hiddenFileEnabled
    (xml.xmlGetParam("/autoindex/show_hidden_file", "enabled"));

  XmlParser::listAttribute	fileCss
    (xml.xmlGetParam("/autoindex/file_css"));
  XmlParser::listAttribute	fileHeader
    (xml.xmlGetParam("/autoindex/file_header"));
  XmlParser::listAttribute	fileFooter
    (xml.xmlGetParam("/autoindex/file_footer"));
  XmlParser::listAttribute	textHeader
    (xml.xmlGetParam("/autoindex/text_header"));
  XmlParser::listAttribute	textFooter
    (xml.xmlGetParam("/autoindex/text_footer"));

  response +=
    "<html>\n"
    "<head>\n"
    "<style><!--"
    "body{"
    "font-size:" + textSize + ";"
    "}"
    "--></style>\n";

  if (fileCss["enabled"] == "true")
    response +=
      "<link rel=\"stylesheet\" href=\""
      + fileCss["value"]
      + "\" type=\"text/css\" />\n";

  response +=
    "</head>\n"
    "<body>\n";

  if (fileHeader["enabled"] == "true")
    {
      FileInfo	file(info.getPath() + fileHeader["value"]);

      response += file.getContent() + '\n';
    }

  if (textHeader["enabled"] == "true")
    response += textHeader["value"] + '\n';

  response +=
    "<h1>Index of " + uri.getPath() + "</h1>\n"
    "<ul>\n";

  for (FileInfo::listDir::iterator
	 it = listDir.begin(),
	 end = listDir.end();
       it != end; ++it)
    {
      std::string	file = *it;

      if (hiddenFileEnabled != "true")
	if (file != "." && file != "..")
	  if (file[0] == '.')
	    continue;

      std::string	path(info.getPath() + file);

      FileInfo		checkDir(path);

      if (checkDir.getType() == FileInfo::DIR)
	response +=
	  "<li class=\"dir\"><a href=\"" + file + '/' + "\">"
	  + file + '/' + "</a></li>\n";
      else
	response +=
	  "<li class=\"file\"><a href=\"" + file + "\">"
	  + file + "</a></li>\n";
    }

  response += "</ul>\n";

  if (textFooter["enabled"] == "true")
    response += textFooter["value"] + '\n';

  if (fileFooter["enabled"] == "true")
    {
      FileInfo	file(info.getPath() + fileFooter["value"]);

      response += file.getContent() + '\n';
    }

  response +=
    "</body>\n"
    "</html>\n";

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
