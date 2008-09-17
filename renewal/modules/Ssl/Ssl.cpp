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
  std::cout << "[mod_ssl] loading..." << std::endl;

  SSL_library_init();
  SSL_load_error_strings();

  return (true);
}

void	Ssl::onUnLoad()
{
  std::cout << "[mod_ssl] unloading..." << std::endl;
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
  BIO*		io;
  BIO*		ssl_bio;
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

      //if (connectionType == IConnectionInfos::TLS)
      //	method = TLSv1_method();
      //      else

      method = SSLv23_method();
      ctx = SSL_CTX_new(method);


      if (!SSL_CTX_use_certificate_file(ctx, SERVER_CERT, SSL_FILETYPE_PEM))
	{
	  BIO_printf(bio_err, "Can't read certificate\n");
	  ERR_print_errors(bio_err);
	}

      if (!SSL_CTX_use_PrivateKey_file(ctx, SERVER_CERT, SSL_FILETYPE_PEM))
	{
	  BIO_printf(bio_err, "Can't read key file\n");
	  ERR_print_errors(bio_err);
	}

      if (!SSL_CTX_check_private_key(ctx))
	{
	  BIO_printf(bio_err, "Private key doesn't match\n");
	  ERR_print_errors(bio_err);
	}

#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
      SSL_CTX_set_verify_depth(ctx, 1);
#endif

      sbio = BIO_new_socket(s, BIO_NOCLOSE);
      ssl = SSL_new(ctx);
      SSL_set_bio(ssl, sbio, sbio);

      if ((r = SSL_accept(ssl)) <= 0)
	{
	  std::cout << "SSL_accept failed" << std::endl;
	  //	  ERR_print_errors(bio_err);
	  return (false); // ?
	}
      std::cout << "SSL_accept ok?!?" << std::endl;

      io = BIO_new(BIO_f_buffer());
      ssl_bio = BIO_new(BIO_f_ssl());
      BIO_set_ssl(ssl_bio, ssl, BIO_CLOSE);
      BIO_push(io, ssl_bio);

      BIO_puts(io, "HTTP/1.1 200 OK\r\n");
      BIO_puts(io, "Server: Zia\r\n\r\n");
      BIO_puts(io, "Hello world");

      BIO_flush(io);

      SSL_shutdown(ssl);
      SSL_free(ssl);
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
