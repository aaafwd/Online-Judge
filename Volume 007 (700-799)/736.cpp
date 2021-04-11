/* @JUDGE_ID: 19899RK 736 C++ "By Anadan" */
// Lost in Space
// Accepted (0.148 seconds using as much as 388 kbytes)

#include <stdio.h>

char map[52][52];
const char dirs[8][3] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };

int find_word(char *s, int r, int c, int k){
	while (*s){
		do{
			switch (k){
			case 1: ++c;
			case 0: --r; break;
			case 3: ++r;
			case 2: ++c; break;
			case 5: --c;
			case 4: ++r; break;
			case 7: --r;
			case 6: --c; break;
			}
		}while (map[r][c] == ' ');
		if (*s++ != map[r][c]) return 0;
	}

	return 1;
}

int main(){
	int set, N, i, j, k;
	char str[51], found;

	for (i = 0; i < 52; ++i) map[0][i] = map[i][0] = 0;
	scanf("%d\n\n", &set);
	while (set--){
		gets(str);
		sscanf(str, "%d", &N);
		for (i = 1; i <= N; ++i) gets(map[i] + 1);
		for (i = 0; i <= 52; ++i) map[N + 1][i] = 0;

		while (gets(str) && str[0]){
			found = 0;
			printf("\n%s\n", str);

			for (i = 1; i <= N; ++i)for (j = 1; j <= N; ++j){
				if (map[i][j] == str[0]){
					for (k = 0; k < 8; ++k){
						if (find_word(str + 1, i, j, k)){
							printf("(%d,%d) - %s\n", i, j, dirs[k]);
							found = 1;
						}
					}
				}
			}

			if (!found) printf("not found\n");
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
