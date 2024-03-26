

#include <iostream>
#include <future>
#include <cli-sock_t.hpp>

int main(int n, char** argv){

    for(int i=0; i< 100; ++i){
        Clisock_t client;
        client.init_with(std::stoi(argv[1]));
        
        if(client.connect_t()){
            std::cout << "i===> " << i <<" :: connected on: " << client.get_port()<<std::endl;
        }
        client.sender();
        // std::future<void> f2 = std::async(std::launch::async, &Clisock_t::sender, &client);

        // f2.get();
        sleep(1);
    }
    

}
