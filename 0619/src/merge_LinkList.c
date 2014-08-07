/*************************************************************************
	> File Name: merge_LinkList.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 11:34:36 PM PDT
 ************************************************************************/

#include "LinkList.h"

void merge_LinkList(LinkList *L1,LinkList *L2)
{
	printf("L1:");
	show_LinkList(*L1);
	printf("L2:");
	show_LinkList(*L2);
	Lnode *newhead = (*L1)->next->data >= (*L2)->next->data ? (*L2) : (*L1);
	Lnode *work1 = newhead->next->next;//指向要合并的第二个结点
	Lnode *work2 = (*L1)->next->data >= (*L2)->next->data ? (*L1)->next : (*L2)->next;//point bigger
	Lnode *smaller;
	Lnode *tail = newhead->next;
	while( work1 && work2)
	{
		smaller = work1->data >= work2->data ? work2 : work1;
		tail->next = smaller;
		tail = smaller;
		if( smaller == work1)
			work1 = work1->next;
		if( smaller == work2)
			work2 = work2->next;
	}
	if( work1 != NULL)
	{
		tail->next = work1;
	}
	if( work2 != NULL)
	{
		tail->next = work2;
	}
	printf("after merge: ");
	show_LinkList(newhead);

}

