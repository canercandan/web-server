//
// Config.h for **zia** in /home/toumi_m/zia/renewal
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon Sep  8 13:45:46 2008 majdi toumi
// Last update Tue Sep  9 20:47:17 2008 majdi toumi
//

#include <string>
#include <map>
#include <list>
#include "IConfig.hpp"
#include "XmlParser.h"
#include "FileInfo.h"

# define CONFIG_FILE	"../server.xml"

namespace ZenZiAPI
{
  /*
   * @class Config
   * @brief Configuration manager
   */
  class	Config
  {
  public:
    typedef std::map<std::string, std::string>	MapConfig_t;
    typedef std::list<std::string>		ListModule_t;

    Config();
    std::string&	getParam(const std::string& param);
    int			getParamInt(const std::string& param);
    IConfig::OS		getOS();

    //! undef
    ListModule_t&	getListModule();
    //! undef
    void		refresh(FileInfo& info);
    //! undef
    void		ziaDumpConfig();

  private:
    //! undef
    void	_loadConfig();
    void	setParam(const std::string& key,
			 const std::string& value);
    //! undef
    void	setXmlParam(const std::string& key,
			    const std::string& path);

    MapConfig_t			_map_config;
    ListModule_t		_list_module;
    std::string			_last_access;
    std::auto_ptr<XmlParser>	_xmlParser;
  };
};
