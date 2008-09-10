#include "ConnectionInfos.h"

using namespace ZenZiAPI;

const SOCKET		ConnectionInfos::socket()
{
  // ...
}

const connectionType	ConnectionInfos::connectType(void)
{
  return (this->_connectionType);
}

Extension*		ConnectionInfos::extension(void)
{
  return (this->_extension);
}

void			ConnectionInfos::extension(void *ptr)
{
  this->_extension = ptr;
}
