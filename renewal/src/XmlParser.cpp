//
// XmlParser.cpp for zia in /home/toumi_m/zia/renewal/api
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 13:09:45 2008 majdi toumi
// Last update Mon Sep 15 16:06:28 2008 caner candan
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
    {
      std::cerr << "errror - xml file configuration invalid" << std::endl;
      exit(-1);
    }
  this->_root = ::xmlDocGetRootElement(this->_doc);
  if (!this->_root)
    {
      ::xmlFreeDoc(this->_doc);
      std::cerr << "error - xml file configuration is empty" << std::endl;
      exit(-1);
    }
  ::xmlXPathInit();
  this->_ctxt = ::xmlXPathNewContext(_doc);
  if (!this->_ctxt)
    {
      ::xmlFreeDoc(this->_doc);
      std::cerr << "error - can't create xml path context" << std::endl;
      exit(-1);
    }
}

XmlParser::~XmlParser()
{
  ::xmlFreeDoc(this->_doc);
  ::xmlXPathFreeContext(this->_ctxt);
}

std::string	XmlParser::xmlGetParam(const std::string& path)
{
  xmlXPathObjectPtr	xpath;
  xmlNodePtr		node;
  int			i;

  if (!(xpath = ::xmlXPathEvalExpression((xmlChar*)path.c_str(),
					 this->_ctxt)))
    {
      std::cerr << "error - can't evaluate xpath expression"
		<< std::endl;
      exit(-1);
    }
  if (xpath->type != XPATH_NODESET)
    {
      std::cerr << "error: can't find [" << path
		<< "] content" << std::endl;
      exit(-1);
    }
  for (i = 0; i < xpath->nodesetval->nodeNr; i++)
    {
      node = xpath->nodesetval->nodeTab[i];
      return ((char*)node->properties->children->content);
    }
  return ("");
}

XmlParser::listParam	XmlParser::xmlGetListParam(const std::string& path)
{
  listParam		listParam;
  listAttribute		mapAttr;
  xmlXPathObjectPtr	xpath;
  xmlNodePtr		node;
  xmlAttrPtr		attr;
  std::string		key;
  std::string		val;

  if (!(xpath = ::xmlXPathEvalExpression((xmlChar*)path.c_str(),
					 this->_ctxt)))
    {
      std::cerr << "error - can't evaluate xpath expression"
		<< std::endl;
      exit(-1);
    }
  if (xpath->type != XPATH_NODESET)
    {
      std::cerr << "error: can't find [" << path
		<< "] content" << std::endl;
      exit(-1);
    }
  for (int i = 0; i < xpath->nodesetval->nodeNr; i++)
    {
      node = xpath->nodesetval->nodeTab[i];
      node = node->children;
      while (node != NULL)
	{
	  if (node->type == XML_ELEMENT_NODE)
	    {
	      attr = node->properties;
	      while (attr != NULL)
		{
		  key = (char*)attr->name;
		  val = (char*)attr->children->content;
		  mapAttr[key] = val;
		  attr = attr->next;
		}
	      listParam.push_back(mapAttr);
	    }
	  node = node->next;
	}
    }
  return (listParam);
}

