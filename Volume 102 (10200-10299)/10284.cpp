/* @JUDGE_ID: 19899RK 10284 C++ "By Anadan" */ 
// Chessboard in FEN
// Accepted (0.090 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char space[12][12], fig[12][12];

void checkchessboard(){
	int i, j, k;

	for (i = 2; i <= 9; ++i) for (j = 2; j <= 9; ++j){
		if (fig[i][j] == ' ') continue;
		space[i][j] = 1;

		if (fig[i][j] == 'r' || fig[i][j] == 'R' || fig[i][j] == 'q' || fig[i][j] == 'Q'){
			for (k = 1; fig[i - k][j] == ' '; ++k) space[i - k][j] = 1;
			for (k = 1; fig[i + k][j] == ' '; ++k) space[i + k][j] = 1;
			for (k = 1; fig[i][j - k] == ' '; ++k) space[i][j - k] = 1;
			for (k = 1; fig[i][j + k] == ' '; ++k) space[i][j + k] = 1;
		}

		if (fig[i][j] == 'b' || fig[i][j] == 'B' || fig[i][j] == 'q' || fig[i][j] == 'Q'){
			for (k = 1; fig[i - k][j - k] == ' '; ++k) space[i - k][j - k] = 1;
			for (k = 1; fig[i + k][j + k] == ' '; ++k) space[i + k][j + k] = 1;
			for (k = 1; fig[i + k][j - k] == ' '; ++k) space[i + k][j - k] = 1;
			for (k = 1; fig[i - k][j + k] == ' '; ++k) space[i - k][j + k] = 1;
		}

		if (fig[i][j] == 'k' || fig[i][j] == 'K'){
			space[i - 1][j - 1] = space[i - 1][j] = space[i - 1][j + 1] = 1;
			space[i + 1][j - 1] = space[i + 1][j] = space[i + 1][j + 1] = 1;
			space[i][j - 1] = space[i][j + 1] = 1;
		}else if (fig[i][j] == 'n' || fig[i][j] == 'N'){
			space[i - 2][j - 1] = space[i - 2][j + 1] = 1;
			space[i + 2][j - 1] = space[i + 2][j + 1] = 1;
			space[i - 1][j - 2] = space[i - 1][j + 2] = 1;
			space[i + 1][j - 2] = space[i + 1][j + 2] = 1;
		}
		else if (fig[i][j] == 'p') space[i + 1][j - 1] = space[i + 1][j + 1] = 1;
		else if (fig[i][j] == 'P') space[i - 1][j - 1] = space[i - 1][j + 1] = 1;
	}
}

int main(){
	int i, j, k;
	char str[81], *p;

	memset(fig, 0, sizeof(fig));
	while (scanf("%s\n", str) == 1){
		p = str;
		for (i = 2; i <= 9; ++i){
			for (j = 2; *p; ++p){
				if (*p == '/') { ++p; break; }
				if ('0' <= *p && *p <= '8'){
					for (k = *p - '0'; k--;) fig[i][j++] = ' ';
				}else fig[i][j++] = *p;
			}
		}

		memset(space, 0, sizeof(space));
		checkchessboard();

		for (k = 0, i = 2; i <= 9; ++i) for (j = 2; j <= 9; ++j){
			if (!space[i][j]) ++k;
		}

		printf("%d\n", k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
