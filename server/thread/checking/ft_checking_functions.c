#include "checking_head.h"

int ft_nbrfield(char* header) {
	int		count	= 0;
	int		len;
	char*	cursor	= NULL;

	cursor = header;

	 while (len != 0) {
		len = ft_lenuntil(cursor, "\r\n");
		if (len != 0) {
			cursor	+= len + 2;
			count	+= 1;
		}
	}

	return count;
}
