//
// MyModule.h for MyModule in /home/candan_c/cu/rendu/zia/renewal/modules/MyModule
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:22 2008 caner candan
// Last update Sat Sep 13 20:03:07 2008 florent hochwelker
//

#ifndef __MYMODULE_H__
# define __MYMODULE_H__

# include <string>
# include "IModule.hpp"

class	MyModule : public ZenZiAPI::IModule
{
  typedef std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >	listCallback;
public:
  MyModule();
  bool	onLoad();
  void	onUnLoad();

  const listCallback&	getCallbacks();

  bool	run(ZenZiAPI::ITools&);

private:
  listCallback	_p_int;
};

#endif // !__MYMODULE_H__
