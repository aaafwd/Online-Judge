/* @JUDGE_ID: 19899RK 552 C++ "By Anadan" */ 
// Filling the Gaps
// Accepted (0.113 seconds using as much as 448 kbytes)

#include <stdio.h>
#include <string.h>

int L, M, tmp;
char str[16];
char pattern[32678], nums[32678];

void setnums(char *s){
	char *p = strchr(s, '*');

	if (p == NULL){
		tmp = 0;
		for (p = str; *p; ++p){
			tmp <<= 1;
			if (*p == '1') ++tmp;
		}

		if (nums[tmp] == 0){
			nums[tmp] = 1;
			++M;
		}

		return;
	}

	*p = '0';
	setnums(p + 1);
	*p = '1';
	setnums(p + 1);
	*p = '*';
}

int main(){
	int N, i;
	char *p;

	while (scanf("%d%d\n", &L, &N) == 2){
		if (L == 0 && N == 0){
			printf("YES 0\n");
			break;
		}

		i = 1 << L;
		while (i--) pattern[i] = nums[i] = 0;

		M = 0;
		while (N--){
			scanf("%s\n", str);
			for (i = 0, p = str; *p; ++p){
				i <<= 1;
				if (*p == '*') ++i;
			}
			if (pattern[i]) break;
			pattern[i] = 1;
			setnums(str);
		}

		if (N >= 0){
			while (N--) scanf("%*s\n");
			printf("NO\n");
		}else{
			printf("YES %d\n", M);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
