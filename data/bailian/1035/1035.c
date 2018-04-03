#include <stdio.h>
#include <string.h>
#include <math.h>
#define ID 1035
#define NAME "拼写检查"
int main()
{

// 1、删除单词A的一个字母后得到单词B；
// 2、用任意一个字母替换单词A的一个字母后得到单词B；
// 3、在单词A的任意位置增加一个字母后得到单词B。
// 你的任务是发现词典中与给定单词相同或相似的单词。

// ?x is correct
// ?x: ?x1 ?x2 ...?xn //?x1...?xn代表词典中与需要检查的单词相似的单词
// ?x:

// 字母只有26种可能

	char dictionary[10000][20];
	char p_dictionary[10000][20];
	int d_strlen[10000];
	char search[50][20];
	int s_strlen[50];
	int d_num = 0;
	int s_num = 0;

	int end = 0;
	int i = 0;
	while(1){
		if(end==2) break;
		if(end==0){
			scanf("%s",dictionary[i]);
			d_strlen[i]=strlen(dictionary[i]);
			d_num++;
			if(dictionary[i][0]=='#'){
				end++;
				d_num--;
				i=0;
				continue ;
			}
		}else{
			scanf("%s",search[i]);
			s_strlen[i]=strlen(search[i]);
			s_num++;
			if(search[i][0]=='#'){
				end++;
				s_num--;
			}
		}
		i++;
	}

	// return 0;
	printf("dictionary:%d\n",d_num);
	for (int i = 0; i < d_num; ++i)
	{
		printf("%s\n", dictionary[i]);
	}
	printf("search:%d\n",s_num);
	for (int i = 0; i < s_num; ++i)
	{
		printf("%s\n", search[i]);
	}


	// printf("$%.2f\n", m/12);
	return 0;
}