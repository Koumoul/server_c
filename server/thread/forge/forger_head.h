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

typedef struct sockaddr_in sockaddr_in;


int				ft_lenuntil(char* str, char* pattern);
char*			ft_cleanbuffer(char* dest, char* src);
void			myprint(int c);
int				ft_hash(char* key);
char*			ftobuff(char* buffer, char* file);
char*			ft_extension(char* extension, char* file_name);

char*			ft_forge_response(char* response, s_rqst* rqst);
char*			ft_forge_statusline(char* header, s_rqst* rqst);
char*			ft_forge_header(char* header, s_rqst* rqst);
char*			ft_forge_data(char* data, s_rqst* rqst);

char*			ft_content_type(char* content_type, s_rqst* rqst);
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
