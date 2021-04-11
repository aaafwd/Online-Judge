/* @JUDGE_ID: 19899RK 729 C++ "By Anadan" */
// The Hamming Distance Problem
// Accepted (0.140 seconds using as much as 392 kbytes)

#include <stdio.h>

char str[17];
int L, H;

void func(int i = 0, int ones = 0){
	if (L - i + ones == H){
		while (i < L) str[i++] = '1';
		printf("%s\n", str);
	}else if (ones == H){
		while (i < L) str[i++] = '0';
		printf("%s\n", str);
	}else{
		str[i] = '0'; func(i + 1, ones);
		str[i] = '1'; func(i + 1, ones + 1);
	}
}

int main(){
	long N;
	scanf("%ld", &N);

	while(N--){
		scanf("%d%d", &L, &H);
		str[L] = 0;
		func();
		if (N) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
