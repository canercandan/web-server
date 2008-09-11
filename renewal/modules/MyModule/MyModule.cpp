//
// AutoIndex.cpp for AutoIndex in /home/candan_c/cu/rendu/zia/renewal/modules/AutoIndex
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:25 2008 caner candan
// Last update Thu Sep 11 15:59:51 2008 caner candan
//

#include <iostream>
#include "MyModule.h"

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
//   this->p_int[ZenZiAPI::PARSED].first =
//     static_cast<IModule::p_callback>(&MyModule::run);
//   this->p_int[ZenZiAPI::PARSED].seconde = ZenZiAPI::LAST;
  return (this->p_int);
}

void	MyModule::run(ZenZiAPI::ITools&)
{
  std::cout << "TEST MODULE IS RUNNING" << std::endl;
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
