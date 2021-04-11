/* @JUDGE_ID: 19899RK 10032 C++ "By Anadan" */ 
// Tug of War
// Accepted (4.689 seconds using as much as 2632 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>

char map[51][45001];

inline int abs(int x) { return (x < 0) ? (-x) : (x); }

int main(){
	int set, i, j, k, m, N, people[100], sum;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		m = N >> 1;

		k = -1;
		for (sum = j = i = 0; i < N; ++i){
			scanf("%d\n", people + i);
			sum += people[i];
			if (j == 0){
				if (k == -1) k = people[i];
				else if (k != people[i]) j = 1;
			}
		}

		// special case (all weights are equal)
		if (j == 0){
			k *= m;
			printf("%d %d\n", k, sum - k);
			if (set) putchar('\n');
			continue;
		}

		memset(map, 0, sizeof(map));
		map[0][0] = 1;

		for (i = 0; i < N; ++i){
			j = i;
			if (j >= m) j = m - 1;

			for (; j >= 0; --j){
				if (j < i - m) break;
				for (k = 0; k <= sum - people[i]; ++k){
					if (map[j][k]){
						map[j + 1][k + people[i]] = 1;
					}
				}
			}
		}

		for (i = k = sum; k > 0; --k){
			if (map[m][k] && abs(sum - 2*i) > abs(sum - 2*k)) i = k;
		}

		if (i > sum - i) i = sum - i;
		printf("%d %d\n", i, sum - i);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
