#include "txt.h"
void strMatch(char *filename,char *kid)
{
	char temp[1024];
	FILE *rd = fopen(filename,"rb");
	if( rd == NULL)
	{
		perror("error\n");
		exit(-1);
	}
	while( fgets(temp,1024,rd) )
	{
		if(Match(temp,kid))
		{
			puts(temp);
		}
	}
	fclose(rd);
}
int Match( char *str,char *str_kid)
{	
	int index_s=0;
	int index_k=0;
	int count=0;
	while(str[index_s+index_k]  )
	{
		if(str[index_s+index_k] == str_kid[index_k])
		{
			++index_k;
		}
		else
		{
			++index_s;
			index_k = 0;
		}
		if( str_kid[index_k] == '\0' )
		{
			return 1;
		}
	}
}
