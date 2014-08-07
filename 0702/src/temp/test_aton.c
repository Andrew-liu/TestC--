/*************************************************************************
	> File Name: test_aton.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Wed 02 Jul 2014 02:28:07 PM HKT
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
 * 1.点十进制转换为网络字节序 int inet_aton(const char *str,struct in_addr *add)  in_addr_t inet_addr(const char* str)
 * 2.网络字节转化为点十进制字符串 char *inet_ntoa(struct in_addr inaddr)
 */

int main(int argc,char *argv[])
{
	struct in_addr adder1,adder2;
	inet_aton(argv[1],&adder1);
	printf("net is %x\n",adder1.s_addr);
	adder2.s_addr = inet_addr(argv[1]);
	printf("net is %x\n",adder2.s_addr);
	printf("%s\n",inet_ntoa(adder1));

}

