/* @JUDGE_ID: 19899RK 10019 C++ "By Anadan" */
// Funny Encryption Method
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int ones(long M){
	int res = 0;
	while (M){
		if (M & 1L) ++res;
		M >>= 1;
	}
	return res;
}

int main(){
	int N, b1, b2;
	long M;
	char str[10];
	scanf("%d\n", &N);

	while (N--){
		scanf("%s\n", str);
		sscanf(str, "%ld", &M);
		b1 = ones(M);
		sscanf(str, "%X", &M);
		b2 = ones(M);
		printf("%d %d\n", b1, b2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
