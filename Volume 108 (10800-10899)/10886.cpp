/* @JUDGE_ID: 19899RK 10886 C++ "By Anadan" */
// Standard Deviation
// Accepted (2.871 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

typedef unsigned long long qword;

qword seed;
inline double gen() {
	static const double Z = 1.0 / (qword(1) << 32);
	seed >>= 16;
	seed &= (qword(1) << 32) - 1;
	seed *= seed;
	return seed * Z;
}

int main() {
	int set, cs = 0, N, i;
	double sum, sum2, x;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%llu", &N, &seed);
		sum = sum2 = 0;
		for (i = 0; i < N; ++i) {
			x = gen();
			sum += x;
			sum2 += x*x;
			if (!seed) break;
		}
		sum /= N;
		sum2 /= N;
		x = sqrt(sum2 - sum*sum);
		printf("Case #%d: %.5lf\n", ++cs, x);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
