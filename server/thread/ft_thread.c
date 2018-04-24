#include "thread_head.h"

void *ft_thread(void* socket) {
    int*			client_socket;
	char			buffer[5000];
    char*			request		= (char*)malloc(sizeof(char) * 3000);
	char*			response	= (char*)malloc(sizeof(char) * 6000);
    s_rqst*         rqst        = (s_rqst*)malloc(sizeof(s_rqst));
	int				i			= 0;

	rqst->rqstline			= (s_rqstline*)malloc(sizeof(s_rqstline));
	rqst->hashtable			= (char**)malloc(sizeof(char) * 1000);
	while (i < 1000) {
		rqst->hashtable[i]	= (char*)malloc(sizeof(char) * 1000);
		i++;
	}
	//char hi[] ="200 HTTP/1.1 OK\r\nContent-Type: text/html; charset=ISO-8859-4\r\n\r\n";

	client_socket = (int*)socket;
	//bzero(riqst->rqstline->target, 5);
	recv(*client_socket, buffer, sizeof(buffer), 0);
	//request = ft_cleanbuffer(request, buffer);
	printf("client request:\n%s\n", buffer);

    ft_parse_request(rqst, buffer);

	ft_forge_response(response, rqst);
	printf("\nresponse:\n%s\n", response);
	send(*client_socket, response, strlen(response), 0);
	close(*client_socket);
	printf("----------connection closed----------\n");
	pthread_exit(NULL);
}
