#include "Parser.h"

using namespace ziApi;

Parser::Parser(const Consumer& consumer,
	       const IRequest& request)
  : _consumer(consumer), _request(request)
{}
