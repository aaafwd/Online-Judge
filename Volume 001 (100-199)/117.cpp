/* @JUDGE_ID: 19899RK 117 C++ "By Anadan" */
// The Postal Worker Rings Once
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, G[26][26];
char letters[26];

int getindex(char c){
	int i;
	for (i = 0; i < N; ++i) if (letters[i] == c) return i;
	letters[N] = c;
	return N++;
}

int dijkstra(int src, int dst){
	int ro[26], i, j, min;
	char passed[26];

	memset(passed, 0, N);
	passed[src] = 1;
	for (i = 0; i < N; ++i) ro[i] = G[src][i];

	while (1){
		for (min = i = 0; i < N; ++i){
			if (passed[i] || ro[i] == 0) continue;
			if (min == 0 || min > ro[i]){
				min = ro[i];
				j = i;
			}
		}

		passed[j] = 1;
		if (j == dst) break;
		for (i = 0; i < N; ++i){
			if (passed[i] || G[j][i] == 0) continue;
			if (ro[i] == 0 || ro[i] > ro[j] + G[j][i])
				ro[i] = ro[j] + G[j][i];
		}
	}

	return ro[dst];
}

int main(){
	int i, j, k, sum;
	char str[1000], mask[26];

	while (scanf("%s\n", str) == 1 && strcmp(str, "deadend")){
		for (i = 0; i < 26; ++i) memset(G[i], 0, sizeof(int) * 26);
		memset(mask, 0, 26);
		N = sum = 0;
		do{
			i = strlen(str);
			j = getindex(str[0]);
			k = getindex(str[i - 1]);
			G[j][k] = G[k][j] = i;
			mask[j] ^= 1; mask[k] ^= 1;
			sum += i;
		}while (scanf("%s\n", str) == 1 && strcmp(str, "deadend"));

		for (i = 0; i < N; ++i) if (mask[i]) break;
		if (i < N){
			for (j = i + 1; j < N; ++j) if (mask[j]) break;
			sum += dijkstra(i, j);
		}

		printf("%d\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
