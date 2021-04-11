/* @JUDGE_ID: 19899RK 671 C++ "By Anadan" */
// Spell checker
// Accepted (0.720 seconds using as much as 560 kbytes)

#include <stdio.h>
#include <string.h>
#define SIZE 10001

int N;
char dict[SIZE][17];

int replacable(int i){
	char *p, *q;
	for (p = dict[i], q = dict[N]; *q == *p && *q && *p; q++, p++);
	if (!strcmp(q + 1, p)) return 1;	// deleting
	if (!strcmp(q, p + 1)) return 1;	// inserting
	if (!strcmp(q + 1, p + 1)) return 1;	// replacing
	return 0;
}

int main(){
	int i, set;
	for (i = 0; i < SIZE; i++) dict[i][16] = 0;
	scanf("%d\n\n", &set);

	while (set--){
		for (N = 0; N < SIZE; N++){
			scanf("%s\n", dict[N]);
			if (dict[N][0] == '#') break;
		}

		while (scanf("%s\n", dict[N]) > 0){
			if (dict[N][0] == '#') break;
			for (i = 0; i < N; i++){
				if (!strcmp(dict[i], dict[N])) break;
			}
			if (i < N) printf("%s is correct\n", dict[N]);
			else{
				printf("%s:", dict[N]);
				for (i = 0; i < N; i++){
					if (replacable(i)) printf(" %s", dict[i]);
				}
				printf("\n");
			}
		}
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
