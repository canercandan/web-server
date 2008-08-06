//
// URIParser.cpp for URIParser in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 10:36:11 2008 caner candan
// Last update Wed Aug  6 00:26:21 2008 morgan armand
//

#include "URIParser.h"

void	Debug::enter(const char* func)
{
  int	i;

  for (i = 0; i < Debug::indent; i++)
    std::cout << " ";

  Debug::indent++;

  std::cout << "[" << func << "]"
	    << " -> " <<
	    << "[" << this->getBuf() << "]"
	    << std::endl;
}

bool	Debug::leave(const char* func, bool retn)
{
  int	i;

  indent--;

  for (i = 0; i < Debug::indent; i++)
    std::cout << " ";

  std::cout << "[" << func << "]"
	    << " -> " <<
	    << "[" <<  retn << "]"
	    << std::endl;

  return (retn);
}


URIParser::URIParser()
{}

URIParser::~URIParser()
{}

bool	URIParser::readURI(){return (false);}

bool	URIParser::readHierPart(){return (false);}

bool	URIParser::readURIReference(){return (false);}

bool	URIParser::readAbsoluteURI(){return (false);}

bool	URIParser::readRelativeRef(){return (false);}

bool	URIParser::readRelativePart(){return (false);}

bool	URIParser::readScheme(){return (false);}

bool	URIParser::readAuthority(){return (false);}

bool	URIParser::readUserinfo(){return (false);}

bool	URIParser::readHost(){return (false);}

bool	URIParser::readPort(){return (false);}

bool	URIParser::readIPLiteral(){return (false);}

bool	URIParser::readIPvFuture(){return (false);}

bool	URIParser::readIPv6address(){return (false);}

bool	URIParser::readH16(){return (false);}

bool	URIParser::readLs32(){return (false);}

bool	URIParser::readIPv4address(){return (false);}

bool	URIParser::readDecOctet(){return (false);}

bool	URIParser::readRegName(){return (false);}

bool	URIParser::readPath(){return (false);}

bool	URIParser::readPathAbempty(){return (false);}

bool	URIParser::readPathAbsolute(){return (false);}

bool	URIParser::readPathNoscheme(){return (false);}

bool	URIParser::readPathRootless(){return (false);}

bool	URIParser::readPathEmpty(){return (false);}

bool	URIParser::readSegment(){return (false);}

bool	URIParser::readSegmentNz(){return (false);}

bool	URIParser::readSegmentNzNc(){return (false);}

bool	URIParser::readPchar(){return (false);}

bool	URIParser::readQuery(){return (false);}

bool	URIParser::readFragment(){return (false);}

bool	URIParser::readPctEncoded(){return (false);}

bool	URIParser::readUnreserved(){return (false);}

bool	URIParser::readReserved(){return (false);}

bool	URIParser::readGenDelims(){return (false);}

bool	URIParser::readSubDelims(){return (false);}
