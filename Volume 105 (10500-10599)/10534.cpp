/* @JUDGE_ID: 19899RK 10534 C++ "By Anadan" */
// Wavio Sequence
// Accepted (0.432 seconds using as much as 548 kbytes)

#include <stdio.h>

int N, arr[10000], m1[10000], m2[10000];
int mine[10000], len;

inline int min(int a, int b) { return (a > b) ? (b) : (a); }

int binsearch(int elem){
	int i = 0, j = len - 1, k;
	
	if (j == -1) return -1;
	while (i + 1 < j){
		k = (i + j) / 2;
		if (mine[k] > elem) j = k; else i = k;
	}
	
	if (mine[i] >= elem) return i - 1;
	if (mine[j] >= elem) return j - 1;
	if (mine[j] < elem) return j;
	return i;
}

void setarray(int *m){
	int i, j;
	
	len = 0;
	for (i = 0; i < N; ++i){
		j = binsearch(arr[i]);
		if (j == len - 1) ++len;
		mine[j + 1] = arr[i];
		m[i] = j + 2;
	}
}

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == '-'){
		sgn = 1;
		x = getchar();
	}

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
	if (sgn) x = -x;
}

int main(){
	int i, j, res, tmp;
	
	while (scanf("%d", &N) == 1){
		for (i = 0; i < N; ++i) myscanf(arr[i]);
		setarray(m1);
		for (i = 0, j = N - 1; i < j; ++i, --j){
			arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
		}
		setarray(m2);
		res = 0;
		
		for (i = 0; i < N; ++i){
			tmp = min(m1[i], m2[N - 1 - i]);
			if (res < tmp) res = tmp;
		}
		
		printf("%d\n", res * 2 - 1);
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
