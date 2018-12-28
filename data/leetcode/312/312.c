#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ID 312  //
/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 */

int maxCoins(int* nums, int numsSize) {

	if(numsSize==0){
		return 0;
	}
	if(numsSize==1){
		return nums[0];
	}

	int all_num = 0;

	int min = -1;
	int index = 0;
	int index_left = 0;
	int index_right = 0;
	int left = nums[0];
	int right = nums[numsSize-1];

	int last = 0;

	for (int j = 1; j < numsSize-1; ++j)
	{
		last = 0;
		index = 0;
		index_left = 0;
		index_right = 0;
		min = -1;
		left = nums[0];
		right = nums[numsSize-1];
		for (int i = 1; i < numsSize-1; ++i)
		{
			if(nums[i]==-1){
				continue;
			}
			if(index!=index_right){
				right = nums[i];
				index_right = index;
			}
			if(nums[i]<min || min==-1){
				min = nums[i];
				index = i;
				if(i==numsSize-2){
					right = nums[numsSize-1];
				}
			}
			if(index!=index_left){
				left = nums[last];
				index_left = index;
			}
			last = i;
		}

		if(last!=numsSize-2){
			right = nums[numsSize-1];
		}

		printf("index%d\n", nums[index]);
		printf("right%d\n", right);
		printf("left%d\n", left);
		printf("\n");

		all_num += nums[index]*right*left;
		printf("all_num%d\n", all_num);
		nums[index] = -1;
	}
	all_num += nums[0]*nums[numsSize-1];

	if(nums[0]>nums[numsSize-1]){
		all_num+=nums[0];
	}else{
		all_num+=nums[numsSize-1];
	}

	// printf("all_num:%d\n",all_num);
    return all_num;
}
int main()
{
	// [9,76,64,21] 116718
	// coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
	// 21*97*64 64*76*97 76*9*97 97*60*9 9*60 60
	// 21*97*64 64*76*97 76*9*97 9*97*1 60*90 90
	// 21*97*64 64*76*97 97*76*60 76*60*9 60*9 60
	int s[] = {9,76,64,21,97,60};
	int a = maxCoins(s,6);
	printf("%d\n", a);
}