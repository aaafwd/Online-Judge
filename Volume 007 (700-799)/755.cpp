/* @JUDGE_ID: 19899RK 755 C++ "By Anadan" */
// 487-3279
// Accepted (3.290 seconds using as much as 10076 kbytes)
// Too much time !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

char nums[MAX][9];

int sort_function(const void *a, const void *b){
	return (strcmp((char *)a, (char *)b));
}

int main(){
	int cmp;
	long i, j, N, M, match;
	char buf[256], *p, solved;
	scanf("%ld", &N);

	while (N--){
		scanf("%ld\n", &M);
		for (i = 0; i < M; i++){
			scanf("%s\n", buf); p = buf;
			for (j = 0; j < 8; j++){
				while (*p == '-') p++;
				if (*p <= '9') nums[i][j] = *p++;
				else if (*p <= 'P')
					nums[i][j] = '2' + (*p++ - 'A') / 3;
				else nums[i][j] = '7' + (*p++ - 'Q') / 3;
			}
		}

		qsort((void *)nums, M, 9, sort_function);
		solved = 0;
		for (i = match = 1L; i < M; i++){
			if (strcmp(nums[i-1], nums[i])){
				if (match > 1L) printf("%.3s-%s %ld\n", nums[i-1], nums[i-1] + 3, match);
				match = 1L;
			}else{
				match++;
				solved = 1;
			}
		}
		if (match > 1L) printf("%.3s-%s %ld\n", nums[M-1], nums[M-1] + 3, match);
		if (!solved) printf("No duplicates.\n");
		if (N) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
