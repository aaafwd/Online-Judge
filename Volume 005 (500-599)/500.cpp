/* @JUDGE_ID: 19899RK 500 C++ "By Anadan" */ 
// Table
// Accepted (0.290 seconds using as much as 420 kbytes)

#include <stdio.h>
#include <string.h>

const char table[4][4] = {
	"ÚÂ¿",
	"ÃÅ´",
	"ÀÁÙ",
	"Ä³ "
};

char *getlen(char *p, int &len){
	int tmp;
	len = 2;

	while (*p == ' ') ++p;
	if (*p == table[3][1]) return ++p;
	if (*p == 0) return p;

	while (1){
		while (*p != ' ' && *p != table[3][1] && *p) ++p, ++len;
		for (tmp = 0; *p == ' '; ++p, ++tmp);
		if (*p == table[3][1]) return ++p;
		if (*p == 0) return p;
		len += tmp;
	}
}

char *outprint(char *p, int len){
	while (*p == ' ') ++p;
	while (*p != table[3][1] && *p && len > 0) putchar(*p++), --len;
	while (len-- > 0) putchar(' ');
	while (*p && *p != table[3][1]) ++p;
	if (*p == 0) return p;
	return ++p;
}

int main(){
	int rows, set, len[70], L, i, j, k;
	char str[101][256], *p;

	scanf("%d\n\n", &set);
	while (set--){
		rows = 0;
		while (gets(str[rows]) && str[rows][0]) ++rows;
		for (L = 1, p = str[0]; *p; ++p) if (*p == table[0][1]) ++L;

		for (i = 0; i < L; ++i) len[i] = 0;
		for (i = 1; i < rows - 1; ++i){
			p = str[i];
			if (*p++ == table[1][0]) continue;
			for (j = 0; j < L; ++j){
				p = getlen(p, k);
				if (len[j] < k) len[j] = k;
			}
		}

		putchar(table[0][0]);
		for (i = 0; i < L - 1; ++i){
			for (j = 0; j < len[i]; ++j) putchar(table[3][0]);
			putchar(table[0][1]);
		}
		for (j = 0; j < len[i]; ++j) putchar(table[3][0]);
		putchar(table[0][2]);
		putchar('\n');

		for (i = 1; i < rows - 1; ++i){
			p = str[i];
			if (*p++ == table[1][0]){
				putchar(table[1][0]);
				for (k = 0; k < L - 1; ++k){
					for (j = 0; j < len[k]; ++j) putchar(table[3][0]);
					putchar(table[1][1]);
				}

				for (j = 0; j < len[k]; ++j) putchar(table[3][0]);
				putchar(table[1][2]);
				putchar('\n');
			}else{
				for (j = 0; j < L; ++j){
					printf("%s", table[3] + 1);
					p = outprint(p, len[j] - 1);
				}

				putchar(table[3][1]);
				putchar('\n');
			}
		}

		putchar(table[2][0]);
		for (i = 0; i < L - 1; ++i){
			for (j = 0; j < len[i]; ++j) putchar(table[3][0]);
			putchar(table[2][1]);
		}
		for (j = 0; j < len[i]; ++j) putchar(table[3][0]);
		putchar(table[2][2]);
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
