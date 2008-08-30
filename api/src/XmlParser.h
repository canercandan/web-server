#ifndef __XMLPARSER_H__
# define __XMLPARSER_H__

# include <libxml/parser.h>
# include <libxml/xpath.h>
# include <string>
# include "IRoot.h"
# include "IXmlParser.h"

# define  SERVER_XML	"../server.xml"

namespace	ziApi
{
  //! XmlParser
  //! This class has the main xml parser methods.
  class	XmlParser : public IXmlParser
  {
  public:
    //! Constructor
    XmlParser(const std::string& filename);
    //! Destructor
    ~XmlParser();

    //! undef
    virtual void	refresh();
    //! undef
    virtual std::string	xmlGetValue(const std::string& path);
  private:
    std::string		_filename;
    xmlDocPtr		_doc;
    xmlNodePtr		_root;
    xmlXPathContextPtr	_ctxt;
  };
};

#endif /* !__XMLPARSER_H__ */
