/* @JUDGE_ID: 19899RK 131 C++ "By Anadan" */
// The Psychic Poker Player
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hand[5][3], deck[5][3], cur[5][3];
const char names[9][16] = {
	"straight-flush", "four-of-a-kind", "full-house", "flush", "straight",
	"three-of-a-kind", "two-pairs", "one-pair", "highest-card"
};

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int getname(){
	int i;
	char straight = 0, flush = 0, flag;
	qsort(cur, 5, 3, sort_function);

	for (i = 1; i < 5; ++i) if (cur[i][1] != cur[0][1]) break;
	if (i == 5) flush = 1;
	for (i = 1; i < 4; ++i) if (cur[i][0] != cur[i - 1][0] + 1) break;
	if (i == 4 && (cur[4][0] == cur[3][0] + 1 || (cur[0][0] == '2' && cur[4][0] == '9' + 5))) straight = 1;
	if (straight && flush) return 0;
	for (i = 1; i < 4; ++i) if (cur[i][0] != cur[i - 1][0]) break;
	if (i == 4) return 1;
	for (i = 2; i < 5; ++i) if (cur[i][0] != cur[i - 1][0]) break;
	if (i == 5) return 1;

	flag = 0;
	for (i = 1; i < 3; ++i) if (cur[i][0] != cur[i - 1][0]) break;
	if (i == 3) flag = 1;
	if (i == 3 && cur[3][0] == cur[4][0]) return 2;
	for (i = 3; i < 5; ++i) if (cur[i][0] != cur[i - 1][0]) break;
	if (i == 5) flag = 1;
	if (i == 5 && cur[0][0] == cur[1][0]) return 2;

	if (flush) return 3;
	if (straight) return 4;

	if (flag) return 5;
	for (i = 2; i < 4; ++i) if (cur[i][0] != cur[i - 1][0]) break;
	if (i == 4) return 5;

	if (cur[0][0] == cur[1][0] && cur[2][0] == cur[3][0]) return 6;
	if (cur[0][0] == cur[1][0] && cur[3][0] == cur[4][0]) return 6;
	if (cur[1][0] == cur[2][0] && cur[3][0] == cur[4][0]) return 6;

	for (i = 1; i < 5; ++i) if (cur[i][0] == cur[i - 1][0]) return 7;
	return 8;
}

const char *getbesthand(){
	int i, j, k, min = 8;
	char mask[5];

	for (mask[0] = 0; mask[0] < 2; ++mask[0])
	for (mask[1] = 0; mask[1] < 2; ++mask[1])
	for (mask[2] = 0; mask[2] < 2; ++mask[2])
	for (mask[3] = 0; mask[3] < 2; ++mask[3])
	for (mask[4] = 0; mask[4] < 2; ++mask[4]){
		for (i = k = 0; i < 5; ++i){
			if (mask[i]) strcpy(cur[i], hand[i]);
			else strcpy(cur[i], deck[k++]);
		}

		j = getname();
		if (min > j) min = j;
	}

	return names[min];
}

int main(){
	int i;

	while (1){
		for (i = 0; i < 5; ++i) if (scanf("%s", hand[i]) < 1) break;
		if (i < 5) break;
		for (i = 0; i < 5; ++i) if (scanf("%s", deck[i]) < 1) break;
		if (i < 5) break;
		printf("Hand: ");
		for (i = 0; i < 5; ++i) printf("%s ", hand[i]);
		printf("Deck: ");
		for (i = 0; i < 5; ++i) printf("%s ", deck[i]);
		for (i = 0; i < 5; ++i){
			if (hand[i][0] == 'T') hand[i][0] = '9' + 1;
			else if (hand[i][0] == 'J') hand[i][0] = '9' + 2;
			else if (hand[i][0] == 'Q') hand[i][0] = '9' + 3;
			else if (hand[i][0] == 'K') hand[i][0] = '9' + 4;
			else if (hand[i][0] == 'A') hand[i][0] = '9' + 5;

			if (deck[i][0] == 'T') deck[i][0] = '9' + 1;
			else if (deck[i][0] == 'J') deck[i][0] = '9' + 2;
			else if (deck[i][0] == 'Q') deck[i][0] = '9' + 3;
			else if (deck[i][0] == 'K') deck[i][0] = '9' + 4;
			else if (deck[i][0] == 'A') deck[i][0] = '9' + 5;
		}
		printf("Best hand: %s\n", getbesthand());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
