/* @JUDGE_ID: 19899RK 526 C++ "By Anadan" */
// String Distance and Transform Process
// Accepted (0.146 seconds using as much as 416 kbytes)

#include <stdio.h>
#include <string.h>

struct COP{
	int pos;
	char c1, c2;
};

int main(){
	int i, j, k, map[81][81], N, M = 0;
	char str1[81], str2[81];
	COP stck[256];

	while (gets(str1) && gets(str2)){
		if (M) putchar('\n');
		N = strlen(str1) + 1;
		M = strlen(str2) + 1;
		for (i = 0; i < M; ++i) map[i][0] = i;
		for (j = 0; j < N; ++j) map[0][j] = j;

		for (j = 1; j < N; ++j){
			for (i = 1; i < M; ++i){
				k = map[i - 1][j];
				if (k > map[i][j - 1]) k = map[i][j - 1];
				if (k > map[i - 1][j - 1]) k = map[i - 1][j - 1];
				++k;

				if (str1[j - 1] == str2[i - 1] && k > map[i - 1][j - 1])
					k = map[i - 1][j - 1];

				map[i][j] = k;
			}
		}

		i = M - 1; j = N - 1; k = 0;
		while (i || j){
			if (i && map[i - 1][j] + 1 == map[i][j]){
				stck[k].c1 = 'I';
				stck[k].c2 = str2[i - 1];
				stck[k].pos = i;
				++k;
				--i;
			}else if (j && map[i][j - 1] + 1 == map[i][j]){
				stck[k].c1 = 'D';
				stck[k].pos = i + 1;
				++k;
				--j;
			}else if (map[i - 1][j - 1] + 1 == map[i][j]){
				stck[k].c1 = 'R';
				stck[k].c2 = str2[i - 1];
				stck[k].pos = i;
				++k;
				--i, --j;
			}else --i, --j;
		}

		i = 0;
		printf("%d\n", k);
		while (k--){
			printf("%d ", ++i);
			if (stck[k].c1 == 'I') printf("Insert %d,%c\n", stck[k].pos, stck[k].c2);
			else if (stck[k].c1 == 'D') printf("Delete %d\n", stck[k].pos);
			else if (stck[k].c1 == 'R') printf("Replace %d,%c\n", stck[k].pos, stck[k].c2);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
