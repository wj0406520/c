#include <stdio.h>
#include <string.h>
#include <math.h>
#define ID 1002
int geta(int x){
	if(x>81){
		x=x-1;
	}
	return (x - 65) / 3 + 2;
}
int main()
{
	int a,c,b,d,f;
	scanf("%d",&a);
	char all[20];
	int allc[a],allb[a];

	f=0;
	for (int i = 0; i < a; ++i)
	{
		scanf("%s",all);

		int l = strlen(all);
		c=b=0;
		d=1;
		for (int j = 0; j < l; ++j)
		{
			int n,m;
			m = all[j];

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

		for (int k = 0; k < f; ++k)
		{
			if(allc[k]==b){
				allb[k] += 1;
				d++;
				break;
			}
		}
		if(d==1){
			allc[f] = b;
			allb[f] = d;
			f++;
		}

	}

	d=0;
	for (int i = 0; i < f; ++i)
	{
	// printf("%d\n", allc[i]);
		if(allb[i]>1){
			// allh[allc[i]] = allb[i];
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
