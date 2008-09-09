#ifndef _HOOKMANAGER_H_
# define _HOOKMANAGER_H_

//#include <map>
#include "IHookManager.hpp"

namespace	ZenZiAPI
{
  class		HookManager : public IHookManager
  {
    typedef	std::map<IModule*, std::pair<IModule::p_callback, hookPosition>*>	HookManagerMods;

  public:
    bool	addModule(std::pair<IModule::p_callback, hookPosition> callbacks[hookPointsNumber], IModule* module);
    void	removeModule(IModule* module);
    bool	manageHookPoint(hookPoint point, ITools& tools);

  private:
    bool	_manageHookPoint(hookPoint point, ITools& tools, hookPosition position);
  private:
    HookManagerMods	_modules;
  };
}

#endif // _HOOKMANAGER_H_
