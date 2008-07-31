//
// Thread.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:39:45 2008 morgan armand
// Last update Wed Jul 30 20:09:18 2008 morgan armand
//

#ifdef WIN32
# include <windows.h>
#else
# include <pthread.h>
#endif

#include <iostream>
#include "Thread.h"

Thread::Thread(IRunnable* obj)
  : _obj(obj)
{
}

void	Thread::start()
{
#ifdef WIN32
  if (CreateThread(NULL, 0, Thread::threadProc, _obj, 0, NULL) == NULL)
    {
      std::cerr << "CreateThread() failed" << std::endl;
    }
#else
  pthread_t	thread;

  if (pthread_create(&thread, NULL, Thread::threadProc, _obj))
    {
      std::cerr << "pthread_create() failed" << std::endl;
    }
  if (pthread_join(thread, NULL))
    {
      std::cerr << "pthread_join() failed" << std::endl;
    }
#endif
}

#ifdef WIN32
DWORD WINAPI	Thread::threadProc(LPVOID arg)
#else
  void*		Thread::threadProc(void* arg)
#endif
{
  ((IRunnable *)arg)->run();
#ifdef WIN32
#else
  pthread_exit(0);
#endif
}
