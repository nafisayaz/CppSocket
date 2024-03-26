
#include "../headers/serv-sock_t.hpp"
#include "../../utilities/headers/quick.hpp"


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

  if (setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &m_opt, sizeof(m_opt)) < 0){
    std::cout << "Failed to set SO_REUSEADDR option. "<< "\n";
    return false;
  }

  while( bind(m_socket, reinterpret_cast<sockaddr*>(&m_sock_addr), sizeof(m_sock_addr)) == -1){
      std::cout<< "m_socket binding failed on port number:  " << m_port <<std::endl;
      m_sock_addr.sin_port = htons(m_port=gen_port());
      // sleep(1);
  }
  
  if( listen(m_socket, 5) == -1){
		std::cout<<"listen() failed => "<<strerror(errno)<< "\n";
	}

  return true;

}


void Servsock_t::receiver(){

	  char message[1024];
	  while(true){
	      int chatfd = accept(m_socket, reinterpret_cast<sockaddr*>(&m_their_addr), &m_their_size);

			  if(recv(chatfd, message, sizeof message, 0) == -1 ){
			  	std::cout<<"recv() failed !! => "<<strerror(errno)<< "\n";
        }
			  else{
			  	std::cout<<green<<message<<reset<<std::endl;
          if( send(chatfd, message,  sizeof(message), 0) == -1 ){
  	      	std::cout<<"send() failed => "<<strerror(errno)<< "\n";
  	      }else{
  	      	std::cout<<"Succesfully send from Server => "<<strerror(errno)<< "\n";
          }
        }
        close(chatfd);  
			  bzero(message,1024);
        // sleep(1);
	}

}



