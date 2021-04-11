/* @JUDGE_ID: 19899RK 699 C++ "By Anadan" */
// The Falling Leaves
// Accepted (0.199 seconds using as much as 392 kbytes)

#include <stdio.h>
#define SZ 102

int left[SZ], right[SZ], l, r;

void scanftree(int level){
	int x;

	while (scanf("%d", &x) == 1 && x != -1){
		if (level >= 0){
			if (level == r) right[r++] = x;
			else right[level] += x;
		}else{
			if (-level - 1 == l) left[l++] = x;
			else left[-level - 1] += x;
		}

		scanftree(level++ - 1);
	}
}

int main(){
	int i, set = 0;

	while (1){
		l = r = 0;
		scanftree(0);
		if (l == 0 && r == 0) break;

		printf("Case %d:\n", ++set);
		if (l){
			printf("%d", left[l - 1]);
			for (i = l - 2; i >= 0; --i){
				printf(" %d", left[i]);
			}

			for (i = 0; i < r; ++i) printf(" %d", right[i]);
		}else{
			printf("%d", right[0]);
			for (i = 1; i < r; ++i) printf(" %d", right[i]);
		}

		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
