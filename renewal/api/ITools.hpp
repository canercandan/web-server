#ifndef _ITOOLS_H_
# define _ITOOLS_H_

# include "defines.hpp"
# include "IConnectionInfos.hpp"
# include "IMessage.hpp"
# include "IConfig.hpp"

namespace ZenZiAPI
{
  /** 
  * @class ITools
  * @brief Interface describing main object used by modules
  */
  class ITools
  {
  public:
    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~ITools() {};

    /** 
     * @brief get the response/request
     * @return a message
     */
    virtual IMessage&		message(void) = 0;

    /** 
     * @brief get the config manager
     * @return the manager
     */
    virtual IConfig&		config(void) = 0;

    /** 
     * @brief get the connection infos
     * @return connection's onfos
     */
    virtual IConnectionInfos	&connectInfos(void) = 0;
    
    /** 
     * @brief data is a pointer to a string used for write/read callbacks with special servers
     * 
     * 
     * @return std::string *data or 0
     */
    virtual std::string		*data(void) = 0;

    /** 
     * @brief data is a pointer to a string used for write/read callbacks with special servers
     * 
     * @param str The new value of data
     */    
    virtual void		data(std::string *str) = 0;
  };
}
#endif //_ITOOLS_H_
