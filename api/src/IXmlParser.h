#ifndef __IXMLPARSER_H__
# define __IXMLPARSER_H__

# include "IRoot.h"

namespace	ziApi
{
  //! IXmlParser
  class	IXmlParser : public IRoot
  {
  public:
    virtual ~IXmlParser() {};

    //! undef
    virtual void	refresh() = 0;
    //! undef
    virtual std::string	xmlGetValue(const std::string& path) = 0;
  };
};

#endif // !__IXMLPARSER_H__
