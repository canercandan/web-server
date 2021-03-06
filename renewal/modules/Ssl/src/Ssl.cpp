#include <openssl/ssl.h>
#include <openssl/err.h>
#include "Ssl.h"

using namespace	ZenZiAPI;

Ssl::Ssl()
  : _ssl(NULL), _ctx(NULL),
    _callbacks(hookPointsNumber)
{}

bool		Ssl::onLoad()
{
  SSL_METHOD*	method;

  std::cout << "[mod_ssl] loading..." << std::endl;

  SSL_library_init();
  SSL_load_error_strings();

  this->_err = BIO_new_fp(stderr, BIO_NOCLOSE);

  method = SSLv23_method();
  this->_ctx = SSL_CTX_new(method);


  if (!SSL_CTX_use_certificate_file(this->_ctx, SERVER_CERT, SSL_FILETYPE_PEM))
    {
      BIO_printf(this->_err, "Can't read certificate\n");
      ERR_print_errors(this->_err);
    }

  if (!SSL_CTX_use_PrivateKey_file(this->_ctx, SERVER_CERT, SSL_FILETYPE_PEM))
    {
      BIO_printf(this->_err, "Can't read key file\n");
      ERR_print_errors(this->_err);
    }

  if (!SSL_CTX_check_private_key(this->_ctx))
    {
      BIO_printf(this->_err, "Private key doesn't match\n");
      ERR_print_errors(this->_err);
    }

#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
  SSL_CTX_set_verify_depth(this->_ctx, 1);
#endif
  return (true);
}

void	Ssl::onUnLoad()
{
  std::cout << "[mod_ssl] unloading..." << std::endl;

  if (this->_ssl)
    {
      SSL_shutdown(this->_ssl);
      SSL_free(this->_ssl);
    }

  if (this->_ctx)
    SSL_CTX_free(this->_ctx);
  if (this->_err)
    BIO_free(this->_err);
}

const std::vector<Ssl::callback_t>&	Ssl::getCallbacks()
{
  this->_callbacks[NEW_CLIENT].first =
    static_cast<IModule::p_callback>(&Ssl::onAccept);
  this->_callbacks[NEW_CLIENT].second = VERY_FIRST;

  this->_callbacks[READ].first =
    static_cast<IModule::p_callback>(&Ssl::onRead);
  this->_callbacks[READ].second = VERY_FIRST;

  this->_callbacks[WRITE].first =
    static_cast<IModule::p_callback>(&Ssl::onWrite);
  this->_callbacks[WRITE].second = VERY_FIRST;

  return (this->_callbacks);
}

bool		Ssl::onAccept(ITools& tools)
{
  BIO*		sbio;
  SOCKET	s;
  int		r;
  IConnectionInfos::connectionType	connectionType;

  std::cout << "[mod_ssl] onAccept..." << std::endl;

  s = tools.connectInfos().getSocket();
  connectionType = tools.connectInfos().getConnectType();


  if (connectionType == IConnectionInfos::SSL  ||
      connectionType == IConnectionInfos::TLS  ||
      connectionType == IConnectionInfos::SSL2 ||
      connectionType == IConnectionInfos::SSL3)
    {
      sbio = BIO_new_socket(s, BIO_NOCLOSE);

      this->_ssl = SSL_new(this->_ctx);
      SSL_set_bio(this->_ssl, sbio, sbio);

      if ((r = SSL_accept(this->_ssl)) <= 0)
	{
	  BIO_printf(this->_err, "SSL_accept failed\n");
	  ERR_print_errors(this->_err);
	  return (false);
	}
    }
  return (true);
}

bool		Ssl::onRead(ITools& tools)
{
  char		buf[128];
  int		ret;

  if (!this->_ssl)
    return (false);

  std::cout << "[mod_ssl] onRead..." << std::endl;

  if ((ret = SSL_read(this->_ssl, buf, sizeof(buf) - 1)) <= 0)
    return (false);

  buf[ret] = 0;
  tools.data(new std::string(buf));

  //  std::cout << "SSL_read: " << tools.data() << std::endl;
  return (true);
}

bool		Ssl::onWrite(ITools& tools)
{
  std::string*	data = tools.data();

  if (!this->_ssl)
    return (false);

  /*
    const char*	buf = tools.message().response().getBody().c_str();
    int		len = tools.message().response().getBody().size();
    int		ret;

    if (!this->_ssl)
    return (false);

    std::cout << "[mod_ssl] onWrite..." << std::endl;

    while (len > 0)
    {
    if ((ret = SSL_write(this->_ssl, buf, len)) <= 0)
    break;

    buf += ret;
    len -= ret;
    }
  */

  if (SSL_write(this->_ssl, data->c_str(), data->size()) <= 0)
    return (false);

  return (true);
}

extern	"C"
{
  EXPORT Ssl*	create()
  {
    return (new Ssl());
  }

  EXPORT void	destroy(void* p)
  {
    delete static_cast<Ssl*>(p);
  }
}
