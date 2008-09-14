//
// SignalManager.h for Signal in /home/candan_c/cu/rendu/cpp/test/signal
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Sep 14 10:30:34 2008 caner candan
// Last update Sun Sep 14 14:00:37 2008 caner candan
//

#ifndef __ISIGNALMANAGER_H__
# define __ISIGNALMANAGER_H__

class	ISignalManager
{
public:
  typedef void	(ISignalManager::*callback)(void);

  virtual ~ISignalManager(){}
};

#endif // !__ISIGNALMANAGER_H__
