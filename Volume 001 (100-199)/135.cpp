/* @JUDGE_ID: 19899RK 135 C++ "By Anadan" */ 
// No Rectangles
// Accepted (0.137 seconds using as much as 1348 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 993

int main(){
	char map[SZ][SZ];
	int k, n, i, j, u, v, s, t, w;

	map[0][0] = 0;
	while (scanf("%d\n", &k) == 1){
		if (map[0][0]) putchar('\n');

		n = k*k - k + 1;
		memset(map, 0, sizeof(map));

		map[0][0] = 1;
		for (i = 0; i < k; ++i){
			for (j = i * (k - 1) + 1; j < (i + 1) * (k - 1) + 1; ++j){
				map[i][j] = map[j][i] = 1;
			}
		}

		for (u = 1; u < k; ++u){
			for (v = 1; v < k; ++v){
				s = u * (k - 1) + 1;
				t = v * (k - 1) + 1;
				for (w = 0; w < k - 1; ++w){
					map[s + (w + (u - 1) * (v - 1)) % (k - 1)][t + w] = 1;
				}
			}
		}

		for (i = 0; i < n; ++i){
			t = 0;
			for (j = 0; j < n; ++j) if (map[i][j]){
				if (t) putchar(' '); else t = 1;
				printf("%d", j + 1);
			}
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
