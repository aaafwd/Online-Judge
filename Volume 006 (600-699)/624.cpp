/* @JUDGE_ID: 19899RK 624 C++ "By Anadan" */
// CD
// Accepted (0.080 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int sum, N, tracks[20], max;
char flags[20], maxf[20];

void func(int i, int s){
	int tmp;
	for (; i < N; i++){
		tmp = tracks[i] + s;
		if (tmp > sum) continue;
		flags[i]++;
		if (tmp > max){
			max = tmp;
			memcpy(maxf, flags, 20);
		}
		func(i + 1, tmp);
		flags[i]--;
	}
}

int main(){
	int i;

	while (scanf("%d", &sum) > 0){
		scanf("%d", &N);
		for (i = 0; i < N; i++) scanf("%d", tracks + i);
		memset(flags, 0, 20);
		max = -1;
		func(0, 0);
		for (i = 0; i < N; i++) if (maxf[i]){
			printf("%d", tracks[i]);
			break;
		}
		for (i++; i < N; i++) if (maxf[i]) printf(" %d", tracks[i]);
		printf(" sum:%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
