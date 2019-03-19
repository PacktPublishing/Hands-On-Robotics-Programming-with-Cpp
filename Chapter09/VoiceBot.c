#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <wiringPi.h>

int main(void)
{
    wiringPiSetup();
    pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	
	struct sockaddr_rc server_address = { 0 }, client_address = { 0 };
    char data[1024] = { 0 };
    int serversocket, clientsocket, bytes;
    socklen_t opt = sizeof(client_address);

    
    serversocket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);


    server_address.rc_family = AF_BLUETOOTH;
    server_address.rc_bdaddr = *BDADDR_ANY;
    server_address.rc_channel = (uint8_t) 1;
	
    bind(serversocket, (struct sockaddr *)&server_address, sizeof(server_address));
    
    listen(serversocket, 1);


    clientsocket = accept(serversocket, (struct sockaddr *)&client_address, &opt);

    ba2str( &client_address.rc_bdaddr, data );
    fprintf(stderr, "Connected to %serversocket\n", data);
    memset(data, 0, sizeof(data));

  for(;;){
    bytes = read(clientsocket, data, sizeof(data));
    if( bytes > 0 ) {
        printf("Alphabet %serversocket\n", data);
		if(*data=='F')
        {
        digitalWrite(0,HIGH);
        digitalWrite(2,LOW);		
        digitalWrite(3,HIGH);
		digitalWrite(4,LOW);
        }
        else if(*data=='B')
        {
        digitalWrite(0,LOW);
        digitalWrite(2,HIGH);		
        digitalWrite(3,LOW);
		digitalWrite(4,HIGH);
        }
		 else if(*data=='L')
        {
        digitalWrite(0,LOW);
        digitalWrite(2,HIGH);		
        digitalWrite(4,HIGH);
		digitalWrite(4,LOW);
        }
		else if(*data=='R')
        {
        digitalWrite(0,HIGH);
        digitalWrite(2,LOW);		
        digitalWrite(3,LOW);
		digitalWrite(4,HIGH);
        }
		else if(*data=='S')
        {
        digitalWrite(0,LOW);
        digitalWrite(2,LOW);		
        digitalWrite(3,LOW);
		digitalWrite(4,LOW);	
        }
    }
}
    // close connection
    close(clientsocket);
    close(serversocket);
    return 0;
}
