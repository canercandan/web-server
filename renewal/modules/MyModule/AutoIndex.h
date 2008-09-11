//
// AutoIndex.h for AutoIndex in /home/candan_c/cu/rendu/zia/renewal/modules/AutoIndex
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:22 2008 caner candan
// Last update Thu Sep 11 15:36:12 2008 caner candan
//

#ifndef __AUTOINDEX_H__
# define __AUTOINDEX_H__

# include <string>
# include "IModule.hpp"

class	AutoIndex : public ZenZiAPI::IModule
{
public:
  bool	onLoad();
  void	onUnLoad();

  const std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >&	getCallbacks();

  void	run(ZenZiAPI::ITools&);
private:
  std::vector<std::pair<p_callback, ZenZiAPI::hookPosition> >	p_int;
};

#endif // !__AUTOINDEX_H__
