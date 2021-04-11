/* @JUDGE_ID: 19899RK 10179 C++ "By Anadan" */ 
// Irreducible Basic Fractions
// Accepted (0.160 seconds using as much as 396 kbytes )

#include <stdio.h>
#include <math.h>

int index;
long mnoj[10], N, sum;

void addtosum(int n, int i0 = 0, long mn = 1L){
	for (int i = i0; i < index-n; i++){
		if (!n) sum -= N / (mn * mnoj[i]);
		else addtosum(n-1, i+1, mn * mnoj[i]);
	}
}


long func(){
	long i, toi, j = N;
	index = 0;

	if (!(j&1)) mnoj[index++] = 2L;
	while (!(j&1)) j >>= 1;

	for (i = 3L, toi = sqrt(j); i <= toi; i += 2L){
		if (!(j % i)){
			mnoj[index++] = i;
			while (!(j % i)) j /= i;
			toi = sqrt(j);
		}
	}
	if (j > 1) mnoj[index++] = j;

	for (sum = N, i = 0L; i < index; i++, N = -N) addtosum(i);
	return sum;
}

int main(){
	while (scanf("%ld", &N) > 0){
		if (N == 0L) break;
		printf("%ld\n", func());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
