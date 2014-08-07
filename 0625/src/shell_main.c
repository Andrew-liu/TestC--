/*************************************************************************
	> File Name: shell_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 07:41:42 PM HKT
 ************************************************************************/

#include "shell.h"

int main()
{
	int ret;
	char str[1024];
	char command[1024];
	char word[100][32];
	consle_str(str);
	char **list;
	int word_num=0;
	while(1)
	{
		while(printf("%s  ",str),memset(command,0,1024),fgets(command,1024,stdin) && command[0] != '\n')
		{
			word_num = get_command(command,word);
			puts(command);
			int n_f = fork();
			 if( n_f == 0)//kid
			{
				int index;
				list = (char **)malloc(sizeof(char *)*word_num);
				for( index = 0;index < word_num;++index)
				{
					list[index] = word[index]; 
				}
				list[index] = NULL;
				ret=execvp(list[0],list);
				if(ret<0)
				{
					perror("child failed!\n");
				}
			//	printf("end\n");
			//	exit(1);
			}else if(n_f>0)
			{

			//	printf("begin\n");
				wait(NULL);
			}
			else
			{
				perror("frok error\n");
				exit(-1);
			}
		}
	}
}
