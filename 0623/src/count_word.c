
#include "txt.h"
int count_word(char *str,int *index)//index���ڴ��ÿ����������ĸ��λ��
{
	int cur = 0;
	int pst = cur; 
	int count_word = 0;
	int j=0;
	index[0] = 0;
	while( cur != strlen(str) )
	{
		int i;
		for(cur = pst; isspace(str[cur]);++cur);//�ҵ���������ĸλ��
		if( str[cur] =='\0')  break;
		index[j] = cur;
		++j;
		for(pst = cur;  !isspace( str[pst] ) && (str[pst]!='\0'); ++pst);//�ҵ����ʵĽ�β
/*		for( i=cur; i !=pst; ++i)
			printf("%c",str[i]);
		printf("\n");*/
		++count_word;
		if( str[pst] == '\0' ) break;
			cur = pst;
	}
	return count_word;
}
