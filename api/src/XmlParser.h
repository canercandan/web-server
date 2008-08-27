#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

# include <libxml/parser.h>
# include <libmxl/xpath.h>
# include <string>
# include "IRoot.h"

# define  SERVER_XML	"../server.xml"

//! XmlParser
//! This class has the main xml parser methods.
class	XmlParser : public IRoot
{
public:
  //! Constructor
  XmlParser(const char* filename);
  //! Copy constructor
  XmlParser(const XmlParser& parser);
  //! Copy constructor with operator '=' overload
  XmlParser&	operator=(const XmlParser& parser);
  //! Destructor
  ~XmlParser();

  //! undef
  std::string	getValue(const std::string& path);
};

#endif /* !__XMLPARSER_H__ */
