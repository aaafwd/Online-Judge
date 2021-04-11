/* @JUDGE_ID: 19899RK 824 C++ "By Anadan" */
// Coast Tracker
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int x0, y0, d, i, j, x, y;
	char map[3][3];

	while (scanf("%d%d%d\n", &x0, &y0, &d) == 3 && x0 != -1){
		--x0; --y0; d = (d + 5) % 7;
		for (i = 0; i < 8; ++i){
			scanf("%d%d%d\n", &x, &y, &j);
			map[x - x0][y - y0] = j;
		}

		for (i = 0; i < 8; ++i, ++d){
			if (d == 8) d = 0;
			if (d == 0) { if (map[1][2]) break; }
			else if (d == 1) { if (map[0][2]) break; }
			else if (d == 2) { if (map[0][1]) break; }
			else if (d == 3) { if (map[0][0]) break; }
			else if (d == 4) { if (map[1][0]) break; }
			else if (d == 5) { if (map[2][0]) break; }
			else if (d == 6) { if (map[2][1]) break; }
			else if (d == 7) { if (map[2][2]) break; }
		}

		printf("%d\n", d);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
