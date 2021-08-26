#include "server_socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	strcpy(buf_mess_send2,"Mensaje Recibido");//MENSAJE A ENVIAR A CLIENTE
	strcpy(ip_add,argv[1]);
	PORT = atoi(argv[2]);
	system("sudo chmod +x welcome.sh bye.sh");
	system("./welcome.sh");
	printf("\t\t\tINFO DEL SERVIDOR\n\tIP [ %s:%d ]\n",ip_add,PORT);
	server.sin_family= AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr=inet_addr(ip_add);
	bzero(&(server.sin_zero),8);
	if (( fd=socket(AF_INET,SOCK_STREAM,0) )<0)
	{
		perror("Error de apertura de socket");
		exit(-1);
	}
	if(bind(fd,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1)
	{
		printf("Error en bind() \n");
		exit(-1);
	}
	if(listen(fd,5) == -1) 
	{
		printf("Error en listen()\n");
		exit(-1);
	}
	printf("\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*SERVIDOR ON-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\t\t\t-*-*-*-*-*-*-*-*-*EN ESPERA DE CONEXION-*-*-*-*-*-*-*-*-*\n");
	lengt_client= sizeof(struct sockaddr_in);
	if ((fd2 = accept(fd,(struct sockaddr *)&client,&lengt_client))==-1) {
		printf("error en accept()\n");
		exit(-1);
	}

	printf("\t\t\t-*-*-*-*-*-*-*-*-*-*CLIENTE CONECTADO-*-*-*-*-*-*-*-*-*-*-*\n");
	strcpy(buf_mess_send,"_-_-_-_-_-CONECTADO CON SERVIDOR_-_-_-_-_-");//MENSAJE DE CONFIRMACION DE CONEXION CON SERVER PARA CLIENTE
	send(fd2, buf_mess_send, 2048,0);
 	

	//*------------------------------------------------------------------------------------*
	printf("*-------------------MENSAJE DE CLIENTE-----------------------*\n");
	recv(fd2,buf_mess_recib,2048,0);
	int leng_buf_mess_recib = strlen(buf_mess_recib);
	int size_buf_mess_recib = sizeof(buf_mess_recib);
	printf("\tMensaje del Cliente: -------------->[ %s ]\n\t\tLongitud [ %d ]\n\t\tBytes [ %d ]\n",buf_mess_recib,leng_buf_mess_recib,size_buf_mess_recib);



	printf("*-------------------MENSAJE A ENVIAR A CLIENTE-----------------------*\n");
	int leng_buf_mess_send2 = strlen(buf_mess_send2);
	int size = sizeof(buf_mess_send2);
	printf("\t\t[ %s ]\n",buf_mess_send2);
	printf("\tTiene un tamano de [ %d ] y pesa [ %d ] bytes\n",leng_buf_mess_send2, size);
	system("sleep 3s");
	send(fd2,buf_mess_send2,2048,0);
	printf("*--------------------------MENSAJE ENVIADO--------------------------*\n");
	printf("*---------------------COMUNICACION FINALIZADA-----------------------*\n");
	//*------------------------------------------------------------------------------------*
	close(fd2);
	close(fd);
	system("./bye.sh");
return 0;
}