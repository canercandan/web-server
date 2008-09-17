//
// FluxClient.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:46 2008 caner candan
// Last update Wed Sep 17 00:11:10 2008 morgan armand
//

#ifndef __FLUXCLIENT_H__
# define __FLUXCLIENT_H__

# include "ITools.hpp"
# include "IFlux.h"
# include "HookManager.h"
//# include "Socket.h"

class	FluxClient : public IFlux
{
public:
  FluxClient(HookManager& hook, ZenZiAPI::ITools& tools);
  ~FluxClient();

  std::string	nextString();

private:
  HookManager&		_hook;
 ZenZiAPI::ITools&	_tools;
};

#endif // !__FLUXCLIENT_H__
