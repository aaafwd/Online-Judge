/* @JUDGE_ID: 19899RK 10200 C++ "By Anadan" */ 
// Prime Time
// Accepted (0.040 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <math.h>

int isprime(int N){
	int i, toi = (int)sqrt(N);
	for (i = 3; i <= toi; i += 2) if (!(N % i)) return 0;
	return 1;
}

int main(){
	int a, b, tmp = 41, solves[10001];

	for (a = 0; a < 10001; tmp += (++a) << 1){
		if (isprime(tmp)) solves[a] = 1; else solves[a] = 0;
	}
	for (a = 1; a < 10001; ++a) solves[a] += solves[a-1];

	while (scanf("%d%d", &a, &b) == 2){
		tmp = solves[b];
		if (a) tmp -= solves[a-1];
		printf("%.2lf\n", round(double(tmp * 10000) / double (b - a + 1)) * 0.01);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

