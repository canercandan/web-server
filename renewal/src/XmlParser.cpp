//
// XmlParser.cpp for zia in /home/toumi_m/zia/renewal/api
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 13:09:45 2008 majdi toumi
// Last update Thu Sep 18 01:38:21 2008 morgan armand
//

#include <string>
#include <iostream>
#include <sstream>
#include "XmlParser.h"

XmlParser::XmlParser(const std::string& filename)
  : _filename(filename)
{
  ::xmlInitParser();
  this->_doc = ::xmlParseFile(this->_filename.c_str());
  if (!this->_doc)
    std::cerr << "errror - xml file configuration invalid" << std::endl;
  else
    {
      this->_root = ::xmlDocGetRootElement(this->_doc);
      if (!this->_root)
	{
	  ::xmlFreeDoc(this->_doc);
	  std::cerr << "error - xml file configuration is empty" << std::endl;
	}
      else
	{
	  ::xmlXPathInit();
	  this->_ctxt = ::xmlXPathNewContext(_doc);
	  if (!this->_ctxt)
	    {
	      ::xmlFreeDoc(this->_doc);
	      std::cerr << "error - can't create xml path context" << std::endl;
	    }
	}
    }
}

XmlParser::~XmlParser()
{
  ::xmlFreeDoc(this->_doc);
  ::xmlXPathFreeContext(this->_ctxt);
}

XmlParser::listAttribute	XmlParser::xmlGetParam(const std::string& path)
{
  listAttribute		mapAttr;
  xmlXPathObjectPtr	xpath = this->_xPath(path);
  xmlNodePtr		node = xpath->nodesetval->nodeTab[0];
  xmlAttrPtr		attr = node->properties;

  while (attr != NULL)
    {
      std::string	key((char*)attr->name);
      std::string	val((char*)attr->children->content);

      mapAttr[key] = val;
      attr = attr->next;
    }
  return (mapAttr);
}

std::string	XmlParser::xmlGetParam(const std::string& path,
				       const std::string& sAttr)
{
  xmlXPathObjectPtr	xpath = this->_xPath(path);
  xmlNodePtr		node = xpath->nodesetval->nodeTab[0];
  xmlAttrPtr		attr = node->properties;

  while (attr != NULL)
    {
      std::string	key((char*)attr->name);
      std::string	val((char*)attr->children->content);

      if (key == sAttr)
	return (val);
    }
  return ("");
}

XmlParser::listParam	XmlParser::xmlGetListParam(const std::string& path)
{
  listParam		listParam;
  listAttribute		mapAttr;
  xmlXPathObjectPtr	xpath = this->_xPath(path);

  for (int i = 0; i < xpath->nodesetval->nodeNr; i++)
    {
      xmlNodePtr	node = xpath->nodesetval->nodeTab[i];

      node = node->children;
      while (node != NULL)
	{
	  if (node->type == XML_ELEMENT_NODE)
	    {
	      xmlAttrPtr	attr = node->properties;

	      while (attr != NULL)
		{
		  std::string	key((char*)attr->name);
		  std::string	val((char*)attr->children->content);

		  mapAttr[key] = val;
		  attr = attr->next;
		}
	      listParam.push_back(mapAttr);
	    }
	  node = node->next;
	}
    }
  //  xmlXPathFreeObject(xpath);
  return (listParam);
}

xmlXPathObjectPtr	XmlParser::_xPath(const std::string& path)
{
  xmlXPathObjectPtr	xpath;

  if (!(xpath = ::xmlXPathEvalExpression((xmlChar*)path.c_str(),
					 this->_ctxt)))
    std::cerr << "error - can't evaluate xpath expression"
	      << std::endl;
  else
    if (xpath->type != XPATH_NODESET)
      std::cerr << "error: can't find [" << path
		<< "] content" << std::endl;
  return (xpath);
}
