#include <winsock.h>
#include <stdio.h>

int main() {
    char buf[8] = "xxxxxxxx";
    int sfd,r;
    struct sockaddr_in soc,csoc;
    int clen = sizeof(struct sockaddr_in);
    sfd=socket(AF_INET, SOCK_DGRAM, 0);

    soc.sin_family=AF_INET;
    soc.sin_port=htons(777);
    soc.sin_addr.s_addr=inet_addr("172.30.115.236");

    bind(sfd, &soc, sizeof(struct sockaddr_in));

    r=recvfrom(sfd, buf, 100, 0, &csoc, &clen);
    buf[r]=0;
    printf("%d %s\n", strlen(buf), buf);

    return 0;
}