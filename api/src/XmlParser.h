//
// XmlParser.h for **zia** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Aug 27 14:07:16 2008 majdi toumi
// Last update Wed Aug 27 15:36:44 2008 majdi toumi
//

/**
 * @file XmlParser.h
 * @brief UNDEF
 */

#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

#include <libxml/parser.h>
#include <libmxl/xpath.h>
#include <string>

#define  SERVER_XML	"../server.xml"

/**
 * @class XmlParser.h
 * @brief Xml parser class
 *
 * This class has the main xml parser methods.
 */
class	XmlParser
{
public:
  //! @brief Constructor
  XmlParser(const char* filename);
  //! @brief Copy constructor
  XmlParser(const XmlParser& parser);
  //! @brief Copy constructor with operator '=' overload
  XmlParser&	operator=(const XmlParser& parser);
  //! @brief Destructor
  ~XmlParser();

  //! @brief UNDEF
  std::string	getValue(const std::string& path);
};

#endif /* !__XMLPARSER_H__ */
