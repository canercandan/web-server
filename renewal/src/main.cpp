//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Mon Sep 15 16:33:50 2008 caner candan
//

#include "Server.h"
#include "Config.h"

int		main()
{
  Config*	conf = Config::getInstance();

  std::cout << "Port = " << conf->getParamInt("port") << std::endl;

  XmlParser::listParam	list(conf->getListParam("//config"));

  for (XmlParser::listParam::const_iterator
	 itb = list.begin(),
	 ite = list.end();
       itb != ite; ++itb)
    {
      for (XmlParser::listAttribute::const_iterator
	     mtb = itb->begin(),
	     mte = itb->end();
	   mtb != mte; ++mtb)
	{
	  std::cout << "key = " << mtb->first
		    << " and value = " << mtb->second
		    << std::endl;
	}
      std::cout << std::endl;
    }

  Server	server;

  server.start(4242);
  server.loop();
  server.stop();
}
