#include <openssl/ssl.h>
#include <openssl/err.h>
#include "Ssl.h"

using namespace	ZenZiAPI;

Ssl::Ssl()
  : _callbacks(hookPointsNumber)
{
}

bool	Ssl::onLoad()
{
  SSL_library_init();
  SSL_load_error_strings();

  // init PRNG
  //  actions_to_seed_PRNG();
  return (true);
}

void	Ssl::onUnLoad()
{
}

const std::vector<Ssl::callback_t>&	Ssl::getCallbacks()
{
  this->_callbacks[NEW_CLIENT].first =
    static_cast<IModule::p_callback>(&Ssl::onAccept);
  this->_callbacks[NEW_CLIENT].second = VERY_FIRST;

  return (this->_callbacks);
}

bool		Ssl::onAccept(ITools& tools)
{
  BIO*		bio_err;
  BIO*		sbio;
  SSL*		ssl;
  SSL_CTX*	ctx;
  SSL_METHOD*	method;
  SOCKET	s;
  int		r;

  IConnectionInfos::connectionType	connectionType;

  s = tools.connectInfos().getSocket();
  connectionType = tools.connectInfos().getConnectType();


  if (connectionType == IConnectionInfos::SSL  ||
      connectionType == IConnectionInfos::TLS  ||
      connectionType == IConnectionInfos::SSL2 ||
      connectionType == IConnectionInfos::SSL3)
    {
      bio_err = BIO_new_fp(stderr, BIO_NOCLOSE);

      if (connectionType == IConnectionInfos::TLS)
	method = TLSv1_method();
      else
	method = SSLv23_method();

      ctx = SSL_CTX_new(method);
      ssl = SSL_new(ctx);

      if (!SSL_CTX_use_certificate_chain_file(ctx, "server.pem"))
	{
	  BIO_printf(bio_err, "Can't read certficate\n");
	  ERR_print_errors(bio_err);
	}

      if (!SSL_CTX_use_PrivateKey_file(ctx, "server.pem", SSL_FILETYPE_PEM))
	{
	  BIO_printf(bio_err, "Can't read key file\n");
	  ERR_print_errors(bio_err);
	}

      if (!SSL_CTX_load_verify_locations(ctx, "root.pem", 0))
	{
	  BIO_printf(bio_err, "Can't read CA list\n");
	  ERR_print_errors(bio_err);
	}

#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
      SSL_CTX_set_verify_depth(ctx, 1);
#endif

      sbio = BIO_new_socket(s, BIO_NOCLOSE);
      SSL_set_bio(ssl, sbio, sbio);

      if ((r = SSL_accept(ssl)) <= 0)
	return (false); // ?
    }
  return (true);
}

extern	"C"
{
  Ssl*		create()
  {
    return (new Ssl());
  }

  void		destroy(void* p)
  {
    delete static_cast<Ssl*>(p);
  }
}
