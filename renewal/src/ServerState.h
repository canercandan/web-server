//
// State.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 18:10:33 2008 caner candan
// Last update Thu Sep 11 12:07:09 2008 majdi toumi
//

#ifndef __STATE_H__
# define __STATE_H__

# include "Singleton.hpp"

class	ServerState : public Singleton<ServerState>
{
  friend class	Singleton<ServerState>;
public:
  enum	State	{PROCESS, BREAK};
public:
  const State&	getState() const;
  void		setState(const State&);
private:
  ServerState();
  ~ServerState();
private:
  State		_state;
};

#endif // !__STATE_H__
