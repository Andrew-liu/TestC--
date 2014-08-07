/*************************************************************************
	> File Name: txt_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 07:01:01 PM HKT
 ************************************************************************/

#include "txt.h"
int main(int argc,char *argv[])
{
	ptxt t = (ptxt)calloc(1,sizeof(txt));
	char command[100];
	if( argc == 1)
	{
		perror("error\n");
		exit(-1);
	}
	else if( argc ==2 )
	{
		t = (ptxt)init(argv[1]);	
		//	printf("file->The file lines are %4d\n",t->line_num);
	while(memset(command,0,sizeof(command)),fgets(command,100,stdin))
	{
		del_mid_space(command);
		del_enter(command);
		puts(command);
		if( strcmp(command,"wc -l") == 0)
		{
			printf("ok\n");
			printf("file->The file lines are %4d\n",t->line_num);
		}
		if( strcmp(command,"wc -w") == 0)
		{
			printf("file->The file word are %4d\n",t->word_num);
		}
		if( strcmp(command,"wc -c") == 0)
		{
			printf("file->The file char are %4d\n",t->char_num);
		}
		if( Match(command,"search"))
		{
			puts(command);
			delfirstspace(command);
			puts(command);
			delstr(command);
			puts(command);
			delfirstspace(command);
			strMatch(argv[1],command);

		}
	}
	}

}

