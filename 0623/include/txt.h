/*************************************************************************
	> File Name: txt.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 06:34:31 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_line 40000
#define max_word (1<<23)
typedef struct word
{
	char word[32];
	int count;
}txt_word,*ptxt_word;
typedef struct tag
{
	int word_num;
	int char_num;
	int word_e_num;
	int line_num;
	ptxt_word word;
	char save_word[100][100];
	char save_txt[max_line][1024];
}txt,*ptxt;
void upper_to_lower(char *str);
void del_punct(char *str);
ptxt init(char *filename);
void del_enter(char *str);
int count_word(char *str,int *index);
//void save_word(char *str,char (*word)[100],int *num,int count_word);
void del_mid_space(char *str);
int Match( char *str,char *str_kid);
void strMatch(char *filename,char *kid);
void delstr(char *str);
void delfirstspace(char *str);
int word_compare(const void *left,const void *right);
