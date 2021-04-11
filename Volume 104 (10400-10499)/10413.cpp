/* @JUDGE_ID: 19899RK 10413 C++ "By Anadan" */
// Crazy Savages
// Accepted (4.998 seconds using as much as 392 kbytes)

#include <stdio.h>

int N, C[15], P[15], L[15];

void algoEuclid(int m, int n, int &x, int &y, int &d){
	int p = 1, q = 0, r = 0, s = 1;

	while (m && n){
		if (m >= n){
			p -= (m / n) * r; q -= (m / n) * s;
			m %= n;
		}else{
			r -= (n / m) * p; s -= (n / m) * q;
			n %= m;
		}
	}

	if (m == 0){
		d = n; x = r; y = s;
	}else{
		d = m; x = p; y = q;
	}
}

int solved(int m){
	int i, j, a, x, y, d, c;

	for (i = 0; i < N; ++i){
		for (j = i + 1; j < N; ++j){
			if (P[i] > P[j]) a = P[i] - P[j], c = C[j] - C[i];
			else a = P[j] - P[i], c = C[i] - C[j];
			algoEuclid(a, m, x, y, d);
			if (c % d) continue;
			x *= c / d;
			y = m / d;

/* ![Warning]! Why period = m / d ? */
			if (x < 0) x += ((-x + y - 1) / y) * y;
			else x %= y;

			if (x <= L[i] && x <= L[j]) return 0;
		}
	}

	return 1;
}

int main(){
	int set, i, m;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (m = i = 0; i < N; ++i){
			scanf("%d%d%d\n", C+i, P+i, L+i);
			if (m < C[i]) m = C[i];
		}

		while (!solved(m)) ++m;
		printf("%d\n", m);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
