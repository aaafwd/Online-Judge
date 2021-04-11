/* @JUDGE_ID: 19899RK 442 C++ "By Anadan" */
// Matrix Chain Multiplication
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Matrix{
	long n, m;
}pt[26];
long res;

Matrix func(char *p){
	int count;
	char *q;
	Matrix A, B;

	if (*p == '('){
		q = ++p;
		count = 0;
		do{
			if (*q == '(') ++count;
			else if (*q == ')') --count;
			++q;
		}while(count);
		A = func(p);
		B = func(q);
		if (res < 0) return A;
		if (A.m != B.n){
			res = -1L;
			return A;
		}
		res += A.n * A.m * B.m;
		A.m = B.m;
		return A;
	}else return pt[*p - 'A'];
}

int main(){
	char ch, str[256];
	int i, N;
	long n, m;

	scanf("%d\n", &N);
	for (i = 0; i < N; i++){
		scanf("%c %ld %ld\n", &ch, &n, &m);
		pt[ch - 'A'].n = n; pt[ch - 'A'].m = m;
	}

	while (scanf("%s\n", str) > 0){
		res = 0L;
		func(str);
		if (res >= 0) printf("%ld\n", res);
		else printf("error\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
