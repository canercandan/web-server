//
// ConnectionInfos.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 12:52:22 2008 caner candan
// Last update Wed Sep 10 15:21:45 2008 caner candan
//

#include "ConnectionInfos.h"

ConnectionInfos::ConnectionInfos()
{}

const SOCKET	ConnectionInfos::socket()
{
  return (this->_sck);
}

const ConnectionInfos::connectionType	ConnectionInfos::connectionType()
{
  return (this->_type);
}

ConnectionInfos::Extension*	ConnectionInfos::extension()
{
  return ((void*)0);
}

void	ConnectionInfos::extension(void*)
{}
