/*************************************************************************
	> File Name: consle_str.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 07:26:12 PM HKT
 ************************************************************************/

#include "FTP.h"

void consle_str(char *str)
{
	char host[100];
	char dirname[100];
	char usr[100];
	int i,j;
	int n_usr = getlogin_r(usr,1024);//获得当前用户名
	if( n_usr != 0)
	{
		perror("get usr error\n");
		exit(-1);
	}
	strcpy(str,"[");
	strcat(str,usr);
	strcat(str,"@");
	int n_host = gethostname(host,100);
	if( n_host != 0)
	{
		perror("get host error\n");
		exit(-1);
	}
	for( i=0;host[i]!='.';++i);
	host[i] = '\0';
	strcat(str,host);
	strcat(str," ");
	getcwd(dirname,100);
	puts(dirname);
	for(j=strlen(dirname)-1;dirname[j]!='/';--j);
	strcat(str,dirname+j+1);
	strcat(str,"]");
	strcat(str,"青");
	puts(str);

}
