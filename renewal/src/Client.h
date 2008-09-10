//
// Client.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:45 2008 caner candan
// Last update Tue Sep  9 17:47:45 2008 caner candan
//

#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <dlfcn.h>

# ifdef WIN32
#  include <windows.h>

#  define dlclose(ptr)		FreeLibrary((HINSTANCE)ptr)
#  define dlopen(name,flag)	((void*)LoadLibrary(name))
#  define dlerror()		"unknown error (Windows)"
#  define dlsym(handle,name)	((void*)GetProcAddress(handle,name))

#  define RTLD_LAZY	-1
#  define RTLD_NOW	-1
#  define RTLD_GLOBAL	-1
# endif

# include "IRunnable.h"
# include "ISocket.h"
# include "Logger.h"
# include "IConfig.h"
# include "ITransition.h"

class Client : public IRunnable
{
public:
  typedef IModule*	(*fct)(IConfig*);

  Client(ISocket* sck);
  ~Client();

  void	run();
private:
  IModule::State	_listModule(const IModule::Event&,
				    ITransition*);
  IModule*	_openModule(const std::string& name);
private:
  ISocket*	_sck;
  Logger	_logger;
  void*	_handler;
};

#endif // !__CLIENT_H__
