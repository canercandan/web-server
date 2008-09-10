#ifndef __HOOK_MANAGER_H__
#define __HOOK_MANAGER_H__

#include <vector>
#include "defines.hpp"
#include "IModule.hpp"
//#include "ITools.hpp"

using namespace	ZenZiAPI;

class	HookManager
{
private:
  typedef std::vector< std::pair<IModule::p_callback, hookPosition> >	Callbacks_t;

public:
  bool	addModule(IModule* module);
  void	delModule(IModule* module);
  bool	hookPoint(hookPoint point, ITools& tools);

private:
  bool	_hookPoint(hookPoint point, hookPosition position, ITools& tools);

private:
  std::map<IModule*, Callbacks_t>	_modules;
};

#endif // __HOOK_MANAGER_H__
