/* @JUDGE_ID: 19899RK 278 C++ "By Anadan" */
// Chess
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	char ch;
	int m, n;
	long res, sets;

	scanf("%ld\n", &sets);
	while (sets--){
		scanf("%c%d%d\n", &ch, &m, &n);
		switch(ch){
		case 'r':	// Rook
		case 'Q':	// Queen
			if (n > m) { n ^= m; m ^= n; n ^= m; }
			res = n;
			break;
		case 'k':	// Knight
			res = (n*m + 1) >> 1;
			break;
		case 'K':	// King
			res = ((n + 1) >> 1) * ((m + 1) >> 1);
			break;
		}
		printf("%ld\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
