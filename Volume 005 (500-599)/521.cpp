/* @JUDGE_ID: 19899RK 521 C++ "By Anadan" */ 
// Gossiping
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Driver{
	int line, a;
}pt[30];
int d;
char map[30][30];

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a) return a; else return b;
}

int connected(){
	int i = 0, j = 1, u, v, vertexes[30];
	char mask[30];

	memset(mask, 0, d);
	vertexes[0] = 0;
	mask[0] = 1;

	while (i < j){
		v = vertexes[i++];
		for (u = 0; u < d; ++u){
			if (mask[u] == 0 && map[v][u]){
				mask[u] = 1;
				vertexes[j++] = u;
			}
		}
	}

	return (j == d);
}

int main(){
	int n, s, i, j, k, m, count, lines[20][50], tot[20];
	char str[256], *p;

	while (scanf("%d%d%d\n", &n, &d, &s) == 3 && n && d && s){
		for (i = 0; i < n; ++i) for (j = 0; j < s; ++j) lines[i][j] = 0;
		for (i = 0; i < d; ++i) for (j = 0; j < d; ++j) map[i][j] = 0;
		for (i = 0; i < n; ++i){
			gets(str);
			count = 0;
			for (p = str; sscanf(p, "%d%n", &j, &k) == 1; p += k){
				lines[i][j - 1] = ++count;
			}
			tot[i] = count;

			gets(str);
			for (p = str; sscanf(p, "%d%d%n", &j, &k, &count) == 2; p += count){
				pt[k - 1].line = i; pt[k - 1].a = lines[i][j - 1];
			}
		}

		for (i = 0; i < d; ++i) for (j = i + 1; j < d; ++j){
			if (pt[i].line == pt[j].line){
				if (pt[i].a == pt[j].a) map[i][j] = map[j][i] = 1;
				continue;
			}

			for (m = 0; m < s; ++m){
				if (lines[pt[i].line][m] && lines[pt[j].line][m]){
					count = (tot[pt[i].line] + pt[i].a - lines[pt[i].line][m]) % tot[pt[i].line];
					count -= (tot[pt[j].line] + pt[j].a - lines[pt[j].line][m]) % tot[pt[j].line];
					if (count < 0) count = -count;
					k = gcd(tot[pt[i].line], tot[pt[j].line]);
					if (!(count % k)){
						map[i][j] = map[j][i] = 1;
						break;
					}
				}
			}
		}

		if (connected()) printf("Yes\n"); else printf("No\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
