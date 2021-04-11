/* @JUDGE_ID: 19899RK 10008 C++ "By Anadan" */
// What's Cryptanalysis?
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Symb{
	char c;
	int f;
}pt[26];

int sort_function(const void *a, const void *b){
	Symb *p1 = (Symb *)a, *p2 = (Symb *)b;
	if (p1->f < p2->f) return 1;
	if (p1->f == p2->f && p1->c > p2->c) return 1;
	return -1;
}

int main(){
	int i, N;
	char str[1024], *p;
	scanf("%d\n", &N);

	for (i = 0; i < 26; i++){
		pt[i].c = 'A' + i;
		pt[i].f = 0;
	}
	while (N--){
		gets(str);
		for (p = str; *p; p++){
			if (isalpha(*p)){
				pt[toupper(*p) - 'A'].f++;
			}
		}
	}
	qsort((void *)pt, 26, sizeof(Symb), sort_function);
	for (i = 0; i < 26; i++){
		if (!pt[i].f) break;
		printf("%c %d\n", pt[i].c, pt[i].f);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
