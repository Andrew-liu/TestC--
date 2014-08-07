/*************************************************************************
	> File Name: my_hton.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 09:40:54 AM HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define my_host(ip)(ip = ((ip4<<24)|(ip3<<16)|(ip2<<8)|ip1))
#define my_hton(ip)\
	(host& 0xff000000)>>24 |(host &0x00ff0000)>>8 | \
	 (host &0x0000ff00)<<8 | (host &0x000000ff)<<24

int ip1,ip2,ip3,ip4;
int main(int argc,char *argv[])
{
	char buf[128];
	int host=0,net=0;
	while( memset(buf,0,128),fgets(buf,1024,stdin) != NULL)
	{
		sscanf(buf,"%d.%d.%d.%d",&ip1,&ip2,&ip3,&ip4);
		printf("ip1 = %d ip2 = %d ip3 = %d ip4 = %d\n",ip1,ip2,ip3,ip4);
		my_host(host);
		printf("The host ip is %x\n",host);
//		net = host;
		host = my_hton(host);
		printf("The net ip is %x\n",host);
	}

}
