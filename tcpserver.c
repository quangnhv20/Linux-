#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //create socket
    int socket_server = socket(AF_INET, SOCK_STREAM, 0);

    //specify addr
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9991);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind
    bind(socket_server, (struct sockaddr*) &server_address, sizeof(server_address));

    //listen with the max waiting client is 4
    listen(socket_server,4);

    //create socket to talk to client
    int socket_client = accept(socket_server, NULL, NULL);

    //send msg to client
    char msg[256] = "Hello from server";
    send(socket_client, msg, sizeof(msg),0);

    //close socket
    close(socket_client);
    close(socket_server);
    return 0;
}
