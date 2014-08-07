#include "txt.h"
void delfirstspace(char *str)
{
	char *cur =str;
	char *pst;
	int begin;
	int last = strlen(str);
	for( begin=0; isspace( str[begin] ); ++begin);
	pst = str+begin;
	while( *pst!='\0' )
	{
		*cur = *pst;
		++cur;
		++pst;
	}
	*cur = '\0';
}
