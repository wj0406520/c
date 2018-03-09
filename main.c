#include <stdio.h>
#include <string.h>
#include <math.h>
int geta(int x){
	if(x>81){
		x=x-1;
	}
	return (x - 65) / 3 + 2;
}
int main()
{
	int a,c,b,d;
	scanf("%d",&a);
	char all[a][16];
	int allc[a],allb[a];
	int allh[10][10][10][a];

	for (int i = 0; i < a; ++i)
	{
		scanf("%s",all[i]);
	}
	for (int i = 0; i < a; ++i)
	{
		int l = strlen(all[i]);
		c=b=0;
		d=1;
		for (int j = 0; j < l; ++j)
		{
			int n,m;
			m = all[i][j];

			if(m==45){
				continue;
			}
			if(m > 60){
				n = geta(m);
			}else{
				n = m - 48;
			}
			b = n*pow(10, (6-c)) + b;
			c++;
		}

		allc[i] = b;
		for (int k = 0; k < i; ++k)
		{
			if(allc[k]==b){
				allb[k] = 1;
				d++;
			}
		}
		allb[i] = d;
	}
	d=0;
	for (int i = 0; i < a; ++i)
	{

		if(allb[i]>1){
			allb[d] = allb[i];
			allc[d] = allc[i];
			d++;
		}
	}
	if(d==0){
		printf("No duplicates.");
		return 0;
	}
	a=d;
	for (int i = 0; i < a - 1; ++i)
	{
		for (int j = 0; j < a - i - 1; ++j)
		{
			if(allc[j]>allc[j+1]){
				c = allc[j];
				allc[j] = allc[j+1];
				allc[j+1] = c;

				c = allb[j];
				allb[j] = allb[j+1];
				allb[j+1] = c;
			}
		}
	}

	for (int i = 0; i < a; i++)
	{
		d=allc[i]/10000;
		b=allc[i]-d*10000;
		printf("%d-%d %d\n", d,b,allb[i]);

	}


	return 0;
}
