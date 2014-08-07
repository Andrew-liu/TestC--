/*************************************************************************
	> File Name: divide_LinkList.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 10:21:03 PM PDT
 ************************************************************************/

#include "LinkList.h"

void divide_LinkList(LinkList *L1,LinkList *L2,LinkList *L3,int len)
{
	int count=1;
	Lnode *tail2 = (*L2);
	Lnode *tail3 = (*L3);
	Lnode *cur = (*L1)->next;
//	init_LinkList(L2);
//	init_LinkList(L3);
	while( cur )
	{
		if( count %2 ==0 )
		{
			Lnode *temp2 = cur;
			cur = cur->next;
			tail2->next = temp2;
			tail2 = temp2;
		}
		tail2->next = NULL;
		if( count %2 != 0)
		{
			Lnode *temp3 = cur;
			cur = cur->next;
			tail3->next = temp3;
			tail3 = temp3;
		}
		tail3->next = NULL;
		++count;
	}

}

