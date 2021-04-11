/* @JUDGE_ID: 19899RK 452 C++ "By Anadan" */ 
// Project Scheduling
// Accepted (0.885 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int tm[26];
char map[26][26];

int getmintime(){
	int res = 0, min, i, j;
	char mask[26];

	while (1){
		min = -1;
		memset(mask, 0, 26);
		for (i = 0; i < 26; ++i){
			if (tm[i] == -1) continue;
			if (memchr(map[i], 1, 26) == NULL){
				mask[i] = 1;
				if (min == -1 || min > tm[i]) min = tm[i];
			}
		}

		if (min == -1) break;
		for (i = 0; i < 26; ++i){
			if (!mask[i]) continue;
			tm[i] -= min;
			if (tm[i] == 0){
				tm[i] = -1;
				for (j = 0; j < 26; ++j) map[j][i] = 0;
			}
		}

		res += min;
	}

	return res;
}

int main(){
	int set, off, i;
	char str[81], tmp[2], *p;

	scanf("%d", &set);
	gets(str); gets(str);
	while (set--){
		for (i = 0; i < 26; ++i){
			tm[i] = -1;
			memset(map[i], 0, 26);
		}

		while (gets(str) && sscanf(str, "%s%d%n", tmp, &i, &off) == 2){
			tm[*tmp - 'A'] = i;
			p = str + off;
			while (*p == ' ' || *p == '\t') ++p;
			while ('A' <= *p && *p <= 'Z'){
				map[*tmp - 'A'][*p - 'A'] = 1;
				++p;
			}
		}

		i = getmintime();
		printf("%d\n", i);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
