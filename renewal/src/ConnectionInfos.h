//
// ConnectionInfos.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 12:41:39 2008 caner candan
// Last update Wed Sep 10 15:24:43 2008 caner candan
//

#ifndef __CONNECTIONINFOS_H__
# define __CONNECTIONINFOS_H__

# include "IConnectionInfos.hpp"

class	ConnectionInfos
  : public ZenZiAPI::IConnectionInfos
{
public:
  ConnectionInfos();

  const SOCKET		socket();
  const connectionType	connectionType();

  Extension*		extension();
  void			extension(void* ptr);
private:
  SOCKET		_sck;
  connectionType	_type;
};

#endif //! __CONNECTIONINFOS_H__
