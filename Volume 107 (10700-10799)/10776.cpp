/* @JUDGE_ID: 19899RK 10776 C++ "By Anadan" */
// Determine The combination
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int N;
char curr[128], lets[26];

void generate(int pos, int i) {
	if (pos == N) {
		puts(curr);
		return;
	}

	for (; i < 26; ++i) {
		if (!lets[i]) continue;
		curr[pos] = i + 'a';
		--lets[i];
		generate(pos + 1, i);
		++lets[i];
	}
}

int main() {
	int i;
	char str[128];

	while (scanf("%s%d", str, &N) == 2) {
		for (i = 0; i < 26; ++i) lets[i] = 0;
		for (i = 0; str[i]; ++i) ++lets[str[i]-'a'];
		curr[N] = 0;
		generate(0, 0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
