#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ID 32  //完成
//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
int longestValidParentheses(char* s)
{
	if(s[0]=='\0'){
		return 0;
	}
	//1去除左边)
	// s=&s[1];
	int i = 0;
	int target = 0;
	while(s[i]!='\0'){
		if(s[i]==')' && target == 0){
			s = &s[i+1];
			i--;
		}else{
			target = 1;
		}
		i++;
	}
	//2去除右边(
	// s[1]='\0';
	while(s[i-1]=='('){
		if(s[i-1]==')'){
			break;
		}
		s[i-1]='\0';
		i--;
	}
	// printf("%s\n", s);
	int left_num = 0;
	int a[50000];
	int b[50000];
	i = 0;
	int right = 0;
	while (s[i]!='\0'){
		if(s[i]=='('){
			a[left_num] = i;
			left_num++;
			i++;
			continue;
		}
		if(s[i]==')' && left_num!=0){
			a[left_num] = 0;
			left_num--;
		}else{
			b[right] = i;
			right++;
		}
		i++;
	}
	int c_a = right+left_num+2;
	int c[c_a];
	c[0] = 0;
	c[right+left_num+1]=i+1;
	int n = right+left_num;
	int t = 0;
	while(1){
		if(right==0 && left_num==0){
			break;
		}
		if(right==0 && left_num!=0){
			t = a[left_num-1];
			left_num--;
		}else if(left_num==0 && right!=0){
			t = b[right-1];
			right--;
		}

		if(right!=0 && left_num!=0){
			if(a[left_num-1]>b[right-1]){
				t = a[left_num-1];
				left_num--;
			}else{
				t = b[right-1];
				right--;
			}
		}
		// printf("%d\n", t);
		// printf("%d\n", left_num);
		// printf("%d\n", right);
		c[n] = t+1;
		n--;
	}
	t = 0;
    for (int i = 0; i < c_a-1; ++i)
    {
    	if((c[i+1]-c[i])>t){
    		t = c[i+1]-c[i]-1;
    	}
    	/* code */
    }
// printf("%s\n", s);
    return t;
}
int main()
{
	char s[] = "(()";
	int a = longestValidParentheses(s);
	printf("%d\n", a);
}