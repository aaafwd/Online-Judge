/* @JUDGE_ID: 19899RK 10455 C++ "By Anadan" */ 
// Gray Code
// Accepted (0.033 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef long long qword;
qword G[7];

void getgraycode(int base, int N, qword num, int *out){
	int bit, len, nbase, i;
	qword n1, n2;

	if (N == 1){
		out[0] = base;
		out[1] = base ^ 1;
		return;
	}

	bit = int(num / (G[N - 1] * G[N - 1]));
	num -= G[N - 1] * G[N - 1] * bit;
	bit = N - 1 - bit;
	n1 = num / G[N - 1];
	n2 = num % G[N - 1];

	len = 1 << (N - 1);
	nbase = ((base >> (bit + 1)) << bit) | (base & ((1 << bit) - 1));

	getgraycode(nbase, N - 1, n1, out);
	getgraycode(out[len - 1], N - 1, n2, out + len);

	for (i = 0; i < len; ++i){
		out[i] = ((out[i] >> bit) << (bit + 1)) | (base & (1 << bit)) | (out[i] & ((1 << bit) - 1));
	}

	base ^= (1 << bit);
	for (len <<= 1; i < len; ++i){
		out[i] = ((out[i] >> bit) << (bit + 1)) | (base & (1 << bit)) | (out[i] & ((1 << bit) - 1));
	}
}

void outprint(int x, int n){
	if (n == 0) return;
	outprint(x >> 1, n - 1);
	putchar('0' + (x & 1));
}

int main(){
	int i, j, set, gray[64];
	qword num;
	char str[9], *p;

	G[1] = 1;
	for (i = 2; i < 7; ++i) G[i] = G[i - 1] * G[i - 1] * i;

	scanf("%d\n", &set);
	while (set--){
		scanf("%s %lld\n", str, &num);
		for (i = 0, p = str; *p; ++p) i = (i << 1) + *p - '0';

		j = strlen(str);
		getgraycode(i, j, num - 1, gray);

		for (i = 0; i < (1 << j); ++i){
			outprint(gray[i], j);
			putchar('\n');
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
