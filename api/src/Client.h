//
// Client.h for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:48:06 2008 florent hochwelker
// Last update Sun Aug 31 16:42:39 2008 caner candan
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
# include "Socket.h"
# include "Logger.h"
# include "IConfig.h"
# include "ITransition.h"

namespace	ziApi
{
  //! Client class
  class Client : public IRunnable
  {
  public:
    typedef IModule*	(*fct)(IConfig*);

    //! \param sck a ISocket pointer
    Client(Socket* sck);
    ~Client();
    //! run method
    void	run();
  private:
    void	_listModule(const IModule::Event&,
			    ITransition*);
    IModule*	_openModule(const std::string& name);
  private:
    Socket*	_sck;
    Logger	_logger;
    void*	_handler;
  };
}
#endif // !__CLIENT_H__
