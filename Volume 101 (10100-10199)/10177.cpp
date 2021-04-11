/* @JUDGE_ID: 19899RK 10177 C++ "By Anadan" */
// (2/3/4)-D Sqr/Rects/Cubes/Boxes?
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#define SZ 101

typedef long long qword;

inline qword qpow2(qword x) { return x * x; }
inline qword qpow3(qword x) { return x * x * x; }
inline qword qpow4(qword x) { return qpow2(x * x); }

int main(){
	int n, tmp;
	qword S2[SZ], S3[SZ], S4[SZ], R2[SZ], R3[SZ], R4[SZ], s1, s2;

	S2[0] = R2[0] = S3[0] = R3[0] = S4[0] = R4[0] = 0;

	s1 = 1; s2 = 0;
	for (n = 1; n < SZ; ++n){
		s1 += 2*n + 1;
		s2 += n * (2*n + 1);
		S2[n] = s1*n - s2;
		R2[n] = qpow2((n * (n + 1)) / 2) - S2[n];
	}

	s1 = 1; s2 = 0;
	for (n = 1; n < SZ; ++n){
		s1 += 3*n*n + 3*n + 1;
		s2 += n * (3*n*n + 3*n + 1);
		S3[n] = s1*n - s2;
		R3[n] = qpow3((n * (n + 1)) / 2) - S3[n];
	}

	s1 = 1; s2 = 0;
	for (n = 1; n < SZ; ++n){
		tmp = (n + 1)*(3*n*n + 3*n + 1) + n * n * n;
		s1 += tmp;
		s2 += n * tmp;
		S4[n] = s1*n - s2;
		R4[n] = qpow4((n * (n + 1)) / 2) - S4[n];
	}

	while (scanf("%d\n", &n) == 1){
		printf("%lld %lld %lld %lld %lld %lld\n", S2[n], R2[n], S3[n], R3[n], S4[n], R4[n]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
