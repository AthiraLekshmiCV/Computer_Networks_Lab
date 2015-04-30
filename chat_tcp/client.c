#include<stdio.h>
#include<stdlib.h>
#include<netinet/tcp.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<netdb.h>
int main(){

	struct sockaddr_in server_addr;
	char smsg[100],rmsg[100];
	int c_sockfd;
	
	c_sockfd=socket(AF_INET,SOCK_STREAM,0);	//creates a socket
	
	bzero((char*)&server_addr,sizeof(server_addr));
	
	server_addr.sin_family=AF_INET;
	inet_aton("127.0.0.1",&server_addr.sin_addr);
	server_addr.sin_port=htons(2345);
	
	connect(c_sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));   //Connect the socket to the address of the server
	
	
	printf("\n");
	
	//send and recieve data.
	//type "bye" to exit
	
	for(;;){
	    
		printf("Client>>");
		scanf("%s",smsg);
	
		
		
		send(c_sockfd,smsg,100,0);

		if((strcmp(smsg,"bye"))==0){
		 
		  exit(0); 
		}
		recv(c_sockfd,rmsg,100,0);
		
		printf("\nServer>>%s\n",rmsg);
		printf("\n");
	}
	
	close(c_sockfd);	


	return 0;
}
