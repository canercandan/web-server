#include <fcntl.h>
#include <stdlib.h>
#include "RessourcesManager.h"

using namespace	ZenZiAPI;

void*	RessourcesManager::rm_alloc(size_t size)
{
  void		*p;

  if ((p = malloc(size)))
    this->_mem.push_back(p);

  return (p);
}

void	RessourcesManager::rm_desalloc(void* ptr)
{
  std::list<void*>::iterator	itb = this->_mem.begin();
  std::list<void*>::iterator	ite = this->_mem.end();

  if (!ptr)
    {
      std::cerr << "RessourcesManager::rm_desalloc: ptr is NULL" << std::endl;
      return;
    }

  for (; itb != ite; ++itb)
    {
      if (*itb == ptr)
	{
	  free(ptr);
	  this->_mem.erase(itb);
	  return;
	}
    }

  std::cerr << "RessourcesManager::rm_desalloc: ptr is invalid" << std::endl;
}

int	RessourcesManager::rm_open(const char* pathname, int flags)
{
  int	fd;

  if ((fd = open(pathname, flags)) >= 0)
    this->_fd.push_back(fd);

  return (fd);
}

int	RessourcesManager::rm_close(int fd)
{
  int				ret;
  std::list<int>::iterator	itb = this->_fd.begin();
  std::list<int>::iterator	ite = this->_fd.end();

  if (fd < 0)
    {
      std::cerr << "RessourcesManager::rm_close: fd is < 0" << std::endl;
      return (-1);
    }

  for (; itb != ite; ++itb)
    {
      if (*itb == fd)
	{
	  if ((ret = close(fd)) == 0)
	    this->_fd.erase(itb);

	  return (ret);
	}
    }

  std::cerr << "RessourcesManager::rm_close: fd is invalid" << std::endl;
  return (-1);
}

void	RessourcesManager::rm_clean()
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
