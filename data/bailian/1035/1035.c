#include <stdio.h>
#include <string.h>
#include <math.h>
#define ID 1035
#define NAME "拼写检查"

// 1、删除单词A的一个字母后得到单词B；
// 2、用任意一个字母替换单词A的一个字母后得到单词B；
// 3、在单词A的任意位置增加一个字母后得到单词B。
// 你的任务是发现词典中与给定单词相同或相似的单词。

// ?x is correct
// ?x: ?x1 ?x2 ...?xn //?x1...?xn代表词典中与需要检查的单词相似的单词
// ?x:



/**
 * [checkLiitle 比对少一个]
 * @DateTime 2018-04-08
 * @param    str1       [少一个字符串]
 * @param    str2       [比对字符串]
 * @param    num        [比对字符串个数]
 * @return              [description]
 */
int checkLiitle(char *str1,char *str2,int num)
{
	int j=0;
	int b=0;
	int sign=0;
	// num -= 1;
	// printf("%s %s %d\n", str1,str2,num);
	for (int i = 0; i < num; ++i)
	{
		j = i;
		if(b==1){
			j = i - 1;
		}
		// printf("%d %d %d\n", j,i,b);
		// printf("%d %d\n", str1[j],str2[i]);
		if(str1[j]!=str2[i]){
			if(sign!=0 || i==0){
			  b++;
			}else{
				return 2;
			}
			continue;
		}
		sign++;
	}

	return num-sign==1?1:2;
}
/**
 * [checkMore 比对多一个]
 * @DateTime 2018-04-08
 * @param    str1       [多一个字符串]
 * @param    str2       [比对字符串]
 * @param    num        [比对字符串个数]
 * @return              [description]
 */
int checkMore(char *str1,char *str2,int num)
{
	// printf("\n\n%s %s %d\n\n", str1,str2,num);
	return checkLiitle(str2,str1,++num);
}
/**
 * [checkLike 比对相同个数]
 * @DateTime 2018-04-08
 * @param    str1       [相同个数字符串]
 * @param    str2       [比对字符串]
 * @param    num        [比对字符串个数]
 * @return              [description]
 */
int checkLike(char *str1,char *str2,int num)
{
	int j=0;
	int b=0;
	// printf("%s %s %d\n", str1,str2,num);
	for (int i = 0; i < num; ++i)
	{
		j = i;
		if(b>1){
			return 2;
		}
		if(str1[j]!=str2[i]){
			b++;
			continue;
		}
	}
	return b;
}


int main()
{


	// char a[] = "more";
	// char b[] = "mre";
	// int c = checkLiitle(a,b,2);
	// printf("%d\n", c);
	// return 0;
 
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
	// printf("dictionary:%d\n",d_num);
	// for (int i = 0; i < d_num; ++i)
	// {
	// 	printf("%s\n", dictionary[i]);
	// }
	// printf("search:%d\n",s_num);
	// for (int i = 0; i < s_num; ++i)
	// {
	// 	printf("%s\n", search[i]);
	// }
	int num = 0;

	for (int i = 0; i < s_num; ++i)
	{

		printf("%s", search[i]);
		// printf("%s\n", search[i]);
		int p = 0;
		int re = -1;
		for (int j = 0; j < d_num; ++j)
		{
			// printf("%s\n", dictionary[i]);
			num = d_strlen[j] - s_strlen[i];
			// printf("%s %s %d %d\n", search[i],dictionary[j],num,s_strlen[i]);
			if(num == -1){
				re = checkLiitle(dictionary[j],search[i],s_strlen[i]);
			}else if(num == 0){
				re = checkLike(dictionary[j],search[i],s_strlen[i]);
			}else if(num == 1){
				re = checkMore(dictionary[j],search[i],s_strlen[i]);
				// re = checkMore(dictionary[j],search[i],s_strlen[i]);
			}else{
				continue;
			}
			// printf("%s %s %d %d %d\n", search[i],dictionary[j],num,s_strlen[i],re);
			// printf("%s %s\n", search[i],dictionary[j]);
			if(re == 0){
				printf("%s\n"," is correct");
				break;
			}
			if(re == 1){
   				strcpy(p_dictionary[p], dictionary[j]);
				p++;
			}
		}
		if(re==0){
			continue;
		}
		if(p==0){
			printf(":\n");
			continue;
		}
		printf(":");
		for (int h = 0; h < p; ++h)
		{
			printf(" %s", p_dictionary[h]);
		}
		printf("\n");


	}


	// 想法
	// 1.按字符串个数存储一个数组
	// 2.按顺序存储一个数组
	// 3.按顺序存储个数数组
	// 
	// 4.流程
	//   1.先找出有没有相同的字符串
	//   	1.有则直接输出，跳过此次循环
	//   2.再找出相似的字符串
	//   	1.判断字符个数
	//   	2.小于1个的判断流程
	//   	3.相同的判断流程
	//   	4.大于1个的判断流程
	//   	
	//  5.结束

	// printf("$%.2f\n", m/12);
	return 0;
}