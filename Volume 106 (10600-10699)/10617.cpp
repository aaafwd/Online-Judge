/* @JUDGE_ID: 19899RK 10617 C++ "By Anadan" */
// Again Palindromes
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef long long qword;

char str[64];
qword map[64][64];

qword generate(int i, int j){
	int k;
	if (i == j) return 2;
	if (i > j) return 1;
	if (map[i][j]) return map[i][j];

	map[i][j] = generate(i + 1, j);
	for (k = i; k <= j; ++k){
		if (str[i] == str[k]) map[i][j] += generate(i + 1, k - 1);
	}

	return map[i][j];
}

int main(){
	int set;

	scanf("%d", &set);
	while (set--){
		scanf("%s", str);
		memset(map, 0, sizeof(map));
		printf("%lld\n", generate(0, strlen(str) - 1) - 1);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
