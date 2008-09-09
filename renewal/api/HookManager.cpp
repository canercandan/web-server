#include "HookManager.h"

using namespace	ZenZiAPI;

bool	HookManager::addModule(std::pair<IModule::p_callback, hookPosition> callbacks[hookPointsNumber], IModule* module)
{
  if (!module)
    return (false);

  if (this->_modules.find(module) == this->_modules.end())
    return (false);

  this->_modules[module] = callbacks;

  return (true);
}

void	HookManager::removeModule(IModule* module)
{
  if (this->_modules.find(module) != this->_modules.end())
    this->_modules.erase(module);
}

bool	HookManager::manageHookPoint(hookPoint point, ITools& tools)
{
  if (!this->_manageHookPoint(point, tools, VERY_FIRST))
    return (false);
  if (!this->_manageHookPoint(point, tools, FIRST))
    return (false);
  if (!this->_manageHookPoint(point, tools, MIDDLE))
    return (false);
  if (!this->_manageHookPoint(point, tools, LAST))
    return (false);
  if (!this->_manageHookPoint(point, tools, VERY_LAST))
    return (false);
}

bool	HookManager::_manageHookPoint(hookPoint point, ITools& tools, hookPosition position)
{
  bool					ret = true;
  HookManagerMods::const_iterator	itb = this->_modules.begin();
  HookManagerMods::const_iterator	ite = this->_modules.end();

  for (; itb != ite; ++itb)
    {
      IModule*						mod = (*itb).first;
      std::pair<IModule::p_callback, hookPosition>*	tab = (*itb).second;

      if (tab[point].second == position)
	{
	  if ((mod->*tab[point].first)(tools) == false)
	    return (false);
	}
    }

  return (true);
}
