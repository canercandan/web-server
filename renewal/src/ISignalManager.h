//
// SignalManager.h for Signal in /home/candan_c/cu/rendu/cpp/test/signal
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Sep 14 10:30:34 2008 caner candan
// Last update Sun Sep 14 10:38:52 2008 caner candan
//

#ifndef __ISIGNALMANAGER_H__
# define __ISIGNALMANAGER_H__

class	ISignalManager
{
public:
  typedef void	(ISignalManager::*callback)(void);

  virtual ~ISignalManager(){}

  virtual void	signal() = 0;
};

#endif // !__ISIGNALMANAGER_H__
