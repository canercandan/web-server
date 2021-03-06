#ifdef WIN32
#else
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#endif

#include <iostream>
#include "Perl.h"
#include "IConfig.h"
#include "IRequest.h"
#include "IResponse.h"

using namespace ziApi;

Perl::Perl(IConfig* conf)
  : _version(0.1),
    _name("Perl"),
    _conf(conf)
{
}

Perl::State	Perl::affect(const Event&,
			     IRequest*)
{
  return (CONTINUE);
}

Perl::State	Perl::affect(const Event& event,
			     IResponse* response)
{
  IRequest*	request = response->getRequest();
  const std::string&	path = request->getUrlPath();
  std::string		app;
  std::string		ext;
  size_t		pos;

  if (event != PRE || path.empty())
    return (CONTINUE);

  if ((pos = path.find_last_of('.')) == std::string::npos)
    return (CONTINUE);

  ext = path.substr(pos);

  if (ext.compare(".pl"))
    return (CONTINUE);

  app = this->_conf->getValue("document_root") + path;

  std::cout << "[mod_perl] executing " << app << std::endl;

#ifdef WIN32
  std::cout << "Not yet implemented."<< std::endl;
#else
  pid_t		pid;
  int		pip[2];
  char		buff[8193];
  int		count;

  pipe(pip);
  if ((pid = ::fork()) < 0)
    {
      std::cout << "fork failed, mamamia !"<< std::endl;
    }

  if (pid == 0)
    {
      close(pip[0]);
      dup2(pip[1], 1);
      ::execl("/usr/bin/perl", "perl", app.c_str(), (char *)0);
      close(pip[1]);
    }
  else
    {
      close(pip[1]);
      ::wait(NULL);
      while((count = read(pip[0], buff, 8192)) > 0)
	{
	  buff[count] = 0;
	  //	  printf("DTC => [%s]\n", buff);
	  response->appendBuf(buff);
	}
    }
#endif

  return (NOPROCESS);
}

extern	"C"
{
  EXPORT IModule*	call(IConfig* conf)
  {
    return (new Perl(conf));
  }

  EXPORT void		kill(Perl* module)
  {
    delete module;
  }
}
