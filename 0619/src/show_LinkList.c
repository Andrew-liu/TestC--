/*************************************************************************
	> File Name: show_LinkList.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 09:58:26 PM PDT
 ************************************************************************/

#include "LinkList.h"

void show_LinkList(LinkList L)
{
	Lnode *cur = L->next;
	while( cur )
	{
		printf("%d,",cur->data);
		cur = cur->next;
	}
//	printf("\b ");
	printf("\n");
}

