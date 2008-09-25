#include <cppunit/TestAssert.h>
#include "HttpParserConsume.h"
#include "HttpParser.h"
#include "Request.h"
#include "FluxString.h"

void	HttpParserConsume::setUp()
{
  _method = "GET";
  _path = "/";
  _version = "HTTP/1.1";
  _host = "127.0.0.1";
  _port = "8484";
  _accept =
    "text/html,application/xhtml+xml,application/xml;"
    "q=0.9,*/*;q=0.8";
  _useragent =
    "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; "
    "en-GB; rv:1.9.0.2) Gecko/2008091620 Firefox/3.0.2";
}

void	HttpParserConsume::tearDown()
{}

void	HttpParserConsume::testParsingLow()
{
  std::string	trame(_method + " " + _path +
		      " " + _version + "\r\n"
		      "\r\n");

  FluxString	flux(trame);
  Consumer	consumer(flux);
  Request	request;
  HttpParser	http(consumer, request);

  http.run();

  CPPUNIT_ASSERT(request.getMethod() == "GET");
  CPPUNIT_ASSERT(request.getHTTPVersion() == "HTTP/1.1");
  CPPUNIT_ASSERT(request.getUri() == "/");
}

void	HttpParserConsume::testParsingMiddle()
{
  std::string	trame(_method + " " + _path + " " + _version + "\r\n"
		      "Host: " + _host + ":" + _port + "\r\n"
		      "\r\n");

  FluxString	flux(trame);
  Consumer	consumer(flux);
  Request	request;
  HttpParser	http(consumer, request);

  http.run();

  CPPUNIT_ASSERT(request.getMethod() == _method);
  CPPUNIT_ASSERT(request.getHTTPVersion() == _version);
  CPPUNIT_ASSERT(request.getUri() == _path);
  CPPUNIT_ASSERT(request.getHeader("Host", "host") == _host);
  CPPUNIT_ASSERT(request.getHeader("Host", "port") == _port);
}

void	HttpParserConsume::testParsingHigh()
{
  std::string	trame(_method + " " + _path + " " + _version + "\r\n"
		      "Accept: " + _accept + "\r\n"
		      "Host: " + _host + ":" + _port + "\r\n"
		      "\r\n");

  FluxString	flux(trame);
  Consumer	consumer(flux);
  Request	request;
  HttpParser	http(consumer, request);

  http.run();

  CPPUNIT_ASSERT(request.getHeader("Accept") == _accept);

}
