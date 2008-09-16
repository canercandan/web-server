//
// ConnectionInfos.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:19:45 2008 caner candan
// Last update Tue Sep 16 17:49:33 2008 caner candan
//

#include "ConnectionInfos.h"

ConnectionInfos::ConnectionInfos(SOCKET sck,
				 const std::string& type)
  : _sck(sck)
{
  if (type == "SIMPLE")
    _connectionType = SIMPLE;
  else if (type == "SSL")
    _connectionType = SSL;
  else if (type == "SSL2")
    _connectionType = SSL2;
  else if (type == "SSL3")
    _connectionType = SSL3;
  else if (type == "TLS")
    _connectionType = TLS;
  else
    _connectionType = OTHER;
}

const SOCKET	ConnectionInfos::getSocket() const
{
  return (this->_sck);
}

const ConnectionInfos::connectionType	ConnectionInfos::getConnectType(void) const
{
  return (this->_connectionType);
}

ConnectionInfos::Extension*	ConnectionInfos::getExtension(void) const
{
  return (this->_extension);
}

void	ConnectionInfos::setExtension(void *ptr)
{
  this->_extension = ptr;
}
