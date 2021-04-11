/* @JUDGE_ID: 19899RK 129 C++ "By Anadan" */ 
// Krypton Factor
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, L, cur;
char res[81];

int generate(int pos){
	int i;
	char mask[26];

	if (cur == N){
		res[pos] = 0;
		return 1;
	}

	memset(mask, 0, L);
	for (i = (pos + 1) >> 1; i > 0; --i){
		if (strncmp(res + pos - i - i + 1, res + pos - i + 1, i - 1) == 0){
			mask[res[pos - i] - 'A'] = 1;
		}
	}

	for (i = 0; i < L; ++i){
		if (mask[i]) continue;
		res[pos] = 'A' + i;
		++cur;
		if (generate(pos + 1)) return 1;
	}

	return 0;
}

int main(){
	int i;
	char *p;

	while (scanf("%d%d\n", &N, &L) == 2 && L){
		cur = 0;
		generate(0);

		for (i = 1, p = res; *p; ++i){
			if (i % 5) putchar(*p++);
			else if (i == 80) putchar('\n');
			else putchar(' ');
		}
		printf("\n%d\n", int(p - res));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
