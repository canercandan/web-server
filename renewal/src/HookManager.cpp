//
// HookManager.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:20:01 2008 caner candan
// Last update Sat Sep 13 21:09:29 2008 caner candan
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
      if (callbacks[i].second == ZenZiAPI::VERY_FIRST &&
	  this->_checkHookPoint(static_cast<ZenZiAPI::hookPoint>(i),
				ZenZiAPI::VERY_FIRST) ||
	  callbacks[i].second == ZenZiAPI::VERY_LAST &&
	  this->_checkHookPoint(static_cast<ZenZiAPI::hookPoint>(i),
				ZenZiAPI::VERY_LAST))
	return (false);
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
  if (!this->_manageHookPoint(point, ZenZiAPI::VERY_FIRST, tools))
    return (false);
  if (!this->_manageHookPoint(point, ZenZiAPI::FIRST, tools))
    return (false);
  if (!this->_manageHookPoint(point, ZenZiAPI::MIDDLE, tools))
    return (false);
  if (!this->_manageHookPoint(point, ZenZiAPI::LAST, tools))
    return (false);
  if (!this->_manageHookPoint(point, ZenZiAPI::VERY_LAST, tools))
    return (false);
  return (true);
}


bool	HookManager::_manageHookPoint(ZenZiAPI::hookPoint point,
				      ZenZiAPI::hookPosition position,
				      ZenZiAPI::ITools& tools)
{
  std::map<ZenZiAPI::IModule*, Callbacks_t>::const_iterator	itb;
  std::map<ZenZiAPI::IModule*, Callbacks_t>::const_iterator	ite;

  itb = this->_modules.begin();
  ite = this->_modules.end();

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
	    if ((mod->*handler)(tools) == false)
	      return (false);
	}
    }
  return (true);
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
	if (cb[point].second == position)
	  return (true);
    }
  return (false);
}
