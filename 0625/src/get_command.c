/*************************************************************************
	> File Name: get_command.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 08:32:59 PM HKT
 ************************************************************************/

#include "shell.h"

void del_mid_space(char *str)
{
	int i= -1;
	int j= 0;
	while( str[j] )
	{
		if( !isspace(str[j]) )
		{
			str[++i] = str[j];
		}
		else if(i != -1 && !isspace(str[i]))
		{
			str[++i] = ' ';
		}
		++j;
	}
	for (;i>=0;--i)
	{
		if( !isspace(str[i]))
		{
			break;
		}
	}
	str[++i] = '\0';
//	printf("\n");
	fflush(stdout);
}
void del_enter(char *str)
{
	int i;
	for(i=strlen(str)-1; str[i]!='\n';--i);
	str[i] = '\0';
	str[++i] = '\0';
}
int get_command(char *str,char(*word_str)[32])//去空格，数单词
{
	char word[32];
	int word_num = 0;
	int pos = 0;
	int i=0;
	del_mid_space(str);
	del_enter(str);
	printf("%s\n",str);
	while(memset(word,0,32),sscanf(str+pos,"%s",word) == 1 )
	{
		++word_num;
		pos = pos+strlen(word)+1;
		strcpy(word_str[i],word);
//		puts(word);
//		puts(word_str[i]);
		++i;
	}
//	printf("\n");
	fflush(stdout);
	return word_num;
}

