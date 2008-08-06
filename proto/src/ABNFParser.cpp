//
// ABNFParser.cpp for ABNFParser.cpp in /home/candan_c/rendu/zia/proto/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Aug  6 11:12:53 2008 caner candan
// Last update Wed Aug  6 12:00:22 2008 morgan armand
//

#include "ABNFParser.h"

ABNFParser::ABNFParser(HttpProducer* prod)
  : HttpConsumer(prod)
{}

ABNFParser::~ABNFParser()
{}

bool	ABNFParser::readAlpha()
{return (false);}

bool	ABNFParser::readDigit()
{return (false);}

bool	ABNFParser::readHexdig()
{return (false);}
