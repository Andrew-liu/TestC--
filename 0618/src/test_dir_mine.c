/*************************************************************************
	> File Name: test_dir_mine.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 05:08:49 AM PDT
 ************************************************************************/
//查看目录内容
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc,char *argv[])
{
	DIR *opdir;
	struct dirent *chdirinfo;//check dir info
	if(argc < 2 )//命令行参数未输入
	{
		//DIR *opendif(const char *name)打开目录
		opdir = opendir(".");
	}
	else
	{
		opdir = opendir(argv[1]);
	}
	if(opdir == NULL)
	{
		fprintf(stderr,"open dir fail\n");
		return -1;
	}
	//struct dirent *readdir(DIR *dir)	
	while((chdirinfo = readdir(opdir))!=NULL)
	{
		printf("%s\n",chdirinfo->d_name);
	}
	closedir(opdir);
}
