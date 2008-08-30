#ifndef __URIPARSER_H__
# define __URIPARSER_H__

# include <string>
# include "IParser.h"
# include "Consumer.h"
# include "IRequest.h"
# include "HttpParser.h"

# define ALPHA	static_cast<HttpParser*>(this->_parent)->readAlpha()
# define CR	static_cast<HttpParser*>(this->_parent)->readCR()
# define LF	static_cast<HttpParser*>(this->_parent)->readLF()
# define CRLF	static_cast<HttpParser*>(this->_parent)->readCRLF()
# define DIGIT	static_cast<HttpParser*>(this->_parent)->readDigit()
# define HEXDIG	static_cast<HttpParser*>(this->_parent)->readHexdig()
# define SP	static_cast<HttpParser*>(this->_parent)->readSP()
# define LWS	SP

namespace	ziApi
{
  //! URIParser
  class	URIParser : public IParser
  {
  public:
    //! undef
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    //! \param parent a IParser pointer
    URIParser(Consumer* consumer,
	      IRequest* request,
	      IParser* parent = NULL);

    //! first method called
    bool	run();
    //! undef
    bool	readHierPart();
    //! undef
    bool	readAbsoluteURI();
    //! undef
    bool	readScheme();
    //! undef
    bool	readAuthority();
    //! undef
    bool	readUserInfo();
    //! undef
    //! \param extract a std::string&
    bool	readHost(std::string& extract);
    //! undef
    //! \param extract a std::string&
    bool	readPort(std::string& extract);
    //! undef
    bool	readIPLiteral();
    //! undef
    bool	readIPvFuture();
    //! undef
    bool	readIPv6address();
    //! undef
    bool	readIPv4address();
    //! undef
    bool	readDecOctet();
    //! undef
    bool	readRegName();
    //! undef
    bool	readPath();
    //! undef
    bool	readPathAbempty();
    //! undef
    bool	readPathAbsolute();
    //! undef
    bool	readPathAbsoluteQuery();
    //! undef
    bool	readPathNoScheme();
    //! undef
    bool	readPathRootless();
    //! undef
    bool	readPathEmpty();
    //! undef
    bool	readSegment();
    //! undef
    bool	readSegmentNz();
    //! undef
    bool	readSegmentNzNc();
    //! undef
    bool	readPchar();
    //! undef
    bool	readQuery();
    //! undef
    bool	readFragment();
    //! undef
    bool	readPctEncoded();
    //! undef
    bool	readUnreserved();
    //! undef
    bool	readReserved();
    //! undef
    bool	readGenDelims();
    //! undef
    bool	readSubDelims();
  private:
    bool	_readAbsoluteURIOpt();

    bool	_readAuthorityOpt1();
    bool	_readAuthorityOpt2();

    bool	_readPathAbemptyPart2();

    bool	_readPathAbsoluteOpt();
    bool	_readPathAbsolutePart2();

    bool	_readPathNoSchemePart2();

    bool	_readPathRootlessPart2();
  private:
    Consumer*	_consumer;
    IRequest*	_request;
    IParser*	_parent;
  };
};

#endif // !__URIPARSER_H__
