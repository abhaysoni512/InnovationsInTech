#include <iostream>     // for cout/cerr
#include <arpa/inet.h>  // for ip inet_pton()
#include <netinet/in.h> // for address
#include <sys/select.h> // for io multiplexing (select)
#include <sys/socket.h> // for socket
#include <unistd.h>     // for close()
#include <vector>       // for storing client
using namespace std;
struct clientDetails
{
    int32_t clientfd;
    int32_t serverfd;    // server file descriptor
    std::vector<int> clientList; // for storing all the client fd
    clientDetails(void)
    { // initializing the variable
        this->clientfd = -1;
        this->serverfd = -1;
    }
};
const int port = 4277;
const char *ip = "127.0.0.1"; // Listen on all interfaces
const int backlog = 5; // Maximum number of pending connections

int main(){
   
    auto client = new clientDetails(); // Create a new clientDetails object
    client->serverfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
    // error handling
    if (client->serverfd <= 0)
    {
        std::cerr << "socket creation error\n";
        delete client;
        exit(1);
    }
    else
    {
        std::cout << "socket created\n";
    }

    // // setting serverFd to allow multiple connection

    int opt = 1;
    if (setsockopt(client->serverfd, SOL_SOCKET, SO_REUSEADDR,
                   &opt, sizeof(opt)) < 0)
    {
        std::cerr << "setsockopt failed\n";
        close(client->serverfd);
        delete client;
        exit(1);    
    }
    else
    {
        std::cout << "setsockopt success\n";
    }

    // setting up the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; // IPv4
    serverAddr.sin_port = htons(port); // Port number in network byte order
    inet_pton(AF_INET, ip, &serverAddr.sin_addr); // Convert IP address from text to binary form

    // binding the socket to the address
    if (bind(client->serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        std::cerr << "bind failed\n";
        close(client->serverfd);
        delete client;
        exit(1);
    }
    else
    {
        std::cout << "bind success\n";
    }
    // listening for incoming connections
    if (listen(client->serverfd, backlog) < 0)
    {
        std::cerr << "listen failed\n";
        close(client->serverfd);
        delete client;
        exit(1);   
    }
    else
    {
        std::cout << "listening on port " << port << "\n";
    }

    // Set up the file descriptor set for select
    fd_set readfds;
    int max_sd = client->serverfd; // Initialize max_sd to the server socket
    int sd = 0; // Variable to hold the socket descriptor
    int activity = 0; // Variable to hold the activity status

    while (true)
    {
        std::cout << "Waiting for connections...\n";
        // Clear the file descriptor set
        FD_ZERO(&readfds);
        // Add the server socket to the set
        FD_SET(client->serverfd, &readfds);
        // Update max_sd if necessary
        if (client->serverfd > max_sd)
        {
            max_sd = client->serverfd;
        }
        // copying the client list to readfds
        // so that we can listen to all the client
        for(auto sd : client->clientList)
        {
            if(sd > 0)
            {
                FD_SET(sd, &readfds);
            }
        }
        if (sd > max_sd)
        {
            max_sd = sd;
        }

                /* using select for listen to multiple client
            select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds,
            fd_set *restrict errorfds, struct timeval *restrict timeout);
        */
        activity=select(max_sd+1, &readfds, NULL, NULL, NULL);
            if (activity<0){
                std::cerr<<"select error\n";
                continue;
            }
        
        // Check if there is activity on the server socket
        if (FD_ISSET(client->serverfd, &readfds)){
            client->clientfd = accept(client->serverfd, NULL, NULL); // Accept the connection
            if (client->clientfd < 0)
            {
                std::cerr << "accept error\n";
                continue;
            }
            else
            {
                std::cout << "New connection accepted, clientfd: " << client->clientfd << "\n";
                // Add the new client socket to the list
                client->clientList.push_back(client->clientfd);
            }
        }
        // for storing the recive message
        char buffer[1024] = {0};
        for(int i = 0; i < client->clientList.size(); i++)
        {
            sd = client->clientList[i];
            // Check if there is activity on the client socket
            if (FD_ISSET(sd, &readfds))
            {
                // Read data from the client
                int bytesRead = read(sd, buffer, sizeof(buffer));
                if (bytesRead <= 0)
                {
                    // Client disconnected or error occurred
                    std::cerr << "Client disconnected or read error, clientfd: " << sd << "\n";
                    close(sd);
                    client->clientList.erase(client->clientList.begin() + i);
                    i--; // Adjust index after erasing
                }
                else
                {
                    // Process the received data
                    std::cout << "Received data from clientfd " << sd << ": " << buffer << "\n";
                    // Optionally, you can send a response back to the client
                    send(sd, buffer, bytesRead, 0);
                }
            }
        }
    }
    delete client; // Clean up the clientDetails object
    
}
