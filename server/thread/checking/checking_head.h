#ifndef __CHECKING_HEAD__
#define __CHECKING_HEAD__

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

int ft_lenuntil(char* str, char* pattern);
int ft_check_method(char* request);
int ft_checking_request(char* request);
int ft_check_header(char* request);
int ft_nbrfield(char* request);
#endif
