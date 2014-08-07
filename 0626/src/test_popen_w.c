/*************************************************************************
	> File Name: test_popen_w.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 26 Jun 2014 09:51:45 AM HKT
 ************************************************************************/



#include "reserve.h"
/*
 * 从键盘读，打到屏幕
 */
/*void reverse_str(char *str);
void reverse_word(char *str);
void del_mid_space(char *str);*/
int main()
{
	char buf[1024];
	int num[50];
	while( memset(buf,0,1024),fgets(buf,1024,stdin) )
	{
		if( buf[0] != '\n' )
		{
			buf[strlen(buf)-1] = '\0';
//			reverse_str(buf);
			inverse_word(buf,num);
		//	reverse_word(buf);
			puts(buf);
		}

	}
}
void reverse_str(char *str)
{
	int begin=0;
	int end = strlen(str)-1;
	char temp;
	do
	{
		temp = str[end];
		str[end--] = str[begin];
		str[begin++] = temp;
	}while(begin < end);
}
/*void reverse_word(char *str)
{
	char word[32];
	int i=0,j;
	del_mid_space(str);
	reverse_str(str);
	puts(str);
	while( str[i] )
	{
		char temp;
		j=0;
		for(i=0;str[i]!=' ';++i);
		int temp_i = i-1;
		int temp_j = j;
		do
		{
			temp = str[temp_i];
			str[temp_i--] =str[j];
			str[j++] = temp;
		}while(temp_j<temp_i);
		j = i;
	}

}*/
/*void del_mid_space(char *str)
{
	int i=-1;
	int j=0;
	while( str[j])
	{
		if( !isspace(str[j]))
		{
			str[++i]  = str[j];
		}
		else if( i!=-1 && !isspace(str[i]))
		
		{
			str[++i] = ' ';
		}
		++j;
	}
	for(;i>=0;--i)
	{
		if( !isspace(str[i]))
		{
			break;
		}
	}
	str[++i] = '\0';

}*/
