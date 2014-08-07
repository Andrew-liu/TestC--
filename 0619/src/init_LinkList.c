/*************************************************************************
	> File Name: init_LinkList.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 18 Jun 2014 09:55:53 PM PDT
 ************************************************************************/

#include "LinkList.h"

void init_LinkList(LinkList *L)
{
	(*L) = (LinkList)calloc(1,sizeof(Lnode));
}

