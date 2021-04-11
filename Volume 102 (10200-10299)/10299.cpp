/* @JUDGE_ID: 19899RK 10299 C++ "By Anadan" */
// Relatives
// Accepted (1.760 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int N, res, tmp, i, toi;

	while (scanf("%d", &N) == 1 && N){
		if (N == 1) puts("0");
		else{
			tmp = res = N;

			if (!(tmp & 1)){
				res >>= 1;
				while (!(tmp & 1)) tmp >>= 1;
			}

			for (i = 3; i * i <= tmp; i += 2){
				if (!(tmp % i)){
					res = res / i * (i - 1);
					while (!(tmp % i)) tmp /= i;
				}
			}

			if (tmp != 1) res = res / tmp * (tmp - 1);

			printf("%d\n", res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
