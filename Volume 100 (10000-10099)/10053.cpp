/* @JUDGE_ID: 19899RK 10053 C++ "By Anadan" */
// Envelopes
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Card {
	int l, w;
} cards[16];
struct Envelope {
	int l, w, c, i;
} env[16];
int M, N, bestPrice, bestMatch[16], currMatch[16];
char envMask[16];

const double pi_2 = acos(0);
const double pi = pi_2 * 2;
const double eps = 1e-12;

int adjusted(unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
	double asn, acs, tmp, theta, f1, f2;

	if (x <= a && y <= b) return 1;
	if (x*y > a*b) return 0;

	tmp = sqrt(x*x + y*y);
	asn = (a < tmp) ? asin(a/tmp) : pi_2;
	acs = (b < tmp) ? acos(b/tmp) : 0;
	theta = asin(x/tmp);

	f1 = pi - asn - theta;
	f2 = asn - theta;

	tmp = theta + acs;
	if (tmp+tmp <= pi + eps && (tmp >= f1-eps || tmp <= f2+eps)) return 1;

	tmp = theta - acs;
	if (tmp >= -eps && (tmp >= f1-eps || tmp <= f2+eps)) return 1;

	return 0;
}

void generate(int i, int price) {
	int j;

	if (bestPrice != -1 && bestPrice <= price) return;
	if (i >= M) {
		bestPrice = price;
		for (i = 0; i < M; ++i) bestMatch[i] = currMatch[i];
		return;
	}

	for (j = 0; j < N; ++j) {
		if (envMask[j]) continue;
		if (adjusted(cards[i].l, cards[i].w, env[j].l, env[j].w) || 
			adjusted(cards[i].l, cards[i].w, env[j].w, env[j].l)
		) {
			currMatch[i] = env[j].i;
			envMask[j] = 1;
			generate(i+1, price + env[j].c);
			envMask[j] = 0;
		}
	}
}

int main() {
	int set = 0, i, j;

	while (scanf("%d%d", &M, &N) == 2 && M) {
		for (i = 0; i < M; ++i) scanf("%d%d", &cards[i].l, &cards[i].w);
		for (i = 0; i < N; ++i) {
			scanf("%d%d%d", &env[i].l, &env[i].w, &env[i].c);
			env[i].i = i;
			envMask[i] = 0;
		}
		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				if (env[i].c > env[j].c) {
					Envelope tmp = env[i];
					env[i] = env[j];
					env[j] = tmp;
				}
			}
		}

		bestPrice = -1;
		generate(0, 0);

		if (set) putchar('\n');
		printf("Case #%d\n", ++set);
		if (bestPrice == -1) puts("cannot buy");
		else {
			for (i = 0; i < M; ++i) printf("%d\n", bestMatch[i] + 1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
