/* @JUDGE_ID: 19899RK 711 C++ "By Anadan" */
// Dividing up
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char mask[1024];

int main(){
	int set = 0, i, j, k, sum, n[6];

	while (1) {
		sum = 0;
		for (i = 0; i < 6; ++i) {
			scanf("%d", n+i);
			sum += n[i] * (i+1);
		}
		if (sum == 0) break;

		printf("Collection #%d:\n", ++set);
		if (sum & 1) puts("Can't be divided.\n");
		else {
			for (i = 0; i < 3; ++i) {
				if (n[i] < 3) continue;
				if (n[i] & 1) {
					n[i*2 + 1] += n[i] / 2;
					n[i] = 1;
				} else {
					n[i*2 + 1] += (n[i] - 2) / 2;
					n[i] = 2;
				}
			}

			sum = 0;
			for (i = 0; i < 6; ++i) {
				n[i] %= 8; // If less than 8 then WA;
				// 32 - for sure since 2^16 > maxsum/2 = 120000/2
				// and we can group it (divide 16+16)
				sum += n[i] * (i+1);
			}
			sum >>= 1;

			memset(mask, 0, sum + 1);
			mask[0] = 1;
			for (i = 0; i < 6; ++i) {
				for (j = sum - i - 1; j >= 0; --j) {
					if (!mask[j]) continue;
					for (k = 1; k <= n[i] && j + k*(i+1) <= sum; ++k) {
						mask[j + k*(i+1)] = 1;
					}
					if (mask[sum]) { i = 6; break; }
				}
			}

			if (mask[sum]) puts("Can be divided.\n");
			else puts("Can't be divided.\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
