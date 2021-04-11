/* @JUDGE_ID: 19899RK 446 C++ "By Anadan" */
// Kibbles `n' Bits `n' Bits `n' Bits
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

void outp(int n){
	int l = 1 << 12;
	while (l){
		if (n & l) printf("1"); else printf("0");
		l >>= 1;
	}
}

int main(){
	int n1, n2;
	char ch;
	long set;
	scanf("%ld\n", &set);

	while (set--){
		scanf("%x %c %x\n", &n1, &ch, &n2);
		outp(n1);
		printf(" %c ", ch);
		outp(n2);
		if (ch == '+') printf(" = %d\n", n1 + n2);
		else printf(" = %d\n", n1 - n2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
