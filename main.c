#include <stdio.h>
#include <string.h>
#include <math.h>

struct ln{
	char *s;
	struct ln *p;
};
int main()
{
	int num,length;
	scanf("%d",&length);
	scanf("%d",&num);
	//多一个存储\n不然变成一行了
	char str[num][length+1];
	int count[num];
	ln al[6000];
	// 按逆序对数从少到多输出字符串，逆序对数一样多的字符串按照输入的顺序输出。
	// ACGT
	for (int i = 0; i < num; ++i)
	{
		int n=0;
		int m[4]={0,0,0,0};
		scanf("%s",str[i]);
		// printf("%s\n", str[i]);
	    struct ln l;        /* 声明 Book1，类型为 Books */
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
		l.s = str[i];
		// printf("%s\n", l.s);
		// printf("%s\n",al[n].s);
		if(al[n].s==NULL){
			al[n] = l;
		}else{
			struct ln *m;
			m = al[n].p;
			while(m->p != NULL){
				m = m->p;
			}
			m->p = &l;
		}
	}

	for (int i = 0; i < 5000; ++i)
	{
		if(al[i].s == NULL) continue;
		if(al[i].p==NULL){
			printf("%s\n", al[i].s);
		}else{
			struct ln *m;
			m = al[i].p;
			while(m->p != NULL){
				printf("%s\n", m->s);
				m = m->p;
			}
			printf("%s\n", m->s);
		}
		// printf("%s\n", str[i]);
		/* code */
	}
	// 解法1
	// 1.4后面小于4的都是逆序对
	// 2.3后面小于3的都是逆序对
	// 4.2后面小于2的都是逆序对

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
