#ifndef __IXMLPARSER_H__
# define __IXMLPARSER_H__

# include "IRoot.h"

namespace	ziApi
{
  class	IXmlParser : public IRoot
  {
  public:
    virtual ~IXmlParser() {};

    virtual void	refresh() = 0;
    virtual std::string	xmlGetValue(const std::string& path) = 0;
  };
};

#endif // !__IXMLPARSER_H__
