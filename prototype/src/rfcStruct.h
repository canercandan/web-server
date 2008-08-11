//
// rfcStruct.h for zia in /home/hochwe_f/zia/proto/src
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Sat Aug  2 22:58:23 2008 florent hochwelker
// Last update Sat Aug  2 23:42:41 2008 florent hochwelker
//

#ifndef __RFCSTRUCT_H__
#define __RFCSTRUCT_H__

#include <string>
#include <list>

struct	VersionProtocol
{ // HTTP-Version   = "HTTP" "/" 1*DIGIT "." 1*DIGIT
  std::string		name;
  int			major;
  int			minor;
  std::string		otherVersion;
};

struct		Host
{
  std::string	host;
  int		port;
};

struct		HttpUrl
{ // http_URL = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
  Host		host;
  std::string	abs_path;
  std::string	query;
};

struct				Key
{
  std::string			key;
  std::list<std::string>	value;
};

struct				Type
{ // [page 100] pas encore de gestion de quality et level
  std::string			typeMajor;
  std::string			typeMinor;
  std::list<Key>		parameter;
};

struct		Warning
{
  int		warnCode;
  std::string	warAgent;
  std::string	warText;
  std::string	warDate;
};

#endif // __RFCSTRUCT_H__
