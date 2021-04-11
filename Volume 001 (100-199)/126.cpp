/* @JUDGE_ID: 19899RK 126 C++ "By Anadan" */
// The Errant Physicist
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int N, M;
struct Coeef{
	int x, y, c;
}pt[50], res[2500];

char *sreadnum(char *p, int *num){
	if (isdigit(*p)){
		*num = 0;
		while (isdigit(*p)){
			*num *= 10;
			*num += *p++ - '0';
		}
	}
	else *num = 1;

	return p;
}

int sort_function(const void *a, const void *b){
	Coeef *ca = (Coeef *)a, *cb = (Coeef *)b;
	if (ca->x > cb->x) return -1;
	else if (ca->x < cb->x) return 1;

	if (ca->y < cb->y) return -1;
	return 1;
}

void simplify(){
	int i, j;

	for (j = 0, i = 1; i < M; ++i){
		if (res[i].x == res[j].x && res[i].y == res[j].y){
			res[j].c += res[i].c;
			res[i].c = 0;
		}else j = i;
	}
}

int main(){
	int x, y, c, i;
	char str[100], powers[100], *p, sign;

	while (gets(str) && str[0] != '#'){
		N = M = 0;
		p = str;
		while(*p){
			sign = 0;
			if (*p == '-') sign = 1, ++p;
			else if (*p == '+') ++p;

			p = sreadnum(p, &pt[N].c);
			if (sign) pt[N].c = -pt[N].c;

			pt[N].x = pt[N].y = 0;
			if (*p == 'x') p = sreadnum(p + 1, &pt[N].x);
			else if (*p == 'y') p = sreadnum(p + 1, &pt[N].y);
			if (*p == 'x') p = sreadnum(p + 1, &pt[N].x);
			else if (*p == 'y') p = sreadnum(p + 1, &pt[N].y);
			if (pt[N].c) ++N;
		}

		p = gets(str);
		while (*p){
			sign = 0;
			if (*p == '-') sign = 1, ++p;
			else if (*p == '+') ++p;

			p = sreadnum(p, &c);
			if (sign) c = -c;

			x = y = 0;
			if (*p == 'x') p = sreadnum(p + 1, &x);
			else if (*p == 'y') p = sreadnum(p + 1, &y);
			if (*p == 'x') p = sreadnum(p + 1, &x);
			else if (*p == 'y') p = sreadnum(p + 1, &y);

			if (c == 0) continue;
			for (i = 0; i < N; ++i){
				res[M].c = pt[i].c * c;
				res[M].x = pt[i].x + x;
				res[M].y = pt[i].y + y;
				++M;
			}
		}

		qsort(res, M, sizeof(Coeef), sort_function);
		simplify();
		memset(str, ' ', 100);
		memset(powers, ' ', 100);

		for (c = i = 0; i < M; ++i){
			if (res[i].c == 0) continue;
			if (res[i].c < 0){
				res[i].c = -res[i].c;
				if (c) str[++c] = '-', c += 2;
				else str[c++] = '-';
			}else if (c) str[++c] = '+', c += 2;

			if (res[i].c > 1 || (res[i].x == 0 && res[i].y == 0)){
				sprintf(str + c, "%d%n", res[i].c, &x);
				c += x;
				str[c] = ' ';
			}

			if (res[i].x){
				str[c++] = 'x';
				if (res[i].x > 1){
					sprintf(powers + c, "%d%n", res[i].x, &x);
					c += x;
					powers[c] = ' ';
				}
			}

			if (res[i].y){
				str[c++] = 'y';
				if (res[i].y > 1){
					sprintf(powers + c, "%d%n", res[i].y, &x);
					c += x;
					powers[c] = ' ';
				}
			}
		}

		str[c] = powers[c] = 0;
		if (c) printf("%s\n%s\n", powers, str);
		else printf(" \n0\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
