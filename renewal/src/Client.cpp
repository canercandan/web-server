//
// Client.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:43 2008 caner candan
// Last update Sun Sep 14 01:19:08 2008 caner candan
//

#include <iostream>
#include "Client.h"
#include "Tools.h"
#include "Consumer.h"
#include "FluxClient.h"
#include "HttpParser.h"
#include "FileInfo.h"

Client::Client(Socket* sck)
  : _sck(sck)
{}

Client::~Client()
{
  if (_sck)
    delete _sck;
}

void	Client::run()
{
  Tools		tools(this->_sck->getSocket());
  FluxClient	flux(this->_sck);
  Consumer	consumer(flux);
  HttpParser	parser(consumer, tools.message().request());

  this->_loadModules();

  this->_hook.manageHookPoint(ZenZiAPI::NEW_CLIENT, tools);
  this->_hook.manageHookPoint(ZenZiAPI::DATA_IN, tools);

  parser.run();

  this->_hook.manageHookPoint(ZenZiAPI::PARSED, tools);
  this->_hook.manageHookPoint(ZenZiAPI::DEL_CLIENT, tools);

  tools.message().response().setUri(tools.message().request().getUri());

  std::string	response = tools.message().response().buildResponse();

  std::cout << "buildResponse: " << std::endl
	    << response
	    << std::endl;

  this->_sck->send(response);

  this->_unloadModules();

  //  this->_hook.manageHookPoint(ZenZiAPI::FILESYSTEM, tools);
  //  this->_hook.manageHookPoint(ZenZiAPI::DATA_OUT, tools);
  //  this->_hook.manageHookPoint(ZenZiAPI::READ, tools);
  //  this->_hook.manageHookPoint(ZenZiAPI::WRITE, tools);
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
#else
      if (!(handle = dlopen((*itb).c_str(), RTLD_NOW)))
#endif
	{
	  std::cerr << (*itb) << " not found" << std::endl;
	  continue;
	}
#ifdef WIN32
	  if (!(create = (create_t)GetProcAddress(handle, "create")) ||
		  !(destroy = (destroy_t)GetProcAddress(handle, "destroy")))
	  {
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
  FileInfo::FileInfo	info(Config::getInstance()->getParam("module_directory"));
  std::string		time;

  time = info.getLastTimeAccess();
  if (this->_lastAccess == "" ||
      this->_lastAccess != time)
    {
      this->_refreshListModule(info);
      this->_lastAccess = time;
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
