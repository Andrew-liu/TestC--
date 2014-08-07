/*************************************************************************
	> File Name: print_preLikeTree.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 11:55:21 PM HKT
 ************************************************************************/

#include "tree.h"

void print_preLikeTree(BiTree T,int depth)//缩进打印树
{
	if( T ==NULL )
	{
		return ;
	}
	else
	{
	//	printf("%*s%c\n",depth*space,"",T->data);
		print_preLikeTree(T->rchild,(depth+1));
		printf("%*s%c\n",depth*space,"",T->data);
		print_preLikeTree(T->lchild,(depth+1));
	}

}

