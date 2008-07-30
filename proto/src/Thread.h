//
// Thread.h for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 16:38:41 2008 morgan armand
// Last update Wed Jul 30 17:11:51 2008 morgan armand
//

class	Thread
{
public:
  // Create a new thread and call the run method.
  void	start();

  // Must be overload in all class
#ifdef WIN32
  DWORD	run(LPVOID arg);
#else
  void*	run(void* arg) = 0;
#endif
};
