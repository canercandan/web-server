//
// IRunnable.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sat Sep 13 22:19:59 2008 caner candan
// Last update Sat Sep 13 22:19:59 2008 caner candan
//

#ifndef __IRUNNABLE_H__
# define __IRUNNABLE_H__

class	IRunnable
{
public:
  virtual ~IRunnable(){};

  virtual void run() = 0;
};

#endif // !__IRUNNABLE_H__
