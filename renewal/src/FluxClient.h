//
// FluxClient.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:46 2008 caner candan
// Last update Fri Sep 12 18:52:04 2008 caner candan
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

  std::string	nextString();
private:
  Socket*	_sck;
};

#endif // !__FLUXCLIENT_H__
