/* @JUDGE_ID: 19899RK 10412 C++ "By Anadan" */
// Big Big Trees
// Accepted (0.105 seconds using as much as 468 kbytes)

#include <stdio.h>

struct Tree{
	int h, l[20];
}pt[1000];

inline int sqr(int x) { return x * x; }

int main(){
	int set, n, m, max, i, j, k, l, d, min, cur, tmp;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d\n", &n, &m, &max);
		max *= max;
		for (i = 0; i < n; ++i){
			scanf("%d", &pt[i].h);
			for (j = 0; j < pt[i].h; ++j) scanf("%d", &pt[i].l[j]);
			while (j < 20) pt[i].l[j++] = 0;
		}

		for (d = i = 0; i < n - 1; ++i){
			min = m;

			for (j = 0; j < pt[i].h; ++j){
				for (k = 0; k < pt[i + 1].h; ++k){
					cur = pt[i].l[j] + pt[i + 1].l[k];
					if (cur >= min) continue;
					if (sqr(m - pt[i].l[j] - pt[i + 1].l[k]) + sqr(j - k) > max) continue;

					if (j < k){
						for (l = j + 1; l < k; ++l){
							tmp = pt[i].l[j] * (k - j) + (l - j) * (m - pt[i].l[j] - pt[i + 1].l[k]);
							if (tmp <= (k - j) * pt[i].l[l] || tmp >= (k - j) * (m - pt[i + 1].l[l])) break;
						}

						if (l >= k) min = cur;
					}else{
						for (l = k + 1; l < j; ++l){
							tmp = (m - pt[i + 1].l[k]) * (j - k) - (l - k) * (m - pt[i].l[j] - pt[i + 1].l[k]);
							if (tmp <= (j - k) * pt[i].l[l] || tmp >= (j - k) * (m - pt[i + 1].l[l])) break;
						}

						if (l >= j) min = cur;
					}
				}
			}

			d += min;
		}

		printf("%d\n", d);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
