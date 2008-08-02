//
// Thread.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:39:45 2008 morgan armand
// Last update Sat Aug  2 11:18:02 2008 morgan armand
//

#include <iostream>
#include "Thread.h"

Thread::Thread(IRunnable* obj)
  : _obj(obj)
{
}

void	Thread::start()
{
#ifdef WIN32
  if ((this->thread = CreateThread(NULL, 0, Thread::threadProc, _obj, 0, NULL)) == NULL)
    {
      std::cerr << "CreateThread() failed" << std::endl;
    }
#else
  if (pthread_create(&(this->thread), NULL, Thread::threadProc, _obj))
    {
      std::cerr << "pthread_create() failed" << std::endl;
    }
  if (pthread_detach(this->thread))
    {
      std::cerr << "pthread_create() failed" << std::endl;
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
  return (0);
#else
  pthread_exit(0);
#endif
}
