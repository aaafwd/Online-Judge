/* @JUDGE_ID: 19899RK 562 C++ "By Anadan" */
// Dividing coins
// Accepted (0.170 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <string.h>
#define MAXS 25001

inline long abs(long a) { return (a < 0) ? (-(a)) : (a); }

int main(){
	char flags[MAXS];
	int i, j, m, n, max;
	long set, sum, sum2;
	scanf("%ld\n", &set);

	while (set--){
		scanf("%d", &m);
		memset(flags, 0, MAXS);
		flags[0] = 1;
		for (sum = 0L, i = max = 0; i < m; i++){
			scanf("%d", &n);
			sum += n;
			for (j = max; j >= 0; j--){
				if (flags[j]){
					if (j + n < MAXS){
						flags[j + n] = 1;
						if (j + n > max) max = j + n;
					}
				}
			}
		}
		sum2 = sum >> 1;
		for (j = 0; ;j++){
			if (flags[sum2+j]){
				printf("%ld\n", abs((sum2 + j)*2L - sum));
				break;
			}
			if (flags[sum2-j]){
				printf("%ld\n", abs(sum - 2L*(sum2 - j)));
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
