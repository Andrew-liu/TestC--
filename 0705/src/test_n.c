/*************************************************************************
	> File Name: test_n.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 05 Jul 2014 08:55:37 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	char buf[123] = "abc 123";
	int num;
	int rec[123];
	int fd[2];//0 pw 1cr
	pipe(fd);
	if (0 != fork())
	{
	//	int fd_rd = open(fd[0],O_RDONLY);
		FILE *fp_rd = fdopen(fd[0],"r");
		fscanf(fp_rd,"%s %d",rec,&num);
		printf("OK\n");
	}
	else
	{

	//	int fd_wr = open(fd[1],O_WRONLY);
		FILE *fp = fdopen(fd[1],"w");
		fprintf(fp,"%s\n",buf);
		fflush(fp);
	}
//	int fd = open("a.txt",O_RDONLY | O_CREAT);
//	while(memset(a,0,123),scanf("%s",a)==1)
//		printf("%s\n",a);
	

}
