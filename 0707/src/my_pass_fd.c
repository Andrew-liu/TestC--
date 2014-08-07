/*************************************************************************
	> File Name: my_pass_fd.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 08 Jul 2014 09:18:51 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

void recy_source(int num)
{
	wait();
	exit(EXIT_SUCCESS);
}
void send_fd(int sockfd,int send_fd );
void recv_fd(int sockfd,int *fd);
int main(int argc,char *argv[])
{
	pid_t pid;
	int fd[2];
	if( -1 == socketpair(AF_LOCAL,SOCK_STREAM,0,fd) )
		ERR_EXIT("socketpair error");
	pid = fork();
	if( pid > 0 )
	{
		close(fd[0]);
		signal(SIGCHLD,recy_source);
		int fd_file = open(argv[1],O_RDONLY,0666);
//		printf("OKKK\n");
		if( -1 == fd_file )
			ERR_EXIT("open error");
		send_fd(fd[1],fd_file);
		printf("OKKK\n");
	}
	else
	{
		printf("AAA\n");
		int fd_file ;
		printf("BBBB\n");
		recv_fd(fd[0],&fd_file);
		printf("CCC\n");
		char recv_buf[1024];
		FILE *fp_rd = fdopen(fd_file,"r");
		if( NULL == fp_rd )
			ERR_EXIT("fdopen error");
		printf("OK\n");
		while(bzero(recv_buf,1024),fgets(recv_buf,1024,fp_rd) != NULL )
		{
			puts(recv_buf);
		}
	}
//	else
//		ERR_EXIT("fork error");
}
void send_fd(int sockfd,int send_fd )
{
	//define buff
	char send_buf[1024];
	bzero(send_buf,1024);
	//init msghdr
	struct msghdr send_msgh;
	bzero(&send_msgh,sizeof(send_msgh));
	send_msgh.msg_name    = NULL;
	send_msgh.msg_namelen = 0;
	send_msgh.msg_flags   = 0;
	//init struct iovec
	strcpy( send_buf,"hello world\n");
	struct iovec buff[1];
	buff[0].iov_base = send_buf;
	buff[1].iov_len  = strlen(send_buf);
	//
	send_msgh.msg_iov    = buff;
	send_msgh.msg_iovlen = 1;
	//init cmsg use for init control
	struct cmsghdr *control_msg;
	int control_size = CMSG_LEN(sizeof(int));
	control_msg = (struct cmsghdr *)calloc(1,control_size);
	control_msg ->cmsg_len   = control_size;
	control_msg ->cmsg_level = SOL_SOCKET;
	control_msg ->cmsg_type  = SCM_RIGHTS;
	*(int *)CMSG_DATA(control_msg) = send_fd;
	//
	send_msgh.msg_control    = control_msg;
	send_msgh.msg_controllen = control_size;
	//sendmsg
	sendmsg(sockfd,&send_msgh,0);
	printf("end send\n");
}
void recv_fd(int sockfd,int *fd)
{
//	int fd;
	char recv_buf[1024];
	//init msghdr
	struct msghdr recv_msgh;
	bzero(&recv_msgh,sizeof(recv_msgh));
	recv_msgh.msg_name    = NULL;
	recv_msgh.msg_namelen = 0;
	recv_msgh.msg_flags   = 0;
	//init iovec
	struct iovec buff[1];
	buff[0].iov_base = recv_buf;
	buff[0].iov_len = 1024;
	recv_msgh.msg_iov    = buff;
	recv_msgh.msg_iovlen = 1;
	//init cmsg
	struct cmsghdr *control_msg;
	int control_size = CMSG_LEN(sizeof(int));
	control_msg = (struct cmsghdr *)calloc(1,control_size);
	recv_msgh.msg_control    = control_msg;
	recv_msgh.msg_controllen = control_size;
	//
	printf("GGG\n");
	recvmsg(sockfd,&recv_msgh,0);
	printf("rcvv\n");
	*fd = *(int *)CMSG_DATA(control_msg);
	printf("recv_buf%s\n",recv_buf);
	printf("end recv\n");
//	return fd;
}
