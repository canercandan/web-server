#include <memory>
#include "Client.h"
#include "Request.h"
#include "Response.h"
#include "FluxClient.h"
#include "Consumer.h"
#include "HttpParser.h"
#include "URIParser.h"
#include "Config.h"

using namespace ziApi;

Client::Client(Socket* sck)
  : _sck(sck)
{}

Client::~Client()
{
  if (_sck)
    delete _sck;
}

void	Client::run()
{
  std::auto_ptr<IRequest>	request(new Request);
  std::auto_ptr<IResponse>	response(new Response(request.get()));
  std::auto_ptr<IFlux>		flux(new FluxClient(this->_sck));
  std::auto_ptr<Consumer>	consumer(new Consumer(flux.get()));
  std::auto_ptr<URIParser>	uri(new URIParser(consumer.get(), request.get()));
  std::auto_ptr<HttpParser>	http(new HttpParser(consumer.get(), request.get(), uri.get()));

  this->_listModule(IModule::PRE, request.get());
  http->run();
  this->_listModule(IModule::POST, request.get());
  this->_listModule(IModule::PRE, response.get());
  this->_listModule(IModule::POST, response.get());
  response->sendResponse(this->_sck);
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

void	Client::_listModule(const IModule::Event& event,
			    ITransition* transition)
{
  std::list<std::string>		list
    = Config::getInstance()->getListModule();
  std::list<std::string>::const_iterator	it;
  std::list<std::string>::const_iterator	end;
  IModule*				module;

  for (it = list.begin(), end = list.end(); it != end; ++it)
    if ((module = this->_openModule(*it)))
      transition->accept(event, module);
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
  return (call(Config::getInstance()));
}
