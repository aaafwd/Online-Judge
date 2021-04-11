/* @JUDGE_ID: 19899RK 669 C++ "By Anadan" */
// Defragment
// Accepted (0.143 seconds using as much as 440 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 10000

char mask[SZ];
short position[SZ], point[SZ];

void myscanf(int &x){
	int i;
	while ((x = getchar()) < '0' || x > '9');
	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9'){
		x = x * 10 + i - '0';
	}
}

void myprintf(int x){
	if (x){
		myprintf(x / 10);
		putchar('0' + (x % 10));
	}
}

int main() {
	int set, N, K, M, i, j, sum, pos, solved;

	scanf("%d", &set);
	while (set--) {
		myscanf(N); myscanf(K);
		memset(mask, 0, N);
		solved = 1;
		for (sum = i = 0; i < K; ++i) {
			myscanf(M);
			while (M--) {
				myscanf(j); --j;
				position[sum] = j;
				mask[j] = 1;
				point[j] = sum;
				if (sum++ != j) solved = 0;
			}
		}

		if (solved) {
			puts("No optimization needed");
			if (set) putchar('\n');
			continue;
		}

		for (i = 0; i < sum; ++i) {
			if (mask[i]) continue;
			pos = i;
			while (pos < sum) {
				myprintf(position[pos] + 1); putchar(' ');
				myprintf(pos + 1); putchar('\n');
				j = position[pos];
				position[pos] = pos;
				mask[pos] = 1;
				pos = j;
				mask[pos] = 0;
			}
		}

		for (i = 0; i < sum; ++i) {
			if (position[i] == i) continue;
			myprintf(i + 1); putchar(' ');
			myprintf(sum + 1); putchar('\n');
			position[point[i]] = sum;
			pos = i;
			while (pos < sum) {
				myprintf(position[pos] + 1); putchar(' ');
				myprintf(pos + 1); putchar('\n');
				j = position[pos];
				position[pos] = pos;
				mask[pos] = 1;
				pos = j;
				mask[pos] = 0;
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
