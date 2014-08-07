#include "ftpmsg.h"
//去命令空格
void delete_space(char* src)
{
	int i , j ;
	for(i = -1, j = 0; j < strlen(src); j ++ )
	{
		if(src[j]!=' ') //不是空格
		{ 

			src[++i] = src[j];
		}
		else//是空格
		{
			if(i != -1 && src[i]!=' ') //去空格
			{
				src[++i] = ' ' ;
			}
		}
	}
	for(;i>=0 ; i--)//最后有空格的时候
	{
		if(src[i]!=' ')
		{
			break ;
		}
	}
	src[++i] = '\0' ;
}
//void download(char *str) //文件名
//初始化TCPsocket
int listenfd_init(char *ip,char *port)
{
	int fd_sever;
	int reuse = 1;
	struct sockaddr_in sever_addr;
	//int addrlen = sizeof(client_addr);
	//MSG msg,snd_msg ;
	//int read_n ;
	if((fd_sever = socket(AF_INET,SOCK_STREAM, 0) ) == -1)
	{
		perror("socket");
		exit(-1);
	}
	if(0 != setsockopt(fd_sever,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)))
	{
		perror("setsockopt");
		close(fd_sever);
		exit(-1);
	}
	memset(&sever_addr, 0 , sizeof(sever_addr)) ;
	sever_addr.sin_family = AF_INET ;
	sever_addr.sin_port = htons(atoi(port));
	sever_addr.sin_addr.s_addr = inet_addr(ip);
	if(-1 == bind(fd_sever,(struct sockaddr*)&sever_addr,sizeof(sever_addr)))
	{
		perror("bind");
		close(fd_sever);
		exit(-1);
	}
	if(-1 == listen(fd_sever,5))
	{
		perror("listen");
		close(fd_sever);
	}
	return fd_sever;
}
int handle_request(int fd_client)
{
	//int fd_file ;
	MSG msg;
	char *error_buf;
	
	while(memset(&msg,0, sizeof(msg)),recv(fd_client,&msg.s_len, MSG_LEN , 0),recv(fd_client,&msg.s_buf,msg.s_len,0))
	{
		printf("recv msg :%s \n", msg.s_buf);
		delete_space(msg.s_buf);
		if(strncmp(msg.s_buf,"cd",2)==0)
		{
			printf("ok1");
			cd_func(fd_client,msg.s_buf);
		}
		else if(strncmp(msg.s_buf,"ls",2)==0)
		{
			ls_func(fd_client,msg.s_buf);
		}
		else if(strncmp(msg.s_buf,"rm",1)==0)
		{
			rm_func(fd_client,msg.s_buf);
		}
		else if(strncmp(msg.s_buf,"puts",4)==0)
		{
			puts_func(fd_client,msg.s_buf);
		}
		else if(strncmp(msg.s_buf,"gets",4)==0)
		{
			gets_func(fd_client,msg.s_buf);
		}
		else
		{
			error_buf="No Such Command!";
			send(fd_client,error_buf,strlen(error_buf),0);
			continue;
		}
	}
	close(fd_client);

}
void cd_func(int fd_client,char *str)
{
	char buf[1024];
	char path[1024];
	memset(buf,0,1024);
	memset(path,0,1024);
	sscanf(str+3,"%s",buf);
	printf("%s\n",buf);
	if(chdir(buf)==-1)//改变目录
	{
		getcwd(path,1024);
		strcat(path,"\n\0");
		send(fd_client,path,strlen(path),0);
	}
	else
	{
		getcwd(path,1024);
//		path[strlen(path)]='\n';
		strcat(path,"\n\0");
		send(fd_client,path,strlen(path),0);
	}
}
void ls_func(int fd_client,char *str)
{
	DIR *Pdir;
	struct dirent *myent;
	struct stat mystat ;
	 char str_mode[2];
//	char buf[1024];
//	memset(buf,0,1024);
	MSG msg;
	Pdir=opendir(".");
	if(Pdir==NULL)
	{
		perror("opendir!");
	}
	while((myent=readdir(Pdir))!=NULL)
	{
		stat(myent ->d_name, &mystat);
//		printf("name=%s\t\tsize=%d\n",myent->d_name,mystat.st_size);
		memset(str_mode,0,2);
		mode_to_str(mystat.st_mode,str_mode);
		memset(&msg,0,sizeof(MSG));
		sprintf(msg.s_buf,"%-3s%-20s\t\t%-10d",str_mode,myent->d_name,mystat.st_size);
		printf("%s\n",msg.s_buf);
		msg.s_len=strlen(msg.s_buf);
		send(fd_client,&msg,msg.s_len+MSG_LEN,0);
	}
	memset(&msg,0,sizeof(MSG));
	msg.s_len=0;
	send(fd_client,&msg,msg.s_len+MSG_LEN,0);

}
void mode_to_str(mode_t md,char *str)
{
	strcpy(str,"-");
	if(S_ISDIR(md))
	{
		str[0]='d';
	}
}
void rm_func(int fd_client,char *str)
{
	char buf1[1024];
	char buf2[1024];
	memset(buf1,0,1024);
	memset(buf2,0,1024);
	sscanf(str+3,"%s",buf1);
	strcpy(buf2,"rm -f ");
	strcat(buf2,buf1);
	printf("%s\n",buf2);
	system(buf2);
	memset(buf2,0,1024);
	strcpy(buf2,"Delete successful!");
	send(fd_client,buf2,strlen(buf2),0);
}
void puts_func(int fd_client,char *str)
{
	int fd_file;
	char file[1024];
	MSG msg;
	memset(file,0,1024);
	sscanf(str+5,"%s",file);
	printf("filename:%s\n",file);
	fd_file=open("copyfile",O_WRONLY|O_CREAT,0666);
	if(fd_file==-1)
	{
		perror("open failed!\n");
	}
		while(1)
		{
			memset(&msg,0,sizeof(MSG));
			recv(fd_client,&msg,MSG_LEN,0);
			if(msg.s_len>0)
			{
				recv(fd_client,&msg.s_buf,msg.s_len,0);
				write(fd_file,msg.s_buf,msg.s_len);
			}
			else
			{
				break;
			}
		}

	}
void gets_func(int fd_client,char *str)//客户端下载功能
{
	char file[1024];
	MSG msg;
	char buf[2];
	int fd_file,read_n;
	memset(file,0,1024);
	sscanf(str+5,"%s",file);//获取服务器文件名
	printf("loadname:%s\n",file);
	fd_file=open(file,O_RDONLY);
	if(fd_file==-1)
	{
		perror("open file failed!");
	}
	while(bzero(buf,2),memset(&msg,0,sizeof(MSG)),(read_n=read(fd_file,msg.s_buf,MSG_SIZE))>0)
	{
		msg.s_len=strlen(msg.s_buf);
		if(msg.s_len>0)
		{
			send(fd_client,&msg,msg.s_len+MSG_LEN,0);
			if(recv(fd_client,buf,2,0)==2)
				continue;
		}
		else
		{
			break;
		}
	}
	bzero(&msg,sizeof(MSG));
	msg.s_len=0;
	send(fd_client,&msg,msg.s_len+MSG_LEN,0);

}
void sig_handle(int num)//用于回收僵尸资源
	{
	while(waitpid(-1,NULL,WNOHANG)>0);
}
