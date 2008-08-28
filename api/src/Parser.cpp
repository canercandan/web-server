#include "Parser.h"

using namespace ZapII;

Parser::Parser(Consumer* consumer, IRequest* request)
  : _consumer(consumer), _request(request)
{}
