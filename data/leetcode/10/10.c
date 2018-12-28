#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID 10
/*
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 */

bool isMatch(char* s, char* p) {
	bool re = true;

	int c_p = strlen(p)-1;
	int c_s = strlen(s)-1;

	int location_s = 0;
	int location_p = 0;
//1.获取最大重复值 o(s)
//2.检测*个数 o(p)
//3.生成对应个数的所有字符串
//4.匹配所有的字符串
//5.返回结果
	for (int i = 0; i <= c_p; i++){
		// printf("%c\n", p[i]);
		if(p[i+1]=='*'){
			if(p[i]=='.'){
				location_s = c_s + 1;
			}
			if(p[i]==s[location_s] & p[i]!='.'){
				while(p[i]==s[location_s]){
					location_s++;
				}
			}
			i++;
		}else{
			if(p[i]==s[location_s] | p[i]=='.'){
				location_s++;
			}else{
				if(s[location_s-2]==s[location_s-1] & p[i-1]=='*'){
					continue;
				}

				return false;
			}
		}
		// printf("%c\n", p[i+1]);
	}
	location_s--;
	// printf("%d\n", location_s);

    return location_s==c_s;
}

int main()
{
	char s[] = "bbbba";
	char p[] = ".*a*a";
	bool a = isMatch(s,p);
	int num = 0;
	num = a?1:0;
	printf("%d\n", num);
}
bool isMatch1(char* s, char* p) {
	bool re = true;

	int location = 0;
	int i = 0;

	char up = 0;
	char pnext = 0;
	char snext = 0;

	char *temp = s;

	while(*p){
	    i = 0;
	    s = temp;
	    while(*s){
	    	pnext = *(p+1);
	    	snext = *(s+1);
	    	if(i<location){
		    	i++;
		    	s++;
	    		continue;
	    	}
	    	if(*p=='*'){
	    		if(!pnext){
	    			break;
	    		}
	    		if(pnext==*s){
		    		location = i;
		    		up = *s;
		    		break;
	    		}
	    		if(!snext){
	    			break;
	    		}
	    		if(pnext==snext){
		    		location = i+1;
		    		up = *s;
		    		break;
	    		}
	    	}
	    	if(*p=='?'){
	    		location = i+1;
	    		up = *s;
	    		break;
	    	}
	    	if(*p!=*s && up>0){
	    		re = false;
	    		break;
	    	}
	    	if(*p==*s){
	    		location = i+1;
	    		up = *s;
	    		break;
	    	}
	    	i++;
	    	s++;
	    }
	    if(!re){
	    	break;
	    }
	    p++;
	}

    return re;
}

