#ifndef __ICONNECTIONINFOS_H_
# define __ICONNECTIONINFOS_H_

#include "defines.hpp"

namespace ZenZiAPI
{
  /** 
   * @class IConnectionInfos
   * @brief Interface describing connexion informations
   */
  class IConnectionInfos
  {
  public:
    
    typedef void	Extension; /**< extension typedef */

    enum connectionType		/**< server type  */
      {
	SIMPLE,
	SSL,
	SSL2,
	SSL3,
	TLS,
	OTHER
      };

    /** 
     * @brief virtual dtor
     * @return
     */
    virtual ~IConnectionInfos(){};
    
    /** 
     * @brief get the client socket
     * @return the manager
     */
    virtual const SOCKET		getSocket() const = 0;

    
    /** 
     * @brief gets the connectionType
     * 
     * 
     * @return connectionType
     */
    virtual const connectionType	getConnectType(void) const = 0;

    /** 
     * @brief Gets the connection extension or NULL
     * 
     * 
     * @return Extension pointer ( void )
     */
    virtual Extension			*getExtension(void) const = 0;

    /** 
     * @brief Sets the connection extension or NULL
     * 
     */
    virtual void			setExtension(Extension *ptr) = 0;
  };
}

#endif // __ICONNECTIONINFOS_H_
