//
// XmlDomConfig.cpp for **zia** in /u/epitech_2010s/toumi_m/cu/rendu/httpd/zia/proto/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Thu Jul 31 22:32:19 2008 majdi toumi
// Last update Mon Aug  4 10:02:11 2008 User Toumi_m
//

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>
#include <sstream>
#include <string>
#include "XmlDomConfig.h"

XmlDomConfig::XmlDomConfig(const char *filename)
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

XmlDomConfig::XmlDomConfig(const XmlDomConfig& xmlDoc)
{
  *this = xmlDoc;
}

XmlDomConfig&	XmlDomConfig::operator=(const XmlDomConfig& xmlDoc)
{
  if (this != &xmlDoc)
    {
      this->_filename = xmlDoc._filename;
      this->_doc = xmlDoc._doc;
    }
  return (*this);
}

XmlDomConfig::~XmlDomConfig()
{
  xmlFreeDoc(this->_doc);
}

void		XmlDomConfig::xmlDumpConfig()
{
  std::cout << "Server xml configuration:" << std::endl;
  xmlDocFormatDump(stdout, this->_doc, 1);
}

xmlNodePtr	XmlDomConfig::getRootNode()
{
  return (this->_root);
}

std::string	XmlDomConfig::getValue(const char* attribut)
{
  xmlChar*	value;

  value = this->xmlPrefixSearch(this->_root, attribut);
  std::string s((char*)value);
  return (s);
}

xmlChar*	XmlDomConfig::xmlPrefixSearch(xmlNodePtr node, const char* attribut)
{
  xmlNodePtr	n;
  xmlChar*	content = NULL;

  for (n = node; n != NULL; n = n->next)
    {
      if (n->type == XML_ELEMENT_NODE)
	{
	  if ((n->children != NULL) && (n->children->type == XML_TEXT_NODE))
	    {
	      content = xmlGetProp(n, (const xmlChar*)attribut);
	      if (content != NULL)
		return (content);
	    }
	}
      if ((n->type == XML_ELEMENT_NODE) && (n->children != NULL))
	content = xmlPrefixSearch(n->children, attribut);
    }
  return (content);
}
