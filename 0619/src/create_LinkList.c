/*************************************************************************
	> File Name: create_LinkList.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 09:47:16 PM PDT
 ************************************************************************/

#include "LinkList.h"

void create_head_Insert(LinkList *L,int len)
{
	int count;
	int number= 0;
	for(count = 0;count < len;++count)
	{
		Lnode *temp = (Lnode *)calloc(1,sizeof(Lnode));
		temp->data  = number++;
		temp->next  = (*L)->next;
		(*L)->next  = temp;
	}

}

