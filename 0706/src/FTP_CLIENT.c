/*************************************************************************
	> File Name: FTP_CLIENT.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 06 Jul 2014 11:05:46 AM HKT
 ************************************************************************/

#include "FTP.h"

int main(int argc,char *argv[])
{
	if( 3 != argc )
	{
		perror("argc error\n");
		exit(-1);
	}
	//init socket
	int fd_client = tcp_connect(argv[1],atoi(argv[2]));
	show_fun(fd_client);
	return 0;
}

void show_fun(int fd_client)
{
	printf("+==========================================+\n");
	printf("| Weclome to my ftp!                       |\n");
	printf("+==========================================+\n");
	printf("| Select function:                         |\n");
	printf("| 1.cd + path                              |\n");
	printf("| 2.upload: command: puts + filename       |\n");
	printf("| 3.download:command:gets + filename       |\n");
	printf("+==========================================+\n");
	char send_buf[1024];
	char file_name[20][32];
	char command[64];
	int len,re_len,file_num =0;
	char consle[64] = "";
	memset(consle,0,1024);
	int consle_len;
	recv(fd_client,&consle_len,sizeof(int),0);
	recv(fd_client,&consle,consle_len,0);
	while(printf("%s "),fflush(stdout),memset(send_buf,0,1024),fgets(send_buf,1024,stdin)!=NULL)
	{	
		if( send_buf[0] == '\n')
			continue;
		send_buf[strlen(send_buf)-1] = '\0';
		len = strlen(send_buf);
		send(fd_client,&len,sizeof(len),0);
		send(fd_client,send_buf,strlen(send_buf),0);
		file_num = get_command(send_buf,file_name,command);
		//
		if( 0 == strncmp(command,"cd",3) )
		{
			handle_ccd(fd_client,consle);

		}else if( 0 == strncmp(command,"ls",3) )
		{
			;

		}else if( 0 == strncmp(command,"gets",5) )
		{
			handle_download(fd_client,file_num,file_name);

		}else if( 0 == strncmp(command,"puts",5) )
		{
			handle_upload(fd_client,file_num,file_name);

		}else if( 0 == strncmp(command,"rm",3) )
		{
			;
		}else if( 0 == strncmp(command,"bye",4) )
		{
			break;
		}
		else
		{
			printf("error command\n");
		}

	}	
}
void handle_ccd(int fd_client,char *consle)
{
	char recv_buf[64];
	int re_len;
	//recv 
	recv(fd_client,&re_len,sizeof(int),0);
	recv(fd_client,recv_buf,re_len,0);
	memset(consle,0,1024);
	strcpy(consle,recv_buf);
}
void handle_download(int fd_client,int file_num,char (*file_name)[32])
{

	//send to server
	char send_buf[1024];
	char newfile[64];
	int  total = 0,index,len;;
	MSG recv_msg;
		//init file
		for( index = 0;index < file_num; ++file_num )
		{
			int total = 0;
			strcpy(newfile,file_name[index]);
			strcat(newfile,".bak");
			int fd_write = open(newfile,O_WRONLY|O_CREAT,0666);
			if( -1 == fd_write )
			{
				perror("open error\n");
				exit(-1);
			}
			//recv data
			while(1)
			{	
				bzero(&recv_msg,sizeof(MSG));
				recv(fd_client,&recv_msg,MSG_LEN,0);
				total += recv_msg.len;
				if( recv_msg.len > 0 )
				{
					printf("downloading...%.2lfkb\n",(double)total/1024);
					recv(fd_client,&recv_msg.buf,recv_msg.len,0);
					write(fd_write,recv_msg.buf,recv_msg.len);
				}
				else
					break;
			}
			close(fd_write);
			printf("KKK\n");
		}
	//	close(fd_client);
}
void handle_upload(int fd_client,int file_num,char (*file_name)[32])
{
	//init file
	char send_buf[1024];
	int len,index;
	int read_n;
	//init msg
	MSG msg,snd_msg;
	memset(&msg,0,sizeof(MSG));
//
	for(index = 0;index < file_num; ++index )
	{
		int fd_file = open(file_name[index],O_RDONLY);
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
	printf("upload success!\n");
}
void handle_lls(int fd_client)
{
	;
}
