//
// Thread.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:38:41 2008 morgan armand
// Last update Sun Aug  3 13:42:21 2008 caner candan
//

#ifndef __THREAD_H__
#define __THREAD_H__

#ifdef WIN32
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
#else
# include <pthread.h>
#endif

#include "HttpConsumer.h"

class	Thread
{
public:
  Thread(HttpConsumer*);

  // This method create the thread and start it.
  void	start();

public:

#ifdef WIN32
  static DWORD WINAPI	threadProc(LPVOID arg);
#else
  static void*		threadProc(void* arg);
#endif

private:
  HttpConsumer*	_hc;

#ifdef WIN32
  HANDLE	thread;
#else
  pthread_t	thread;
#endif
};

#endif // __THREAD_H__
