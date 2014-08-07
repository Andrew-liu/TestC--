/*************************************************************************
	> File Name: tcp_process_pool.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 07 Jul 2014 08:12:09 PM HKT
 ************************************************************************/

#include "tcp_process_pool.h"

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
	printf("send end\n");
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
	printf("PPP\n");
	recvmsg(sockfd,&recv_msgh,0);
	printf("FFFFF\n");
	printf("From parent buf %s\n",recv_buf);
	*fd_to_recv = *(int *)CMSG_DATA(pcmsg);//改值要传指针或者引用了
	
}
