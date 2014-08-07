/*************************************************************************
	> File Name: print_preOrder.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 11:29:42 PM HKT
 ************************************************************************/

#include "tree.h"

void print_preOrder(BiTree T)
{
	if( T ==NULL)
		putchar('#');
	else
	{
		printf("%c",T->data);
		print_preOrder( T->lchild );
		print_preOrder( T->rchild );
	}
}

