/* @JUDGE_ID: 19899RK 371 C++ "By Anadan" */
// Ackermann Functions
// Accepted (0.470 seconds using as much as 388 kbytes)

#include <stdio.h>

typedef unsigned long dword;

dword cyclelen(dword i){
	dword res = 0L;

	do{
		if (i & 1L){
			i += (i + 1) >> 1;
			res += 2;
		}else{
			i >>= 1;
			++res;
		}
	}while (i > 1);
	return res;
}

int main(){
	dword i, j, tmp, V, max;

	while (scanf("%lu%lu", &i, &j) == 2){
		if (i == 0 && j == 0) break;
		if (i > j) { i ^= j; j ^= i; i ^= j; }
		printf("Between %lu and %lu, ", i, j);

		if (i > j) { tmp = i; i = j; j = tmp; }
		for (max = 0; i <= j; i++){
			tmp = cyclelen(i);
			if (tmp > max){
				max = tmp;
				V = i;
			}
		}
		printf("%lu generates the longest sequence of %lu values.\n", V, max);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
