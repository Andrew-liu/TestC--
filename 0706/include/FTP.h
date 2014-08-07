/*************************************************************************
	> File Name: FTP.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 06 Jul 2014 12:36:11 AM HKT
 ************************************************************************/
#ifndef _FTP
#define _FTP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define MSG_SIZE 8188
#define MSG_LEN (8192 - MSG_SIZE)

typedef struct tag
{
	int len;
	char buf[MSG_SIZE];
}MSG;
//server
int  tcp_init(const char*ip,int port);
int  tcp_accept(int fd_server);
void handle_request(int command_socket);
int  get_command(char *str,char (*file_path)[32],char *com_name);
void delete_mid_space(char *str);
void handle_gets(int fd_client,char *filename);
void handle_puts(int fd_client,char *filename);
void recy_source(int num);
void consle_str(char *str);
void handle_cd(int fd_client,char *path);
void send_consle(int fd_client);
//client
int  tcp_connect(const char *ip,int port);
void handle_download(int fd_client,int file_num,char (*file_name)[32]);
void handle_upload(int fd_client,int file_num,char (*file_name)[32]);
void handle_ccd(int fd_client,char *consle);
void show_fun(int fd_client);
//






#endif
