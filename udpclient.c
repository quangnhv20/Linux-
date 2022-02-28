#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //create socket
    int socket_server = socket(AF_INET, SOCK_DGRAM, 0);

    //specify addr
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9992);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //send msg to
    char msg[256] = "Hello from client";
    sendto(socket_server, msg, sizeof(msg),0, (struct sockaddr *) &server_address, sizeof(server_address));

    close(socket_server);
    return 0;

}
