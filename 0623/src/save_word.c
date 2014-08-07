

#include "txt.h"
void save_word(char *str,char (*word)[1024],int *num,int count_word)
{
	int i,j=0;
	int k=0;
	int index;
	for(i=0; i<count_word; ++i)
	{
		index=num[k];
		++k;
		j=0;
		while( (str[index]) !=' ' && str[index] !='\0')
		{
			word[i][j] = str[index];
			++j;
			++index;
		}
		word[i][j]='\0';
	}
}
