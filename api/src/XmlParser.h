//
// XmlParser.h for **zia** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Aug 27 16:41:34 2008 majdi toumi
// Last update Wed Aug 27 16:41:34 2008 majdi toumi
//

#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

# include <libxml/parser.h>
# include <libmxl/xpath.h>
# include <string>
# include "IRoot.h"

# define  SERVER_XML	"../server.xml"

namespace	ZapII
{
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
};

#endif /* !__XMLPARSER_H__ */
