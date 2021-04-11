/* @JUDGE_ID: 19899RK 719 C++ "By Anadan" */
// Glass Beads
// Accepted (0.180 seconds using as much as 440 kbytes)

#include <stdio.h>
#define SZ 10010

char str[SZ];
int index[SZ], sp;

int main(){
	int set, len, i, j, k, ch;

	scanf("%d", &set);
	while (set--){
		scanf("%s", str);
		for (j = i = 0; str[i]; ++i) if (str[j] > str[i]) j = i;
		for (sp = i = 0; str[i]; ++i){
			if (str[i] == str[j]) index[sp++] = i;
		}
		len = i;

		if (sp == len){
			puts("1");
			continue;
		}

		for (i = 1; sp != 1; ++i){
			for (ch = 256, j = 0; j < sp; ++j){
				if (++index[j] == len) index[j] = 0;
				if (ch > str[index[j]]) ch = str[index[j]];
			}

			for (k = j = 0; j < sp; ++j){
				if (str[index[j]] != ch) continue;
				if (j && ((index[j - 1] + i) % len) == index[j]) continue;
				index[k++] = index[j];
			}
			sp = k;
		}

		printf("%d\n", (index[0]+len-i+1)%len + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
