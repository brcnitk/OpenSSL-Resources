#include <iostream>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char* argv[])
{
        char fname[50], buffer[1025];
        int sd;
        struct sockaddr_in address;

        address.sin_family = AF_INET;
        address.sin_port = htons(5000);
        address.sin_addr.s_addr = inet_addr("127.0.0.1");

        sd = socket(AF_INET, SOCK_STREAM, 0);
        connect(sd, (struct sockaddr*)&address, sizeof(address));
        
        cout<<"Enter a filename: ";
        cin>>fname;
        
        cout<<"Sending request"<<endl;
        send(sd, fname, sizeof(fname), 0);
        
        cout<<"Recieved response:"<<endl;
        int n=recv(sd, buffer, sizeof(buffer), 0);
        buffer[n]='\0';
        cout<<buffer;
        cout<<endl;
        
        return 0;
}
