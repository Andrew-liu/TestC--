/*************************************************************************
	> File Name: create_link.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 07:10:22 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
	int data;
	struct LinkList *next;
}*LinkList,Lnode;

int main()
{
	int count = 8;
	int number=1;
	int i;
	LinkList head;
	head = (LinkList)calloc(1,sizeof(Lnode));
	for(  i=0; i<count;++i)
	{
		Lnode *temp = (Lnode *)calloc(1,sizeof(Lnode));
		temp->data = number++;
		temp->next = head->next;
		head->next = temp;
	}
	Lnode *pr = head->next;//use for print
	while( pr )
	{
		printf("%d,",pr->data);
		pr = pr->next;
	}
	printf("\n");
	Lnode *cur,*pn,*temp;//use for reserve
	cur  = head->next;
	pn   = cur->next;
	head->next =NULL;
	while( pn )
	{
		temp = pn;
		pn = pn->next;
		temp->next = head->next;
		head->next = temp;
	}
//	pn->next = head->next;
//	head->next = pn;
	cur->next->next = NULL;

	pr = head->next;
	while( pr )
	{
		printf("%d,",pr->data);
		pr = pr->next;
	}
	printf("\n");
}


