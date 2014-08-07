/*************************************************************************
	> File Name: tcp_process_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 07 Jul 2014 08:12:09 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <fcntl.h>
#include <signal.h>


//创建进程，父进程负责将描述符发给儿子,儿子接受描述符后直接就能读，不用再打开
//同一时刻多个子进程退出的不能用wait，用waitpid
//
void recy_source(int num)
{
	wait();
	exit(1);
}

void send_describe(int sockfd,int fd_to_send);
void recv_describe(int sockfd,int *fd_to_recv);

void main(int argc,char *argv[])
{
	//int fd_file;
	pid_t pid;
	int fd[2];
	socketpair(AF_LOCAL,SOCK_STREAM,0,fd);
	pid = fork();
	if( pid >0 )//fds[1]
	{
		close(fd[0]);
		signal(SIGCHLD,recy_source);
		int fd_file = open(argv[1],O_RDONLY);
		send_describe(fd[1],fd_file);

	}
	else//fds[0]
	{
		close(fd[1]);
		char recv_buf[1024];
		int fd_file;
		recv_describe(fd[0],&fd_file);
		FILE *fp = fdopen(fd_file,"r");
		if( NULL == fp )
		{
			perror("open error");
			exit(-1);
		}
		while(bzero(recv_buf,1024),fgets(recv_buf,1024,fp)!=NULL)
		{
			puts(recv_buf);
		}
		fclose(fp);
	}
}

void send_describe(int sockfd,int fd_to_send)
{
	char buf[32] = "nihao";
	struct msghdr send_msgh;
	bzero(&send_msgh,sizeof(send_msgh));

	/*input message
	 * 1.msg_name,msg_namelen可以置空，不关心
	 * 2.struct iovec 缓冲区数组，用于存储多个缓冲区
	 * 3.control控制信息，辅助作用 用cmsghdr这个结构体存
	 * 4.用CMSG_DATA传地址
	 */
	send_msgh.msg_name    = NULL;
	send_msgh.msg_namelen = 0;
	send_msgh.msg_flags   = 0;
	//init iovec
	struct iovec bufs[1];
	bufs[0].iov_base = buf;
	bufs[0].iov_len  = strlen(buf);
	send_msgh.msg_iov    = bufs;
	send_msgh.msg_iovlen = 1;
	//init msg_control
	struct cmsghdr *pcmsg;
	int cmsglen = CMSG_LEN(sizeof(int));
	pcmsg = (struct cmsghdr *)calloc(1,cmsglen);
	pcmsg->cmsg_len   = cmsglen;
	pcmsg->cmsg_level = SOL_SOCKET;
	pcmsg->cmsg_type  = SCM_RIGHTS;
	*(int *)CMSG_DATA(pcmsg) = fd_to_send;//通过)这个函数获得传输数据的地址
	//init msg_control
	send_msgh.msg_control = pcmsg;
	send_msgh.msg_controllen   = cmsglen;
	sendmsg(sockfd,&send_msgh,0);
}
void recv_describe(int sockfd,int *fd_to_recv)
{
	char recv_buf[32] = "";
	//init struct msghdr
	struct msghdr recv_msgh;
	bzero(&recv_msgh,sizeof(recv_msgh));
	//
	struct cmsghdr *pcmsg;
	int cmsglen = CMSG_LEN(sizeof(int));
	pcmsg = (struct cmsghdr *)calloc(1,cmsglen);

	//init struct iovec,use for recv buf data
	struct iovec bufs[1];
	bufs[0].iov_base = recv_buf;
//	bufs[0].iov_len  = strlen(recv_buf);
	bufs[0].iov_len  = 32;

	recv_msgh.msg_iov = bufs;
	recv_msgh.msg_iovlen  = 1;
	recv_msgh.msg_control = pcmsg;
	recv_msgh.msg_controllen = cmsglen;

	//
	recvmsg(sockfd,&recv_msgh,0);

	printf("From parent buf %s\n",recv_buf);
	*fd_to_recv = *(int *)CMSG_DATA(pcmsg);//改值要传指针或者引用了
	
}
