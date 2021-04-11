/* @JUDGE_ID: 19899RK 10176 C++ "By Anadan" */ 
// Ocean Deep! Make it shallow!!
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, rest;

	while (1){
		while ((i = getchar()) != EOF && i != '0' && i != '1');
		if (i == EOF) break;
		rest = i - '0';
		while ((i = getchar()) != '#'){
			rest <<= 1;
			if (i == '1') ++rest;
			if (rest >= 131071) rest -= 131071;
		}

		if (rest) printf("NO\n"); else printf("YES\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
