/* @JUDGE_ID: 19899RK 416 C++ "By Anadan" */ 
// LED Test
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char led[10][8];
const char lednums[10][8] = {
	"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY",
	"YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"
};

int match(int curr){
	int i, j;
	char mask[7];

	memset(mask, 0, sizeof(mask));
	for (i = 0; i < N; ++i, --curr){
		for (j = 0; j < 7; ++j){
			if (led[i][j] == 'Y' && (mask[j] || lednums[curr][j] == 'N')) return 0;
			if (led[i][j] != lednums[curr][j]) mask[j] = 1;
		}
	}

	return 1;
}

int main(){
	int i, j;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			while ((j = getchar()) != 'Y' && j != 'N');
			led[i][0] = j;
			for (j = 1; j < 7; ++j) led[i][j] = getchar();
		}

		for (i = 9; i >= N - 1; --i){
			if (match(i)) break;
		}

		puts((i >= N - 1) ? ("MATCH") : ("MISMATCH"));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
