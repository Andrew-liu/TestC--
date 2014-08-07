/*************************************************************************
	> File Name: post_deep_tree.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 11:44:19 PM HKT
 ************************************************************************/

#include "tree.h"

int post_deep_tree(BiTree T)
{
	int dl,dr;//分别记录左子树与右子树的深度
	int max_deep = 0 ;
	if( T != NULL)
	{
		dl = post_deep_tree(T->lchild);
		dr = post_deep_tree(T->rchild);
		max_deep = (dl > dr) ? dl : dr;
		return max_deep+1;
	}
	else
	{
		return 0;
	}
}

