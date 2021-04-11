/* @JUDGE_ID: 19899RK 133 C++ "By Anadan" */
// The Dole Queue
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char flag[20];
	int i, x, y, N, dk, dm, k0, m0;
	long k, m;

	while (scanf("%d%ld%ld", &N, &k, &m) == 3){
		if ((!N) && (!k) && (!m)) break;
		memset(flag, 0, 20);
		i = N; k0 = 0; m0 = N-1;
		while (i){
			dk = i + int(k % i); x = k0;
			while(1){
				if (!flag[x]) dk--;
				if (!dk) break;
				x = (x + 1) % N;
			}

			dm = i + int(m % i); y = m0;
			while(1){
				if (!flag[y]) dm--;
				if (!dm) break;
				y = (y + N - 1) % N;
			}
			k0 = x; m0 = y;
			flag[x] = flag[y] = 1;
			if (i-- < N) printf(",");
			if (x == y) printf("%3d", x+1);
			else{
				printf("%3d%3d", x+1, y+1);
				i--;
			}
		}
		printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
