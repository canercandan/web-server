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
  std::auto_ptr<HttpParser>	http(new HttpParser(consumer.get(),
						    request.get(), uri.get()));

  this->_listModule(IModule::PRE, request.get());
  http->run();
  this->_listModule(IModule::POST, request.get());
  if (this->_listModule(IModule::PRE, response.get())
      == IModule::CONTINUE)
    response->buildResponse();
  this->_listModule(IModule::POST, response.get());
  response->sendResponse(this->_sck);
}

IModule::State	Client::_listModule(const IModule::Event& event,
				    ITransition* transition)
{
  const Config::listModule&	list
    = Config::getInstance()->getListModule();
  Config::listModule::const_iterator	it;
  Config::listModule::const_iterator	end;
  IModule*				module;
  IModule::State			state;

  for (it = list.begin(), end = list.end();
       it != end; ++it)
    if ((module = this->_openModule(*it)))
      if ((state = transition->accept(event, module))
	  != IModule::CONTINUE)
	return (state);
  return (IModule::CONTINUE);
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
