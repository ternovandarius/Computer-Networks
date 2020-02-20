#include <sys/types.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){
	int c;
	struct sockaddr_in server;
	u_int16_t a;

	c=socket(AF_INET, SOCK_STREAM, 0);
	if(c<0){
		printf("Eroare la socket.");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(4321);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr=inet_addr("192.168.0.105");

	if(connect(c, (struct sockaddr *) &server, sizeof(server))<0){
		printf("Eroare...");
		return 1;
	}

	char str[]="Ana are BERE.";
	send(c, &str, sizeof(str), 0);

	
	char res[40];
	recv(c, &res, sizeof(res), 0);
	//res=ntohs(res);
	printf("%s", res);
	close(c);
}
