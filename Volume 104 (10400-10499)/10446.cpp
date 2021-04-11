/* @JUDGE_ID: 19899RK 10446 C++ "By Anadan" */ 
// The Marriage Interview ;-)
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long qword;

int main(){
	int set = 0, n, b, i, j;
	qword map[61][61];

	for (i = 0; i < 61; ++i) map[0][i] = map[1][i] = 1;

	for (n = 2; n < 61; ++n){
		map[n][0] = 1;
		for (b = 1; b < 61; ++b){
			map[n][b] = 1;
			for (i = 1; i <= b; ++i){
				if (n - i <= 1) ++map[n][b];
				else map[n][b] += map[n - i][b];
			}
		}
	}

	while (scanf("%d%d", &n, &b) == 2 && n <= 60){
		printf("Case %d: ", ++set);
		if (n <= 1 || b < 1) printf("1\n");
		else printf("%llu\n", map[n][b]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
