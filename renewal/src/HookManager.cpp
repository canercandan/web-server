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

bool	HookManager::hookPoint(hookPoint point, ITools& tools)
{
  if (!this->_hookPoint(point, tools, VERY_FIRST))
    return (false);
  if (!this->_hookPoint(point, tools, FIRST))
    return (false);
  if (!this->_hookPoint(point, tools, MIDDLE))
    return (false);
  if (!this->_hookPoint(point, tools, LAST))
    return (false);
  if (!this->_hookPoint(point, tools, VERY_LAST))
    return (false);
}

bool	HookManager::_hookPoint(hookPoint point, hookPosition position, ITools& tools)
{
  std::map<IModule*, Callbacks_t>::const_iterator	itb;
  std::map<IModule*, Callbacks_t>::const_iterator	ite;

  itb = this->_modules.begin();
  ite = this->_modules.end();

  for (; itb != ite; ++itb)
    {
      IModule*				mod;
      Callbacks_t::const_iterator	ctb;
      Callbacks_t::const_iterator	cte;

      mod = (*itb).first;
      ctb = (*itb).second.begin();
      cte = (*itb).second.end();

      for (; ctb != cte; ++ctb)
	{
	  p_callback	handler = (*ctb).first;

	  if ((*ctb).second == position)
	    {
	      if ((mod->*handler)(tools) == false)
		return (false);
	    }
	}
    }

  return (true);
}
