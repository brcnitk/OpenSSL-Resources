#include <iostream>
#include <fstream>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
        char fname[50];
        int sd, source, file;
        struct sockaddr_in address;

        address.sin_family = AF_INET;
        address.sin_port = htons(5000);
        address.sin_addr.s_addr = INADDR_ANY;

        cout<<"Waiting for request."<<endl;
        
        sd = socket(AF_INET, SOCK_STREAM, 0);
        bind(sd, (struct sockaddr*)&address, sizeof(address));
        listen(sd, 10);

        while(1)
        {
                source = accept(sd, (struct sockaddr*)NULL, NULL);
                
                recv(source, fname, sizeof(fname), 0);
                cout<<"Received request for: "<<fname<<endl;

                ifstream is (fname);
                if (is)
                {
                        is.seekg (0, is.end);
                        int length = is.tellg();
                        is.seekg (0, is.beg);
                        char * buffer = new char [length];
                        cout << "Sending " << length << " characters... "<<endl;
                        is.read (buffer,length);
                        is.close();
                        send(source, buffer, length, 0);

                        delete[] buffer;
                }
                else
                {
                        cout<<"Sending file not found"<<endl;
                        send(source, "File not found", sizeof("File not found"), 0);
                }
        }

        return 0;
}
