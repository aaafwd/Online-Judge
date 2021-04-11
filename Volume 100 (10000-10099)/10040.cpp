/* @JUDGE_ID: 19899RK 10040 C++ "By Anadan" */
// Ouroboros Snake
// Accepted (0.648 seconds using as much as 6584 kbytes)

#include <stdio.h>
#include <string.h>

char * res[22];
char mask[2097152], currres[2097152];

void precalc(int n) {
	int len = 1 << n, i, curr = 0, ones = 0, len2 = len/2;

	memset(mask, 0, len);
	mask[0] = 1;
	memset(currres, 0, len);

	for (i = n; i < len; ++i) {
		if (currres[i-n]) curr -= len2;
		curr <<= 1;

		if (i > len2 + ones) currres[i] = 2;

		if (currres[i] == 0) {
			if (!mask[curr] && i != len-1) {
				mask[curr] = 1;
				continue;
			}
			currres[i] = 1;
		}

		if (currres[i] == 1) {
			curr |= 1;
			++ones;
			if (!mask[curr]) {
				mask[curr] = 1;
				continue;
			}
			--ones;
		}

		currres[i] = 0;
		curr >>= 1;
		if (currres[i-n]) curr += len2;
		mask[curr] = 0;

		--i;
		if (currres[i]) --ones;
		curr >>= 1;
		if (currres[i-n]) curr += len2;
		++currres[i--];
	}

	res[n] = new char[len];
	memcpy(res[n], currres, len);
}

int solve(int n, int k) {
	int result = 0, masklen = (1 << n) - 1, i;

	for (i = 0; i < n; ++i) {
		result <<= 1;
		result |= res[n][k++];
		k &= masklen;
	}

	return result;
}

int main() {
	int set, n, k;

	for (n = 1; n < 22; ++n) precalc(n);

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &n, &k);
		printf("%d\n", solve(n,k));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
