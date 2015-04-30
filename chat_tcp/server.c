#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>

int main(){
	  
    	struct sockaddr_in server_addr,client_addr;
	char rmsg[100],smsg[100];
	int c_sockfd,s_sockfd;
	
	int clientlen=sizeof(client_addr);
	s_sockfd=socket(AF_INET,SOCK_STREAM,0);	//creates a socket
	
	bzero((char*)&server_addr,sizeof(server_addr));
	
	server_addr.sin_family=AF_INET;
	inet_aton("127.0.0.1",&server_addr.sin_addr);
	server_addr.sin_port=htons(2345);
	
	bind(s_sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));	//bind the socket to an address
	
	listen(s_sockfd,5);	//listen for connections	
	
	c_sockfd=accept(s_sockfd,(struct sockaddr*)&client_addr,&clientlen);	//accept a connections
	
	//send and recieve data
	//stop when client says bye
	for(;;){
	
		recv(c_sockfd,rmsg,100,0);
		
		printf("\nClient>>%s\n",rmsg);
		if((strcmp(rmsg,"bye"))==0){
			
			exit(0);
		}
		printf("\nServer>>");
		scanf("%s",smsg);
	
		send(c_sockfd,smsg,100,0);
	
	}
	
	close(s_sockfd);
	close(c_sockfd);
	
	return 0;
}
