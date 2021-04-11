/* @JUDGE_ID: 19899RK 676 C++ "By Anadan" */ 
// Horse Step Maze
// Accepted (0.281 seconds using as much as 488 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 50001

int main(){
	int set, i, x, y, x0, y0, N, sp;
	char stones[9][9], steps[SZ], stack[SZ];

	scanf("%d\n\n", &set);
	while (set--){
		for (i = 0; i < 9; ++i) memset(stones[i], 0, 9);
		scanf("%*1s%d%*1s%d%*1s\n%*1s%d%*1s%d%*1s\n", &x, &y, &x0, &y0);
		if (x > x0) i = x - x0; else i = x0 - x;
		if (y > y0) i += y - y0; else i += y0 - y;

		if (i & 1) printf("fail\n");
		else{
			--x; --y; --x0; --y0;
			N = sp = 0;
			stack[0] = 0;
			while (1){
				stones[x][y] = 1;
				steps[N++] = 10 * (x + 1) + y + 1;
				if (x == x0 && y == y0) break;
				if (N == SZ) break;

				switch (stack[sp]){
				case 0: if (x && y < 8 && !stones[x - 1][y + 1])
					{ --x; ++y; stack[sp] = 0; break; }
				case 1: if (x < 8 && y < 8 && !stones[x + 1][y + 1])
					{ ++x; ++y; stack[sp] = 1; break; }
				case 2: if (x < 8 && y && !stones[x + 1][y - 1])
					{ ++x; --y; stack[sp] = 2; break; }
				case 3: if (x && y && !stones[x - 1][y - 1])
					{ --x; --y; stack[sp] = 3; break; }
				default: stack[sp] = 4;
				}

				if (stack[sp] == 4){
					stones[x][y] = 0;
					--sp;
					if (stack[sp] == 0) ++x, --y;
					else if (stack[sp] == 1) --x, --y;
					else if (stack[sp] == 2) --x, ++y;
					else if (stack[sp] == 3) ++x, ++y;
					++stack[sp];
				}else stack[++sp] = 0;
			}

			if (x == x0 && y == y0){
				printf("(%d,%d)", steps[0] / 10, steps[0] % 10);
				for (i = 1; i < N; ++i) printf(", (%d,%d)", steps[i] / 10, steps[i] % 10);
				putchar('\n');
			}else printf("more than 50000 steps\n");
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
