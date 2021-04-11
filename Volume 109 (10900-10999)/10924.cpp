/* @JUDGE_ID: 19899RK 10924 C++ "By Anadan" */
// Prime Words
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline int code(int c) {
	if ('a' <= c && c <= 'z') return c-'a'+1;
	return c-'A'+27;
}
inline int isletter(int c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int prime(int N) {
	int i, toi;
	if (N < 3) return 1;
	if (!(N & 1)) return 0;

	toi = (int)sqrt(N);
	for (i = 3; i <= toi; i += 2) {
		if (!(N % i)) return 0;
	}
	return 1;
}

int main() {
	int i, sum;
	
	while (1) {
		while ((i = getchar()) != EOF && !isletter(i));
		if (i == EOF) break;
		sum = code(i);
		while ((i = getchar()) != EOF && isletter(i)) {
			sum += code(i);
		}
		if (prime(sum)) puts("It is a prime word.");
		else puts("It is not a prime word.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
