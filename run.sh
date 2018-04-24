#!/bin/zsh

gcc -c server/**/*.c
ar rc libserver.a *.o
rm -f *.o
gcc server/main/tcp_server.c -L. -lserver -o server.exe


