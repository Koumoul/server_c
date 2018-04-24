#include "server_head.h"

int main(int ac, char** av) {
	int				serv_socket, client_socket, bind_ret;
	int				port = atoi(av[1]);
	sockaddr_in		serv_addr, client_addr;
	pthread_t		tid;
	socklen_t		addrlen = sizeof(client_addr);

//----------check the args passed in commande line------------------------------
	if (ac != 2) {
		fprintf(stderr, "Usage: %s port...\n", av[0]);
		exit(EXIT_FAILURE);}

//Create socket
	serv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_socket < 0) {printf("socket issue\n");exit(EXIT_FAILURE);}

// Binding address to a port
	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_port			= htons(port);
	serv_addr.sin_addr.s_addr	= INADDR_ANY;

	bind_ret = bind(serv_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if (bind_ret < 0) {printf("binding issue\n");exit(EXIT_FAILURE);}

//Listening to connection indefenitly (5 max at same time)
	listen(serv_socket, 5);
	while (1) {
		printf("\nWaiting for new connection...\n");

		//Creat new socket for the client
		client_socket = accept(serv_socket, (struct sockaddr*)&client_addr, &addrlen);
		printf("connection from host %s, port %d\n",
				inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		pthread_create(&tid, NULL, ft_thread, &client_socket);

	}
	return 0;
}
