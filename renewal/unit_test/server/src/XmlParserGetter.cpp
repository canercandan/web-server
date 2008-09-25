#include <cppunit/TestAssert.h>
#include "XmlParserGetter.h"

void	XmlParserGetter::setUp()
{
  _xml = new XmlParser("../server.xml");
}

void	XmlParserGetter::tearDown()
{
  delete _xml;
}

void	XmlParserGetter::testListAttribute()
{
  XmlParser::listAttribute	attr(_xml->xmlGetParam("/server"));

  CPPUNIT_ASSERT(attr["name"] == "Zia");
}

void	XmlParserGetter::testAttribute()
{
  CPPUNIT_ASSERT(_xml->xmlGetParam("/server", "name") == "Zia");
}

void	XmlParserGetter::testListParam()
{
  XmlParser::listParam	list(_xml->xmlGetListParam("//server/config"));

  for (XmlParser::listParam::iterator
	 it = list.begin(),
	 end = list.end();
       it != end; ++it)
    {
      XmlParser::listAttribute&	attr = *it;

      CPPUNIT_ASSERT(!attr["port"].empty());
      CPPUNIT_ASSERT(!attr["type"].empty());
    }
}
