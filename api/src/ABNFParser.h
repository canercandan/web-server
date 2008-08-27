#ifndef __ABNFPARSER_H__
# define __ABNFPARSER_H__

# include "IParser.h"
# include "Consumer.h"

//! ABNFParser
/*! description */
class	ABNFParser : public IParser
{
public:
  //! \param consumer
  ABNFParser(Consumer* consumer);
  //! read a CR character
  bool	readCR();
  //! read a LF character
  bool	readLF();
  //! read CRLF characters
  bool	readCRLF();
  //! read a char between a - z
  bool	readAlpha();
  //! read a char between 0 - 9
  bool	readDigit();
  //! read a char between 0 - 9 and a - f
  bool	readHexdig();
  //! read a space
  bool	readSP();
};

#endif // !__ABNFPARSER_H__
