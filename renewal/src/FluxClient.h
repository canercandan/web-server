//
// FluxClient.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:50:46 2008 caner candan
// Last update Tue Sep  9 17:50:50 2008 caner candan
//

#ifndef __FLUXCLIENT_H__
# define __FLUXCLIENT_H__

# include "IFlux.h"
# include "ISocket.h"

class	FluxClient : public IFlux
{
public:
  FluxClient(ISocket* sck);
  ~FluxClient();

  virtual std::string	nextString();
private:
  ISocket*	_sck;
};

#endif // !__FLUXCLIENT_H__
