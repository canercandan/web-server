#ifndef __SINGLETON_HPP__
# define __SINGLETON_HPP__

# include <cstdlib>

namespace	ZapII
{
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
};

#endif // !__SINGLETON_HPP__
