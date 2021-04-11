/* @JUDGE_ID: 19899RK 10490 C++ "By Anadan" */ 
// Mr. Azad and his Son!!!!!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int primes[50], powers[50], M;
typedef long long qword;
qword k, rest;

int prime(int x){
	int i, toi;

	if (x == 2) return 1;
	if (!(x & 1)) return 0;
	toi = (int)sqrt(x);
	for (i = 3; i <= toi; i += 2) if (!(x % i)) return 0;
	return 1;
}

void isperfect(qword curr, int i){
	int j;

	if (i == M){
		if (curr != k) rest -= curr;
		return;
	}

	isperfect(curr, i + 1);
	for (j = 0; j < powers[i]; ++j){
		curr *= primes[i];
		isperfect(curr, i + 1);
	}
}

int perfect(int N){
	int x = (1 << N) - 1, i, toi;

	M = 1;
	primes[0] = 2;
	powers[0] = N - 1;

	toi = (int)sqrt(x);
	for (i = 3; i <= toi; i += 2){
		if (!(x % i)){
			primes[M] = i;
			powers[M] = 0;
			while (!(x % i)){
				x /= i;
				++powers[M];
			}

			++M;
		}
	}

	if (x != 1){
		primes[M] = x;
		powers[M++] = 1;
	}

	rest = k;
	isperfect(1, 0);
	return (rest == 0);
}

#ifdef ONLINE_JUDGE

int main(){
	int N;

	while (scanf("%d", &N) == 1 && N){
		switch (N){
		case 2: puts("Perfect: 6!"); break;
		case 3: puts("Perfect: 28!"); break;
		case 5: puts("Perfect: 496!"); break;
		case 7: puts("Perfect: 8128!"); break;
		case 13: puts("Perfect: 33550336!"); break;
		case 17: puts("Perfect: 8589869056!"); break;
		case 19: puts("Perfect: 137438691328!"); break;
		case 31: puts("Perfect: 2305843008139952128!"); break;
		case 11:
		case 23:
		case 29: puts("Given number is prime. But, NO perfect number is available."); break;
		default: puts("Given number is NOT prime! NO perfect number is available.");
		}
	}

	return 0;
}

#else

int main(){
	int N;

	while (scanf("%d", &N) == 1 && N){
		k = qword(1 << (N - 1)) * qword((1 << N) - 1);
		printf("%d ", N);
		if (perfect(N)) printf("Perfect: %I64d!\n", k);
		else if (prime(N)) puts("Given number is prime. But, NO perfect number is available.");
		else puts("Given number is NOT prime! NO perfect number is available.");
	}

	return 0;
}

#endif

/* @END_OF_SOURCE_CODE */
