#include "Client.h"
#include "Request.h"
#include "Response.h"
#include "FluxClient.h"
#include "Consumer.h"
#include "HttpParser.h"
#include "Config.h"

using namespace ziApi;

Client::Client(Socket* sck)
  : _sck(sck)
{}

void	Client::run()
{
  IRequest*	request = new Request;
  //IResponse*	response = new Response(request);
  IFlux*	flux = new FluxClient(this->_sck);
  Consumer*	consumer = new Consumer(flux);
  HttpParser	parser(consumer, request);
  IModule*	module;

  const Config::listModule&	list
    = Config::getInstance()->getListModule();
  Config::listModule::const_iterator	it;
  Config::listModule::const_iterator	end;

  for (it = list.begin(), end = list.end(); it != end; ++it)
    if (!(module = this->_openModule(*it)))
      request->accept(IModule::PRE, module);

//   if (this->_module != NULL)
//     {
//       request->accept(IModule::PRE, this->_module);
//       request->accept(IModule::POST, this->_module);
//       response->accept(IModule::PRE, this->_module);
//     }
//   response->sendResponse(this->_sck);
//   if (this->_module != NULL)
//     response->accept(IModule::POST, this->_module);
}
  
IModule*	Client::_openModule(const std::string& name)
{
  fct		call;

  if (!(this->_handler = dlopen(name.c_str(), RTLD_NOW)))
    {
      this->_logger.error("Module Error: " + std::string(dlerror()));
      return (false);
    }
  if (!(call = (fct)dlsym(this->_handler, "call")))
    {
      this->_logger.error("Module Error: " + std::string(dlerror()));
      return (false);
    }
  return (call());
}
