/*************************************************************************
	> File Name: creat_thread.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 30 Jun 2014 02:26:02 PM HKT
 ************************************************************************/


/*
 * int pthread_create(phtread_t *thread,const pthread_attr *attr,void* (*start routine) (void*),void* arg)
 * 1.编译时连接第三方库gcc -o XXX XXX.c -l XXX
 * 2.进程死，线程死
 * 3.线程结束，回收资源 int  pthread_john(pthread_t thread,void **retval),第二个参数传出参数，返回的不能上局部变量
 * 4.pthread_exit退出线程，exit退出进程
 * 5.pthread_self 返回id
 */

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define NUM 10
void* my_hand(void *arg);
int main()
{
	int i;
	pthread_t tid;
	int a[NUM];
	char *p;
	srand(time(NULL));
	for( i = 0;i< NUM;++i)
	{
		a[i]  = rand()%100;
		printf("%d ",a[i]);
	}
	printf("\n");
	pthread_create(&tid,NULL,my_hand,(void *)a);
	pthread_join(tid,(void *)&p);
	puts(p);
	sleep(3);
	return 0;

}
void* my_hand(void *arg)
{
	int *num = (int *)arg;
	int sum;
	printf("sum[0]=%d\n",*num);
	printf("sum[NUM] = %d\n",num[9]);
	sum = ( (*num) + (*(num+NUM-1) ) )*NUM / 2;
	printf("the sum is %d\n",sum);
	char *str = "hello,world\n";
	return (void *)str;

}
