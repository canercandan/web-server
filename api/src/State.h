#ifndef __STATE_H__
# define __STATE_H__

# include "IRoot.h"
# include "Singleton.hpp"

//! State
class	State : public IRoot,
		public Singleton<State>
{
public:
  //! Status
  enum	Status {PRE, POST, END, ERROR};

  //! undef
  const Status&	getState();
  //! undef
  void		setState(const Status& state);
};

#endif // !__STATE_H__
