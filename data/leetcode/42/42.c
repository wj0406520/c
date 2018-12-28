#include <stdio.h>

#define ID 42  // 完成 trap(On) trap1(On2) 超时(需要更好的算法)
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
int trap(int* height, int heightSize) {
    int max = 0;
    int max_temp = 0;
    int max_location = 0;
    int all_num = 0;

	for (int i = heightSize-1; i >= 0; --i)
	{
		if(height[i]>max){
			max = height[i];
			max_location = i;
		}
		// printf("%d %d\n", max_location, max);
	}

	for (int i = 0; i < max_location; ++i)
	{
		if(height[i]>max_temp){
			max_temp = height[i];
		}else{
			all_num += (max_temp-height[i]);
		}
	}
	max_temp = 0;
	for (int i = heightSize-1; i >= max_location; --i)
	{
		if(height[i]>max_temp){
			max_temp = height[i];
		}else{
			all_num += (max_temp-height[i]);
		}
	}
	// printf("%d\n", max_location);

	return all_num;
}

int trap1(int* height, int heightSize) {
    int max = 0;
    int all_num = 0;
	for (int i = 0; i < heightSize; ++i)
	{
		if(height[i]>max){
			max = height[i];
		}
	}

	for (int i = 0; i < max; ++i)
	{
		int left = 0;
		int num = 0;
		for (int j = 0; j < heightSize; ++j)
		{
			int h = height[j]-i;
			if(left==0 && h==0){
				continue;
			}
			if(num!=0 && h>0 && left==1){
				all_num += num;
				// printf("%d %d %d %d\n", num,i,j,h);
				num = 0;
				continue;
			}
			if(h>0 && left==0){
				left = 1;
				num = 0;
			}
			if(h<=0){
				++num;
			}
		}
		// printf("%d\n", all_num);
	}
	return all_num;

}


int main()
{
	// int s[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	// int a = trap(s,12);
	int s[] = {4,2,3};
	int a = trap(s,3);
	printf("%d\n", a);
}