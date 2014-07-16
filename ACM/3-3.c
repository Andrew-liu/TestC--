#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char argv[])
{
    char str[1024];
    int flag=0;
    gets(str);
    int i;
    for(i=0;i<strlen(str);++i)
    {
        if(str[i]=='"')
        {
            if(flag==0)
            {
                printf("``");
                flag=1;
            }
            else if(flag==1)
            {
                printf("''");
                flag=0;
            }
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    printf("\n");
    return 0;
}
