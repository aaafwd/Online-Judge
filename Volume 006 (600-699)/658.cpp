/* @JUDGE_ID: 19899RK 658 C++ "By Anadan" */
// It's not a Bug, it's a Feature!
// Accepted (1.340 seconds using as much as 5516 kbytes)

#include <stdio.h>
#include <string.h>

struct Rule {
	int time, inmask, inxor, outmask, outor;
} pt[100];
int N, M, min[1048576];
char mask[1048576];

void solve() {
	int i, k, state = (1 << N) - 1, next, closest = 0;

	memset(min, -1, (state + 1) * sizeof(int));
	memset(mask, 0, state + 1);
	min[state] = 0;
	mask[state] = 1;

	while (state) {
		if (!mask[state]) { state = closest--; continue; }

		mask[state] = 0;
		next = closest;
		for (i = 0; i < M; ++i) {
			if ((state ^ pt[i].inxor) & pt[i].inmask) continue;
			k = (state | pt[i].outor) & pt[i].outmask;
			if (min[k] == -1 || min[k] > min[state] + pt[i].time) {
				min[k] = min[state] + pt[i].time;
				mask[k] = 1;
				if (k > next) { closest = next; next = k; }
			}
		}
		state = next;
	}
}

int main() {
	int set = 0, i, j, bugPos;
	char in[21], out[21];

	while (scanf("%d%d", &N, &M) == 2 && N) {
		bugPos = (1 << N) - 1;
		for (i = 0; i < M; ++i) {
			scanf("%d%s%s", &pt[i].time, in, out);

			pt[i].inmask = pt[i].inxor = 0;
			for (j = 0; j < N; ++j) {
				pt[i].inmask <<= 1;
				pt[i].inxor <<= 1;
				if (in[j] == '0') pt[i].inmask |= 1;
				else if (in[j] == '+') pt[i].inxor |= 1;
			}
			pt[i].inmask = (~pt[i].inmask) & bugPos;

			pt[i].outmask = pt[i].outor = 0;
			for (j = 0; j < N; ++j) {
				pt[i].outmask <<= 1;
				pt[i].outor <<= 1;
				if (out[j] == '-') pt[i].outmask |= 1;
				else if (out[j] == '+') pt[i].outor |= 1;
			}
			pt[i].outmask = (~pt[i].outmask) & bugPos;
		}

		solve();

		printf("Product %d\n", ++set);
		if (min[0] < 0) puts("Bugs cannot be fixed.");
		else printf("Fastest sequence takes %d seconds.\n", min[0]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
