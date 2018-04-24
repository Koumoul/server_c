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


typedef struct sockaddr_in sockaddr_in;

void*			ft_thread(void* socket);


#endif
