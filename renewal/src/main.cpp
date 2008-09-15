//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Mon Sep 15 15:19:43 2008 majdi toumi
//

#include "Server.h"
#include "Config.h"

int		main()
{
  Server	server;
  Config*	conf = Config::getInstance();

  XmlParser::ListParam_t	list;
  XmlParser::ListParam_t::const_iterator	itb;
  XmlParser::ListParam_t::const_iterator	ite;
  std::map<std::string, std::string>::const_iterator	mtb;
  std::map<std::string, std::string>::const_iterator	mte;

  std::cout << "Port = " << conf->getParamInt("port") << std::endl;
  list = conf->getListParam("//config");
  ite = list.end();
  for (itb = list.begin(); itb != ite; itb++)
    {
      mte = itb->end();
      for (mtb = itb->begin(); mtb != mte; mtb++)
	std::cout << "key = " << mtb->first << " and value = " << mtb->second << std::endl;
      std::cout << std::endl;
    }

  server.start();
  server.loop();
  server.stop();
}
