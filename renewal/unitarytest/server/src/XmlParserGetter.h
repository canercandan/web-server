#ifndef __XMLPARSERGETTER_H__
# define __XMLPARSERGETTER_H__

# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>
# include "XmlParser.h"

class	XmlParserGetter : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(XmlParserGetter);
  CPPUNIT_TEST(testListAttribute);
  CPPUNIT_TEST(testAttribute);
  CPPUNIT_TEST(testListParam);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testListAttribute();
  void	testAttribute();
  void	testListParam();
private:
  XmlParser*	_xml;
};

#endif // !__XMLPARSERGETTER_H__
