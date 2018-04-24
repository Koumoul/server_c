#include "parser_head.h"

s_rqstline* ft_parse_rqstline(s_rqstline* rqstline, char* request) { 
	int		len;
	char*	strline;
	
	bzero(rqstline->target, sizeof(rqstline->target));

	strncpy(rqstline->target, "content/", 8);
	len = ft_lenuntil(request, "\r\n");
	strline = (char*)malloc(sizeof(char) * (len+1));
	strncpy(strline, request, len);
	
	len = ft_lenuntil(strline, " ");
	strncpy(rqstline->method, strline, len);
	strline += len + 2;
	
	len = ft_lenuntil(strline, " ");
	strncat(rqstline->target, strline, len);
	strline = strline + len + 1;

	printf("file: %s\n", rqstline->target);

	strncpy(rqstline->HTTP_version, strline, 8);
	
	return rqstline;
}

char** ft_parse_rqstheader(char** hashtable, char* request) {
	char*	requestheader;
	char	field[600];
	char	field_name[100];
	char	field_value[500];
	int		hlen, flen, fnlen, fvlen, len, nbrfield;
	int i = 0;

	len = ft_lenuntil(request, "\r\n");
	requestheader = request + len + 2;
	
	hlen = ft_lenuntil(requestheader, "\r\n\r\n");

	nbrfield = ft_nbrfield(requestheader);


	while ( i < nbrfield && i < 50)
		{
		flen = ft_lenuntil(requestheader, "\r\n");
		strncpy(field, requestheader, len);
		field[len] = '\0';

		fnlen = ft_lenuntil(requestheader, ":");
		strncpy(field_name, requestheader, fnlen);
		field_name[fnlen] = '\0';

		requestheader += fnlen + 2;
		fvlen = ft_lenuntil(requestheader, "\r\n");
		strncpy(field_value, requestheader, fvlen);
		field_value[fvlen] = '\0';

		requestheader += fvlen + 2;
		strncat(hashtable[ft_hash(field_name)], field_value, strlen(field_value));
		printf(" in ft_parsing_functions:: field n: %d // field_name |%s| ; field_value |%s|\n", i, field_name, field_value);
		i++;
	}
    return hashtable;
}
