//
// Client.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:43:05 2008 florent hochwelker
// Last update Fri Aug 29 18:21:09 2008 florent hochwelker
//

#include <Client.h>

using namespace ziApi;

Client::Client(ISocket &sck)
  : _sck(sck), _module(0)
{}

Client::run()
{
  Request	req;
  Response	response(req);
  FluxClient	flux(this->_sck);
  Consumer	consumer(flux);
  HttpParser	parser(consumer, req);

  if (openModule("/tmp/test.so"))
    {
      req.accept(IModule::PRE, this->_module);
      req.accept(IModule::POST, this->module);
      response.accept(IModule::PRE, this->response);
    }
  response.sendResponse(this->_sck);
  response.accept(IModule::POST, this->response);
}
  
bool	Client::openModule(const std::string& moduleName)
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
      return true;
    }
  return false;
}
