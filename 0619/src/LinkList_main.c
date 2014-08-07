/*************************************************************************
	> File Name: LinkList_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 10:01:21 PM PDT
 ************************************************************************/

#include "LinkList.h"

int main()
{
	LinkList L,L2,L3;
	init_LinkList(&L);
	init_LinkList(&L2);
//	init_LinkList(&L3);
//	create_head_Insert(&L,10);
//a
//	create_tail_insert(&L,10);
	create_desc_insert(&L,5);
	create_asc_insert(&L2,5);
//	show_LinkList(L);
//	divide_LinkList(&L,&L2,&L3,10);
//	show_LinkList(L2);
	merge_LinkList(&L,&L2);
//	show_LinkList(L);
//	show_LinkList(L2);
//	show_LinkList(L3);
	return 0;
}

