#ifndef __SSL_H__
# define __SSL_H__

# include "IModule.hpp"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT
# endif

// SSL Certificate
# define SERVER_CERT	"../server.pem"

using namespace	ZenZiAPI;

class	Ssl : public IModule
{
public:
  typedef std::pair<p_callback, hookPosition>		callback_t;

public:
  Ssl();

  bool	onLoad();
  void	onUnLoad();

  const std::vector<callback_t>&	getCallbacks();

  bool	onAccept(ITools& tools);
  bool	onRead(ITools& tools);
  bool	onWrite(ITools& tools);

private:
  SSL*				_ssl;
  SSL_CTX*			_ctx;
  BIO*				_err;
  std::vector<callback_t>	_callbacks;
};

#endif // __SSL_H__
