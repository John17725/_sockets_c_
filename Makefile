all:
	gcc -g -c -Wall server_socket.c -o server_socket.o
	gcc -g -c -Wall client_socket.c -o client_socket.o
	gcc -g -Wall server_socket.o  -o server
	gcc -g -Wall client_socket.o  -o client
	clear
	cat README.md
clean:
	rm *.o
	rm server
	rm client
