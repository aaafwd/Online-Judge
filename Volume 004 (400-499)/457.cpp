/* @JUDGE_ID: 19899RK 457 C++ "By Anadan" */
// Linear Cellular Automata
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

inline int getDNA(char c){
	if (c == 'W') return 3;
	else if (c == 'x') return 2;
	else if (c == '.') return 1;
	return 0;
}

inline char getsymb(int dens){
	if (dens == 0) return ' ';
	else if (dens == 1) return '.';
	else if (dens == 2) return 'x';
	return 'W';
}

int main(){
	int i, j, DNA[10], d;
	char cur[42], next[42];
	long set;
	scanf("%ld\n", &set);

	next[0] = ' '; next[41] = 0;
	while (set--){
		sprintf(cur, "%41s", ""); cur[20] = '.';
		for (i = 0; i < 10; i++) scanf("%d", DNA+i);
		for (i = 0; i < 49; i++){
			printf("%s\n", cur+1);
			for (j = 1; j <= 40; j++){
				d = getDNA(cur[j-1]) + getDNA(cur[j]) + getDNA(cur[j+1]);
				next[j] = getsymb(DNA[d]);
			}
			sprintf(cur, "%s", next);
		}
		printf("%s\n", cur+1);
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
