/* @JUDGE_ID: 19899RK 10261 C++ "By Anadan" */ 
// Ferry Loading
// Accepted (0.523 seconds using as much as 8280 kbytes)

#include <stdio.h>

int port[202][10002];

void outprint(int n, int m){
	if (n == 0) return;
	outprint(n - 1, port[n][m]);
	if (m == port[n][m]) printf("port\n"); else printf("starboard\n");
}

int main(){
	int set, len, sum, i, j, k, n;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &len); len *= 100;
		for (i = 1; i <= len; ++i) port[0][i] = -1;
		sum = 0; port[0][0] = 0; n = 1;
		while (scanf("%d\n", &k) == 1 && k){
			for (i = 0; i <= len; ++i) port[n][i] = -1;
			sum += k;
			for (i = j = 0; i <= len; ++i){
				if (port[n - 1][i] == -1) continue;
				if (i + k <= len && sum - i - k <= len) { port[n][i + k] = i; j = 1; }
				if (sum - i <= len) { port[n][i] = i; j = 1; }
			}
			if (j == 0) break;
			++n;
		}
		while (k) scanf("%d\n", &k);

		printf("%d\n", --n);
		for (i = 0; i <= len; ++i) if (port[n][i] != -1) break;
		outprint(n, i);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
