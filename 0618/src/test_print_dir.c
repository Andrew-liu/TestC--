/*************************************************************************
	> File Name: test_print_dir.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 05:33:50 AM PDT
 ************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void printdir(char *dir,int depth)
{
	DIR *dp = opendir(dir);
	if( NULL == dp)
	{
		fprintf(stderr,"cannot open dir %s\n",dir);
		return ;
	}
	chdir(dir);
	struct dirent *entry;
	struct stat statbuf;
	while((entry = readdir(dp))!=NULL)
	{
		stat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0)
			{
				continue;
			}
				printf("%*s%s/\n",depth,"",entry->d_name);
				printdir(entry->d_name,depth+4);
		}
		else
			printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");
	closedir(dp);
}
int main(int argc,char *argv[])
{
	char *topdir,pwd[2]=".";
	if(argc < 2)
	{
		topdir = pwd;
	}
	else
		topdir = argv[1];
	printf("Directory scan of %s\n",topdir);
	printdir(topdir,0);
	printf("done.\n");
	exit(0);
}



