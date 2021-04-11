/* @JUDGE_ID: 19899RK 181 C++ "By Anadan" */
// Hearts
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Player{
	char deck[10][2], mask[10];
	int score;
}pt[5];
char denom[] = "23456789TJQKA", suits[] = "CDHS";
int leader, trump;

int getcard(char *str){
	int i;

	while ((i = getchar()) == ' ' || i == '\t' || i == '\n');
	if (i == '#' || i == EOF) return 0;
	str[0] = int(strchr(denom, i) - denom);
	str[1] = int(strchr(suits, i = getchar()) - suits);

	return 1;
}

void deal(){
	int i, j, k, w = leader, playsuit, currsuit, currcard, score = 0;

	for (j = 0; pt[leader].mask[j]; ++j);
	for (i = j + 1; i < 10; ++i){
		if (pt[leader].mask[i]) continue;
		if (pt[leader].deck[i][0] > pt[leader].deck[j][0]) j = i;
		else if (pt[leader].deck[i][0] == pt[leader].deck[j][0] && pt[leader].deck[j][1] != trump && (pt[leader].deck[i][1] == trump || pt[leader].deck[i][1] > pt[leader].deck[j][1])) j = i;
	}

	pt[leader].mask[j] = 1;
	currcard = pt[leader].deck[j][0];
	playsuit = currsuit = pt[leader].deck[j][1];
	if (playsuit == 2) score = pt[leader].deck[j][0] + 2;

	for (k = (leader + 1) % 5; k != leader; k = (k + 1) % 5){
		for (i = 0; i < 10; ++i){
			if (pt[k].mask[i]) continue;
			if (pt[k].deck[i][1] == playsuit) break;
		}

		if (i < 10){
			for (j = i++; i  < 10; ++i){
				if (pt[k].mask[i]) continue;
				if (pt[k].deck[i][1] == playsuit && pt[k].deck[i][0] > pt[k].deck[j][0]) j = i;
			}
		}else{
			for (i = 0; i < 10; ++i){
				if (pt[k].mask[i]) continue;
				if (pt[k].deck[i][1] == trump) break;
			}

			if (i < 10){
				for (j = i++; i < 10; ++i){
					if (pt[k].mask[i]) continue;
					if (pt[k].deck[i][1] == trump && pt[k].deck[i][0] > pt[k].deck[j][0]) j = i;
				}
			}else{
				for (i = 0; pt[k].mask[i]; ++i);
				for (j = i++; i < 10; ++i){
					if (pt[k].mask[i]) continue;
					if (pt[k].deck[i][0] > pt[k].deck[j][0]) j = i;
					else if (pt[k].deck[i][0] == pt[k].deck[j][0] && pt[k].deck[i][1] > pt[k].deck[j][1]) j = i;
				}
			}
		}

		pt[k].mask[j] = 1;
		if (pt[k].deck[j][1] == 2) score += pt[k].deck[j][0] + 2;

		if (pt[k].deck[j][1] == trump){
			if (currsuit != trump || (currsuit == trump && pt[k].deck[j][0] > currcard)){
				currsuit = trump;
				currcard = pt[k].deck[j][0];
				w = k;
			}
		}else if (pt[k].deck[j][1] == currsuit && pt[k].deck[j][0] > currcard){
			currcard = pt[k].deck[j][0];
			w = k;
		}
	}

	pt[w].score += score;
	leader = w;
}

int main(){
	int i, j;
	char s1[2], s2[2];

	while (getcard(pt[0].deck[0])){
		for (j = 1; j < 5; ++j) getcard(pt[j].deck[0]);
		for (i = 1; i < 10; ++i){
			for (j = 0; j < 5; ++j) getcard(pt[j].deck[i]);
		}

		getcard(s1);
		getcard(s2);
		if (s1[0] > s2[0] || (s1[0] == s2[0] && s1[1] > s2[1])) trump = s1[1];
		else trump = s2[1];

		for (i = 0; i < 5; ++i){
			memset(pt[i].mask, 0, sizeof(pt[i].mask));
			pt[i].score = 0;
		}

		leader = 0;
		for (i = 0; i < 10; ++i) deal();

		printf("%3d", pt[4].score);
		for (i = 0; i < 4; ++i) printf("%3d", pt[i].score);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
