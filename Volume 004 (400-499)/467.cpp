/* @JUDGE_ID: 19899RK 467 C++ "By Anadan" */ 
// Synching Signals
// Accepted (0.514 seconds using as much as 388 kbytes)

#include <stdio.h>

int main(){
	int set = 0, sig[11], N, i, j, t;
	char str[256], *p;

	while (gets(str) && sscanf(str, "%d%n", sig, &i) == 1){
		j = sig[0] * 2;
		p = str + i;
		for (N = 1; sscanf(p, "%d%n", sig + N, &i) == 1; ++N){
			if (j > sig[N] * 2) j = sig[N] * 2;
			p += i;
		}

		for (; j <= 3600; ++j){
			for (i = 0; i < N; ++i){
				t = j % (sig[i] + sig[i]);
				if (t >= sig[i] - 5) break;
			}
			if (i == N) break;
		}

		printf("Set %d ", ++set);
		if (j <= 3600) printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", j / 60, j % 60);
		else printf("is unable to synch after one hour.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
