/*************************************************************************
	> File Name: func.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Tue 17 Jun 2014 08:40:57 PM PDT
 ************************************************************************/
#ifndef _sort
#define _sort
#include <stdio.h>
#include <stdlib.h>
#define LEN 10
void bubble_sort(int *a,int len);
void quick_sort (int *a,int len);
void insert_sort(int *a,int len);
void select_sort(int *a,int len);
int partion(int *a,int len);
void getarray(int *a,int len);
void print(const char *str,int *a,int len);
#endif

