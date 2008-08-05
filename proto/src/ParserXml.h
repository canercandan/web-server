/*
** ParserXml.h for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Jul 31 22:13:58 2008 majdi toumi
** Last update Mon Aug  4 16:31:41 2008 User Toumi_m
*/

#ifndef _PARSEXML_H__
# define __PARSEXML_H__

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <string>
#include "ZiaConfiguration.h"

# define SERVER_XML	"../server.xml"

class			ParserXml
{
 private:
  const char*		_filename;
  xmlDocPtr		_doc;
  xmlNodePtr		_root;
  xmlXPathContextPtr	_ctxt;

 public:
  typedef void (*funCourse_t)(xmlNodePtr);

 public:
  ParserXml(const char *filename);
  ParserXml(const ParserXml& xmlDoc);
  ParserXml&	operator=(const ParserXml& xmlDoc);
  ~ParserXml();

  ZiaConfiguration	xmlLoadConfig();
  std::string		xmlGetValue(const char* attribut);
  void			xmlDumpConfig();
};

#endif /* !__PARSEXML_H__ */
