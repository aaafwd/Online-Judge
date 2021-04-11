/* @JUDGE_ID: 19899RK 10102 C++ "By Anadan" */
// The path in the colored field
// Accepted (0.650 seconds using as much as 468 kbytes)

#include <stdio.h>
#define SIZE 5000

int N1, N3;
struct Point{
	int i, j;
}pt1[SIZE], pt3[SIZE];

inline int abs(int a) { return ((a < 0) ? (-(a)) : (a)); }

int main(){
	int i, j, k, tmp, M, res;

	while (scanf("%d", &M) > 0){
		for (N1 = N3 = i = 0; i < M; i++){
			for (j = 0; j < M; j++){
				scanf("%1d", &k);
				if (k == 1){
					pt1[N1].i = i; pt1[N1].j = j;
					++N1;
				}else if (k == 3){
					pt3[N3].i = i; pt3[N3].j = j;
					++N3;
				}
			}
		}

		for (res = i = 0; i < N1; i++){
			k = abs(pt3[0].i - pt1[i].i) + abs(pt3[0].j - pt1[i].j);
			for (j = 1; j < N3; j++){
				tmp = abs(pt3[j].i - pt1[i].i) + abs(pt3[j].j - pt1[i].j);
				if (tmp < k) k = tmp;
			}

			if (k > res) res = k;
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
