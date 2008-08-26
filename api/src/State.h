#ifndef __STATE_H__
# define __STATE_H__

# include "IServer.h"
# include "Singleton.hpp"

//! State
class	State : public IServer,
		public Singleton<State>
{
public:
  //! undef
  const Status&	getState();
  //! undef
  void		setState(const Status& state);
};

#endif // !__STATE_H__
