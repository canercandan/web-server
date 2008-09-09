#ifndef _IREQUEST_H_
# define _IREQUEST_H_

#include <iostream>
#include <map>

namespace ZenZiAPI
{
  /** 
   * @class IRequest
   * @brief Interface describing a Request
   */
  class IRequest
  {
  public:
    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IRequest() {}

    /** 
     * @brief http version getter
     * @return the http version
     */
    virtual const std::string&	HTTPVersion() = 0;

    /** 
     * @brief  http version setter
     * @param version : the version to set
     */
    virtual void		HTTPVersion(const std::string& version) = 0;

    /** 
     * @brief method getter
     * @return the method
     */
    virtual const std::string&	method() = 0;

    /** 
     * @brief uri getter
     * @return the uri
     */
    virtual const std::string&	uri() = 0;

    /** 
     * @brief uri setter
     * @param field : the uri to set
     */
    virtual void		uri(std::string&  field) = 0;

    /** 
     * @brief get a multidimensional header, like 'accept'
     * @param field : the key to get
     * @return the header map
     */
    virtual const std::map<std::string, std::string>&	getHeaders(const std::string& field) = 0;

    /** 
     * @brief set a multidimensional header, like 'accept'
     * @param field : the filed to set
     * @param headers : the multidimensional header
     */
    virtual void		setHeaders(const std::string& field,
					   std::map<std::string, std::string>& headers) = 0;

    /** 
     * @brief get a single header, like 'accept -> test/test'
     * @param field : the field to get ('accept')
     * @param key : the key to get ('test/test')
     * @return the value
     */
    virtual const std::string&	getHeader(const std::string& field, const std::string& key) = 0;

    /** 
     * @brief set a single header, like 'accept -> test/test'
     * @param field : the field to get ('accept')
     * @param key : the key to get ('test/test')
     * @param value : the value to set
     */
    virtual void		setHeader(const std::string& field, const std::string& key,
					  const std::string& value) = 0;

    /** 
     * @brief get a single header, like 'host'
     * @param header : the header to get
     * @return the value
     */
    virtual const std::string&		getHeader(const std::string& header) = 0;

    /** 
     * @brief set a single header, like 'host'
     * @param field : the field to set ('host')
     * @param value : the value to set
     */
    virtual void		setHeader(const std::string& field, const std::string& value) = 0;

    /** 
     * @brief body getter
     * @return the body
     */
    virtual const std::string&	body() = 0;

    /** 
     * @brief body setter
     * @param body : the body to set
     */
    virtual void		body(const std::string& body) = 0;

    /** 
     * @brief append a string to the body
     * @param body : the string to append
     */
    virtual void		bodyAppend(const std::string& body) = 0;

    /** 
     * @brief append a string with a desired size to the body
     * @param body : the string to append
     * @param size : the size to append
     */
    virtual void		bodyAppend(char* body, unsigned int size = 0) = 0;

    /** 
     * @brief return true if response is chunked
     * @return true if response is chunked
     */
    virtual bool		chunked() const = 0;

    /** 
     * @brief set if the response is chunked
     * @param isChunked : the bool to set
     */
    virtual void		chunked(bool isChunked) = 0;
  };
}

#endif
