/* @JUDGE_ID: 19899RK 462 C++ "By Anadan" */ 
// Bridge Hand Evaluator
// Accepted (0.330 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

char cards[4][13], rank[] = "A23456789TJQK";

void setcard(char *str){
	int i, j;
	if (str[1] == 'S') i = 0;
	else if (str[1] == 'H') i = 1;
	else if (str[1] == 'D') i = 2;
	else if (str[1] == 'C') i = 3;
	j = int(strchr(rank, str[0]) - rank);
	++cards[i][j];
}

int main(){
	int i, j, k, c, max, pts1, pts2;
	char str[3], stopped;

	while (scanf("%s", str) == 1){
		for (i = 0; i < 4; ++i) memset(cards[i], 0, 13);
		setcard(str);
		for (i = 1; i < 13; ++i){
			scanf("%s", str);
			setcard(str);
		}

		pts1 = pts2 = max = 0;
		for (i = 0; i < 4; ++i) pts1 += 4*cards[i][0] + 3*cards[i][12] + 2*cards[i][11] + cards[i][10];
		stopped = 0;
		for (i = 0; i < 4; ++i){
			for (k = j = 0; j < 13; ++j) k += cards[i][j];
			if (max < k) { max = k; c = i; }
			if (cards[i][12] && k == 1) --pts1;
			if (cards[i][11] && k <= 2) --pts1;
			if (cards[i][10] && k <= 3) --pts1;
			if (k == 2) ++pts2; else if (k < 2) pts2 += 2;
			if (cards[i][0] || (cards[i][12] && k >= 2) || (cards[i][11] && k >= 3)) ++stopped;
		}

		if (pts1 + pts2 < 14) printf("PASS\n");
		else if (pts1 >= 16 && stopped == 4) printf("BID NO-TRUMP\n");
		else printf("BID %c\n", "SHDC"[c]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
