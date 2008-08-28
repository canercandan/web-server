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
    typedef std::list<std::string>		listConfig;

    //! undef
    virtual const std::string&	getPath();
    //! undef
    virtual void		setPath(const std::string&);

    //! undef
    void	loadConfig();
    //! undef
    void	getListeModule();
    //! undef
    void	ziaDumpConfig();

  private:
    Config();

  private:
    std::string	_path;
    mapConfig	_map_config;
    listConfig	_list_module;
    XmlParser*	_xml_parser;
  };
};

#endif // !__CONFIG_H__
