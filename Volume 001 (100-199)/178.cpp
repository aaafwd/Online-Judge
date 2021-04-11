/* @JUDGE_ID: 19899RK 178 C++ "By Anadan" */ 
// Shuffling Patience
// Accepted (0.076 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

char ranks[] = "A23456789TJQK";
int pile[16], tot[16], p, a, b, c;

inline int getrank(int c){
	return int(strchr(ranks, c) - ranks) + 1;
}

int setpair(){
	int i, j;

	for (i = 0; i < p; ++i){
		for (j = i + 1; j < p; ++j) if (pile[i] + pile[j] == 11) break;
		if (j < p) break;
	}

	if (i < p){
		a = i; b = j; c = -1;
		return 1;
	}

	return 0;
}

int setcover(){
	int i, j, k;
	char mask[3] = { 0, 0, 0 };

	a = b = c = -1;
	setpair();

	for (i = 0; i < p; ++i){
		if (pile[i] < 11) continue;
		mask[pile[i] - 11] = 1;
		for (j = i + 1; j < p; ++j){
			if (pile[j] < 11 || mask[pile[j] - 11]) continue;
			mask[pile[j] - 11] = 1;
			for (k = j + 1; k < p; ++k){
				if (pile[k] < 11 || mask[pile[k] - 11]) continue;
				break;
			}
			mask[pile[j] - 11] = 0;
			if (k < p) break;
		}
		mask[pile[i] - 11] = 0;
		if (j < p) break;
	}

	if (i < p){
		if (a == -1 || a > i){
			a = i; b = j; c = k;
		}

		return 1;

	}else if (a != -1) return 1;

	return 0;
}

int main(){
	int set = 0, i, j;
	char str[3];

	while (scanf("%s", str) == 1 && str[0] != '#'){
		memset(tot, 0, sizeof(tot));
		pile[0] = getrank(str[0]);
		tot[0] = p = 1;

		for (i = 1; i < 52; ++i){
			if (setcover()){
				scanf("%s", str); ++i;
				pile[a] = getrank(str[0]);
				++tot[a];
				if (i == 52) break;

				scanf("%s", str); ++i;
				pile[b] = getrank(str[0]);
				++tot[b];
				if (i == 52) break;

				if (c != -1){
					scanf("%s", str); ++i;
					pile[c] = getrank(str[0]);
					++tot[c];
				}

				--i;
				continue;
			}

			scanf("%s", str);
			if (p == 16) break;
			pile[p] = getrank(str[0]);
			tot[p++] = 1;
		}

		if (i < 52){
			printf("%3d: Overflowed on card no%3d\n", ++set, i + 1);
			while (++i < 52) scanf("%*s");
		}else{
			printf("%3d:", ++set);
			for (i = 0; i < 16; ++i) if (tot[i]) printf("%3d", tot[i]); else break;
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
