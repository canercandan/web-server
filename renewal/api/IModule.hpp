#ifndef _IMODULE_H_
# define _IMODULE_H_

#include <iostream>
#include <openssl/ssl.h>

#include "defines.hpp"
#include "ITools.hpp"


namespace ZenZiAPI
{
  /** 
   * @class IModule
   * @brief Interface describing a module
   */

  class IModule
  {
  public:
    typedef bool (IModule::*p_callback)(ITools&); /**< callbacks typedef */

    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IModule() {};

    /** 
     * @brief get the module's callbacks
     * @return a pair array with callback <=> position
     */
    virtual std::pair<p_callback, hookPosition>* getCallbacks() = 0;
    /** 
     * @brief load the module
     * @return void
     */
    virtual bool	onLoad(void) = 0;
    /** 
     * @brief unload the module
     * @return void
     */
    virtual void	onUnLoad(void) = 0;
  };
}

#endif //_IMODULE_H_
