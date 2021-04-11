/* @JUDGE_ID: 19899RK 10625 C++ "By Anadan" */
// GNU = GNU'sNotUnix
// Accepted (0.141 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

typedef unsigned long long qword;

struct Rule{
	char c, str[128];
	int quantity[10];
} rules[10];
char ruleMask[128];
int R;

void initRules() {
	int i, j;
	char *p;
	for (i = 0; i < R; ++i) {
		memset(rules[i].quantity, 0, sizeof(rules[i].quantity));
		for (p = rules[i].str; *p; ++p) {
			j = ruleMask[*p];
			if (j != -1) ++rules[i].quantity[j];
		}
	}
}

void solve(char * str, char ch, int N) {
	int i, j;
	char *p;
	qword res = 0, quantity[10], tmp[10];

	memset(quantity, 0, sizeof(quantity));

	if (ruleMask[ch] == -1) {
		int adding[10];

		memset(adding, 0, sizeof(adding));
		for (i = 0; i < R; ++i) {
			for (p = rules[i].str; *p; ++p) {
				if (*p == ch) ++adding[i];
			}
		}

		for (p = str; *p; ++p) {
			if (ruleMask[*p] != -1) ++quantity[ruleMask[*p]];
			else if (*p == ch) ++res;
		}

		while (N--) {
			memset(tmp, 0, sizeof(tmp));
			for (i = 0; i < R; ++i) {
				res += quantity[i] * adding[i];
				for (j = 0; j < R; ++j) {
					tmp[j] += quantity[i] * rules[i].quantity[j];
				}
			}
			memcpy(quantity, tmp, sizeof(tmp));
		}
	} else {
		for (p = str; *p; ++p) {
			if (ruleMask[*p] != -1) ++quantity[ruleMask[*p]];
		}

		while (N--) {
			memset(tmp, 0, sizeof(tmp));
			for (i = 0; i < R; ++i) {
				for (j = 0; j < R; ++j) {
					tmp[j] += quantity[i] * rules[i].quantity[j];
				}
			}
			memcpy(quantity, tmp, sizeof(tmp));
		}
		res = quantity[ruleMask[ch]];
	}

	printf("%llu\n", res);
}

int main() {
	int set, i, Q;
	char str[128], ch;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &R);
		memset(ruleMask, -1, sizeof(ruleMask));
		for (i = 0; i < R; ++i) {
			scanf(" %c%*2s%s", &rules[i].c, rules[i].str);
			ruleMask[rules[i].c] = i;
		}
		initRules();
		scanf("%d", &Q);
		while (Q--) {
			scanf("%s %c %d\n", str, &ch, &i);
			solve(str, ch, i);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
