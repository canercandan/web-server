#include <fcntl.h>
#include <stdlib.h>
#include "RessourcesManager.h"

using namespace	ZenZiAPI;

void*		RessourcesManager::rm_alloc(size_t size)
{
  return (malloc(size));
}

void		RessourcesManager::rm_desalloc(void* ptr)
{
  free(ptr);
}

int		RessourcesManager::rm_open(const char* pathname, int flags)
{
  return (open(pathname, flags));
}

int		RessourcesManager::rm_close(int fd)
{
  return (close(fd));
}

void		RessourcesManager::rm_clean()
{
  std::list<void*>::const_iterator	mem_b = this->_mem.begin();
  std::list<void*>::const_iterator	mem_e = this->_mem.end();

  for (; mem_b != mem_e; ++mem_b)
    free(*mem_b);

  std::list<int>::const_iterator	fd_b = this->_fd.begin();
  std::list<int>::const_iterator	fd_e = this->_fd.end();

  for (; fd_b != fd_e; ++fd_b)
    close(*fd_b);
}
