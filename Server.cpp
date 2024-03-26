

#include <iostream>
#include <future>
#include <serv-sock_t.hpp>

int main(int n, char** argv){

    Servsock_t server;
    server.init_t();

    if(server.bind_t()){
        std::cout <<"Server is connected at: " << server.get_port()<<std::endl;
    }

    std::future<void> f1 = std::async(std::launch::async, &Servsock_t::receiver, &server);
    
    f1.get();

}
