/* Documentation tag for Doxygen
 */

/*! \mainpage Zenzia API Documentation
 *
 * <img src="../logo.png">
 *
 * \section intro_sec Introduction
 *
 * This is Zenzia API documentation.
 * Zenzia API is a Module API for webserver.
 *
 * \section prog Programming Language
 * C++
 *
 * \section copyright Copyrights
 * boucho_o - david_g - labori_a - valent_j - vieux_v
 * <BR><BR>
 *
 */

#ifndef _IHOOKMANAGER_H_
# define _IHOOKMANAGER_H_

#include "ITools.hpp"
#include "defines.hpp"
#include "IModule.hpp"

namespace ZenZiAPI
{
  /**
   * @class IHookManager
   * @brief Interface used to manage Hook Points
   */
  class IHookManager
  {
  public:

    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IHookManager() {};
   
    /** 
     * @brief register a module to hook position
     * 
     * @param callbacks : array get form IModule::GetCallbacks
     * @param module : module instance
     * @return false if the module can't be loaded
     */
    virtual bool	addModule(std::pair<IModule::p_callback, hookPosition> callbacks[hookPointsNumber], IModule* module) = 0;
    
    /** 
     * @brief remove a module from the manager
     * @param module : the module to remove
     */
    virtual void	removeModule(IModule* module) = 0;
    
    /** 
     * @brief manage a hook point
     * 
     * @param point : the point to manager
     * @param tools : the module parameter
     */
    virtual bool	manageHookPoint(hookPoint point, ITools& tools) = 0;
  };
}

#endif
