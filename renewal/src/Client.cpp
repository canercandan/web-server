//
// Client.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:43 2008 caner candan
// Last update Thu Sep 25 14:54:02 2008 caner candan
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Client.h"
#include "Consumer.h"
#include "FluxClient.h"
#include "FluxString.h"
#include "HttpParser.h"
#include "FileInfo.h"
#include "Logger.h"
#include "Config.h"

Client::Client(Socket* sck, const std::string& type)
  : _sck(sck), _tools(_sck->getSocket(), type)
{}

Client::~Client()
{
  if (_sck)
    delete _sck;
}

void	Client::run()
{
  FluxClient		flux(_hook, _tools);
  Consumer		consumer(flux);
  HttpParser		parser(consumer, _tools.message().request());
  ZenZiAPI::IResponse*	response = &_tools.message().response();
  Config*		config = Config::getInstance();
  std::string		res;

  _loadModules();

  _hook.manageHookPoint(ZenZiAPI::NEW_CLIENT, _tools);
  _hook.manageHookPoint(ZenZiAPI::DATA_IN, _tools);

  parser.run();

  _hook.manageHookPoint(ZenZiAPI::PARSED, _tools);

  std::string	documentRoot;

  if (!((documentRoot = response->getHeader("Zia", "document_root")).empty()))
    config->setParam("document_root", documentRoot);

  //response->setChunk(true);

  //if (!response->isChunk())
  //else
  //_sck->send((char*)res.c_str(), res.size());

  //bool res_filesystem(true);

  if (!_hook.manageHookPoint(ZenZiAPI::FILESYSTEM, _tools))
    {
      FluxString	flux(response->getUri());
      Consumer	consumer(flux);
      URIParser	uri(consumer);

      uri.run();

      //Config*		config = Config::getInstance();
      res = config->getParam("document_root") + uri.getPath();

      FileInfo	info(res);

      // File is ok
      if (info.isGood() && info.getType() == FileInfo::FILE)
	{
	  std::stringstream	ss("");

	  response->setStatusCode(200);

	  ss << info.getSize();

	  if (info.getSize() > 0)
	    response->setHeader("Content-Length", ss.str());

	  response->setChunk(true);
	}

      // Request a directory
      else if (info.isGood() && info.getType() == FileInfo::DIR)
	{
	  response->setStatusCode(403);
	  response->setBody("<html><head><title>403 Forbidden</title></head><body>"
			    "<h1>Forbidden</h1><p>You don't have permission to access"
			    + info.getPath() + "on this server.</p></body></html>");
	}
      // Request something's wrong
      else
	{
	  response->setStatusCode(404);
	  response->setBody("<html><head><title>404 Not Found</title></head><body>"
			    "<h1>Forbidden</h1><p>The ressource" + info.getPath() +
			    "cannot be found on this server.</p></body></html>");
	}
      //res_filesystem = false;
    }

  std::string	headers(response->buildResponse());

  //response->setBody(headers);

  _hook.manageHookPoint(ZenZiAPI::DATA_OUT, _tools);

  // Send headers
  _tools.data(new std::string(headers));

  if (!_hook.manageHookPoint(ZenZiAPI::WRITE, _tools))
    this->_sendString(headers);

  delete _tools.data();

  std::cout << headers << std::endl;

  if (response->isChunk())
    {
      // UGLY HACK : 14h19
      if (res.empty())
	{
	  _tools.data(new std::string(response->getBody()));
	  if (!_hook.manageHookPoint(ZenZiAPI::WRITE, _tools))
	    this->_sendString(response->getBody());
	  delete _tools.data();
	}
      else
	{
#define CHUNK_SIZE	512

	  std::ifstream		in(res.c_str(), std::ios::binary);
	  char				chunk[CHUNK_SIZE];

	  if (in.is_open())
	    {
	      while (in.good())
		{
		  int			cc;
		  std::stringstream	ss;
		  std::string		data;

		  in.read(chunk, CHUNK_SIZE);

		  cc = in.gcount();
		  ss << std::hex << cc;

		  data  = ss.str();
		  data += "\r\n";
		  data += std::string(chunk, cc);
		  data += "\r\n";

		  //sck->send((char *)data.c_str(), data.size());
		  _tools.data(new std::string(data));
		  if (!_hook.manageHookPoint(ZenZiAPI::WRITE, _tools))
		    this->_sendString(data);
		  delete _tools.data();
		}
		  

	      // Last chunk
	      std::string	last_chunk;

	      last_chunk = "0\r\n\r\n";
	      //sck->send((char *)last_chunk.c_str(), last_chunk.size());
	      this->_sendString(last_chunk);

	      in.close();
	    }
	}
	  
    }
  else
    {
      FileInfo	info(res);

      if (info.isGood() && info.getType() == FileInfo::FILE)
	response->setBody(info.getContent());

      _tools.data(new std::string(response->getBody()));
      if (!_hook.manageHookPoint(ZenZiAPI::WRITE, _tools))
	this->_sendString(response->getBody());
      delete _tools.data();
    }

  /*
    if (!documentRoot.empty())
    config->setLastParam("document_root");

    _hook.manageHookPoint(ZenZiAPI::DATA_OUT, _tools);

    if (!_hook.manageHookPoint(ZenZiAPI::WRITE, _tools))
    { 
    if (!res_filesystem)
    {
    _sendString(response->getBody());
      
    if (response->isChunk())
    ((Response*)(response))->sendFile(_sck);
    }
    }
  */
  _hook.manageHookPoint(ZenZiAPI::DEL_CLIENT, _tools);

  _unloadModules();

  //Sleep(3000);
  delete this;
}

