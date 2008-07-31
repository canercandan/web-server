//
// Thread.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:38:41 2008 morgan armand
// Last update Wed Jul 30 20:08:45 2008 morgan armand
//

#ifndef __THREAD_H__
#define __THREAD_H__

#ifdef WIN32
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
#else
# include <pthread.h>
#endif

#include "IRunnable.h"

class	Thread
{
public:
  Thread(IRunnable* obj);

  // This method create the thread and start it.
  void	start();

public:

#ifdef WIN32
  static DWORD WINAPI	threadProc(LPVOID arg);
#else
  static void*		threadProc(void* arg);
#endif

private:
  IRunnable*	_obj;
};

#endif // __THREAD_H__
