#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
	uint32_t a=12, b;
	int fd;
	struct sockaddr_in serverSocket;

	char aux;

	fd=socket(AF_INET, SOCK_STREAM, 0);
	memset(&serverSocket, 0, sizeof(serverSocket));
	serverSocket.sin_port=htons(1234);
	serverSocket.sin_family=AF_INET;
	serverSocket.sin_addr.s_addr=inet_addr("172.30.119.32");

	connect(fd, (struct sockaddr*) &serverSocket, sizeof(serverSocket));

	a=htonl(a);
	send(fd, &a, sizeof(a), 0);

	a=htonl(0);
	send(fd, &a, sizeof(a), 0);
	recv(fd, &b, sizeof(b), 0);
	b=ntohl(b);
	printf("%d", b);
	close(fd);
	return 0;
}

