/* @JUDGE_ID: 19899RK 10507 C++ "By Anadan" */ 
// Waking up brain
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int map[26][26];
char mask[26];

int main(){
	int N, M, yy, awake, newa, i, j, k;
	char str[81], *p, tmp[26];

	while (scanf("%d%d%s", &N, &M, str) == 3){
		memset(map, 0, sizeof(map));
		memset(mask, 0, sizeof(mask));

		awake = 0;
		for (p = str; *p; ++p){
			mask[*p - 'A'] = 1;
			++awake;
		}

		if (awake != 3) while (1) putchar('*');

		while (M--){
			scanf("%s", str);
			map[str[0] - 'A'][str[1] - 'A'] = 1;
			map[str[1] - 'A'][str[0] - 'A'] = 1;
		}

		for (yy = 0; awake != N; ++yy){
			newa = awake;
			memset(tmp, 0, sizeof(tmp));
			for (i = 0; i < 26; ++i){
				if (mask[i]) continue;
				for (k = j = 0; j < 26; ++j){
					if (mask[j] && map[i][j]) ++k;
					if (k >= 3) break;
				}
				if (k >= 3) tmp[i] = 1;
			}

			for (i = 0; i < 26; ++i){
				if (tmp[i]){
					if (mask[i]) while (1);
					mask[i] = 1;
					++newa;
				}
			}

			if (newa == awake) break;
			awake = newa;
		}

		if (awake > N) while (1);
		if (awake == N) printf("WAKE UP IN, %d, YEARS\n", yy);
		else puts("THIS BRAIN NEVER WAKES UP");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
