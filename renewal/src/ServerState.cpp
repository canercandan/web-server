//
// ServerState.cpp for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 10:45:25 2008 caner candan
// Last update Thu Sep 11 11:05:03 2008 caner candan
//

#include "ServerState.h"

ServerState::ServerState()
  : _state(BREAK)
{}

ServerState::~ServerState()
{}

const ServerState::State&	ServerState::getState() const
{
  return (this->_state);
}

void	ServerState::setState(const ServerState::State& state)
{
  this->_state = state;
}
