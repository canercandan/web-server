#ifndef __CONFIG_H__
# define __CONFIG_H__

# include <map>
# include <list>
# include <string>
# include "IConfig.h"
# include "Singleton.hpp"
# include "XmlParser.h"

# define FILE_CONFIG	"../server.xml"

namespace	ziApi
{
  //! Config
  class	Config : public IConfig,
		 public Singleton<Config>
  {
    friend class	Singleton<Config>;
  public:
    //! mapConfig
    typedef std::map<std::string, std::string>	mapConfig;
    typedef std::list<std::string>		listModule;
    //! undef
    void	setValue(const std::string& key,
			 const std::string& value);
    //! undef
    void	setXmlValue(const std::string& key,
			    const std::string& path);
    //! undef
    const std::string&	getValue(const std::string& key);
    //! undef
    const listModule&	getListModule();
    //! undef
    virtual void	refresh();
    //! undef
    void	ziaDumpConfig();
  private:
    Config();
    ~Config();

    void	_loadConfig();
  private:
    mapConfig			_mapConfig;
    std::list<std::string>	_listModule;
    #ifndef WIN32
    std::string			_last_update;
    # else
    FILETIME			_last_update;
    #endif
    XmlParser*			_xmlParser;
  };
};

#endif // !__CONFIG_H__
