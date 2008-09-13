//
// main.cpp for zia in /home/toumi_m/zia/renewal/src
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Tue Sep  9 20:14:09 2008 majdi toumi
// Last update Sat Sep 13 22:25:03 2008 caner candan
//

#include "Server.h"

int		main()
{
  Server	server;

  server.start();
  server.loop();
  server.stop();
}
