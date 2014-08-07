/*************************************************************************
	> File Name: FTP_SERVER.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 06 Jul 2014 12:35:26 AM HKT
 ************************************************************************/

#include "FTP.h"

void recy_source(int num)
{
	while(	waitpid(-1,NULL,WNOHANG ) );
}

int main(int argc,char *argv[])
{
	if ( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	int fd_socket = tcp_init(argv[1],atoi(argv[2]));
	int command_socket ;
	while(1)
	{
		int command_socket = tcp_accept(fd_socket);
		if( 0 == fork() )
		{
			send_consle(command_socket);
			handle_request(command_socket);
		}
		else
		{
			signal(SIGCHLD,recy_source);
			signal(SIGINT,recy_source);
		}
	}
}



void handle_request(int command_socket)
{
	char file_path[20][32];
	char command[32];
	int file_num;
	int len = 0;
	//init message
	MSG recv_msg;
	//recv command
	char recv_buf[1024];
	while(1)
	{
		recv(command_socket,&len,sizeof(len),0);
		recv(command_socket,recv_buf,len,0);
		//get command
		file_num = get_command(recv_buf,file_path,command);
		printf("command =%s\n",command);
		printf("file_path=%s\n",file_path[0]);
		printf("file num =%d\n",file_num);
		//handle
		if( 0 == strncmp(command,"cd",3) )
		{
			handle_cd(command_socket,file_path[0]);

		}else if( 0 == strncmp(command,"ls",2) )
		{
		//	handle_cd(command_socket);
	
		}else if( 0 == strncmp(command,"rm",2) )
		{
	
		}else if( 0 == strncmp(command,"gets",5) )
		{
			printf("OK1\n");
			int i;
			for( i =0 ;i < file_num;++i)
			{
				bzero(&recv_msg,sizeof(MSG));
				recv_msg.len = strlen(file_path[i]);
				strcpy(recv_msg.buf,file_path[i]);
				handle_gets(command_socket,recv_msg.buf);
			}
		}else if( 0 == strncmp(command,"puts",5) )
		{
			printf("OK2\n");
			int i;
			for( i =0; i < file_num;++i)
			{
				bzero(&recv_msg,sizeof(MSG));
				recv_msg.len = strlen(file_path[i]);
				strcpy(recv_msg.buf,file_path[i]);
				handle_puts(command_socket,recv_msg.buf);
			}
		}else if( 0 == strncmp(command,"bye",4) )
		{
			break;
		}
	}
}


void handle_gets(int fd_client,char *filename)
{
	//init msg
	MSG msg,snd_msg;
	bzero(&msg,sizeof(MSG));
	int read_n;
	int fd_file = open(filename,O_RDONLY);
	if( -1 == fd_file )
	{
		perror("open error\n");
		exit(-1);
	}
	while( bzero(&snd_msg,sizeof(MSG)),( read_n = read(fd_file,snd_msg.buf,MSG_SIZE))>0 )
	{
		snd_msg.len = read_n;
		send(fd_client,&snd_msg,snd_msg.len+MSG_LEN,0);
	}
	snd_msg.len = 0;
	send(fd_client,&snd_msg,snd_msg.len+MSG_LEN,0);
	close(fd_file);	
}

void handle_puts(int fd_client,char *filename)
{
//	send_consle(fd_client);
	//init msg
	MSG msg,recv_msg;
	char newfile[64];
	bzero(&msg,sizeof(MSG));
	int total = 0;

	strcpy(newfile,filename);
	strcat(newfile,".from_Client");
	int fd_file = open(newfile,O_WRONLY|O_CREAT,0666);
	if( -1 == fd_file )
	{
		perror("open error\n");
		exit(-1);
	}
	while(1)
	{	
		bzero(&recv_msg,sizeof(MSG));
		recv(fd_client,&recv_msg,MSG_LEN,0);
		total += recv_msg.len;
		if( recv_msg.len > 0 )
			{
				printf("upload..%.2lfkb\n",(double)total/1024);
				recv(fd_client,&recv_msg.buf,recv_msg.len,0);
				write(fd_file,recv_msg.buf,recv_msg.len);
			}
			else
				break;
	}
	close(fd_file);
	printf("SBB\n");
}
void handle_cd(int fd_client,char *path)
{
	if( -1 == chdir(path) )
	{
		perror("cd error\n");
		exit(-1);
	}
	send_consle(fd_client);
}


void send_consle(int fd_client)
{	
	char consle[64] = "";
	int len;
	consle_str(consle);
	printf("consle = %s\n",consle_str);
	len = strlen(consle);
	send(fd_client,&len,sizeof(len),0);
	send(fd_client,consle,strlen(consle),0);
}
