/* @JUDGE_ID: 19899RK 10226 C++ "By Anadan" */
// Hardwood Species
// Accepted (2.637 seconds using as much as 2504 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSZ 30000u
#define STEP 2999

struct Words{
	char word[31];
	int n;
}pt[MAXSZ];
int M;

int sort_function(const void *a, const void *b){
	Words *wa = (Words *)a, *wb = (Words *)b;
	if (wa->n == 0) return 1;
	if (wb->n == 0) return -1;
	return strcmp(wa->word, wb->word);
}

/*
// Accepted (4.810 seconds using as much as 2508 kbytes)
int hashf(char *s){
	int hash = 0, i = 1;

	while (*s){
		hash += (i++) * (*s++);
	}

	return (hash - i) % MAXSZ;
}
*/
const int coeff[] = { 31, 101, 193, 67, 277 }; 
int hashf(char *s){
	int hash = 0, i = 0;

	while (*s && i < 5){
		hash += coeff[i++] * (*s++);
	}

	return hash % MAXSZ;
}

void inc_word(char *str){
	int h = hashf(str);
	while (1){
		if (pt[h].n == 0){
			strcpy(pt[h].word, str);
			pt[h].n = 1;
			++M;
			break;
		}
		if (!strcmp(pt[h].word, str)){
			++pt[h].n;
			break;
		}
		h = (h + STEP) % MAXSZ;
	}
}

int main(){
	int set, N, i;
	char str[31];

	scanf("%d\n\n", &set);
	while (set--){
		N = M = 0;
		memset(pt, 0, MAXSZ * sizeof(Words));
		while (gets(str) && str[0]){
			inc_word(str);
			++N;
		}

		qsort((void *)pt, MAXSZ, sizeof(Words), sort_function);
		for (i = 0; i < M; ++i){
			printf("%s %.4lf\n", pt[i].word, double(pt[i].n) * 100.0 / N);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
