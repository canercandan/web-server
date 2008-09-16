//
// Client.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Tue Sep  9 17:47:45 2008 caner candan
// Last update Tue Sep 16 17:52:05 2008 caner candan
//

#ifndef __CLIENT_H__
# define __CLIENT_H__

# ifdef WIN32
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
//#  define dlclose(ptr)		FreeLibrary((HINSTANCE)ptr)
//#  define dlopen(name,flag)	(LoadLibrary(name))
//#  define dlerror()		"unknown error (Windows)"
//#  define dlsym(handle,name)	((void*)GetProcAddress(handle,name))

//#  define RTLD_LAZY	-1
//#  define RTLD_NOW	-1
//#  define RTLD_GLOBAL	-1
# else
#  include <dlfcn.h>
# endif

# include <list>
# include <string>
# include "IRunnable.h"
# include "Socket.h"
# include "HookManager.h"
# include "FileInfo.h"
# include "Config.h"
# include "Tools.h"

class Client : public IRunnable
{
  typedef ZenZiAPI::IModule*	(*create_t)();
  typedef void			(*destroy_t)(ZenZiAPI::IModule*);

  typedef std::list<std::string>			listNameModule;
  typedef std::pair<ZenZiAPI::IModule*, destroy_t>	pairModule;
  typedef std::list<pairModule>				listModule;
public:
  Client(Socket* sck, const std::string& type);
  ~Client();

  void	run();
private:
  void	_loadModules();
  void	_unloadModules();

  const listNameModule&	_getNameModules();
  void			_refreshListModule(FileInfo& info);
private:
  Socket*		_sck;
  Tools			_tools;
  HookManager		_hook;
  listNameModule	_listNameModule;
  listModule		_listModule;
#ifdef WIN32
  SYSTEMTIME	_lastAccess;
# else
  std::string	_lastAccess;
#endif
};

#endif // !__CLIENT_H__
