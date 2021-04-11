/* @JUDGE_ID: 19899RK 10423 C++ "By Anadan" */ 
// Peter Takes a Tramway
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set = 0, trams[60], total, N, i, j, k, m;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < 60; ++i) trams[i] = -1;
		total = 0;
		for (i = 0; i < N; ++i){
			scanf("%d:", &j);
			while (scanf("%d", &k) == 1 && k != -1){
				trams[k] = j;
				++total;
			}
		}

		scanf("%d%d\n", &m, &N);
		printf("Case %d: Peter arrives at stop %d by tram ", ++set, N);
		N = (N - 1) % total;
		for (i = m; i < 60; ++i) if (trams[i] != -1) break;
		if (i >= 60) for (i = 0; i < 60; ++i) if (trams[i] != -1) break;
		for (m = 0; m < N; ++m){
			for (++i; i < 60; ++i) if (trams[i] != -1) break;
			if (i >= 60) for (i = 0; i < 60; ++i) if (trams[i] != -1) break;
		}

		printf("%d.\n", trams[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
