#include "parser_head.h"

s_rqst* ft_parse_request(s_rqst* rqst, char* request) {
	sockaddr_in serv_addr, client_addr;

	rqst->rqstline	= ft_parse_rqstline(rqst->rqstline, request);
	ft_parse_rqstheader(rqst->hashtable, request);

	return rqst;
}
