/*************************************************************************
	> File Name: tree.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 07:08:25 PM HKT
 ************************************************************************/

#ifndef _tree
#define _tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
	struct tree *parent;
}BiTnode,*BiTree;
#define space 4
void create_preOrder(BiTree *T);
void print_preOrder(BiTree T);
int post_deep_tree(BiTree T);
void print_preLikeTree(BiTree T,int depth);//缩进打印树


#endif
