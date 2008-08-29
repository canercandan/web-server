#ifndef __IHEADER_H__
# define __IHEADER_H__

# include <map>
# include <string>
# include "IRoot.h"

namespace	ziApi
{
  //! IHeader
  class	IHeader : public IRoot
  {
  public:
    //! mapHeader
    typedef std::map<std::string, std::string>	mapHeader;

    virtual ~IHeader(){}

    //! undef
    bool	addHeader(const std::string& key,
			  const std::string& value);
    //! undef
    const std::string&	getHeader(const std::string& key);
    //! undef
    const mapHeader&	getMapHeader();
  };
};

#endif // !__IHEADER_H__
