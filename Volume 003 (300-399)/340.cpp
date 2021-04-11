/* @JUDGE_ID: 19899RK 340 C++ "By Anadan" */
// Master-Mind Hints
// Accepted (0.130 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	long set = 0L;
	char num[1001], str[1001], tmp[1001], allzero;
	int i, j, p, q, N;

	while (scanf("%d\n", &N) > 0){
		if (N == 0) break;
		printf("Game %ld:\n", ++set);
		for (i = 0; i < N; i++) scanf("%1s", num + i);
		while (1){
			allzero = 1;
			for (i = 0; i < N; i++){
				scanf("%1s", str + i);
				if (str[i] != '0') allzero = 0;
			}
			if (allzero) break;
			p = q = 0;
			memcpy(tmp, num, N);

			for (i = 0; i < N; i++){
				if (tmp[i] == str[i]){
					p++;
					tmp[i] = str[i] = 0;
				}
			}

			for (i = 0; i < N; i++){
				if (!tmp[i]) continue;
				for (j = 0; j < N; j++){
					if (!str[j]) continue;
					if (tmp[i] == str[j]){
						q++;
						tmp[i] = str[j] = 0;
					}
				}
			}

			printf("    (%d,%d)\n", p, q);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