void	Client::_sendString(const std::string& string)
{
  const char*	buf = string.c_str();
  int		len = string.size();
  int		cc;

  while (len > 0)
    {
      if ((cc = this->_sck->send((char *)buf, len)) < 0)
		  break;

	  buf += cc;
      len -= cc;

	  std::cout << "[" << this->_sck->getSocket()
		  << "] " << "Send " << cc << " bytes (still "
<< len << " bytes)" << std::endl;
    }
}

void	Client::_loadModules()
{
#ifdef WIN32
  HMODULE		handle;
#else
  void*			handle;
#endif

  create_t		create;
  destroy_t		destroy;
  ZenZiAPI::IModule*	mod;

  this->_listModule.clear();
  this->_getNameModules();

  for (listNameModule::const_iterator
	 itb = this->_listNameModule.begin(),
	 ite = this->_listNameModule.end();
       itb != ite; ++itb)
    {
#ifdef WIN32
      WCHAR	wszModule[MAX_PATH];

      MultiByteToWideChar(CP_ACP, 0, (*itb).c_str(), -1, wszModule, MAX_PATH);

      if (!(handle = LoadLibrary(wszModule)))
	  {
		  TCHAR	wczErr[255];
			char	err[255];

		  FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), 0, wczErr, 255, NULL);
		  WideCharToMultiByte(CP_ACP, 0, wczErr, -1, err, 255, NULL, NULL);

		  std::cerr << (*itb) << ": " << err << std::endl;
		  continue;
	  }
#else
	if (!(handle = dlopen((*itb).c_str(), RTLD_NOW)))
	  {
	    std::cout << dlerror() << std::endl;
	    continue;
	  }
#endif
#ifdef WIN32
      if (!(create = (create_t)GetProcAddress(handle, "create")) ||
	  !(destroy = (destroy_t)GetProcAddress(handle, "destroy")))
	{
		TCHAR	wczErr[255];
		char	err[255];

		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), 0, wczErr, 255, NULL);
		WideCharToMultiByte(CP_ACP, 0, wczErr, -1, err, 255, NULL, NULL);

		std::cerr << (*itb) << ": " << err << std::endl;
	  FreeLibrary(handle);
	  continue;
	}
#else
      if (!(create = (create_t)dlsym(handle, "create")) ||
	  !(destroy = (destroy_t)dlsym(handle, "destroy")))
	{

	  dlclose(handle);
	  continue;
	}
#endif

      if ((mod = create()) && mod->onLoad())
	{
	  this->_hook.addModule(mod);
	  this->_listModule.push_back(pairModule(mod, destroy));
	}
      //dlclose(handle);
    }
}

const Client::listNameModule&	Client::_getNameModules()
{
  FileInfo	info(Config::getInstance()->getParam("module_directory"));

  if (info.isAccessModified(this->_lastAccess) == true)
    {
      this->_refreshListModule(info);
      this->_lastAccess = info.getLastTimeAccess();
    }
  return (this->_listNameModule);
}

void	Client::_refreshListModule(FileInfo& info)
{
  const FileInfo::listDir&	dir = info.getListDir();
  int				found;

  this->_listNameModule.clear();

  for (FileInfo::listDir::const_iterator
	 itb = dir.begin(),
	 ite = dir.end();
       itb != ite; itb++)
    {
      found = itb->find_last_of(".");
#ifdef WIN32
      if (itb->substr(found + 1) == "dll")
#else
	if (itb->substr(found + 1) == "so")
#endif
	  this->_listNameModule.push_back
	    (Config::getInstance()->getParam("module_directory") + *itb);
    }
}

void	Client::_unloadModules()
{
  for (listModule::const_iterator
	 itb = this->_listModule.begin(),
	 ite = this->_listModule.end();
       itb != ite; ++itb)
    {
      ZenZiAPI::IModule*	mod;
      destroy_t			destroy;

      mod = (*itb).first;
      destroy = (*itb).second;

      if (mod)
	{
	  mod->onUnLoad();
	  this->_hook.delModule(mod);
	}

      if (destroy)
	destroy(mod);
    }
  this->_listModule.clear();
}
