/* @JUDGE_ID: 19899RK 425 C++ "By Anadan" */ 
// Enigmatic Encryption
// Accepted (0.162 seconds using as much as 560 kbytes)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <crypt.h>
#define SZ 1001

int main(){
	int N = 0, i, j, l1, l2;
	char str[81], hash[81], words[SZ][6], *p, *q;

	scanf("%s", hash);
	while (scanf("%s", str) == 1){
		p = str;
		while (*p){
			for (; *p; ++p) if (isalpha(*p)) break;
			for (i = 0, q = p; *p && isalpha(*p); ++p, ++i){
				if ('A' <= *p && *p <= 'Z') *p += 'a' - 'A';
			}
			if (i < 2 || i > 5) continue;
			strncpy(words[N], q, i);
			words[N][i] = 0;
			for (j = 0; j < N; ++j) if (!strcmp(words[j], words[N])) break;
			if (j == N) ++N;
		}
	}

	for (i = 0; i < N; ++i){
		l1 = strlen(words[i]);
		for (j = 0; j < N; ++j){
			l2 = l1 + strlen(words[j]) + 1;
			if (l2 < 5 || l2 > 8) continue;
			sprintf(str, "%s0%s", words[i], words[j]);
			if (!strcmp(hash, crypt(str, hash))) break;
			sprintf(str, "%s2%s", words[i], words[j]);
			if (!strcmp(hash, crypt(str, hash))) break;
			sprintf(str, "%s4%s", words[i], words[j]);
			if (!strcmp(hash, crypt(str, hash))) break;
			sprintf(str, "%s8%s", words[i], words[j]);
			if (!strcmp(hash, crypt(str, hash))) break;
		}
		if (j < N) break;
	}

	printf("%s\n", str);

	return 0;
}
/* @END_OF_SOURCE_CODE */
