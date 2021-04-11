/* @JUDGE_ID: 19899RK 10134 C++ "By Anadan" */ 
// AutoFish
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, bait, caught, last, after, tobait, tofish;
	char str[6];

	scanf("%d\n\n", &set);
	while (set--){
		last = -1;
		bait = caught = tobait = after = tofish = 0;
		while (gets(str) && str[0]){
			if (str[0] == 'f' && bait){
				--bait;
				if (last == -1){
					++caught;
					after = tofish = 0;
				}else if (tofish == 3 && after >= 7){
					++caught;
					after = tofish = 0;
				}else ++tofish;

			}else if (str[0] == 'b' && bait < 3){
				if (tobait) ++bait;
				tobait ^= 1;
			}

			++after;
		}

		printf("%d\n", caught);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
