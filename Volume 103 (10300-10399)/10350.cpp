/* @JUDGE_ID: 19899RK 10350 C++ "By Anadan" */ 
// Liftless EME
// Accepted (0.156 seconds using as much as 388 kbytes)

#include <stdio.h>

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int i, j, k, n, m, tt[15], tt0[15], tmp;
	char str[16];

	while (scanf("%s%d%d", str, &n, &m) == 3){
		for (i = 0; i < m; ++i) tt[i] = 0;
		for (k = 1; k < n; ++k){
			for (i = 0; i < m; ++i) tt0[i] = -1;
			for (i = 0; i < m; ++i){
				for (j = 0; j < m; ++j){
					myscanf(tmp);
					tmp += tt[i] + 2;
					if (tt0[j] == -1 || tt0[j] > tmp) tt0[j] = tmp;
				}
			}

			for (i = 0; i < m; ++i) tt[i] = tt0[i];
		}

		for (j = i = 0; i < m; ++i) if (tt[j] > tt[i]) j = i;

		puts(str);
		printf("%d\n", tt[j]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
