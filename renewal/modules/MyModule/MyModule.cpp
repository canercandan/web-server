//
// AutoIndex.cpp for AutoIndex in /home/candan_c/cu/rendu/zia/renewal/modules/AutoIndex
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:25 2008 caner candan
// Last update Thu Sep 11 18:03:06 2008 morgan armand
//

#include <iostream>
#include "MyModule.h"

MyModule::MyModule()
  : _p_int(ZenZiAPI::hookPointsNumber)
{}

bool	MyModule::onLoad()
{
  std::cout << "LOADING..." << std::endl;
  return (true);
}

void	MyModule::onUnLoad()
{
  std::cout << "UNLOADING..." << std::endl;
}

const std::vector<std::pair<MyModule::p_callback, ZenZiAPI::hookPosition> >&	MyModule::getCallbacks()
{
  this->_p_int[ZenZiAPI::PARSED].first =
    static_cast<IModule::p_callback>(&MyModule::run);
  this->_p_int[ZenZiAPI::PARSED].second = ZenZiAPI::LAST;
  return (this->_p_int);
}

bool	MyModule::run(ZenZiAPI::ITools&)
{
  std::cout << "TEST MODULE IS RUNNING" << std::endl;
  return true;
}

extern "C"
{
  MyModule*	create()
  {
    return (new MyModule);
  }

  void		destroy(void* p)
  {
    delete static_cast<MyModule*>(p);
  }
}
