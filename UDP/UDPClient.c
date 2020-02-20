#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int s;
	struct sockaddr_in server;
	
	srand(time(0));

	s=socket(AF_INET, SOCK_DGRAM, 0);
	server.sin_family = AF_INET;
	server.sin_port=htons(7777);
	server.sin_addr.s_addr=inet_addr("172.30.119.38");

	uint16_t newp;
	uint16_t idk=5;
	
	int r = sendto(s, &idk, sizeof(idk), 0, &server, sizeof(server));
	r=recvfrom(s, &newp, sizeof(newp), 0, &server, sizeof(server));
		int s2=socket(AF_INET, SOCK_DGRAM, 0);
		newp=ntohs(newp);
		printf("%d", newp);
		newp=htons(newp);
		server.sin_port=newp;
		uint16_t ans=0;
		while (ans==0)
		{
			uint16_t num=((rand() % (9999-1000+1))+1000);
			num=htons(num);
			int rr=sendto(s2, &num, sizeof(num), 0, &server, sizeof(server));
			rr=recvfrom(s2, &ans, sizeof(ans), 0, &server, sizeof(server));
			ans=ntohs(ans);
			num=ntohs(num);
			if(ans==0)
				printf("Wrong answer dude: %d\n",num );
			else if (ans==1)
				printf("Nice one! You won!\n");
			else
				printf("You lost, bro\n");
		}

	return 0;
}
