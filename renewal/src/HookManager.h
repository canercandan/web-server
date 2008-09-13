//
// HookManager.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 21:12:35 2008 caner candan
// Last update Sat Sep 13 21:12:35 2008 caner candan
//

#ifndef __HOOK_MANAGER_H__
#define __HOOK_MANAGER_H__

#include <vector>
#include "defines.hpp"
#include "IModule.hpp"
#include "ITools.hpp"

class	HookManager
{
  typedef std::pair<ZenZiAPI::IModule::p_callback,
		    ZenZiAPI::hookPosition>	pairCallback_t;
  typedef std::vector<pairCallback_t>		Callbacks_t;
public:
  bool	addModule(ZenZiAPI::IModule* module);
  void	delModule(ZenZiAPI::IModule* module);
  bool	manageHookPoint(ZenZiAPI::hookPoint point,
			ZenZiAPI::ITools& tools);
private:
  bool	_manageHookPoint(ZenZiAPI::hookPoint point,
			 ZenZiAPI::hookPosition position,
			 ZenZiAPI::ITools& tools);
  bool	_checkHookPoint(ZenZiAPI::hookPoint point,
			ZenZiAPI::hookPosition position);
private:
  std::map<ZenZiAPI::IModule*, Callbacks_t>	_modules;
};

#endif // __HOOK_MANAGER_H__
