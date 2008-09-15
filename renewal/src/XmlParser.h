//

// XmlParser.h for zia in /home/toumi_m/zia/renewal/api
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 13:00:15 2008 majdi toumi
// Last update Mon Sep 15 16:11:55 2008 caner candan
//

#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

# include <string>
# include <libxml/parser.h>
# include <libxml/xpath.h>
# include <list>
# include <map>

class	XmlParser
{
public:
  typedef std::map<std::string, std::string>	listAttribute;
  typedef std::list<listAttribute>		listParam;
public:
  XmlParser(const std::string& filename);
  ~XmlParser();

  std::string	xmlGetParam(const std::string& path);
  listParam	xmlGetListParam(const std::string& path);
private:
  std::string		_filename;
  xmlDocPtr		_doc;
  xmlNodePtr		_root;
  xmlXPathContextPtr	_ctxt;
};

#endif // !__XMLPARSER_H__
