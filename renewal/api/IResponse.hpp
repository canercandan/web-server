#ifndef _IRESPONSE_H_
# define _IRESPONSE_H_

#include <iostream>

#include "IRequest.hpp"

namespace ZenZiAPI
{
  /** 
   * @class IResponse
   * @brief Interface describing a response
   */
  class IResponse : public virtual IRequest
  {
  public:
    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IResponse() {};

    /** 
     * @brief statusCode setter
     * @param code : the code to set
     */
    virtual void		statusCode(int code) = 0;

    /** 
     * @brief statusCode getter
     * @return current statusCode
     */
    virtual const std::string&	statusCode() = 0;

    /** 
     * @brief statusMessage setter
     * @param message : the message to set
     */
    virtual void		statusMessage(const std::string& message) = 0;

    /** 
     * @brief statusMessage getter
     * @return current statusMessage
     */
    virtual const std::string&	statusMessage() = 0;

    /** 
     * @brief build the entire response
     * @return the response
     */
    virtual std::string		buildResponse() = 0;

    /** 
     * @brief clean all headers
     */
    virtual void		resetHeaders() = 0;
  };
}

#endif
