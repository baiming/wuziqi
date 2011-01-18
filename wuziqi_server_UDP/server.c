
#include "main.h"
#define SERVER_PORT		31313
#define BUFFER_SIZE		12

char buffer[BUFFER_SIZE];
int server_sock;
socklen_t client_len;
struct sockaddr_in server,client;
struct in_addr in;
msg_t *pp = (msg_t *)buffer;
/* Following struct only for demo */
/*
truct sockaddr_in
{
	short int sin_family;          // Address family
	unsigned short int sin_port;   // Port number
	struct in_addr sin_addr;       // Internet address
	unsigned char sin_zero[8];     // Same size as struct sockaddr
};

struct in_addr
{
	unsigned long s_addr;
};
*/

int main(int argc, char *argv[])
{    
    int j;
    system("clear");
    create_scr_fb();
    for(j=0;j<910;j++)
    {
        fb_line(80+j,20,80+j,750,0x00ac899c);  //hua xian han shu
    }  
    print_board();
	// 1. create socket - create an endpoint for communication
	// int socket(int domain, int type, int protocol);
	if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("create socket ok!\n");
	}
	
	// 2. bind - bind a name to a socket
	// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = htons(INADDR_ANY);

	if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("bind addr ok!\n");
		printf("\n");
	}
    mouse_doing1();

	printf("Client close the socket\n");
	close(server_sock);

	exit(EXIT_SUCCESS);
}

