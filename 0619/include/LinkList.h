/* *************************************************************************
	> File Name: LinkList.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 09:50:39 PM PDT
 ************************************************************************/
#ifndef _LinkList
#define _LinkList

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}*LinkList,Lnode;
void create_head_Insert(LinkList *L,int len);
void create_tail_insert(LinkList *L,int len);
void divide_LinkList(LinkList *L1,LinkList *L2,LinkList *L3,int len);
void init_LinkList(LinkList *L);
void show_LinkList(LinkList L);
void create_desc_insert(LinkList *L,int len);
void create_asc_insert(LinkList *L,int len);
void merge_LinkList(LinkList *L1,LinkList *L2);
#endif

