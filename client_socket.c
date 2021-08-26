#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
 
int main(int argc, char *argv[])
{
	struct sockaddr_in server;
	char ip_add[16];
	int fd, numbytes,PORT;
	char buf[2048];
	char buf_mess_send[2048];
	system("clear");
	system("sudo chmod +x welcome.sh bye.sh");
	system("./welcome.sh");
	strcpy(ip_add,argv[1]);
	PORT = atoi(argv[2]);
	if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
		printf("socket() error\n");
		exit(-1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	server.sin_addr.s_addr=inet_addr(ip_add);
	bzero(&(server.sin_zero),8);
	if(connect(fd, (struct sockaddr *)&server,
	sizeof(struct sockaddr))==-1){
		printf("connect() error\n");
		exit(-1);
	}
	printf("\t\t\t--------> Conexion Establecida por [ %s:%d ]<--------\n",ip_add,PORT);
	if ((numbytes=recv(fd,buf,2048,0)) == -1){
		printf("Error en recv() \n");
		exit(-1);
	}
	printf("\n\t\t\t\t[ %s ]\n\n",buf);

	strcpy(buf_mess_send,"https://www.amazon.com/-/es/Nintendo-eShop-Gift-Card/dp/B07ZJ6RY1W?pf_rd_r=G1NRR6W14GAG4K209EFC&pf_rd_p=44af84b0-2bb7-59d3-988f-f593bbf68fea&pd_rd_r=fc96f415-253b-4854-8dc9-2b64dc67bb3b&pd_rd_w=MaV2e&pd_rd_wg=fNmOx&ref_=pd_gw_ri");//CADENA A ENVIAR A SERVIDOR
	int leng_buf_mess_send = strlen(buf_mess_send);
	int size_buf_mess_send = sizeof(buf_mess_send);
	printf("\t--------->//MENSAJE A ENVIAR [ %s ]\n\t\tLongitud: [ %d ]\n\t\tBytes [ %d ]\n",buf_mess_send,leng_buf_mess_send,size_buf_mess_send); 
	send(fd,buf_mess_send,2048,0);

	recv(fd,buf,2048,0);
	printf("----->Mensaje de Servidor: [ %s ]<-----\n",buf);
	printf("--------------------------CONEXION FINALIZADA--------------------------\n");
	close(fd);
	system("./bye.sh");
}