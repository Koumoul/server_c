#include "checking_head.h"

int ft_checking_request(char* request) {

	if (ft_check_method(request)) { 
		printf("FAIL!!!\n");
		return EXIT_FAILURE ;
	}

	if (ft_check_header(request)) {
		printf("FAIL!!!\n");
		return EXIT_FAILURE;
	}

	printf("SUCCESS!!!\n");
	return EXIT_SUCCESS;
}


int ft_check_method(char* request) {
	int		cursor = 0;
	char	buffer[20];
	
	bzero(buffer, 20);
	cursor = ft_lenuntil(request, " ");
	if (cursor < 20) strncpy(buffer, request, cursor);
	else return EXIT_FAILURE;

	if (strcmp(buffer, "GET") == 0);
	else {
		printf("CHECKING: this server doesn't handle mehtod %s\n", buffer);
		return EXIT_FAILURE;
	}

	printf("buf : %s\n", buffer);

	return EXIT_SUCCESS;
}

int ft_check_target(char* request) {
	
	return 0;
}

int ft_check_httpver(char* request) {

	return 0;
}

int ft_check_header(char* request) {
	int		cursor		= 0;
	int		nbrheader	= 0;
	int		lenheader	= 0;
	int		i			= 0;
	char*	header;

	header = request;

	cursor = ft_lenuntil(request, "\r\n");
	header += cursor + 2;

	lenheader = ft_lenuntil(header, "\r\n\r\n");
	if (lenheader > 1000) return EXIT_FAILURE;
	
	nbrheader = ft_nbrfield(header);
	printf("nbr head: %d\n", nbrheader);
	while (i < nbrheader) {
		
	}
	return EXIT_SUCCESS;
};

