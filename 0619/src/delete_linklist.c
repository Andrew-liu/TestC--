/*************************************************************************
	> File Name: delete_linklist.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 07:36:32 PM PDT
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
	int number1 =1;
	int number2 =1;
	int i,j;
	LinkList L1;
	LinkList L2;
	L1 = (LinkList)calloc(1,sizeof(Lnode));
	L2 = (LinkList)calloc(1,sizeof(Lnode));
	for(i=0;i<10;++i )//create l1
	{
		Lnode *temp1;
		temp1 = (Lnode *)calloc(1,sizeof(Lnode));
		temp1->data = number1++;
		temp1->next = L1->next;
		L1->next = temp1;
	}
	Lnode *pr1 = L1->next;//usr for print l1
	printf("L1:\n");
	while( pr1 )
	{
		printf("%d,",pr1->data);
		pr1 = pr1->next;
	}
	printf("\n");
	for(j=0;j<5;++j)
	{
		Lnode *temp2;
		temp2 = (Lnode *)calloc(1,sizeof(Lnode));
		temp2->data = (number2*2)+1;
		temp2->next = L2->next;
		L2->next = temp2;
		++number2;
	}
	Lnode *pr2 = L2->next;
	printf("L2:\n");
	while( pr2 )
	{
		printf("%d,",pr2->data);
		pr2 = pr2->next;
	}
	printf("\n");
	Lnode *del1,*del2,*pre1,*pre2;
	pre1 = L1;
	del1 = pre1->next;
	del2 = L2->next;
	while(  del2 )
	{
		while( del1 )
		{
			if(del1->data == del2->data)
			{
				Lnode *temp = del1;
				pre1->next = temp->next;
				del1 = pre1->next;
				printf("pr=%d del1=%d\n",pre1->data,del1->data);
			//	del2 = del2->next;
				free(temp);
				temp = NULL;
			}
			else
			{
				pre1 = del1;
				del1 = del1->next;
			//	del2 = del2->next;
			}
		}
		del2 = del2->next;
		del1 = L1;
	}
	Lnode *dpt = L1->next;//use for print after del
	printf("after del :\n");
	while( dpt )
	{
		printf("%d,",dpt->data);
		dpt = dpt->next;
	}
	printf("\n");
}

