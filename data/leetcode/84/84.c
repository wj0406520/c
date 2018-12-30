#include <stdio.h>

#define ID 84  //

//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。


int largestRectangleArea(int* heights, int heightsSize) {
	for (int i = 0; i < heightsSize; ++i)
	{
		printf("%d\n", heights[i]);
	}
    return 0;
}


int main()
{
	// int s[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	// int a = trap(s,12);
	int s[] = {2,1,5,6,2,3};
	int a = largestRectangleArea(s,6);
	printf("%d\n", a);
}