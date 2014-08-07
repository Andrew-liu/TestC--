/*************************************************************************
	> File Name: init_txt.c
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Mon 23 Jun 2014 06:38:39 PM HKT
 ***********************************************************************/

#include "txt.h"
ptxt init(char *filename)
{
	ptxt t;
	t = (ptxt)calloc(1,sizeof(txt));
	int num[1024];
	FILE *rd = fopen(filename,"rb");
	int i=0,index,j;
	char word[32];
	char *p;
	if( rd == NULL )
	{
		perror("open error\n");
		exit(-1);
	}
	t->word = (ptxt_word)malloc(max_word*sizeof(txt_word));
	memset(t->word,0,max_word*sizeof(txt_word));
	memset(t->save_txt,0,sizeof(t->save_txt));
	memset(t->save_word,0,sizeof(t->save_word));

	while( fgets(t->save_txt[i],1024,rd) )
	{
		memset(num,0,sizeof(num));
		upper_to_lower(t->save_txt[i]);//大写换小写
		del_enter(t->save_txt[i]);//删末尾回车
		del_punct(t->save_txt[i]);//删标点
		del_mid_space(t->save_txt[i]);//删除中间空格
		del_enter(t->save_txt[i]);//删末尾回车
//		puts(t->save_txt[i]);
	//	int temp = count_word(t->save_txt[i],num);//单词计数
	//	save_word(t->save_txt[i],t->save_word[j],num,temp);//保存单词
		p = t->save_txt[i];
		int pos = 0;
		while( memset(word,0,32),sscanf(p+pos,"%s",word)==1 )
		{
//			puts(word);
			++t->word_num;
			index = 0;
			for(;index<t->word_e_num;++index)
			{
				if( strcmp(word,t->word[index].word) == 0)
				{
					++t->word[index].count;
					break;
				}
			}
			if(index >= t->word_e_num)
			{
				strcpy(t->word[index].word,word);
				++t->word_e_num;
				++t->word[index].count;
			}
			pos = pos+ strlen(word) +1;
//			puts(t->word[j].word);
		} 
		++i;
		++t->line_num;
	}
	qsort(t->word,t->word_e_num,sizeof(txt_word),word_compare);
	for(j=0;j<10;++j)
	{
		printf("%10s: %5d\n",t->word[j].word,t->word[j].count);
	}

	printf("line %d word %d word_e %d\n",t->line_num,t->word_num,t->word_e_num);
	return t;
}
int word_compare(const void *left,const void *right)
{
	ptxt_word word_left,word_right;
	word_left  = (ptxt_word)left;
	word_right = (ptxt_word)right;
	int count_left  = word_left->count;
	int count_right = word_right->count;
	return count_right - count_left;
}
