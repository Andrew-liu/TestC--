
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
					char *temp,*temp1 ;//����ɾ��
					//*cur = *pst;
					temp = cur;
					temp1 = pst;
					while( temp1 <= str+strlen(str) )
					{
						*temp = *temp1;
						++temp;
						++temp1;
					}
					temp = cur;//����ʱָ�뻹ԭ
					temp1 = pst;
					++pst;
					//++cur;
					cur = pst;
			    }
		}
	}

}
