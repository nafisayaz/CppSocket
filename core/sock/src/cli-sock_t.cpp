
#include"../headers/cli-sock_t.hpp"
#include "../../utilities/headers/quick.hpp"



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
	while( connect(m_socket, reinterpret_cast<sockaddr*>(&m_sock_addr), sizeof(m_sock_addr)) == -1 ){
		std::cout<<"Please wait!!\n" <<strerror(errno)<<"\n";
		sleep(2);
	}
	return true;
}


void Clisock_t::sender(){
  	std::string message = "Hello \n";
  	// std::getline(std::cin, message);

  	if( send(m_socket, message.c_str(), message.size(), /*sizeof (message),*/  0) == -1 )
  	{
  		std::cout<<"send() failed => "<<strerror(errno)<< "\n";
  	}else{
			std::cout<<"Succesfully send from Client => "<<strerror(errno)<< "\n";
    }
    char msg[1024];
    if(recv(m_socket, msg, sizeof(msg), 0) == -1 )
			std::cout<<"recv() failed !! => "<<strerror(errno)<< "\n";
		else{
			std::cout<<green<<message<<reset<<std::endl;
      close(m_socket); 
     
    }
}




