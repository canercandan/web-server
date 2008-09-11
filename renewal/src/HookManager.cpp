#include "HookManager.h"

bool	HookManager::addModule(IModule* module)
{
  if (!module)
    return (false);

  if (this->_modules.count(module))
    return (false);

  this->_modules[module] = module->getCallbacks();

  return (true);
}

void	HookManager::delModule(IModule* module)
{
  if (module && this->_modules.count(module))
    this->_modules.erase(module);
}

bool	HookManager::manageHookPoint(hookPoint point, ITools& tools)
{
  if (!this->_manageHookPoint(point, VERY_FIRST, tools))
    return (false);
  if (!this->_manageHookPoint(point, FIRST, tools))
    return (false);
  if (!this->_manageHookPoint(point, MIDDLE, tools))
    return (false);
  if (!this->_manageHookPoint(point, LAST, tools))
    return (false);
  if (!this->_manageHookPoint(point, VERY_LAST, tools))
    return (false);

  return (true);
}


bool	HookManager::_manageHookPoint(hookPoint point, hookPosition position, ITools& tools)
{
  std::map<IModule*, Callbacks_t>::const_iterator	itb;
  std::map<IModule*, Callbacks_t>::const_iterator	ite;

  itb = this->_modules.begin();
  ite = this->_modules.end();

  for (; itb != ite; ++itb)
    {
      IModule*		mod;
      Callbacks_t	cb;

      mod = (*itb).first;
      cb = (*itb).second;

      if ((size_t)point <= cb.size())
	{
	  IModule::p_callback&	handler = cb.at(point).first;

	  if (cb.at(point).second == position)
	    {
	      if ((mod->*handler)(tools) == false)
		return (false);
	    }
	}
    }

  return (true);
}
