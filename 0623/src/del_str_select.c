#include "txt.h"
void delstr(char *str)
{
	char *cur = str;
	char *pst;
	int i;
	for(i =0;isspace(str[i]);++i)
		;
	for(;isalpha(str[i]);++i)
		;
	pst = str + i;
	while( *pst != '\0')
	{
		*cur = *pst;
		++cur;
		++pst;
	}
	*cur = '\0';
}
