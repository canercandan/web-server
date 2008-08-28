#ifndef __CONFIG_H__
# define __CONFIG_H__

# include "IConfig.h"
# include "Singleton.hpp"
# include "XmlParser.h"

namespace	ZapII
{
  //! Config
  class	Config : public IConfig,
		 public Singleton<Config>
  {
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

    void	_loadConfig();
  private:
    mapConfig	_mapConfig;
    listModule	_listModule;
    XmlParser*	_xmlParser;
  };
};

#endif // !__CONFIG_H__
