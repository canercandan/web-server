//
// Client.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:43:05 2008 florent hochwelker
// Last update Fri Aug 29 05:46:04 2008 caner candan
//

#include <Client.h>

using namespace ziApi;

Client::Client(ISocket &sck)
  : _sck(sck)
{}

Client::run()
{
  openModule("/tmp/test.so");
}

Client::openModule(const std::string& moduleName)
{
  if ((_handler = dlopen(moduleName.str_c(), RTLD_NOW)) == NULL)
    {
      _logger.error("Module Error: " + dlerror());
    }
  else if ((this->_call = dlsym(this->_handler, "call")) == NULL)
    {
      _logger.error("Module Error: " + dlerror());
    }
  else
    {
      this->_module = this->_call();
    }
}
