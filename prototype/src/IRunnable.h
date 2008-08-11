//
// IRunnable.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 19:45:50 2008 morgan armand
// Last update Wed Jul 30 19:59:59 2008 morgan armand
//

#ifndef __IRUNNABLE_H__
#define __IRUNNABLE_H__

class	IRunnable
{
public:
  virtual	~IRunnable() {};

  // The method will be called by the thread.
  virtual void	run() = 0;
};
#endif // __IRUNNABLE_H__
