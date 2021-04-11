/* @JUDGE_ID: 19899RK 10205 C++ "By Anadan" */ 
// Stack 'em Up
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int deck[2][52], c;
const char suits[4][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const char values[13][6] = 
 { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

void doshuffle(int *shuffle){
	int i;

	for (i = 0; i < 52; ++i){
		deck[c ^ 1][i] = deck[c][shuffle[i]];
	}

	c ^= 1;
}

int main(){
	int set, N, i, j, shuffle[100][52];
	char str[81];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d", &N);

		for (i = 0; i < N; ++i) for (j = 0; j < 52; ++j){
			scanf("%d", &shuffle[i][j]);
			--shuffle[i][j];
		}

		for (c = i = 0; i < 52; ++i) deck[0][i] = i;

		gets(str);
		while (gets(str) && str[0]){
			sscanf(str, "%d", &i);
			doshuffle(shuffle[i - 1]);
		}

		for (i = 0; i < 52; ++i) printf("%s of %s\n", values[deck[c][i] % 13], suits[deck[c][i] / 13]);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
