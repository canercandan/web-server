//
// main.cpp for **zia** in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Thu Sep 11 11:49:04 2008 caner candan
//

#include "Server.h"
#include "Config.h"

int		main()
{
  Server	server;

  server.start();
  server.loop();
  server.stop();
  Config::kill();
}
