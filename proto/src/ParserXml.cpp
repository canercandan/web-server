//
// ParserXml.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Mon Aug 11 20:26:14 2008 majdi toumi
//

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>
#include <sstream>
#include <string>
#include "ParserXml.h"

ParserXml::ParserXml(const char *filename)
  : _filename(filename)
{
  xmlInitParser(); // ->> init with thread
  _doc = xmlParseFile(filename);
  if (_doc == NULL)
    {
      std::cerr << "errror - xml file configuration invalid" << std::endl;
      exit(-1);
    }
  _root = xmlDocGetRootElement(_doc);
  if (_root == NULL)// && xmlStrcasecmp(_root->name, "server"))
    {
      xmlFreeDoc(_doc);
      std::cerr << "error - xml file configuration is empty" << std::endl;
      exit(-1);
    }
  xmlXPathInit();
  _ctxt = xmlXPathNewContext(_doc);
  if (_ctxt == NULL)
    {
      xmlFreeDoc(_doc);
      std::cerr << "error - can't create xml path context" << std::endl;
      exit(-1);
    }
}

ParserXml::ParserXml(const ParserXml& xmlDoc)
{
  *this = xmlDoc;
}

ParserXml&	ParserXml::operator=(const ParserXml& xmlDoc)
{
  if (this != &xmlDoc)
    {
      this->_filename = xmlDoc._filename;
      this->_doc = xmlDoc._doc;
    }
  return (*this);
}

ParserXml::~ParserXml()
{
  xmlFreeDoc(this->_doc);
  xmlXPathFreeContext(this->_ctxt);
}

std::string		ParserXml::xmlGetValue(const char* attribut)
{
  xmlXPathObjectPtr	xpath;
  xmlNodePtr		node;

  xpath = xmlXPathEvalExpression((xmlChar*)attribut, this->_ctxt);
  if (xpath == NULL)
    {
      std::cerr << "error - can't evaluate xpath expression" << std::endl;
      exit(-1);
    }
  if (xpath->type == XPATH_NODESET)
    {
      for (int i = 0; i < xpath->nodesetval->nodeNr; i++)
	{
	  node = xpath->nodesetval->nodeTab[i];
	  return ((char*)node->properties->children->content);
	}
    }
  std::cerr << "error: can't find [" << attribut << "] content" << std::endl;
  exit(-1);
}

ZiaConfiguration	ParserXml::xmlLoadConfig()
{
  ZiaConfiguration	ziaConfig;
  int			port;
  std::string		name;
  std::string		shutdown;
  bool			debug;
  std::string		respect_rfc;
  std::string		document_root;

  name = this->xmlGetValue("/server[@name]");
  std::istringstream	iss(this->xmlGetValue("/server/config/port[@value]"));
  iss >> port;
  shutdown = this->xmlGetValue("/server/config/shutdown[@value]");
  debug = (this->xmlGetValue("/server/config/debug[@value]") == "true" ? true : false);
  respect_rfc = this->xmlGetValue("/server/config/respect_rfc[@value]");
  document_root = this->xmlGetValue("/server/config/document_root[@value]");

  std::cout << document_root << std::endl;
  ziaConfig.setName(name);
  ziaConfig.setPort(port);
  ziaConfig.setShutdown(shutdown);
  ziaConfig.setDebug(debug);
  ziaConfig.setRespectRfc(respect_rfc);
  ziaConfig.setDocumentRoot(document_root);
  return(ziaConfig);
}

// std::string	ParserXml::getValue(const char* attribut)
// {
//   xmlChar*	value;

//   value = this->xmlPrefixSearch(this->_root, attribut);
//   std::string s((char*)value);
//   return (s);
// }

// xmlChar*	ParserXml::xmlPrefixSearch(xmlNodePtr node, const char* attribut)
// {
//   xmlNodePtr	n;
//   xmlChar*	content = NULL;

//   for (n = node; n != NULL; n = n->next)
//     {
//       if (n->type == XML_ELEMENT_NODE)
// 	{
// 	  if ((n->children != NULL) && (n->children->type == XML_TEXT_NODE))
// 	    {
// 	      content = xmlGetProp(n, (const xmlChar*)attribut);
// 	      if (content != NULL)
// 		return (content);
// 	    }
// 	}
//       if ((n->type == XML_ELEMENT_NODE) && (n->children != NULL))
// 	content = xmlPrefixSearch(n->children, attribut);
//     }
//   return (content);
// }
