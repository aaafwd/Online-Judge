/* @JUDGE_ID: 19899RK 10518 C++ "By Anadan" */ 
// How Many Calls?
// Accepted (0.018 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int base;

class Matrix{
public:
	int a[3][3];

	void operator *= (Matrix m){
		int b[3][3], i, j, k;

		for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j){
			b[i][j] = 0;
			for (k = 0; k < 3; ++k){
				b[i][j] += a[i][k] * m.a[k][j];
				b[i][j] %= base;
			}
		}

		for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j){
			a[i][j] = b[i][j];
		}
	}

	void setnull(){
		int i, j;
		for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j){
			a[i][j] = 0;
		}
	}
};

int main(){
	int set = 0, res;
	qword n;
	Matrix A, B, R;

	while (scanf("%lld%d", &n, &base) == 2 && base){
		printf("Case %d: %lld %d ", ++set, n, base);
		if (n < 2){
			res = 1;
		}else{
			A.setnull();
			A.a[0][0] = A.a[0][1] = A.a[0][2] = A.a[1][0] = A.a[2][2] = 1;
			R = A;

			--n;
			while (n){
				if (n & 1){
					R *= A;
					--n;
				}else{
					A *= A;
					n >>= 1;
				}
			}

			res = R.a[1][0] + R.a[1][1] + R.a[1][2];
		}

		res %= base;
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
