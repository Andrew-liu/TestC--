/*************************************************************************
	> File Name: test_file_describe.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 22 Jun 2014 09:20:07 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char buf1[32];
	char buf2[50];
	printf("Input string:");
	printf("\n");
//	fflush(stdout);
	int iret = read(STDIN_FILENO,buf1,sizeof(buf1));
	buf1[iret] = '\0';
	sprintf(buf2,"The string is %s",buf1);
	write(STDOUT_FILENO,buf2,strlen(buf2));
	return 0;

}

