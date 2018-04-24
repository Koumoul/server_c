#include "forger_head.h"

char* ft_forge_statusline(char* statusline, s_rqst* rqst) {
    
    char HTTP_version[]     = "HTTP/1.1";
    char status_code[]      = "200";
    char reason_phrase[]    = "OK";

    strncat(statusline, HTTP_version, strlen(HTTP_version));
    strncat(statusline, " ", 1);
    strncat(statusline, status_code, strlen(status_code));
    strncat(statusline, " ", 1);
    strncat(statusline, reason_phrase, strlen(reason_phrase));
    strncat(statusline, " ", 1);
    strncat(statusline, "\r\n", 2);
    
    return statusline;
}

char* ft_forge_header(char* header, s_rqst* rqst) {
	char* content_type;

	content_type = (char*)malloc(sizeof(char) * 100);
	ft_content_type(content_type, rqst);



	strncat(header, content_type, strlen(content_type));

	strncat(header, "\r\n\r\n", 4);
	return header;
}

char* ft_forge_data(char* data, s_rqst* rqst) {
	ftobuff(data, rqst->rqstline->target);
	return data;
}
