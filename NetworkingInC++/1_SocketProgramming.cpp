#include <iostream>
#include <sys/socket.h>
#include <cstring>
int main(){
    //Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // socket(int domain, int type, int protocol);

    // AF_INET specifies the address family for IPv4
    // SOCK_STREAM indicates that this is a TCP socket

    // Check if the socket was created successfully
    if (sockfd < 0) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        return *strerror(errno);
    }

    std::cout << "Socket created successfully with file descriptor: " << sockfd << std::endl;

    // Bind the socket to an address
    struct sockaddr_in serveraddr ;
}