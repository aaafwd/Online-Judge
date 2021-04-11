/* @JUDGE_ID: 19899RK 10344 C++ "By Anadan" */
// 23 Out of 5
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int a[5], b[5];

inline int abs(int x) { return (x < 0) ? (-x) : (x); }

int is23(){
	int o[4], i, j, k;

	for (o[0] = 0; o[0] < 3; ++o[0]){
		if (o[0] == 0) i = a[b[0]] + a[b[1]];
		else if (o[0] == 1) i = a[b[0]] - a[b[1]];
		else if (o[0] == 2) i = a[b[0]] * a[b[1]];

		for (o[1] = 0; o[1] < 3; ++o[1]){
			if (o[1] == 0) j = i + a[b[2]];
			else if (o[1] == 1) j = i - a[b[2]];
			else if (o[1] == 2) j = i * a[b[2]];

			for (o[2] = 0; o[2] < 3; ++o[2]){
				if (o[2] == 0) k = j + a[b[3]];
				else if (o[2] == 1) k = j - a[b[3]];
				else if (o[2] == 2) k = j * a[b[3]];

				if (abs(k + a[b[4]]) == 23) return 1;
				if (abs(k - a[b[4]]) == 23) return 1;
				if (abs(k * a[b[4]]) == 23) return 1;
			}
		}
	}

	return 0;
}

int solvable(){
	for (b[0] = 0; b[0] < 5; ++b[0]){
		for (b[1] = 0; b[1] < 5; ++b[1]){
			if (b[0] == b[1]) continue;
			for (b[2] = 0; b[2] < 5; ++b[2]){
				if (b[2] == b[0] || b[2] == b[1]) continue;
				for (b[3] = 0; b[3] < 5; ++b[3]){
					if (b[3] == b[0] || b[3] == b[1] || b[3] == b[2]) continue;
					b[4] = 10 - b[0] - b[1] - b[2] - b[3];
					if (is23()) return 1;
				}
			}
		}
	}

	return 0;
}

int main(){
	int i;

	while (1){
		for (i = 0; i < 5; ++i) scanf("%d", a + i);
		for (i = 0; i < 5; ++i) if (a[i]) break;
		if (i == 5) break;
		if (solvable()) printf("Possible\n");
		else printf("Impossible\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
