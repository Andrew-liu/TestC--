/*************************************************************************
	> File Name: shell.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 25 Jun 2014 07:27:13 PM HKT
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

void consle_str(char *str);
void del_mid_space(char *str);
int get_command(char *str,char (*word_str)[32]);//去空格，数单词
void del_enter(char *str);

