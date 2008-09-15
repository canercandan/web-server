//

// XmlParser.h for zia in /home/toumi_m/zia/renewal/api
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 13:00:15 2008 majdi toumi
// Last update Mon Sep 15 15:20:17 2008 majdi toumi
//

#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

# include <string>
# include <libxml/parser.h>
# include <libxml/xpath.h>
# include <list>
# include <map>

/*
 * @class XmlParser
 * @brief This class has the main xml parser methods.
 */
class	XmlParser
{
public:
  typedef std::list<std::map<std::string, std::string> >	ListParam_t;

  //! undef
  XmlParser(const std::string& filename);
  //! undef
  ~XmlParser();
  //! undef
  std::string	xmlGetParam(const std::string& path);
  ListParam_t	xmlGetListParam(const std::string& path);

private:
  std::string		_filename;
  xmlDocPtr		_doc;
  xmlNodePtr		_root;
  xmlXPathContextPtr	_ctxt;
};

#endif /* !__XMLPARSER_H__ */
