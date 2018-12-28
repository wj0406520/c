#include <stdio.h>
#include<math.h>
#include<stdlib.h>

#define ID 1061


// 青蛙A和青蛙B，规定纬度线上东经0度处为原点，
// 由东往西为正方向，单位长度1米，这样我们就得到了一条首尾相接的数轴。
// 设青蛙A的出发点坐标是x，青蛙B的出发点坐标是y。
// 青蛙A一次能跳m米，青蛙B一次能跳n米，两只青蛙跳一次所花费的时间相同。
// 纬度线总长L米。现在要你求出它们跳了几次以后才会碰面。
// 输入
// 输入只包括一行5个整数x，y，m，n，L，
// 其中x≠y < 2000000000，0 < m、n < 2000000000，0 < L < 2100000000。

int distence(int x,int y,int m,int n,int l,int i)
{
	int dis = abs(((m-n)*i+((m*i)/l-(n*i)/l)*l)%l);
	dis += y - x;
	return dis;
}

int main()
{
	int x,y,m,n,l,count,dis;

	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&l);

	if(m == n){
		printf("Impossible\n");
		return 0;
	}

	count = l/abs(n-m)+1;

	// printf("%d\n", count);
	for (int i = 1; i <= count; ++i)
	{
		// dis =  distence(x, y, m, n, l, i);
		dis = ((n*i+y)%l-(m*i+x)%l);

		if(dis==0){
			printf("%d\n", i);
			return 0;
		}

	}

	printf("Impossible\n");



	return 0;
}
