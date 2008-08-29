//
// Client.h for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:48:06 2008 florent hochwelker
// Last update Fri Aug 29 09:25:48 2008 caner candan
//

#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <dlfcn.h>

# ifdef HAVE_WINDOWS_H
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
# include "IModule.h"

namespace	ziApi
{
  //! Client class
  class Client : public IRunnable
  {
  public:
    typedef IModule*	(*fct)();

    //! \param sck a ISocket pointer
    Client(ISocket &sck);
    //! run method
    void	run();

  private:
    void	openModule(const std::string& moduleName);
    fct		_call;

    ISocket&	_sck;
    Logger	_logger;
    void*	_handler;
    IModule*	_module;
  };
}
#endif // !__CLIENT_H__
