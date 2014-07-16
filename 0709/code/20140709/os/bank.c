#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_account = 1000;

void *thread_A(void *arg){
    int cnt = 0;
    while(1){
        int temp = g_account;
        printf("No. %d, before save money, account equals %d\n", cnt, temp);
        temp += 500;
        sleep(2);
        g_account = temp;
        printf("No. %d, after save money, account equals %d\n", cnt, temp);
        ++cnt;
    }
    return NULL;
}

void *thread_B(void *arg){
    int cnt = 0;
    while(1){
        int temp = g_account;
        printf("No. %d, before withdraw money, account equals %d\n", cnt, temp);
        temp -= 200;
        sleep(3);
        g_account = temp;
        printf("No. %d, after withdraw money, account equals %d\n", cnt, temp);
        ++cnt;
    }
    return NULL;
}


int main(int argc, const char *argv[])
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread_A, NULL);
    pthread_create(&tid2, NULL, thread_B, NULL);


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
