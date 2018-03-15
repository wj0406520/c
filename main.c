#include <stdio.h>
#include <string.h>


int main()
{
	int num,length;
	scanf("%d",&length);
	scanf("%d",&num);
	//多一个存储\n不然变成一行了
	char str[num][length+1];
	int count[num];
	// 按逆序对数从少到多输出字符串，逆序对数一样多的字符串按照输入的顺序输出。
	// ACGT
	for (int i = 0; i < num; ++i)
	{
		int n=0;
		int m[4]={0,0,0,0};
		scanf("%s",str[i]);
		// printf("%s\n", str[i]);
		for (int j = 0; j < length; ++j)
		{

			switch(str[i][j]) {
			   case 'A':
			   		m[0]+=1;
			      break;
			   case 'C':
			   		n+=length-j-1-m[1];
			   		m[1]+=1;
			      break;
			   case 'G':
			   		n+=length-j-1-m[2]-m[1];
			   		m[2]+=1;
			      break;
			   case 'T':
			   		n+=length-j-1-m[3]-m[2]-m[1];
			   		m[3]+=1;
			      break;
			}
			/* code */
		}
		count[i] = n;

	}

	int m[2];
	for (int i = 0; i < num; ++i)
	{
		m[0] = count[i];
		m[1] = i;
		for (int j = i+1; j < num; ++j)
		{
			if(m[0]>count[j]){
				m[0]=count[j];
				m[1]=j;
			}
			/* code */
		}
		// printf("%d\n", m[1]);
		// printf("%d\n", count[m[1]]);
		int f=count[m[1]];
		count[m[1]]=count[i];
		count[i]=f;

		printf("%s\n", str[m[1]]);
		char *s=str[m[1]];
		strcpy(str[m[1]],str[i]);
		strcpy(str[i],s);
		// printf("%d\n", count[i]);
		// printf("%s\n", str[i]);
		/* code */
	}
	// 解法1
	// 1.4后面小于4的都是逆序对
	// 2.3后面小于3的都是逆序对
	// 4.2后面小于2的都是逆序对

	// CCCGGGGGGA
	// AACATGAAGG
	// GATCAGATTT
	// ATCGATGCAT
	// TTTTGGCCAA
	// TTTGGCCAAA
	// 解法2
	// 1.当前是4则有length-1个
	// 2.当后面有一个则逆序对减1
	// 3.当前是3则有length-1个

	// 4假设后面都是3则有length-j-1 出现一个4则+1
	// 3假设后面都是2则有length-j-1 出现一个3或者4则加1
	// 2假设后面都是1则有length-j-1 出现一个2或者3或者4则加1

	// 2114 3-1=2
	// 32134  4+3+0-1-1+1-1-1-1=

	return 0;
}
