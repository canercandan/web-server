#ifndef _ICONFIG_H_
# define _ICONFIG_H_

# include <iostream>


namespace ZenZiAPI
{
  /**
   * @class IConfig
   * @brief Interface for configuration manager
   */
  class IConfig
  {
  public:
    enum OS			/**< differenta operatinga system */
      {
	LINUX,
	WINDOWS,
	MAC_OS,
	BSD,
	OTHER
      };
    
    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IConfig() {};
    
    /** 
     * @brief get a keyword in the configuration manager
     * @param param  : the param to find
     * @return the value
     */
    virtual std::string&	getParam(const std::string& param) = 0;
    
    /** 
     * @brief get a keyword in the configuration manager
     * @param param  : the param to find
     * @return the value
     */
    virtual int			getParamInt(const std::string& param) = 0;

    /** 
     * @brief get the current OS
     * @return the OS
     */ 
    virtual OS			getOS() = 0;
  };
}
#endif
