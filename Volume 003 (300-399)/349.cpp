/* @JUDGE_ID: 19899RK 349 C++ "By Anadan" */ 
// Transferable Voting (II)
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char isbad[100];
int votes[100][5];

int main(){
	char mask[5];
	int set = 0, c, rest, N, i, j, badv, count[5], min, max;

	while (scanf("%d%d", &c, &N) == 2 && (c || N)){
		memset(isbad, 0, N);
		for (badv = i = 0; i < N; ++i){
			memset(mask, 0, c);
			for (j = 0; j < c; ++j){
				scanf("%d", &votes[i][j]);
				if (votes[i][j] < 1 || votes[i][j] > c) mask[0] = 2;
				else ++mask[votes[i][j] - 1];
			}

			for (j = 0; j < c; ++j) if (mask[j] != 1) break;
			if (j < c){
				++badv;
				isbad[i] = 1;
			}
		}

		printf("Election #%d\n", ++set);
		if (badv) printf("   %d bad ballot(s)\n", badv);

		rest = c;
		memset(mask, 0, c);
		while (rest){
			for (i = 0; i < c; ++i) count[i] = 0;
			for (i = 0; i < N; ++i){
				if (isbad[i]) continue;
				for (j = 0; j < c; ++j) if (!mask[votes[i][j] - 1]) break;
				if (j < c) ++count[votes[i][j] - 1];
			}

			min = 1000;
			max = -1;
			for (i = 0; i < c; ++i){
				if (mask[i]) continue;
				if (max < count[i]) max = count[i];
				if (min > count[i]) min = count[i];
			}

			if (min == max){
				if (rest == 1){
					for (i = 0; i < c; ++i) if (!mask[i]) break;
					printf("   Candidate %d is elected.\n", i + 1);
				}else{
					printf("   The following candidates are tied:");
					for (i = 0; i < c; ++i) if (!mask[i]) printf(" %d", i + 1);
					putchar('\n');
				}

				break;
			}

			for (i = 0; i < c; ++i){
				if (mask[i] == 0 && count[i] == min){
					mask[i] = 1;
					--rest;
				}
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
