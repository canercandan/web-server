//
// HookManager.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:20:01 2008 caner candan
// Last update Wed Sep 17 00:05:19 2008 morgan armand
//

#include "HookManager.h"

bool	HookManager::addModule(ZenZiAPI::IModule* module)
{
  Callbacks_t	callbacks;

  if (!module)
    return (false);

  if (this->_modules.count(module))
    return (false);

  callbacks = module->getCallbacks();

  for (size_t i = 0, size = callbacks.size();
       i < size; i++)
    {
      if (callbacks[i].first)
	{
	  if (callbacks[i].second == ZenZiAPI::VERY_FIRST &&
	      this->_checkHookPoint(static_cast<ZenZiAPI::hookPoint>(i),
				    ZenZiAPI::VERY_FIRST))
	    {
	      std::cout << "warning: a module is already registered at VERY_FIRST" << std::endl;
	      return (false);
	    }

	  if (callbacks[i].second == ZenZiAPI::VERY_LAST &&
	      this->_checkHookPoint(static_cast<ZenZiAPI::hookPoint>(i),
				    ZenZiAPI::VERY_LAST))
	    {
	      std::cout << "warning: a module is already registered at VERY_LAST" << std::endl;
	      return (false);
	    }
	}
    }

  this->_modules[module] = callbacks;

  return (true);
}

void	HookManager::delModule(ZenZiAPI::IModule* module)
{
  if (module && this->_modules.count(module))
    this->_modules.erase(module);
}

bool	HookManager::manageHookPoint(ZenZiAPI::hookPoint point,
				     ZenZiAPI::ITools& tools)
{
  return (this->_manageHookPoint(point, ZenZiAPI::VERY_FIRST, tools)	||
	  this->_manageHookPoint(point, ZenZiAPI::FIRST, tools)		||
	  this->_manageHookPoint(point, ZenZiAPI::MIDDLE, tools)	||
	  this->_manageHookPoint(point, ZenZiAPI::LAST, tools)		||
	  this->_manageHookPoint(point, ZenZiAPI::VERY_LAST, tools));
}


bool	HookManager::_manageHookPoint(ZenZiAPI::hookPoint point,
				      ZenZiAPI::hookPosition position,
				      ZenZiAPI::ITools& tools)
{
  bool	ret;
  std::map<ZenZiAPI::IModule*, Callbacks_t>::const_iterator	itb;
  std::map<ZenZiAPI::IModule*, Callbacks_t>::const_iterator	ite;

  itb = this->_modules.begin();
  ite = this->_modules.end();
  ret = false;

  for (; itb != ite; ++itb)
    {
      ZenZiAPI::IModule*	mod;
      Callbacks_t		cb;

      mod = (*itb).first;
      cb = (*itb).second;

      if (static_cast<size_t>(point) <= cb.size())
	{
	  ZenZiAPI::IModule::p_callback	handler = cb.at(point).first;

	  if (handler && cb[point].second == position)
	    ret |= (mod->*handler)(tools);
	}
    }

  return (ret);
}

bool	HookManager::_checkHookPoint(ZenZiAPI::hookPoint point,
				     ZenZiAPI::hookPosition position)
{
  for (std::map<ZenZiAPI::IModule*, Callbacks_t>::const_iterator
	 itb = this->_modules.begin(),
	 ite = this->_modules.end();
       itb != ite; ++itb)
    {
      Callbacks_t	cb;

      cb = (*itb).second;

      if (static_cast<size_t>(point) <= cb.size())
	if (cb[point].first && cb[point].second == position)
	  return (true);
    }
  return (false);
}
