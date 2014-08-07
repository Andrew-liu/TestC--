/*************************************************************************
	> File Name: tree_main.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Sat 21 Jun 2014 08:12:41 PM HKT
 ************************************************************************/

#include "tree.h"

int main()
{
	int dep ;
	BiTree tree;
	create_preOrder(&tree);
	dep = post_deep_tree(tree);
	printf("the tree of deep is %d\n",dep);
	print_preLikeTree(tree,dep);
//	print_preOrder(tree);
	
	return 0;
}

