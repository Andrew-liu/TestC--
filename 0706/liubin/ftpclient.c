#include "ftpmsg.h"
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("EXE IP PORT!\n");
		exit(-1);
	}
	int fd_client;
	SK sever_addr;
	int total=0;
	MSG msg;
	char buf[1024];
	fd_client=socket(AF_INET,SOCK_STREAM,0);
	if(fd_client==-1)
	{
		perror("socket!");
		exit(-1);
	}
	bzero(&sever_addr,sizeof(SK));
	sever_addr.sin_family=AF_INET;
	sever_addr.sin_port=htons(atoi(argv[2]));
	sever_addr.sin_addr.s_addr=inet_addr(argv[1]);
	if(-1==connect(fd_client,(struct sockaddr*)&sever_addr,sizeof(SK)))
	{
		perror("connect!xxxxx");
		exit(-1);
	}	
	while(memset(&msg,0,sizeof(msg)),printf("%s",TITLE),fgets(msg.s_buf,MSG_SIZE,stdin)!=NULL)
	{
		msg.s_buf[strlen(msg.s_buf)-1]='\0';
		msg.s_len=strlen(msg.s_buf);
		send(fd_client,&msg,msg.s_len+MSG_LEN,0);
		delete_space(msg.s_buf);
		if(strncmp(msg.s_buf,"cd",2)==0)
		{
			return_cd(fd_client);
		}
		else if(strncmp(msg.s_buf,"ls",2)==0)
		{
	//		printf("ok1\n");
			return_ls(fd_client);
		}
		else if(strncmp(msg.s_buf,"rm",2)==0)
		{
			return_rm(fd_client);
		}
		else if(strncmp(msg.s_buf,"puts",4)==0)
		{
			return_puts(fd_client,msg.s_buf);
		}
		else if(strncmp(msg.s_buf,"gets",4)==0)
		{
			return_gets(fd_client,msg.s_buf);
		}
		else
		{
			memset(buf,0,1024);
			recv(fd_client,buf,1024,0);
			printf("%s\n",buf);
			continue;
		}
	}
	return 0;
}
void return_cd(int fd_client)
{
	char buf[1024];
	memset(buf,0,1024);
	recv(fd_client,buf,1024,0);
	printf("%s",buf);
	fflush(stdout);
}
void return_ls(int fd_client)
{
	MSG msg;
	char buf[1024];
	while(1)
	{
	//	printf("ok2\n");
		memset(&msg,0,sizeof(MSG));
		recv(fd_client,&msg,MSG_LEN,0);
		if(msg.s_len>0)
		{
	//		printf("ok3\n");
			recv(fd_client,msg.s_buf,msg.s_len,0);
			printf("%s\n",msg.s_buf);
		}
		else
		{
		//	printf("ok4\n");
			break;
		}
	}
}
void return_rm(int fd_client)
{
	char buf[1024];
	memset(buf,0,1024);
	recv(fd_client,buf,1024,0);
	printf("%s\n",buf);
}
void return_puts(int fd_client,char *str)
{
	int fd_file,read_n,total=0;
	char file[1024];
	MSG msg;
	memset(file,0,1024);
	sscanf(str+5,"%s",file);
	printf("filename:%s\n",file);
	fd_file=open(file,O_RDONLY);
	if(fd_file==-1)
	{
		perror("open file failed!");
		exit(-1);
	}
	while(memset(&msg,0,sizeof(MSG)),(read_n=read(fd_file,msg.s_buf,MSG_SIZE))>0)
	{
		//printf("OK\n");
		msg.s_len=strlen(msg.s_buf);
		if(msg.s_len>0)
		{
		//	printf("ok!\n");
			total += msg.s_len ;
			system("clear");
			printf("dowloading...%.2f kb \n",(double)total/ 1024);
			send(fd_client,&msg,msg.s_len+MSG_LEN,0);
		}
		else
		{
			break;
		}
	}

}
void return_gets(int fd_client,char *str)
{
	int fd_file,total=0;
	char file[1024],buf[2];
	MSG msg;
	memset(file,0,1024);
	sscanf(str+5,"%s",file);
	printf("filename:%s\n",file);
	fd_file=open("getsfile",O_WRONLY|O_CREAT,0666);
	if(fd_file==-1)
	{
		perror("gets open error!");
		exit(-1);
	}
	while(1)
	{
		bzero(buf,2);
		strcpy(buf,"L");
		memset(&msg, 0, sizeof(MSG));
		recv(fd_client,&msg,MSG_LEN, 0);
		total += msg.s_len ;
		system("clear");
		printf("dowloading...%.2f kb \n",(double)total/ 1024);
		if(msg.s_len > 0)
		{
			recv(fd_client,&msg.s_buf,msg.s_len, 0);
			write(fd_file,msg.s_buf,msg.s_len);
			send(fd_client,buf,strlen(buf),0);
		}
		else 
		{
			break ;
		}
	}
	close(fd_file);
}

