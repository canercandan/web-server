//
// ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:13:58 2008 majdi toumi
// Last update Wed Aug 13 20:04:32 2008 caner candan
//

#ifndef __PARSEXML_H__
# define __PARSEXML_H__

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>

#define SERVER_XML	"../server.xml"

class	ParserXml
{
public:
  ParserXml(const char *filename);
  ParserXml(const ParserXml& xmlDoc);
  ParserXml&	operator=(const ParserXml& xmlDoc);
  ~ParserXml();

  std::string		xmlGetValue(const char* attribut);

 private:
  const char*		_filename;
  xmlDocPtr		_doc;
  xmlNodePtr		_root;
  xmlXPathContextPtr	_ctxt;
};

#endif // !__PARSEXML_H__
