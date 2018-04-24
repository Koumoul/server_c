#ifndef __FT_SERVER_H__
#define __FT_SERVER_H__

#ifdef WIN32 /* si vous êtes sous Windows */

#include <winsock2.h> 

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#endif

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_rqst		s_rqst;
typedef struct s_rqstheader s_rqstheader;
typedef struct s_rqstline	s_rqstline;

s_rqst*			ft_parse_request(s_rqst* rqst, char* request);
char*			ft_forge_response(char* response, s_rqst* rqst);

//Homemade  structure
// REQUEST;

struct s_rqst{
	s_rqstline*		rqstline;
	char**			hashtable;
};

struct s_rqstline {
	char method[10];
	char target[100];
	char HTTP_version[10];
};
#endif
