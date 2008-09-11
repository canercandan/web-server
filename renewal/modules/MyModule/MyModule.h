//
// MyModule.h for MyModule in /home/candan_c/cu/rendu/zia/renewal/modules/MyModule
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:22 2008 caner candan
// Last update Thu Sep 11 15:39:00 2008 caner candan
//

#ifndef __MYMODULE_H__
# define __MYMODULE_H__

# include <string>
# include "IModule.hpp"

class	MyModule : public ZenZiAPI::IModule
{
public:
  bool	onLoad();
  void	onUnLoad();

  const std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >&	getCallbacks();

  void	run(ZenZiAPI::ITools&);
private:
  std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >	p_int;
};

#endif // !__MYMODULE_H__
