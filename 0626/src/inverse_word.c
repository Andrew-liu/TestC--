
#include "reserve.h"
/*
 * 11.�����ַ��������ʣ�
 */
void inverse_word(char *str,int *index)//����ȥ�������ĸλ�õ���������
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
		//j�ǿո�
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
