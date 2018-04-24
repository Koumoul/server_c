#include "forger_head.h"

char* ft_content_type(char* content_type, s_rqst* rqst) {
	char*	extension;
	char	type[20];

	extension = (char*)malloc(sizeof(char) * 5);

	content_type = strncpy(content_type, "Content-type: ", 14);

	extension = ft_extension(extension, rqst->rqstline->target);

	if (!strcmp(extension, "html")) strncat(content_type, "text/html\r\n", 11);
	if (!strcmp(extension, "jpg")) strncat(content_type, "image/jpg\r\n", 11);
	if (!strcmp(extension, "css")) strncat(content_type, "text/css\r\n", 10);
	if (!strcmp(extension, "jpeg")) strncat(content_type, "image/jpeg\r\n", 12);

	printf("content_type: |%s|\n", content_type);
	return content_type;
}

char* ft_content_lenght(char* content_lenght, s_rqst* rqst) {

	return content_lenght;
};
