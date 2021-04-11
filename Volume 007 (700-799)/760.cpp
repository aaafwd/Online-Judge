/* @JUDGE_ID: 19899RK 760 C++ "By Anadan" */ 
// DNA Sequencing
// Accepted (1.254 seconds using as much as 488 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int l1, l2;
char s1[310], s2[310];

inline int min(int x, int y) { return (x < y) ? (x) : (y); }

int lcs_length(){
	int i, j;
	char ch;

	for (i = min(l1, l2); i > 0; --i){
		for (j = 0; j <= l1 - i; ++j){
			ch = s1[i + j];
			s1[i + j] = 0;
			if (strstr(s2, s1 + j)) break;
			s1[i + j] = ch;
		}

		if (j <= l1 - i){
			s1[i + j] = ch;
			break;
		}
	}

	return i;
}

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int main(){
	int i, j, N, flag = 0;
	char solves[310][310], ch;

	while (scanf("%s%s\n", s1, s2) == 2){
		l1 = strlen(s1); l2 = strlen(s2);
		if (flag) putchar('\n'); else flag = 1;

		j = lcs_length();

		if (j == 0) printf("No common sequence.\n");
		else{
			N = 0;
			for (i = 0; i <= l1 - j; ++i){
				ch = s1[i + j];
				s1[i + j] = 0;
				if (strstr(s2, s1 + i)){
					strcpy(solves[N++], s1 + i);
				}
				s1[i + j] = ch;
			}

			qsort(solves, N, sizeof(solves[0]), sort_function);
			printf("%s\n", solves[0]);
			for (i = 1; i < N; ++i) if (strcmp(solves[i], solves[i - 1])) printf("%s\n", solves[i]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
