#include <stdio.h>

#define ID 84  //

//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。


int largestRectangleArea(int* heights, int heightsSize) {

	int min = 1;
	int num = heightsSize;
	if(heightsSize==1){
		return heights[0];
	}
	for (int i = 0; i < heightsSize; ++i)
	{
		if(heights[i]==0){
			num--;
			continue;
		};
		if(heights[i] < min){
			min = heights[i];
		}
	}
	int max = 0;

	while(num>0)
	{
		int len = 0;
		int max_len = 0;
		int min2 = 0;
		/* code */
		for (int j = 0; j < heightsSize; ++j)
		{
			if(heights[j]==0){
				if(len > max_len){
					max_len = len;
				}
				len = 0;
				continue;
			}
			/* code */
			if(heights[j]==min){
				heights[j] = 0;
				len++;
				num--;
			}else{
				len++;
				if(min2==0 || heights[j]<min2){
					min2 = heights[j];
				}
			}
		}

		if(len > max_len){
			max_len = len;
		}

		if(max<(max_len*min)){
			max = max_len*min;
		}


		min = min2;
		max_len = 0;
	}

    return max;
}


int main()
{
	// int s[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	// int a = trap(s,12);
	int s[] = {2,5,5,6,2,3};
	// int s[] = {2};
	int a = largestRectangleArea(s,6);
	printf("%d\n", a);
}