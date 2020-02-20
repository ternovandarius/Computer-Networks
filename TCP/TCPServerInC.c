#include <stdio.h>
#include <winsock.h>

#define MYPORT 6969
#define CONNECTIONS 10

int main() {
    int sockfd, new_fd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;

    if((sockfd=socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("socket");
        exit(1);
    }

    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(MYPORT);
    my_addr.sin_addr.s_addr=INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);

    if(bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr))==-1)
    {
        perror("bind");
        exit(1);
    }

    if(listen(sockfd, CONNECTIONS)==-1){
        perror("listen");
        exit(1);
    }

    while(1){
        sin_size
    }

    return 0;
}