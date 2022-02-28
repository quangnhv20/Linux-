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

    //check connect status
    int connect_stt = connect(socket_server, (struct sockaddr*) &server_address, sizeof(server_address));

    if(connect_stt == -1){
        printf("can not connect");
    }

    //receive msg from server
    char msg[256];
    recv(socket_server, msg, sizeof(msg),0);

    printf("msg was received %s\n",msg);

    //close socket
    close(socket_server);
    return 0;

}
