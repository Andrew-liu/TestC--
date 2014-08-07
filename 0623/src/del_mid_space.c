
#include "txt.h"

void del_mid_space(char *str)
{
	char *cur ;
	char *pst ;
	char temp;
	cur = str;
	pst = str;
	while( *cur )
	{
		if(*cur!=' ')
			++cur;
		else
		{
			++cur;
			pst = cur;
			while( *pst==' ')
			{
				++pst;
			}

				while( *pst!=' '&& *pst)
				{
					char *temp,*temp1 ;//用于删除
					//*cur = *pst;
					temp = cur;
					temp1 = pst;
					while( temp1 <= str+strlen(str) )
					{
						*temp = *temp1;
						++temp;
						++temp1;
					}
					temp = cur;//将临时指针还原
					temp1 = pst;
					++pst;
					//++cur;
					cur = pst;
			    }
		}
	}

}
