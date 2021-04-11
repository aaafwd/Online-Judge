/* @JUDGE_ID: 19899RK 312 C++ "By Anadan" */ 
// Crosswords (II)
// Accepted (0.162 seconds using as much as 392 kbytes)

#include <stdio.h>

int map[27][27];

void mark(int i, int j){
	map[i][j] = 2;
	if (map[i - 1][j] == 1) mark(i - 1, j);
	if (map[i + 1][j] == 1) mark(i + 1, j);
	if (map[i][j - 1] == 1) mark(i, j - 1);
	if (map[i][j + 1] == 1) mark(i, j + 1);
}

int main(){
	int r, c, i, j, k, sp;

	for (i = 0; i < 27; ++i) map[0][i] = map[i][0] = 2;

	while (scanf("%d%d\n", &r, &c) == 2 && r){
		for (i = 1; i <= r; ++i){
			for (j = 1; j <= c; ++j){
				while ((k = getchar()) == ' ');
				map[i][j] = k - '0';
			}
			while (getchar() != '\n');
			map[i][j] = 2;
		}
		for (j = 0; j <= c + 1; ++j) map[i][j] = 2;

		for (i = 1; i <= r; ++i){
			if (map[i][1] == 1) mark(i, 1);
			if (map[i][c] == 1) mark(i, c);
		}

		for (j = 1; j <= c; ++j){
			if (map[1][j] == 1) mark(1, j);
			if (map[r][j] == 1) mark(r, j);
		}

		for (k = 0, i = 1; i <= r; ++i){
			for (j = 1; j <= c; ++j){
				if (map[i][j] == 0 && ((map[i - 1][j] > 0 && map[i + 1][j] < 1) || (map[i][j - 1] > 0 && map[i][j + 1] < 1))){
					map[i][j] = --k;
				}
			}
		}

		for (i = 1; i <= r; ++i){
			for (k = c; k > 0 && map[i][k] == 2; --k);
			for (sp = 0, j = 1; j <= c; ++j){
				if (map[i][j] != 2 || map[i - 1][j] != 2){
					while (sp--) putchar(' ');
					fputs("+++++", stdout);
					sp = 0;
				}else{
					if (map[i][j - 1] != 2 || map[i - 1][j - 1] != 2) putchar('+');
					else ++sp;
					sp += 4;
				}
			}
			if (sp == 0) putchar('+');
			putchar('\n');

			for (j = 1; j <= k; ++j){
				if (map[i][j] < 0){
					putchar('+');
					sp = -map[i][j] / 10;
					putchar(sp / 10 + '0');
					putchar(sp % 10 + '0');
					putchar((-map[i][j]) - sp * 10 + '0');
					putchar(' ');
				}
				else if (map[i][j] == 1) fputs("+++++", stdout);
				else if (map[i][j] == 0 || map[i][j - 1] != 2) fputs("+    ", stdout);
				else fputs("     ", stdout);
			}
			if (k) putchar('+');
			putchar('\n');

			for (j = 1; j <= k; ++j){
				if (map[i][j] == 1) fputs("+++++", stdout);
				else if (map[i][j] <= 0 || map[i][j - 1] != 2) fputs("+    ", stdout);
				else fputs("     ", stdout);
			}
			if (k) putchar('+');
			putchar('\n');
		}

		for (sp = 0, j = 1; j <= c; ++j){
			if (map[r][j] != 2){
				while (sp--) putchar(' ');
				fputs("+++++", stdout);
				sp = 0;
			}else{
				if (map[r][j - 1] != 2) putchar('+');
				else ++sp;
				sp += 4;
			}
		}
		if (sp == 0) putchar('+');
		fputs("\n\n", stdout);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
