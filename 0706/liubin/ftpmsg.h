#ifndef __MSG_H__
#define __MSG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <pthread.h>
#include <dirent.h>
#define MSG_SIZE 8188 
#define MSG_LEN  (8192 - MSG_SIZE)
#define TITLE  "[liubin@In Order To Mother's Smile]$"
typedef struct sockaddr_in SK;
typedef struct tag
{
	int s_len ;
	char s_buf[MSG_SIZE];
} MSG;

void delete_space(char* src);
int listenfd_init(char *ip,char *port);
int handle_request(int fd_client);
void cd_func(int fd_client,char *str);
void ls_func(int fd_client,char *str);
void puts_func(int fd_client,char *str);
void gets_func(int fd_client,char *str);
void rm_func(int fd_client,char *str);
void mode_to_str(mode_t md,char *str);

void return_rm(int fd_client);
void return_cd(int fd_client);
void return_ls(int fd_client);
void return_puts(int fd_client,char *str);
void return_gets(int fd_client,char *str);
void sig_handle(int num);//用于回收僵尸资源
#endif
