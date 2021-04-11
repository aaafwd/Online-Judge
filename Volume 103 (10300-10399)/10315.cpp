/* @JUDGE_ID: 19899RK 10315 C++ "By Anadan" */
// Poker Hands
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char black[5][3], white[5][3];

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

long getrank(char str[5][3]){
	int i, j;
	char flush = 0, straight = 0;

	for (i = 0; i < 5; ++i) str[i][0] -= '2';
	for (i = 1; i < 5; ++i) if (str[i][1] != str[i - 1][1]) break;
	if (i == 5) flush = 1;
	for (i = 1; i < 5; ++i) if (str[i][0] != str[i - 1][0] + 1) break;
	if (i == 5) straight = 1;

	if (straight && flush) return 773936L + str[4][0];
	for (i = 1; i < 4; ++i) if (str[i][0] != str[i - 1][0]) break;
	if (i == 4) return 773383L + str[0][0];
	for (i = 2; i < 5; ++i) if (str[i][0] != str[i - 1][0]) break;
	if (i == 5) return 773383L + str[1][0];

	for (i = 1; i < 3; ++i) if (str[i][0] != str[i - 1][0]) break;
	if (i == 3){
		if (str[3][0] == str[4][0]) return 773370L + str[0][0];
		else return 402051L + str[0][0];
	}

	for (i = 2; i < 4; ++i) if (str[i][0] != str[i - 1][0]) break;
	if (i == 4){
		if (str[4][0] == str[0][0]) return 773370L + str[1][0];
		else return 402051L + str[1][0];
	}

	for (i = 3; i < 5; ++i) if (str[i][0] != str[i - 1][0]) break;
	if (i == 5){
		if (str[0][0] == str[1][0]) return 773370L + str[2][0];
		else return 402051L + str[2][0];
	}

	if (flush) return 402077L + str[0][0] + 13L * str[1][0] + 13L * 13L * str[2][0] + 13L * 13L * 13L * str[3][0] + 13L * 13L * 13L * 13L * str[4][0];
	if (straight) return 402064L + str[4][0];
	for (i = 1; i < 5; ++i) if (str[i][0] == str[i - 1][0]) break;
	if (i == 5) return str[0][0] + 13L * str[1][0] + 13L * 13L * str[2][0] + 13L * 13L * 13L * str[3][0] + 13L * 13L * 13L * 13L * str[4][0];
	for (j = i + 2; j < 5; ++j) if (str[j][0] == str[j - 1][0]) break;
	if (j >= 5){
		long rank = 371293L, tmp = 1L;
		for (j = 0; j < 5; ++j){
			if (j == i - 1 || j == i) continue;
			rank += tmp * str[j][0];
			tmp *= 13L;
		}
		return rank + tmp * str[i][0];
	}
	return 399854L + 13L * str[i][0] + 13L * 13L * str[j][0] + str[(i & 1) << 1][0];
}

int main(){
	long i, j;

	while (1){
		for (i = 0L; i < 5L; i++){
			if (scanf("%s", black[i]) != 1) return 0;
			if (black[i][0] == 'T') black[i][0] = '9' + 1;
			else if (black[i][0] == 'J') black[i][0] = '9' + 2;
			else if (black[i][0] == 'Q') black[i][0] = '9' + 3;
			else if (black[i][0] == 'K') black[i][0] = '9' + 4;
			else if (black[i][0] == 'A') black[i][0] = '9' + 5;
		}
		for (i = 0L; i < 5L; i++){
			if (scanf("%s", white[i]) != 1) return 0;
			if (white[i][0] == 'T') white[i][0] = '9' + 1;
			else if (white[i][0] == 'J') white[i][0] = '9' + 2;
			else if (white[i][0] == 'Q') white[i][0] = '9' + 3;
			else if (white[i][0] == 'K') white[i][0] = '9' + 4;
			else if (white[i][0] == 'A') white[i][0] = '9' + 5;
		}
		qsort((void *)black, 5, 3, sort_function);
		qsort((void *)white, 5, 3, sort_function);
		i = getrank(black);
		j = getrank(white);
		if (i > j) printf("Black wins.\n");
		else if (i < j) printf("White wins.\n");
		else printf("Tie.\n");
	}
}
/* @END_OF_SOURCE_CODE */
