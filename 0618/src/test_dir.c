/*************************************************************************
	> File Name: test_dir.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 04:52:13 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc,char *argv[])
{
	struct dirent *pDirinfo;
	DIR *pDir;
	if(argc < 2)
		pDir = opendir(".");
	else
	{
		pDir = opendir(argv[1]);
	}
	if(NULL == pDir)
	{
		fprintf(stderr,"open dir fail\n");
		return -1;
	}
	while((pDirinfo = readdir(pDir))!=NULL)
		printf("%s\n",pDirinfo->d_name);
	closedir(pDir);
	return 0;
}

