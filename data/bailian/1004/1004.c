#include <stdio.h>
#include <string.h>
#include <math.h>
#define ID 1004
int main()
{
	float n,m=0;

	for (int i = 0; i < 12; ++i)
	{
		scanf("%f",&n);
		m +=n;
	}

	printf("$%.2f\n", m/12);
	return 0;
}
