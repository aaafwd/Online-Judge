/* @JUDGE_ID: 19899RK 10646 C++ "By Anadan" */
// What is the Card?
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>

char cr[52][3];

inline int getvalue(int i){
	if ('2' <= cr[i][0] && cr[i][0] <= '9') return cr[i][0] - '0';
	return 10;
}

int main(){
	int set, nt = 0, i, j, x, y;

	scanf("%d", &set);
	while (set--){
		for (i = 0; i < 52; ++i) scanf("%s", cr[i]);
		i = 26; y = -1;
		for (j = 0; j < 3; ++j){
			x = getvalue(i);
			y += x;
			i -= 11 - x;
		}

		if (y > i) y += 26 - i;
		printf("Case %d: %s\n", ++nt, cr[y]);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
