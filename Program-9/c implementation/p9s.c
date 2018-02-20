#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main() 
{
	char fname[50], buffer[1025];
	int sd, source, size, file, n;
	struct sockaddr_in address;
		
	address.sin_family = AF_INET;	
	address.sin_port = htons(15000);	
	address.sin_addr.s_addr = INADDR_ANY;
	
	printf("Waiting for request... \n");
	
	sd = socket(AF_INET, SOCK_STREAM, 0);	
	bind(sd, (struct sockaddr*)&address, sizeof(address));
	listen(sd, 3);
	
	source = accept(sd, (struct sockaddr*)NULL, NULL);
	recv(source, fname, sizeof(fname), 0);
	printf("Received request for: %s \n", fname);
	file = open(fname, O_RDONLY);
	if(file < 0)
		send(source, "File not found. \n", 18,  0);
	else 
		while((n = read(file, buffer, sizeof(buffer))) > 0)
			send(source, buffer, n, 0);
	printf("Response sent. \n");
	close(file);
	return 0;
}
