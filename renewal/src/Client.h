//
// Client.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:45 2008 caner candan
// Last update Wed Sep 10 18:57:00 2008 morgan armand
//

#ifndef __CLIENT_H__
# define __CLIENT_H__

# ifdef WIN32
#  include <windows.h>

#  define dlclose(ptr)		FreeLibrary((HINSTANCE)ptr)
#  define dlopen(name,flag)	((void*)LoadLibrary(name))
#  define dlerror()		"unknown error (Windows)"
#  define dlsym(handle,name)	((void*)GetProcAddress(handle,name))

#  define RTLD_LAZY	-1
#  define RTLD_NOW	-1
#  define RTLD_GLOBAL	-1
#else
# include <dlfcn.h>
# endif

# include "IRunnable.h"
# include "Socket.h"
# include "HookManager.h"

class Client : public IRunnable
{
public:
  Client(Socket* sck);
  ~Client();

  void	run();

private:
  void	_loadModules();
  void	_unloadModules();

private:
  Socket*					_sck;
  HookManager					_hook;
  std::list< std::pair<IModule*, void*> >	_mods;
};

#endif // !__CLIENT_H__
