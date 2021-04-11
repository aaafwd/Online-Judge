/* @JUDGE_ID: 19899RK 665 C++ "By Anadan" */
// False coin
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	long set;
	int N, K, P, i, j, l;
	char flags[100], tmpf[100], ch;

	scanf("%ld\n\n", &set);
	while(set--){
		scanf("%d %d\n", &N, &K);
		memset(flags, 0, N);
		for (l = 0; l < K; l++){
			memset(tmpf, 0, N);
			scanf("%d", &P); P <<= 1;
			for (i = 0; i < P; i++){
				scanf("%d", &j); j--;
				tmpf[j] = 1;
			}
			scanf("\n%c\n", &ch);
			if (ch == '='){
				for (i = 0; i < N; i++){
					if (tmpf[i]) flags[i] = 1;
				}
			}else{
				for (i = 0; i < N; i++){
					if (!tmpf[i]) flags[i] = 1;
				}
			}
		}
		for (i = 0; i < N; i++) if (!flags[i]) break;
		if (i < N){
			for (j = i + 1; j < N; j++) if (!flags[j]) break;
			if (j < N) printf("0\n"); else printf("%d\n", i + 1);
		}else printf("0\n");
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
