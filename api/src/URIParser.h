#ifndef __URIPARSER_H__
# define __URIPARSER_H__

# include <string>
# include "IParser.h"

namespace	ZapII
{
  //! URIParser
  class	URIParser : public IParser
  {
  public:
    //! undef
    //! \param consumer a Consumer pointer
    //! \param request a IRequest pointer
    URIParser(Consumer* consumer, IRequest* request);

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
  };
};

#endif // !__URIPARSER_H__
