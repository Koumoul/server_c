#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int ft_lenuntil(char* str, char* pattern) {
	int i, j;

	i = 0;
	j = 0;
	while (str[i]) {
		if (pattern[j] == str[i]) {
			while (pattern[j] == str[i+j]) {
				j++;
			}
			if (j == strlen(pattern)) return i;
		}
		j = 0;
		i++;
	}
	return 0;
}

char* ft_cleanbuffer(char* dest, char* src) {
	int len = 0;
	
	len = ft_lenuntil(src, "\r\n\r\n");
	dest = strncpy(dest, src, len);
	return dest;
}

int ft_hash(char* key) {
	int i = 0;
	int sum = 0;
	
	i = 0;
	while (key[i]) {
		sum += key[i];
		i++;
	}
	sum += 1000;
	sum %= 1000;
	return sum;
}

void myprint(int c)
{
    if (isprint(c))
		putchar(c); // just print printable characters
	else if (c == '\n')
		printf("\\n"); // display newline as \n
	else if (c == '\r')
		printf("\\r");
	else
		printf("%02x", c); // print everything else as a number
}

char* ft_extension(char* extension, char* file_name) {
	int len;
	int tronc;


	len		= strlen(file_name);
	tronc	= ft_lenuntil(file_name, ".");
	strncpy(extension, file_name + tronc + 1, len - tronc + 1);
	return extension;
}

char* ftobuff(char* buffer,char* file) {
	char	line[10000]	= "";
	FILE*	fp			= NULL;

	printf("looking for %s\n", file);
	fp = fopen(file, "r");

	if (fp != NULL) {
		while (fgets(line, 10000, fp) != NULL) {
			strncat(buffer, line, strlen(line));
		}
	}
	else
		printf("the file doesn't exist to me\n");
	return buffer;
}

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
