//
// FluxClient.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:46 2008 caner candan
// Last update Thu Sep 11 11:48:11 2008 morgan armand
//

#ifndef __FLUXCLIENT_H__
# define __FLUXCLIENT_H__

# include "IFlux.h"
# include "Socket.h"

class	FluxClient : public IFlux
{
public:
  FluxClient(Socket* sck);
  ~FluxClient();

  virtual std::string	nextString();
private:
  Socket*	_sck;
};

#endif // !__FLUXCLIENT_H__
