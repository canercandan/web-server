//
// ConnectionInfos.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 20:19:45 2008 caner candan
// Last update Sat Sep 13 20:19:46 2008 caner candan
//

#include "ConnectionInfos.h"

ConnectionInfos::ConnectionInfos(SOCKET sck)
  : _sck(sck)
{}

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
