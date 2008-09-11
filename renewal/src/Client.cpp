//
// Client.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:43 2008 caner candan
// Last update Thu Sep 11 09:54:40 2008 morgan armand
//

//#include <memory>
#include <iostream>
#include "Client.h"
//#include "Request.h"
//#include "Response.h"
//#include "FluxClient.h"
//#include "Consumer.h"
//#include "HttpParser.h"
//#include "URIParser.h"
//#include "Config.h"

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
  this->_loadModules();
  this->_unloadModules();
}

void	Client::_loadModules()
{
  void*						handle;
  create_t					create;
  destroy_t					destroy;
  IModule*					mod;
  std::list<std::string>			mods;
  std::list<std::string>::const_iterator	itb;
  std::list<std::string>::const_iterator	ite;

  mods.push_back("/tmp/test.so");
  mods.push_back("/tmp/autoindex.so");

  itb = mods.begin();
  ite = mods.end();

  this->_mods.clear();

  for (; itb != ite; ++itb)
    {
      if (!(handle = dlopen((*itb).c_str(), RTLD_NOW)))
	{
	  std::cerr << (*itb) << "not found" << std::endl;
	  continue;
	}
      if (!(create = (create_t)dlsym(handle, "create")) ||
	  !(destroy = (destroy_t)dlsym(handle, "destroy")))
	{
	  dlclose(handle);
	  continue;
	}

      if ((mod = create()))
	{
	  this->_hook.addModule(mod);
	  this->_mods.push_back(std::pair<IModule*, destroy_t>(mod, destroy));
	}

      dlclose(handle);
    }
}

void	Client::_unloadModules()
{
  std::list< std::pair<IModule*, destroy_t> >::const_iterator	itb;
  std::list< std::pair<IModule*, destroy_t> >::const_iterator	ite;

  itb = this->_mods.begin();
  ite = this->_mods.end();

  for (; itb != ite; ++itb)
    {
      IModule*	mod;
      destroy_t	destroy;

      mod = (*itb).first;
      destroy = (*itb).second;

      if (mod)
	this->_hook.delModule(mod);

      if (destroy)
	destroy(mod);
    }

  this->_mods.clear();
}
