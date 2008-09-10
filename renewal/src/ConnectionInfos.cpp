#include "ConnectionInfos.h"

using namespace ZenZiAPI;

ConnectionInfos::ConnectionInfos(SOCKET sck)
  : _sck(sck)
{
}

const SOCKET		ConnectionInfos::socket()
{
  return (this->_sck);
}

const ConnectionInfos::connectionType	ConnectionInfos::connectType(void)
{
  return (this->_connectionType);
}

ConnectionInfos::Extension*		ConnectionInfos::extension(void)
{
  return (this->_extension);
}

void			ConnectionInfos::extension(void *ptr)
{
  this->_extension = ptr;
}
