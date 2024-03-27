
#pragma once

#include <cassert>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <string>

class Servsock_t{

    public:
        
        // auto init(int port_r )->bool;
        auto init_t()->bool;
        auto init_with(int port)->bool;
        auto create_sock()->bool;
        auto bind_t()->bool;
        auto connect_t()->bool;

        auto get_port()->int const; 
        void receiver();
        void sender();


    private:
        const char*         m_ipAddress             = "192.168.58.1";
        int                 m_port;
        int                 m_socket;
        int                 m_opt                   = 1;
        int                 m_udpSocket;
        sockaddr_in         m_sock_addr;
        sockaddr_in         m_their_addr            {};
	    socklen_t           m_their_size            {};


};

