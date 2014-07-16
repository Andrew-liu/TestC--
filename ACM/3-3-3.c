#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *str)
{
    int low=0;high=strlen(str)-1;
    char ch;
    while(low<high)
    {   
        ch=str[low];
        str[low]=str[high];
        str[high]=ch;
        ++low;
        --high;
    }
}
int mirror(char *str)
{
    char mir[]="AAB C D E3F G HHIIJLK LJMMN OOP Q R S2TTUUVVWWXXYYZ5112S3E4 5Z6 7 889 ";
    int i;
    int j;
    
    while(str[j++]!='\0')
    {
        for(i=0;i<strlen(mir);++i)
        {
            if(mir[i]==str[j]&&i%2==0)
            {
                str[j]=mir[i+1];
                if(mir[i+1]==' ')
                {
                    return 0;
                }
                break;
            }
        }
    }
    return 1;//转化镜像串成功
}
int main(int argc, const char *argv[])
{
    char new[1024],str[1024];
    memset(new,0,1024);
    memset(str,0,1024);
    while(scanf("%s",str)!=EOF)
    {
        strcpy(new,str);//保存原字符串
        reverse(str);//翻转字符串
        
    }
    return 0;
}
