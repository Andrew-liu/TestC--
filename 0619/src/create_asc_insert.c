/*************************************************************************
	> File Name: create_asc_insert.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 11:28:17 PM PDT
 ************************************************************************/

#include "LinkList.h"

void create_asc_insert(LinkList *L,int len)
{
	int count;
	Lnode *node,*pre,*cur;
//	int number;
	srand(time(NULL));
	for( count = 0;count <len; ++count)
	{
		node = (Lnode *)malloc(sizeof(Lnode));
	//	scanf("%d",&number);
		node->data = rand()%100;
		pre = (*L);
		cur = (*L)->next;
		while( cur )
		{
			if( cur->data <= node->data )
			{
			//	printf("%d\n",cur->data);
				pre = cur;
				cur = cur->next;
			}
			else 
				break;
		}
			if(pre == (*L))
			{
				node->next = (*L)->next;
				(*L)->next = node;
			}
			else
			{
				node->next = pre->next;
				pre->next = node;
			}
		
	}
}


