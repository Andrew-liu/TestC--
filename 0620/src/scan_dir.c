/*************************************************************************
	> File Name: scan_dir.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 11:21:03 PM PDT
 ************************************************************************/


#include "file.h"

void scan_dir(const char *str)
{
	struct dirent *dirinfo;
	struct stat statbuf;
	DIR *mydir = opendir(str);
	char mode_u[10];
	char mode_g[10];
	char mode_o[10];
	char newpth[100];
	char *ptm;
/*	if( NULL == mydir)
	{
		perror("open fail\n");
		exit(-1);
	}
	strcpy(nd_name,str);*/
//	chdir(str);
	strcpy(newpth,str);
	strcat(newpth,"/");
	while( (dirinfo = readdir(mydir))!= NULL)
	{
	//	strcat(nd_name,"/");
		if( strncmp(dirinfo->d_name,".",1) == 0 || strncmp(dirinfo->d_name,"..",2) == 0)
		{
			continue;
		}
		stat(strcat(newpth,dirinfo->d_name),&statbuf);
		if( S_ISDIR(statbuf.st_mode) )//目录
		{
			if(S_IRUSR & statbuf.st_mode )//judge usr
				mode_u[0]='r';
			else
				mode_u[0]='-';
			if(S_IWUSR & statbuf.st_mode)
				mode_u[1] = 'w';
			else
				mode_u[1] = '-';
			if(S_IXUSR &statbuf.st_mode)
				mode_u[2] = 'x';
			else
				mode_u[2] = '-';
			mode_u[3] = '\0';
			if(S_IRGRP & statbuf.st_mode)
				mode_g[0] = 'r';
			else
				mode_g[0] = '-';
			if(S_IWGRP & statbuf.st_mode)
				mode_g[1] = 'w';
			else
				mode_g[1] = '-';
			if(S_IXGRP & statbuf.st_mode)
				mode_g[2] = 'x';
			else
				mode_g[2] = '-';
			mode_g[3] = '\0';
			if(S_IROTH & statbuf.st_mode )
				mode_o[0] = 'r';
			else
				mode_o[0] = '-';
			if(S_IWOTH & statbuf.st_mode)
				mode_o[1] = 'w';
			else
				mode_o[1] = '-';
			if(S_IXOTH & statbuf.st_mode)
				mode_o[2] = 'x';
			else
				mode_o[2] = '-';
			mode_o[3] = '\0';
			//--------------------------//
			time_t t = statbuf.st_atime;
			ptm = ctime(&t);	
			format(ptm);
			printf("-%s%s%s %4d %5s %5s %8ld %s %-20s\n",mode_u,mode_g,mode_o,statbuf.st_nlink,getpwuid(statbuf.st_uid)->pw_name,getgrgid(statbuf.st_gid)->gr_name,statbuf.st_size,ptm+4,dirinfo->d_name);
		}
		if( S_ISREG(statbuf.st_mode))//文件
		{
			if(S_IRUSR & statbuf.st_mode)//judge usr
				mode_u[0]='r';
			else
				mode_u[0]='-';
			if(S_IWUSR & statbuf.st_mode)
				mode_u[1] = 'w';
			else
				mode_u[1] = '-';
			if(S_IXUSR & statbuf.st_mode)
				mode_u[2] = 'x';
			else
				mode_u[2] = '-';
			mode_u[3] = '\0';
			if(S_IRGRP & statbuf.st_mode)
				mode_g[0] = 'r';
			else
				mode_g[0] = '-';
			if(S_IWGRP & statbuf.st_mode)
				mode_g[1] = 'w';
			else
				mode_g[1] = '-';
			if(S_IXGRP & statbuf.st_mode)
				mode_g[2] = 'x';
			else
				mode_g[2] = '-';
			mode_g[3] = '\0';
			if(S_IROTH & statbuf.st_mode)
				mode_o[0] = 'r';
			else
				mode_o[0] = '-';
			if(S_IWOTH & statbuf.st_mode)
				mode_o[1] = 'w';
			else
				mode_o[1] = '-';
			if(S_IXOTH & statbuf.st_mode)
				mode_o[2] = 'x';
			else
				mode_o[2] = '-';
			mode_o[3] = '\0';
			time_t t = statbuf.st_atime;
			ptm = ctime(&t);
			format(ptm);
			printf("-%s%s%s %4d %5s %5s %8ld %s %-20s\n",mode_u,mode_g,mode_o,statbuf.st_nlink,getpwuid(statbuf.st_uid)->pw_name,getgrgid(statbuf.st_gid)->gr_name,statbuf.st_size,ptm+4,dirinfo->d_name);
		}
	}
	closedir(mydir);
}
void format(char *str)
{
	while( *str )
	{
		str++;
	}
	while( *str !=':')
	{
		str--;
	}
	*str = '\0';
	printf("hello\n");
}
