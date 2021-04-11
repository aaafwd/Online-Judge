/* @JUDGE_ID: 19899RK 10530 C++ "By Anadan" */ 
// Guessing Game
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, a, b;
	char str[30];

	while (scanf("%d\n", &i) == 1 && i){
		a = 0; b = 11;
		while (gets(str)){
			if (str[0] == 'r') break;
			if (str[4] == 'h'){
				if (b > i) b = i;
			}else{
				if (a < i) a = i;
			}

			scanf("%d\n", &i);
		}

		if (a < i && i < b) puts("Stan may be honest");
		else puts("Stan is dishonest");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
