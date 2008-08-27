//
// XmlParser.cpp for **zia** in /home/toumi_m/zia/api/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Aug 27 15:04:11 2008 majdi toumi
// Last update Wed Aug 27 15:24:24 2008 majdi toumi
//

#include <string>
#include "XmlParser.h"

/**
 * @file XmlParser.cpp
 * @note
 * @brief
 */

/*
 * @fn XmlParser(const char* filename)
 * @brief Xml parser constructor
 * @param filename: server configuration name
 */
XmlParser::XmlParser(const char *filename)
  : _filename(filename)
{
  xmlInitParser();
  _doc = xmlParseFile(filename);
  if (_doc == NULL)
    {
      std::cerr << "errror - xml file configuration invalid" << std::endl;
      exit(-1);
    }
  _root = xmlDocGetRootElement(_doc);
  if (_root == NULL) //&& xmlStrcasecmp(_root->name, "server"))
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

/*
 * @fn XmlParser(const XmlParser& parser)
 * @brief Xml parser copy constructor
 * @param parser: XmlParser object
 */
XmlParser::XmlParser(const XmlParser& parser)
{
  *this = parser;
}

/*
 * @fn operator=(const XmlParser& parser)
 * @brief Xml parser copy constructor with '=' overload
 * @param parser: XmlParser object
 */
XmlParser&      XmlParser::operator=(const XmlParser& parser)
{
  if (this != &parser)
    {
      this->_filename = parser._filename;
      this->_doc = parser._doc;
    }
  return (*this);
}

/*
 * @fn ~XmlParser()
 * @brief Xml parser destructor
 */
XmlParser::~XmlParser()
{
  xmlFreeDoc(this->_doc);
  xmlXPathFreeContext(this->_ctxt);
}

/*
 * @fn xmlGetValue(const char* attribut)
 * @brief Xml parser copy constructor with '=' overload
 * @param attribut: node path configuration file
 */
std::string             XmlParser::xmlGetValue(const char* attribut)
{
  xmlXPathObjectPtr     xpath;
  xmlNodePtr            node;

  xpath = xmlXPathEvalExpression((xmlChar*)attribut, this->_ctxt);
  if (xpath == NULL)
    {
      std::cerr << "error - can't evaluate xpath expression" << std::endl;
      exit(-1);
    }
  if (xpath->type == XPATH_NODESET)
    for (int i = 0; i < xpath->nodesetval->nodeNr; i++)
      {
        node = xpath->nodesetval->nodeTab[i];
        return ((char*)node->properties->children->content);
      }
  std::cerr << "error: can't find [" << attribut << "] content" << std::endl;
  exit(-1);
}
