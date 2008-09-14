//
// Signal.cpp for Signal in /home/candan_c/cu/rendu/cpp/test/signal
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Sun Sep 14 10:44:09 2008 caner candan
// Last update Sun Sep 14 13:29:00 2008 caner candan
//

#include <iostream>
#include <csignal>
#include "Signal.h"

Signal::Signal()
{
  ::signal(SIGINT, _sigInt);
  //::signal(SIGQUIT, _sigQuit);
}

Signal::~Signal()
{}

void	Signal::addCallback(Signal::Type type,
			    ISignalManager* sm,
			    ISignalManager::callback callback)
{
  this->_signals[type].push_back(pairCallback(sm, callback));
}

void	Signal::_sigInt(int)
{
  Signal::getInstance()->_signalLoop(INT);
}

void	Signal::_sigQuit(int)
{
  Signal::getInstance()->_signalLoop(QUIT);
}

void	Signal::_signalLoop(const Type& type)
{
  listCallback&	list = this->_signals[type];

  for (listCallback::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      ISignalManager*		sm = it->first;
      ISignalManager::callback	cb = it->second;

      (sm->*cb)();
    }
  ::exit(-1);
}
