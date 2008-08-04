/*
** XmlDomConfig.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Jul 31 22:13:58 2008 majdi toumi
** Last update Mon Aug  4 10:01:57 2008 User Toumi_m
*/

#ifndef __XMLDOMCONFIG_H__
# define __XMLDOMCONFIG_H__

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>

# define SERVER_CONF	"../server.xml"

class			XmlDomConfig
{
 private:
  const char*		_filename;
  xmlDocPtr		_doc;
  xmlNodePtr		_root;
  xmlXPathContextPtr	_ctxt;

 public:
  typedef void (*funCourse_t)(xmlNodePtr);

 public:
  XmlDomConfig(const char *filename);
  XmlDomConfig(const XmlDomConfig& xmlDoc);
  XmlDomConfig&	operator=(const XmlDomConfig& xmlDoc);
  ~XmlDomConfig();

  void			xmlLoadConfig();
  void			xmlDumpConfig();
  xmlNodePtr		getRootNode();
  std::string		getValue(const char* attribut);
  xmlChar*		xmlPrefixSearch(xmlNodePtr node, const char* attribut);
};

#endif /* !__XMLCONFIG_H__ */
