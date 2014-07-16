#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char key[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char ch;
    int i;
    while((ch=getchar())!=EOF)
    {
        for(i=1;i<strlen(key);++i)
        {
            if(ch==key[i])
            {
                printf("%c",key[i-1]); 
                break;
            }
        }
        if(i==strlen(key))
            printf("%c",ch);
    }
    printf("\n");
    return 0;
}
