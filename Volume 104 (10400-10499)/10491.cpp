/* @JUDGE_ID: 19899RK 10491 C++ "By Anadan" */ 
// Cows and Cars
// Accepted (0.037 seconds with low memory spent)

#include <stdio.h>

int myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	if (x == EOF) return 0;

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}

	return 1;
}

int main(){
	int n1, n2, s;
	double p;

	while (myscanf(n2) && myscanf(n1) && myscanf(s)){
		p = double(n1 * (n2+n1-1)) / double((n1+n2-s-1) * (n1+n2));
		printf("%.5lf\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
