#ifndef __ICONNECTIONINFOS_H_
# define __ICONNECTIONINFOS_H_

#ifdef __linux
#ifndef SOCKET
typedef int SOCKET;
#endif
#else
#include <Winsock2.h>
#endif

namespace ZenZiAPI
{
  class IConnectionInfos
  {
  public:
    
    typedef void	Extension; /**< extension typedef */

    enum connectionType		/**< server type  */
      {
	SIMPLE,
	SSL
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
    virtual const SOCKET		socket() = 0;

    
    /** 
     * @brief gets the connectionType
     * 
     * 
     * @return connectionType
     */
    virtual const connectionType	connectType(void) = 0;

    /** 
     * @brief Gets the connection extension or NULL
     * 
     * 
     * @return Extension pointer ( void )
     */
    virtual Extension			*extension(void) = 0;

    /** 
     * @brief Sets the connection extension or NULL
     * 
     */
    virtual void			extension(void *ptr) = 0;
  };
}

#endif // __ICONNECTIONINFOS_H_
