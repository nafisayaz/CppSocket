#include <serv-sock_t.hpp>
#include <quick.hpp>


auto  Servsock_t::get_port()->int const{
  return m_port;

}

auto Servsock_t::create_sock()->bool{
  m_socket = socket(PF_INET, SOCK_STREAM, 0);    
  m_sock_addr.sin_family = AF_INET;
  m_sock_addr.sin_port = htons(m_port);
  m_sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  return true;
}

auto  Servsock_t::init_t()->bool{
    m_port = gen_port();
    if(!create_sock()) return false;
    return true;

}

auto Servsock_t::init_with(int port)->bool{
  m_port = port;
  if(!create_sock()) return false;
  return true;
}

auto  Servsock_t::bind_t()->bool{

  inet_pton(AF_INET, m_ipAddress, &m_sock_addr.sin_addr );
  assert( 
     ( (setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &m_opt, sizeof(m_opt)) == -1 ) , "Failed to set SO_REUSEADDR option." )
    );

  while( bind(m_socket, reinterpret_cast<sockaddr*>(&m_sock_addr), sizeof(m_sock_addr)) == -1){
      m_sock_addr.sin_port = htons(m_port=gen_port());
  }
  
  assert( 
     ( (listen(m_socket, 5) == -1 ) , strerror(errno) )
    );
  

  return true;

}


void Servsock_t::receiver(){

	  char message[1024];
	  while(true){
	      int chatfd = accept(m_socket, reinterpret_cast<sockaddr*>(&m_their_addr), &m_their_size);

        assert( 
            ( (recv(chatfd, message, sizeof message, 0) == -1) , strerror(errno) )
          );
        
        assert( 
            ( (send(chatfd, message,  sizeof(message), 0) == -1) , strerror(errno) )
          );

        close(chatfd);  
			  bzero(message,1024);
	}

}



