/* @JUDGE_ID: 19899RK 10591 C++ "By Anadan" */
// Happy Number
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#define SZ 1000

int set = 1, mask[SZ];

int happy(int x){
	int i, j;

	while (x > 1){
		i = 0;
		while (x){
			j = x % 10;
			x /= 10;
			i += j * j;
		}

		x = i;
		if (x < SZ){
			if (mask[x] == set) return 0;
			mask[x] = set;
		}
	}

	return 1;
}

int main(){
	int N, nt;

	scanf("%d", &nt);
	while (nt--){
		scanf("%d", &N);
		printf("Case #%d: %d is %s number.\n", set, N, happy(N) ? "a Happy" : "an Unhappy");
		++set;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
