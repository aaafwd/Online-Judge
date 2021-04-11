/* @JUDGE_ID: 19899RK 555 C++ "By Anadan" */
// Bridge Hands
// Accepted (0.570 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char suits[] = "CDSH";
const char order[] = "23456789TJQKA";

int sort_function(const void *a, const void *b){
	char *p, *q;
	p = strchr(suits, ((char *)a)[0]);
	q = strchr(suits, ((char *)b)[0]);
	if (p < q) return -1;
	if (p > q) return 1;
	p = strchr(order, ((char *)a)[1]);
	q = strchr(order, ((char *)b)[1]);
	if (p < q) return -1;
	if (p > q) return 1;
	return 0;
}

int main(){
	int i, j, k;
	char dealer[2], str[105], *p;
	char cards[4][13][3];

	for (i = 0; i < 13; ++i) for (j = 0; j < 4; ++j) cards[j][i][2] = 0;
	while (scanf("%s\n", dealer) == 1 && dealer[0] != '#'){
		scanf("%s", str); scanf("%s", str + 52);
		for (p = str, i = 0; i < 13; ++i){
			for (j = 0; j < 4; ++j){
				cards[j][i][0] = *p++;
				cards[j][i][1] = *p++;
			}
		}

		for (j = 0; j < 4; ++j) qsort(cards[j], 13, 3, sort_function);

		if (dealer[0] == 'S') j = 3;
		else if (dealer[0] == 'W') j = 2;
		else if (dealer[0] == 'N') j = 1;
		else if (dealer[0] == 'E') j = 0;
		else return 1;

		for (k = 0; k < 4; ++k, ++j, j &= 3){
			printf("%c:", "SWNE"[k]);

			for (i = 0; i < 13; ++i){
				printf(" %s", cards[j][i]);
			}

			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
