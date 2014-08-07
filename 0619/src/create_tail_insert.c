/*************************************************************************
	> File Name: create_tail_insert.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 10:12:14 PM PDT
 ************************************************************************/

#include "LinkList.h"

void create_tail_insert(LinkList *L,int len)
{
	int count;
	Lnode *tail = (*L);
	int number = 0;
	for (count = 0;count<len;++count)
	{
		Lnode *temp = (Lnode *)malloc(sizeof(Lnode));
		temp->data = 2*number +1;
		tail->next = temp;
		tail = temp;
		++number;
	}
	tail->next = NULL;
}


