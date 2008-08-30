//
// Client.cpp for zia in /home/hochwe_f/zia/prototype/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Wed Aug 27 16:43:05 2008 florent hochwelker
// Last update Fri Aug 29 15:06:46 2008 caner candan
//

#include "Client.h"
#include "Request.h"
#include "Response.h"
#include "FluxClient.h"
#include "Consumer.h"
#include "HttpParser.h"

using namespace ziApi;

Client::Client(ISocket* sck)
  : _sck(sck), _module(0)
{}

void	Client::run()
{
  IRequest*	request = new Request;
  IResponse*	response = new Response(request);
  IFlux*	flux = new FluxClient(this->_sck);
  Consumer*	consumer = new Consumer(flux);
  HttpParser	parser(consumer, request);

  this->_openModule("/tmp/test.so");
  if (this->_module != NULL)
    {
      request->accept(IModule::PRE, this->_module);
      request->accept(IModule::POST, this->_module);
      response->accept(IModule::PRE, this->_module);
    }
  response->sendResponse(this->_sck);
  if (this->_module != NULL)
    response->accept(IModule::POST, this->_module);
}
  
bool	Client::_openModule(const std::string& moduleName)
{
  if (!(this->_handler = dlopen(moduleName.c_str(), RTLD_NOW)))
    this->_logger.error("Module Error: " + std::string(dlerror()));
  else if (!(this->_call = (fct)dlsym(this->_handler, "call")))
    this->_logger.error("Module Error: " + std::string(dlerror()));
  else
    {
      this->_module = this->_call();
      return true;
    }
  return false;
}
