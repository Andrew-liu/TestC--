/*************************************************************************
	> File Name: UDP_socket.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Fri 04 Jul 2014 09:49:01 AM HKT
 ************************************************************************/
#ifndef _udp
#define _udp
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
int udp_init(const char *ip,int port);

int is_ip(char *ip);//0 is right
#endif
