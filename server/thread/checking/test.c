#include "checking_head.h"
#include <stdio.h>

int main() {

	int		i;
	char	str[] = "GET /index.html HTTP/1.1\r\nHost: 127.0.0.1:8000\r\nUser-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.12; rv:59.0) Gecko/20100101 Firefox/59.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nCookie: csrftoken=6jnrsig2A0heFBcA80K9o2wu9t6Q3WBYIWCk6UwfNTytLHdHn8Gdcwr6afkqX2ih; sessionid=8mlow885dflktwblkpzzser0iecccu82\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 0\r\n\r\nPffffffdaffffffa2Vffffffff7f";

		i = ft_checking_request(str);
		printf("%d\n",i);



}
