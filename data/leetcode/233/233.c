#include <stdio.h>
#include <math.h>

#define ID 233  //完成

int countDigitOne(int n)
{
	int b[20];

	long m = 1;
	int count = 0;
	while(n/m){
		b[count] = n/m%10;
		m *= 10;
		// printf("%d\n", num);
		count++;
	}

	int num = 1;
	int p = 0;
	int re = 0;

	for (int i = 0; i < count; ++i)
	{

		if(b[i] > 1 ){
			re += num*1;

			// re += b[i];
			// re += 1*b[i];
			// re += b[i];
			// re += 1*p;
		}
		if(b[i] == 1){
			re += p+1;
			// printf("5\n");
		}
		if(num>9){
			// re += num*
			re += (num/10)*i*b[i];
			// printf("3\n");
		}
		// if(b[i]>1){
			// re += num;
			// re += b[i];
		// }
		// printf("%d\n", re);
		// printf("---%d,%d,%d,%d\n", num, b[i], p, i);


		p += num * b[i];
		num = num * 10;
	}

	// printf("%d\n", re);

	// int num = n/10;
	// int a = n%10;
	// num = a>=1?num+1:num;
	// printf("%d\n", num);
	return re;
}
int main()
{

	// int a = 1410065408;
	int a = countDigitOne(1410065408);
	printf("%d\n", a);
}