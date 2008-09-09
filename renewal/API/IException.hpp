#ifndef _IEXCEPTION_H_
# define _IEXCEPTION_H_

#include <iostream>
#include <exception>

class IException: public std::exception
{
public:
  /** 
   * @brief virtual dtor
   * @return 
   */
  virtual		~IException() throw(){};

  /** 
   * @brief show the exception's content
   * @return the content string
   */
  virtual		const char* what() const throw() = 0;

};

#endif // _IEXCETPION_H_
