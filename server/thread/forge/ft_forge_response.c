#include "forger_head.h"

char* ft_forge_response(char* response, s_rqst* rqst) {
    /*
    char	statusline[]	= "HTTP/1.1 200 OK \r\n";
	char	header[]		= "Content-Type: text/html; charset=ISO-8859-4\r\n\r\n";
    */
	char* statusline	= (char*)malloc(sizeof(char) * 30);
	char* header		= (char*)malloc(sizeof(char) * 300);
	char* data			= (char*)malloc(sizeof(char) * 5000);

	ft_forge_statusline(statusline, rqst);
	ft_forge_header(header, rqst);
	ft_forge_data(data, rqst);

	strncat(response, statusline, strlen(statusline));
	strncat(response, header, strlen(header));
	strncat(response, data, strlen(data));

   return response;
}
