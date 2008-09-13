//
// ConnectionInfos.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:19:42 2008 caner candan
// Last update Sat Sep 13 20:19:43 2008 caner candan
//

#ifndef	__CONNECTIONINFOS_H__
# define __CONNECTIONINFOS_H__

# include "IConnectionInfos.hpp"

class	ConnectionInfos : public ZenZiAPI::IConnectionInfos
{
public:
  ConnectionInfos(SOCKET sck);

  const SOCKET		getSocket() const;
  const connectionType	getConnectType(void) const;
  Extension*		getExtension(void) const;
  void			setExtension(void *ptr);
private:
  connectionType	_connectionType;
  Extension*		_extension;
  SOCKET		_sck;
};

#endif	// !__CONNECTIONINFOS_H__
