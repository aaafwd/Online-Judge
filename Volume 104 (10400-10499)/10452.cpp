/* @JUDGE_ID: 19899RK 10452 C++ "By Anadan" */ 
// Marcus, help!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[10][10], cur[20];
const char word[] = "IEHOVA#";

int outprint(int i, int j, int n){
	map[i][j] = 0;
	if (n == 7) return 1;
	if (map[i - 1][j] == word[n] && outprint(i - 1, j, n + 1)) { cur[n] = 0; return 1; }
	if (map[i][j - 1] == word[n] && outprint(i, j - 1, n + 1)) { cur[n] = 1; return 1; }
	if (map[i][j + 1] == word[n] && outprint(i, j + 1, n + 1)) { cur[n] = 2; return 1; }
	return 0;
}

inline void outprintdir(char c){
	if (c == 0) printf("forth");
	else if (c == 1) printf("left");
	else printf("right");
}

int main(){
	int set, i, j, r, c;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d\n", &r, &c);
		memset(map, 0, sizeof(map));
		for (i = 1; i <= r; ++i) scanf("%s\n", map[i] + 1);
		for (i = 1; i <= r; ++i){
			for (j = 1; j <= c; ++j) if (map[i][j] == '@') break;
			if (j <= c) break;
		}

		outprint(i, j, 0);
		outprintdir(cur[0]);
		for (i = 1; i < 7; ++i){
			putchar(' ');
			outprintdir(cur[i]);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
