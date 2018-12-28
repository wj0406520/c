#include <stdio.h>

#define ID 41  //完成
// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

int firstMissingPositive(int* nums, int numsSize) {
	int target[numsSize+2];
	for (int i = 0; i < numsSize+2; ++i)
	{
		target[i] = 0;
	}
	for (int i = 0; i < numsSize; ++i)
	{
		if(nums[i]<=0){
			continue;
		}
		if(nums[i]>numsSize){
			continue;
		}
		target[nums[i]] = 1;
		// printf("%d\n", nums[i]);
	}

	for (int i = 1; i < numsSize+2; ++i)
	{
		if(target[i]==0){
			return i;
		}
	}
    return 1;
}


int main()
{
	int s[] = {1,2,0};
	int a = firstMissingPositive(s,3);
	printf("%d\n", a);
}