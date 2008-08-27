#include <string>
#include "XmlParser.h"

//! Xml parser constructor
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

//! Xml parser copy constructor
XmlParser::XmlParser(const XmlParser& parser)
{
  *this = parser;
}

// Xml parser copy constructor with '=' overload
XmlParser&      XmlParser::operator=(const XmlParser& parser)
{
  if (this != &parser)
    {
      this->_filename = parser._filename;
      this->_doc = parser._doc;
    }
  return (*this);
}

//! Xml parser destructor
XmlParser::~XmlParser()
{
  xmlFreeDoc(this->_doc);
  xmlXPathFreeContext(this->_ctxt);
}

//! Xml parser copy constructor with '=' overload
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
