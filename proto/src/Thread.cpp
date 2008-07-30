//
// Thread.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:39:45 2008 morgan armand
// Last update Wed Jul 30 16:50:54 2008 morgan armand
//

#ifdef WIN32
# include <windows.h>
#else
# include <pthread.h>
#endif

#include <iostream>
#include "Thread.h"

void	Thread::start()
{
#ifdef WIN32
  if (CreateThread(NULL, 0, this->run, NULL, 0, NULL) == NULL)
    {
      std::cerr << "CreateThread() failed" << std::endl;
    }
#else
  pthread_t	thread;

  if (pthread_create(&thread, NULL, this->run, NULL))
    {
      std::cerr << "pthread_create() failed" << std::endl;
    }
  if (pthread_join(thread, NULL))
    {
      std::cerr << "pthread_join() failed" << std::endl;
    }
#endif
}
