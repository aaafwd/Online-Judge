/* @JUDGE_ID: 19899RK 10132 C++ "By Anadan" */ 
// File Fragmentation
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct File{
	char name[256];
	int len, i;
}pt[290];
int N, sum;
char filename[256];

int found(){
	int i, j, k, a, b, c;

	a = b = c = 0;
	for (i = 0; i < N; ++i){
		j = (strncmp(filename, pt[i].name, pt[i].len) == 0);
		k = (strncmp(filename + sum - pt[i].len, pt[i].name, pt[i].len) == 0);
		if (j && k) ++c;
		else if (j) ++b;
		else if (k) ++a;
		else return 0;
	}

	if (a + a > N || b + b > N) return 0;

	return 1;
}

int main(){
	int set, i, j;

	scanf("%d\n\n", &set);
	while (set--){
		N = sum = 0;
		while (gets(pt[N].name) && pt[N].name[0]){
			pt[N].len = strlen(pt[N].name);
			sum += pt[N++].len;
		}

		sum /= (N >> 1);
		for (i = 0; i < N; ++i) pt[i].i = i;

		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j){
				if (i == j || pt[i].len + pt[j].len != sum) continue;
				sprintf(filename, "%s%s", pt[i].name, pt[j].name);
				if (found()) break;
			}

			if (j < N) break;
		}

		printf("%s\n", filename);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
