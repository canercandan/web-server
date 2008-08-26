/**
 * @file Socket.h
 * @brief 
 * @note 
 */
class Socket 
{
public:
  bool create ();
  bool bind ();
  bool listen ();
  ISocket* accept ();
  void close ();
  int recv ();
  int send ();
  bool isValid ();
private:
  struct sockaddr_in ;
};
