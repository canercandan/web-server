#ifndef _IMESSAGE_H_
# define _IMESSAGE_H_

# include "IResponse.hpp"

namespace ZenZiAPI
{
  /** 
   * @struct IMessage
   * @brief Interface describing a message
   */
  class IMessage
  {
  public:
    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IMessage() {};

    /** 
     * @brief request getter
     * @return the request
     */
    virtual IRequest&	request() = 0;

    /** 
     * @brief response getter
     * @return the response
     */
    virtual IResponse&	response() = 0;   
  };
}


#endif
