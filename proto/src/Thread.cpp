//
// Thread.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:39:45 2008 morgan armand
// Last update Sun Aug  3 09:45:24 2008 caner candan
//

#include <iostream>
#include "Thread.h"
#include "Parser.h"

Thread::Thread(HttpConsumer* hc)
  : _hc(hc)
{}

void	Thread::start()
{
#ifdef WIN32
  if ((this->thread = CreateThread(NULL, 0, Thread::threadProc,
				   this->_hc, 0, NULL)) == NULL)
    std::cerr << "CreateThread() failed" << std::endl;
#else
  if (pthread_create(&(this->thread), NULL, Thread::threadProc,
		     this->_hc))
    std::cerr << "pthread_create() failed" << std::endl;
#endif
}

#ifdef WIN32
DWORD WINAPI	Thread::threadProc(LPVOID arg)
#else
  void*		Thread::threadProc(void* arg)
#endif
{
  Parser::Http::run((HttpConsumer*)arg);
#ifdef WIN32
  return (0);
#else
  pthread_exit(0);
#endif
}
