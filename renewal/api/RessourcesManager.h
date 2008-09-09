#ifndef _RESSOURCESMANAGER_H_
# define _RESSOURCESMANAGER_H_

# include <list>
# include "IRessourcesManager.hpp"

namespace	ZenZiAPI
{
  class		RessourcesManager : IRessourcesManager
  {
  public:
    void*	rm_alloc(size_t size);
    void	rm_desalloc(void* ptr);

    int		rm_open(const char* pathname, int flags);
    int		rm_close(int fd);

    void	rm_clean();

  private:
    std::list<void*>	_mem;
    std::list<int>	_fd;
  };
}

#endif // _RESSOURCESMANAGER_H_
