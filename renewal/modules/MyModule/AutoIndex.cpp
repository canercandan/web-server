//
// AutoIndex.cpp for AutoIndex in /home/candan_c/cu/rendu/zia/renewal/modules/AutoIndex
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Thu Sep 11 14:16:25 2008 caner candan
// Last update Thu Sep 11 15:36:14 2008 caner candan
//

#include "AutoIndex.h"

bool	AutoIndex::onLoad()
{
  std::cout << "LOADING..." << std::endl;
  return (true);
}

void	AutoIndex::onUnLoad()
{
  std::cout << "UNLOADING..." << std::endl;
}

const std::vector<std::pair<AutoIndex::p_callback, ZenZiAPI::hookPosition> >&	AutoIndex::getCallbacks()
{
//   this->p_int[ZenZiAPI::PARSED].first =
//     static_cast<IModule::p_callback>(&AutoIndex::run);
//   this->p_int[ZenZiAPI::PARSED].seconde = ZenZiAPI::LAST;
  return (this->p_int);
}

void	AutoIndex::run(ZenZiAPI::ITools&)
{
  std::cout << "TEST MODULE IS RUNNING" << std::endl;
}

extern "C"
{
  AutoIndex*	create()
  {
    return (new AutoIndex);
  }

  void		destroy(void* p)
  {
    delete static_cast<AutoIndex*>(p);
  }
}
