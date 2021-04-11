/* @JUDGE_ID: 19899RK 10062 C++ "By Anadan" */
// Tell me the frequencies!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Chars{
	char c;
	int freq;
}pt[100];

int sort_function(const void *a, const void *b){
	Chars *p1 = (Chars *)a, *p2 = (Chars *)b;
	if (p1->freq > p2->freq) return 1;
	if (p1->freq == p2->freq && p1->c < p2->c) return 1;
	return -1;
}

int main(){
	int i = 0;
	char str[1024], *p;

	while (gets(str)){
		if (i) printf("\n");
		for (i = 0; i < 100; i++){
			pt[i].c = i + 32;
			pt[i].freq = 0;
		}
		for (p = str; *p; p++){
			pt[*p - 32].freq++;
		}
		qsort((void *)pt, 100, sizeof(Chars), sort_function);
		for (i = 0; pt[i].freq == 0; i++);
		for (; i < 100; i++){
			printf("%d %d\n", pt[i].c, pt[i].freq);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
