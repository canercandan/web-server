#include "HookManager.h"

bool	HookManager::addModule(IModule* module)
{
  size_t	i;
  size_t	size;
  Callbacks_t	callbacks;

  if (!module)
    return (false);

  if (this->_modules.count(module))
    return (false);

  callbacks = module->getCallbacks();
  size = callbacks.size();

  for (i = 0; i < size; i++)
    {
      if ((callbacks[i].second == VERY_FIRST && this->_checkHookPoint((hookPoint)i, VERY_FIRST)) ||
	  (callbacks[i].second == VERY_LAST && this->_checkHookPoint((hookPoint)i, VERY_LAST)))
	return (false);
    }

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

	  if (cb[point].second == position)
	    {
	      if ((mod->*handler)(tools) == false)
		return (false);
	    }
	}
    }

  return (true);
}

bool	HookManager::_checkHookPoint(hookPoint point, hookPosition position)
{
  std::map<IModule*, Callbacks_t>::const_iterator	itb;
  std::map<IModule*, Callbacks_t>::const_iterator	ite;

  itb = this->_modules.begin();
  ite = this->_modules.end();

  for (; itb != ite; ++itb)
    {
      Callbacks_t	cb;

      cb = (*itb).second;

      if ((size_t)point <= cb.size())
	{
	  if (cb[point].second == position)
	    return (true);
	}
    }

  return (false);
}
