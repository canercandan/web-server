#include <cppunit/TestAssert.h>
#include "ConfigParameter.h"
#include "Config.h"

void	ConfigParameter::setUp()
{
  Config*	config = Config::getInstance();

  config->setParam("one", "abcdef");
  config->setParam("two", "abcdef");
  config->setParam("three", "fedcba");
}

void	ConfigParameter::tearDown()
{
  Config::kill();
}

void	ConfigParameter::testSetter()
{
  Config*	config = Config::getInstance();

  CPPUNIT_ASSERT(config->getParam("one")
		 == config->getParam("two"));
  CPPUNIT_ASSERT(config->getParam("one")
		 != config->getParam("three"));
}

void	ConfigParameter::testXmlPushed()
{
  Config*	config = Config::getInstance();

  CPPUNIT_ASSERT(config->getParam("name") == "Zia");
  CPPUNIT_ASSERT(config->getParamInt("port") == 4242);
}

void	ConfigParameter::testLastParam()
{
  Config*	config = Config::getInstance();
  std::string	key("key");
  std::string	value("i wish to replace this value");
  std::string	newvalue("new value");

  config->setParam(key, value);
  config->setParam(key, newvalue);
  config->setLastParam(key);
  CPPUNIT_ASSERT(config->getParam(key) == value);
}

void	ConfigParameter::testGetterListParam()
{
  Config*	config = Config::getInstance();

  XmlParser::listParam	list(config->getListParam("//server/config"));

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
