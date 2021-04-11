/* @JUDGE_ID: 19899RK 628 C++ "By Anadan" */
// Passwords
// Accepted (0.060 seconds using as much as 420 kbytes)

#include <stdio.h>

int N, res[256];
char dict[100][256], rule[256];

void genpasswords(char *s, int n){
	int i;
	if (*s == 0){
		for (i = 0; i < n; ++i){
			if (res[i] > 100) putchar(res[i] - 100);
			else printf("%s", dict[res[i]]);
		}

		putchar('\n');
		return;
	}

	if (*s == '0'){
		for (i = '0'; i <= '9'; ++i){
			res[n] = i + 100;
			genpasswords(s + 1, n + 1);
		}
	}else if (*s == '#'){
		for (i = 0; i < N; ++i){
			res[n] = i;
			genpasswords(s + 1, n + 1);
		}
	}
}

int main(){
	int i, m;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i) scanf("%s\n", dict[i]);
		printf("--\n");
		scanf("%d\n", &m);
		for (i = 0; i < m; ++i){
			scanf("%s\n", rule);
			genpasswords(rule, 0);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
