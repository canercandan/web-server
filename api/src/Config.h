#ifndef __CONFIG_H__
# define __CONFIG_H__

# include <map>
# include <list>
# include <string>
# include "IConfig.h"
# include "Singleton.hpp"
# include "XmlParser.h"

namespace	ziApi
{
  //! Config
  class	Config : public Singleton<Config>//,
  //public IConfig
  {
    friend class	Singleton<Config>;
  public:
    //! mapConfig
    typedef std::map<std::string, std::string>	mapConfig;
    typedef std::list<std::string>		listModule;

    //! undef
    virtual void	setValue(const std::string& key,
				 const std::string& value);
    //! undef
    virtual void	setXmlValue(const std::string& key,
				    const std::string& path);
    //! undef
    virtual const std::string&	getValue(const std::string& key);

    //! undef
    const listModule&	getListModule();
    //! undef
    void	ziaDumpConfig();
  private:
    Config();
    virtual ~Config();

    void	_loadConfig();
  private:
    mapConfig	_mapConfig;
    listModule	_listModule;
    XmlParser*	_xmlParser;
  };
};

#endif // !__CONFIG_H__
