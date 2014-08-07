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
#define MSG_USR 1
#define MSG_GRP 2
#define MSG_ON  3
#define MSG_OFF 4
#define MSG_SIZE 1024
#define MSG_LEN (8192 - MSG_SIZE)
int udp_init(const char *ip,int port);

int is_ip(char *ip);//0 is right

typedef struct sockaddr_in SA;
typedef struct tagmsg
{
	int s_type;
	int s_len;
	SA s_addr;
	char s_msg[MSG_SIZE];
}MSG;

typedef struct tagusr
{
	SA s_addr;
	struct tagusr *next;
}USR,*pUSR;


void LinkList_init(pUSR *p);
void msg_on(pUSR *p,SA *addr);
void msg_off( pUSR *p,SA *addr );
void msg_usr(int fd_server,MSG *msg);
void msg_grp(pUSR p,int fd_server,MSG *msg);
void signal_chat(int fd_client,MSG *msg,SA *addr);
void muti_chat(int fd_client,MSG *msg_grp,SA *addr);
#endif
