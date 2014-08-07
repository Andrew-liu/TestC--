/*************************************************************************
	> File Name: get_command.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sun 06 Jul 2014 04:09:17 PM HKT
 ************************************************************************/

#include "FTP.h"


int get_command(char *str,char (*file_path)[32],char *com_name)
{
	int pos = 0,index = 0,file_num = 0;
	char temp[64];
	bzero(file_path,32);
	bzero(com_name,32);
	delete_mid_space(str);
//	printf("str %s\n",str);
	//get command
	sscanf(str,"%s",temp);
//	printf("temp=%s\n",temp);
	strcpy(com_name,temp);
//	printf("com_name=%s\n",com_name);
	pos = pos + strlen(temp) + 1;
//	++file_num;
	//get file path
	while( bzero(temp,64),1 == sscanf(str+pos,"%s",temp) && pos <= strlen(str) )
	{
	//	file_path = (char **)malloc()
		strcpy(file_path[index],temp);
		pos = pos + strlen(temp) + 1;
		++index;
		++file_num;
	}
	return file_num;
}
