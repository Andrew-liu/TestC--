/************************************************************************
	> File Name: my_mv.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 02:10:14 PM HKT
 ************************************************************************/

#include "mv.h"

void my_mv( char *source, char *copy)
{
	char a[100];
	char newsource[100] ="./";
	char buf[1024];
	strcat(newsource,source);
	int fdr = open(newsource,O_RDONLY,0666);//use for read
	if( chdir(copy) == 0 )
	{
		strcat(copy,source);
	}
	chdir(a);
//	int fdr = open(newsource,O_RDONLY,0666);//use for read
	int fdw = open(copy,O_WRONLY | O_CREAT,0666);//use for write
	if(-1==fdr || -1 == fdw )
	{
		perror("open failed\n");
		exit(-1);
	}
		while(memset(buf,0,1024),read(fdr,buf,sizeof(buf)) )
		{
			write(fdw,buf,strlen(buf));
		}
		close(fdr);
		close(fdw);
	unlink(newsource);
}
