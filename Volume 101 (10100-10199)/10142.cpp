/* @JUDGE_ID: 19899RK 10142 C++ "By Anadan" */ 
// Australian Voting
// Accepted (0.031 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, N, B, i, j, off, min, max, votes[20];
	char names[20][81], str[256], ballots[1000][31], *p;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) gets(names[i]);
		B = 0;
		while (gets(str) && str[0]){
			for (i = 0, p = str; sscanf(p, "%d%n", &j, &off) == 1; p += off){
				ballots[B][i++] = j;
			}
			ballots[B++][i] = 0;
		}

		memset(str, 0, N);
		while (1){
			for (i = 0; i < N; ++i) votes[i] = 0;
			for (i = 0; i < B; ++i){
				for (j = 0; ballots[i][j]; ++j) if (!str[ballots[i][j] - 1]) break;
				if (ballots[i][j]) ++votes[ballots[i][j] - 1];
			}

			for (min = B, max = i = 0; i < N; ++i){
				if (str[i]) continue;
				if (max < votes[i]){
					max = votes[i];
					j = i;
				}
				if (min > votes[i]) min = votes[i];
			}

			if (max * 2 > B){
				printf("%s\n", names[j]);
				break;
			}

			if (min == max){
				for (i = 0; i < N; ++i){
					if (!str[i]) printf("%s\n", names[i]);
				}
				break;
			}

			for (i = 0; i < N; ++i) if (votes[i] == min) str[i] = 1;
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
