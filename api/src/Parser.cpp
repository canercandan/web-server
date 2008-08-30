#include <string>
#include <iostream>
#include "Parser.h"

using namespace ziApi;


Parser::Parser(Consumer& consumer,
	       IRequest& request)
  : _consumer(consumer), _request(request)
{}

