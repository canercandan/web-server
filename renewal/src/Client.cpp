//
// Client.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:43 2008 caner candan
// Last update Wed Sep 17 21:22:55 2008 caner candan
//

#include <iostream>
#include "Client.h"
#include "Consumer.h"
#include "FluxClient.h"
#include "HttpParser.h"
#include "FileInfo.h"
#include "Logger.h"

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
  FluxClient		flux(this->_hook, this->_tools);
  Consumer		consumer(flux);
  HttpParser		parser(consumer, this->_tools.message().request());
  ZenZiAPI::IResponse*	response = &this->_tools.message().response();

  this->_loadModules();

  this->_hook.manageHookPoint(ZenZiAPI::NEW_CLIENT, this->_tools);
  this->_hook.manageHookPoint(ZenZiAPI::DATA_IN, this->_tools);

  parser.run();

  this->_hook.manageHookPoint(ZenZiAPI::PARSED, this->_tools);

  if (!this->_hook.manageHookPoint(ZenZiAPI::FILESYSTEM, this->_tools))
    response->bodyAppend(response->buildResponse());

  this->_hook.manageHookPoint(ZenZiAPI::DATA_OUT, this->_tools);

  if (!this->_hook.manageHookPoint(ZenZiAPI::WRITE, this->_tools))
    {
      if (this->_tools.data())
	{
	  if (!this->_sendString(*this->_tools.data()))
	    this->_sendString(response->getBody());
	}
      else
	this->_sendString(response->getBody());
    }
  this->_hook.manageHookPoint(ZenZiAPI::DEL_CLIENT, this->_tools);

  this->_unloadModules();

  //  this->_hook.manageHookPoint(ZenZiAPI::READ, tools);
  //  this->_hook.manageHookPoint(ZenZiAPI::WRITE, tools);
  this->_sck->close();
}

bool	Client::_sendString(const std::string& string)
{
  const char*	buf = string.c_str();
  int		len = string.size();
  int		ret;
  bool		res(false);

  while (len > 0)
    {
      ret = this->_sck->send((char *)buf, len);
      buf += ret;
      len -= ret;
      res |= true;
    }
  return (res);
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
