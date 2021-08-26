#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define LENG_BUF 2048

	struct sockaddr_in server;
	struct sockaddr_in client;
	
	int fd,fd2,lengt_client,numbytes, PORT;
	char ip_add[16];
	char buf_mess_recib[LENG_BUF]; //Para recibir mensaje
	char buf_mess_send2[LENG_BUF]; //Para enviar mensaje
	char buf_mess_send[LENG_BUF]; //Para enviar mensaje
