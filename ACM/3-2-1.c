#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int count=0;
    char s[20], buf[99];
    scanf("%s", s);
    int abc,de;
    int x,y,z;
    int i;
    for(abc=111;abc<=999;abc++)
    {
        for(de=11;de<=99;de++)
        {
            x=abc*(de%10);//第一位乘数的积
            y=abc*(de/10);//第二位乘数的积
            z=abc*de;//被乘数和乘数的积
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int flag=1;//输出标志
            for(i=0;i<strlen(buf);i++)
            {
                if(strchr(s,buf[i])==NULL)//有任何一个数字不属于数字集合就不输出
                {
                    flag=0;
                }
            }
            if(flag)
            {
                printf("<%d>\n",++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
            }

        }

    }
    printf("The number of solution = %d\n",count);
    return 0;
}
