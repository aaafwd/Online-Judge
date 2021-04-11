/* @JUDGE_ID: 19899RK 741 C++ "By Anadan" */
// Burrows Wheeler Decoder
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Letters{
	char c;
	int i;
}pt[301];

int sort_function(const void *a, const void *b){
	Letters *la = (Letters *)a, *lb = (Letters *)b;
	if (la->c < lb->c) return -1;
	if (la->c > lb->c) return 1;
	if (la->i < lb->i) return -1;
	return 1;
}

int main(){
	int N, i;
	char str[301], flag = 0;

	while (scanf("%s\n%d\n", str, &N) == 2 && N){
		if (flag) putchar('\n'); else flag = 1;
		for (i = 0; str[i]; ++i){
			pt[i].c = str[i];
			pt[i].i = i;
		}

		qsort(pt, i, sizeof(Letters), sort_function);

		i = --N;
		do{
			putchar(pt[i].c);
			i = pt[i].i;
		}while (i != N);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
