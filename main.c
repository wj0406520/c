#include <stdio.h>
#include <string.h>

#define ID 1017

int main()
{
	int n[6],s[6];
	int count=10;

	// for (int i = 0; i < 50; ++i)
	// {
	// 	printf("%d %d %d %d %d %d\n", i,i+1,i+2,i+3,i+4,i+5);
	// 	printf("%d %d %d %d %d %d\n", i+5,i+4,i+3,i+2,i+1,i);
	// 	/* code */
	// }
	// return 0;

	while(1){
		count = 0;
		for (int i = 0; i < 6; ++i)
		{
			scanf("%d",&n[i]);
			s[i]=n[i];
			/* code */
		}
		if(n[0]==0 && n[1]==0 && n[2]==0 && n[3]==0 && n[4]==0 && n[5]==0) return 0;

		count += n[5];

		count += n[4];
		n[0] -= n[4]*11;

		count += n[3];
		if(n[1]<5*n[3]){
			n[0] -= 20*n[3] - n[1]*4;
			n[1] = 0;
		}else{
			n[1] -= n[3]*5;
			// n[0] -= n[3]*2;
		}
		// printf("\n%d %d\n\n", n[0],n[1]);
		count += n[2]/4;
		int y = n[2]%4;

		if(y!=0){
			switch (y){
				case 1:
					if(n[1]>5){
						n[1] -= 5;
						n[0] -= 7;
					}else{
						n[0] -= 36-9-4*n[1];
						n[1] = 0;
					}
				break;
				case 2:
					if(n[1]>3){
						n[1] -= 3;
						n[0] -= 6;
					}else{
						n[0] -= 36-18-4*n[1];
						n[1] = 0;
					}
				break;
				case 3:
					if(n[1]>1){
						n[1] -= 1;
						n[0] -= 5;
					}else{
						n[0] -= 36-27-4*n[1];
						n[1] = 0;
					}
				break;
			}
			count++;
		}
		// count = -18/2;
		// printf("%d\n", count);
		if(n[1]>0){
			count += n[1]/9;
			y = n[1]%9;
			if(y!=0){
				n[0] -= 36 - 4*y;
				count++;
			}
		}

		if(n[0]>0){
			count += n[0]/36;
			y = n[0]%36;
			if(y!=0){
				count ++;
			}
		}
		// if(count==3){
			// printf("%d %d %d %d %d %d\n", s[0],s[1],s[2],s[3],s[4],s[5]);
		// }else{
		// 	continue;
		// }
		printf("%d\n", count);
// 5
// 1 20 5 1 1 1
// 1+1+1+1+1
		// printf("%d %d %d %d %d %d\n", n[0],n[1],n[2],n[3],n[4],n[5]);
	}
	return 0;
}
