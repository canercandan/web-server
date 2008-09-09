#ifndef _IRESSOURCESMANAGER_H_
# define _IRESSOURCESMANAGER_H_

# include <iostream>

namespace ZenZiAPI
{
  /** 
   * @class IRessourcesManager
   * @brief Interface describing the ressources manager
   */
  class IRessourcesManager
  {
  public:

    /** 
     * @brief virtual dtor
     * @return 
     */
    virtual ~IRessourcesManager() {};

    /** 
     * @brief memory allocation overload
     * @param size : the size to alloc
     * @return the allocated pointer 
     */
    virtual void*	rm_alloc(size_t size) = 0;

    /** 
     * @brief memory desalloc overload
     * @param ptr : the param to desalloc
     */
    virtual void	rm_desalloc(void* ptr) = 0;

    /** 
     * @brief open fd overload
     * @param pathname : the file to open
     * @param flags : open flags
     * @return the fd
     */
    virtual int		rm_open(const char* pathname, int flags) = 0;

    /** 
     * @brief close fd overload
     * @param fd : the fd to close
     */
    virtual int		rm_close(int fd) = 0;

    /** 
     * @brief cleanning method
     * should be called in module dtor
     */
    virtual void	rm_clean() = 0;
  }; 
}

#endif
