/* @JUDGE_ID: 19899RK 640 C++ "By Anadan" */
// Self Numbers
// Accepted (0.440 seconds using as much as 400 kbytes)

#include <stdio.h>

#define LIMIT 1000000L
#define SIZE 10000
#define MAX 55

char buf[SIZE];

long f(long n){
	long res = n;
	while (n){
		res += n % 10;
		n /= 10;
	}
	return res;
}

int flushbuf(long cur){
	static long last = 0L;
	int i;

	for (i = 0; i < SIZE; i++){
		if (!buf[i]){
			if (last >= cur + i) continue;
			last = cur + i;
			if (last > LIMIT) return 1;
			printf("%ld\n", last);
		}
	}
	return 0;
}

int main(){
	long i, tmp, cur = 1L;

	while (1){
		for (i = 0; i < SIZE; i++) buf[i] = 0;
		for (i = 0; i < SIZE; i++){
			tmp = f(cur + i) - cur;
			if (tmp < SIZE) buf[tmp] = 1;
		}
		if (flushbuf(cur)) break;
		cur += SIZE - MAX;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
