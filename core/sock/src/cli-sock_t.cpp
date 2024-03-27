
#include <cli-sock_t.hpp>
#include <quick.hpp>
#include <iostream>


auto  Clisock_t::get_port()->int const{
  return m_port;
}

auto  Clisock_t::create_sock()->bool{
  m_socket = socket(PF_INET, SOCK_STREAM, 0);    
  m_sock_addr.sin_family = AF_INET;
  m_sock_addr.sin_port = htons(m_port);
  m_sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  return true;
}

auto  Clisock_t::init_t()->bool{
    m_port = gen_port();
    if(!create_sock()) return false;
    return true;
}

auto Clisock_t::init_with(int port)->bool{
  m_port = port;
  if(!create_sock()) return false;
  return true;
}

auto  Clisock_t::connect_t()->bool{
  inet_pton(AF_INET, m_ipAddress, &m_sock_addr.sin_addr);
  assert( 
   ( (connect(m_socket, reinterpret_cast<sockaddr*>(&m_sock_addr), sizeof(m_sock_addr)) == -1 ) , strerror(errno) )
  );
	return true;
}

void Clisock_t::sender(){
  std::string message = "Hello \n";
  assert( 
   ( (send(m_socket, message.c_str(), message.size(), 0) == -1 ) , strerror(errno) )
  );

  char msg[1024];
  assert( 
   ( (recv(m_socket, msg, sizeof(msg), 0) == -1 ) , strerror(errno) )
  );

  close(m_socket);

  std::cout << "Received from Server : " << msg << std::endl;   
}




