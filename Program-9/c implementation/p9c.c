#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) 
{
	char fname[50], buffer[1025];
	int sd, n;
	struct sockaddr_in address;
	
	address.sin_family = AF_INET;
	address.sin_port = htons(15000);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			perror("socket"); 
	connect(sd, (struct sockaddr*)&address, sizeof(address));
	
	printf("Enter a filename: ");
	scanf("%s", fname);
	
	printf("Sending request... \n");
	send(sd, fname, sizeof(fname), 0);	// send a message on a socket
	
	printf("Recieved response: \n");
	while((n = recv(sd, buffer, sizeof(buffer), 0)) > 0) 	// receive a message from a socket
		write(1, buffer, n);
	
	return 0;
}
