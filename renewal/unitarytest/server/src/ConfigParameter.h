#ifndef __CONFIGPARAMETER_H__
# define __CONFIGPARAMETER_H__

# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>

class	ConfigParameter : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(ConfigParameter);
  CPPUNIT_TEST(testSetter);
  CPPUNIT_TEST(testXmlPushed);
  CPPUNIT_TEST(testLastParam);
  CPPUNIT_TEST(testGetterListParam);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testSetter();
  void	testXmlPushed();
  void	testLastParam();
  void	testGetterListParam();
};

#endif // !__CONFIGPARAMETER_H__
