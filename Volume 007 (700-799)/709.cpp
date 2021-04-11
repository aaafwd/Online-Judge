/* @JUDGE_ID: 19899RK 709 C++ "By Anadan" */ 
// Formatting Text
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 2000

struct Words{
	char *s;
	int badness, len, back, rest;
}pt[SZ];

int getbadness(int rest, int count){
	int i, res = 0;

	while (count){
		i = rest / count;
		res += (i - 1) * (i - 1);
		rest -= i;
		--count;
	}

	return res;
}

int getlines(int n){
	int res = 0;

	while (n >= 0){
		n = pt[n].back - 1;
		++res;
	}

	return res;
}

void outprint(int n){
	int i, j;

	if (n < 0) return;
	outprint(pt[n].back - 1);

	for (i = pt[n].back; i < n; ++i){
		j = pt[n].rest / (n - i);
		printf("%s", pt[i].s);
		pt[n].rest -= j;
		while (j--) putchar(' ');
	}

	printf("%s\n", pt[n].s);
}

int main(){
	int N, W, i, j, k, s, count;
	char str[81], *p;

	while (scanf("%d", &N) == 1 && N){
		while (getchar() != '\n');

		W = 0;
		j = '\n';
		while ((i = getchar()) != EOF){
			if (i == '\n' && j == '\n') break;
			if (i != ' '){
				str[0] = i;
				for (p = str + 1; (i = getchar()) != EOF; *p++ = i){
					if (i == ' ' || i == '\n' || i == EOF) break;
				}
				*p = 0;

				pt[W].s = strcpy((char *)malloc(int(p - str + 1)), str);
				pt[W++].len = int(p - str);
			}

			j = i;
		}

		pt[0].back = 0;
		if (pt[0].len == N) pt[0].badness = 0; else pt[0].badness = 500;
		for (i = 1; i < W; ++i){
			pt[i].back = i;
			if (pt[i].len == N) pt[i].badness = pt[i - 1].badness;
			else{
				k = pt[i].len; 
				pt[i].badness = pt[i - 1].badness + 500;
				count = 1;
				for (j = i - 1; j >= 0; --j){
					k += pt[j].len + 1;
					if (k > N) break;
					s = getbadness(N - k + count, count);
					if (j) s += pt[j - 1].badness;
					if (pt[i].badness > s || (pt[i].badness == s && j && getlines(j - 1) < getlines(pt[i].back - 1))){
						pt[i].badness = s;
						pt[i].back = j;
						pt[i].rest = N - k + count;
					}

					++count;
				}
			}
		}

		outprint(W - 1);
		putchar('\n');

		for (i = 0; i < W; ++i) free(pt[i].s);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
