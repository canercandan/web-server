#ifndef __HTTPPARSERCONSUME_H__
# define __HTTPPARSERCONSUME_H__

# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TestFixture.h>

class	HttpParserConsume : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(HttpParserConsume);
  CPPUNIT_TEST(testParsingLow);
  CPPUNIT_TEST(testParsingMiddle);
  CPPUNIT_TEST(testParsingHigh);
  CPPUNIT_TEST_SUITE_END();
public:
  void	setUp();
  void	tearDown();

  void	testParsingLow();
  void	testParsingMiddle();
  void	testParsingHigh();
private:
  std::string	_method;
  std::string	_path;
  std::string	_version;
  std::string	_host;
  std::string	_port;
  std::string	_accept;
  std::string	_useragent;
};

#endif // !__HTTPPARSERCONSUME_H__
