//
// Singleton.hpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Wed Sep 10 11:14:31 2008 majdi toumi
// Last update Wed Sep 10 12:04:33 2008 majdi toumi
//

#ifndef __SINGLETON_HPP__
# define __SINGLETON_HPP__

# include <cstdlib>

//! Singleton
template <typename T>

class	Singleton
{
public:
  //! get an instance
  //! \return T pointer
  static T*	getInstance()
  {
    if (!_singleton)
      _singleton = new T;
    return (static_cast<T*>(_singleton));
  }
  //! kill an instance
  static void	kill()
  {
    if (_singleton)
      {
	delete _singleton;
	_singleton = NULL;
      }
  }
  //! return true if instance exist
  static bool	exist()
  {
    return (_singleton != NULL);
  }
protected:
  Singleton(){}
  ~Singleton(){}
private:
  static T*	_singleton;
};

template <typename T>
T*	Singleton<T>::_singleton = NULL;

#endif // !__SINGLETON_HPP__
