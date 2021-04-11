/* @JUDGE_ID: 19899RK 10227 C++ "By Anadan" */
// Forests
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int scanfnum(int &i){
	char c;

	while (1){
		c = getchar();
		if (c == '\n' || c == EOF){
			ungetc('\n', stdin);
			return 0;
		}
		if (('0' <= c) && (c <= '9')) break;
	}

	i = c - '0';
	while (1){
		c = getchar();
		if (('0' <= c) && (c <= '9')){
			i *= 10;
			i += c - '0';
		}else{
			ungetc(c, stdin);
			break;
		}
	}

	return 1;
}

int main(){
	int set, T, P, i, j, res;
	char opinions[100][13], flags[100];

	scanf("%d\n\n", &set);
	while (set--){
		scanfnum(P);
		scanfnum(T);
		while (getchar() != '\n');
		for (i = 0; i < P; ++i) memset(opinions[i], 0, 13);

		while(1){
			if (scanfnum(i) == 0){
				while (getchar() != '\n');
				break;
			}

			scanfnum(j);
			while (getchar() != '\n');
			--i; --j;
			opinions[i][j >> 3] |= 1 << (j & 7);
		}

		memset(flags, 0, P);
		for (res = i = 0; i < P; ++i){
			if (flags[i]) continue;
			for (j = i + 1; j < P; ++j)
				if (!memcmp(opinions[i], opinions[j], 13)) flags[j] = 1;
			++res;
		}

		printf("%d\n", res);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
