
#include "reserve.h"
/*
 * 11.逆序字符串（单词）
 */
void inverse_word(char *str,int *index)//传进去存放首字母位置的整型数组
{
	int i,j,k,m;
	char temp;
	int count_word;
	reverse_str(str);
	count_word = countword(str,index);
	for( i=0;i<count_word;++i)
	{
		k = index[i];
		j = index[i];
//		printf("k=%d,j=%d\n",k,j);
		while( str[j] !=' ' && str[j]!= '\0')
		{
		//	printf("%c",a[ j ]);
			++j;
		}
		//j是空格
		m = j-1;
//		printf("m=%d\n",m);
		do
		{
			temp   = str[m];
			str[m--] = str[k];
			str[k++] = temp;

		}while(k<m);

	}

}
