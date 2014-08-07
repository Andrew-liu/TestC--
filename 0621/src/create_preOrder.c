/*************************************************************************
	> File Name: create_preOrder.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 07:53:44 PM HKT
 ************************************************************************/

#include "tree.h"

void create_preOrder(BiTree *T)
{
	char num;
	num  = getchar();
	if( num == '#' )
		*T = NULL;
	else
	{
		(*T) = (BiTree)calloc(1,sizeof(BiTnode));
		(*T)->data = num;
		create_preOrder( &((*T)->lchild) );
		create_preOrder( &((*T)->rchild) );
	}
}

