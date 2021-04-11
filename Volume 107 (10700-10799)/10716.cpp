/* @JUDGE_ID: 19899RK 10716 C++ "By Anadan" */
// Evil Straw Warts Live
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int count[256];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int set, len, i, c, res;
	char str[128], *p, *q;

	scanf("%d", &set);
	while (set--){
		scanf("%s", str);
		memset(count, 0, sizeof(count));
		for (i = 0; str[i]; ++i) ++count[str[i]];
		len = i;
		for (c = i = 0; i < 256; ++i){
			if (!count[i]) continue;
			if (count[i] & 1){
				if (c) break; else c = i;
			}
		}
		if (i < 256) { puts("Impossible"); continue; }
		res = 0; p = str;
		while (len > 1){
			if (*p == c) _reverse(p);
			q = strrchr(p, *p);
			res += int(p + len - 1 - q);
			strcpy(q, q + 1);
			++p;
			len -= 2;
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
