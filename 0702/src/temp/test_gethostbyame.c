/*************************************************************************
	> File Name: test_gethostbyame.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 02:52:05 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <netdb.h>


int main(int argc,char *argv[])
{
	struct hostent* my_ent;
	my_ent = gethostbyname(argv[1]);
	printf("h_name = %s\n",my_ent->h_name);
	printf("h_addtype = %d\n",my_ent->h_addrtype);
	printf("h_length = %d\n",my_ent->h_length);
	char **p = my_ent->h_addr_list;
	while( *p )
	{
		printf("h_addr_list = %s\n",*p);
		printf("h_addr_list = %x\n",*(int *)*p);
		++p;
	}

}

