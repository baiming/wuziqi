#include "main.h"
#define SERVER_PORT		20001
#define BUFFER_SIZE		12
char buffer[BUFFER_SIZE];
msg_t* pp = (msg_t *)buffer;
	int server_sock;
    //int client;
    //int server_len;
    //int len;
	int client_sock;
	socklen_t server_len;
	struct sockaddr_in server;
int main(int argc, char *argv[])
{   
    int j;

	if(argc < 2)
	{
		printf("\n");
		printf("Sorry, your type is wrong.\n");
		printf("Usage: %s x.x.x.x(server IP)\n", argv[0]);
		printf("\n");
		exit(EXIT_FAILURE);
	}

	// 1. create socket - create an endpoint for communication
	// int socket(int domain, int type, int protocol);
	if ((client_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("create socket ok!\n");
	}
    create_scr_fb();
    for(j=0;j<910;j++)
    {
        fb_line(80+j,20,80+j,750,0x00ac899c);  //hua xian han shu
     // usleep(50);
    }
    print_board();


	// make server address information
	bzero(&server, sizeof(server));
//	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    mouse_doing1();

//	inet_aton(argv[1], &server.sin_addr);
  /*  while(1)
    {
        //write to screen
        n = write(STDOUT_FILENO, "> ",3);
//      n = write(fileno(stdout), "> ",3);
        
        //read to server
//      if((len = read(STDOUT_FILENO, buffer, BUFFER_SIZE)) > 0)
        if((len = read(fileno(stdin), buffer, BUFFER_SIZE)) > 0)
        {
            // send to server
//          n = send(client_sock, buffer, len ,0);
            n = write(client_sock, buffer, len);
        
        }

        // Quit flag
        if(buffer[0] == '.') break;

        // receive message from server
        if((len = recv(client_sock, buffer, len, 0)) > 0)
//      if((len = read(client_sock, buffer, len)) > 0)
        {
            // write to screen
            n = write(STDOUT_FILENO, buffer, len);
//          n = write(fileno(stdout), buffer, len);
        }
      
    
    
    }*/
    close(client_sock);
    exit(EXIT_SUCCESS);
  }  



