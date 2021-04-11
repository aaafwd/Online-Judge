/* @JUDGE_ID: 19899RK 10066 C++ "By Anadan" */
// The Twin Towers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

inline int max(int a, int b) { if (a > b) return a; else return b; }

int main(){
	int i, j, N1, N2, tower1[100], tower2[100], set = 0;
	char str1[101], str2[101];

	str2[0] = 0;
	while (scanf("%d%d", &N1, &N2) == 2){
		if (N1 == 0) break;
		for (i = 0; i < N1; ++i) scanf("%d", tower1 + i);
		for (i = 0; i < N2; ++i) scanf("%d", tower2 + i);

		memset(str1, 0, N2 + 1);
		for (i = 0; i < N1; ++i){
			for (j = 1; j <= N2; ++j){
				if (tower1[i] == tower2[j - 1]) str2[j] = str1[j-1] + 1;
				else str2[j] = max(str1[j], str2[j-1]);
			}
			memcpy(str1, str2, N2 + 1);
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++set, int(str1[N2]));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
