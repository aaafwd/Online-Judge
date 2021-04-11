/* @JUDGE_ID: 19899RK 10401 C++ "By Anadan" */ 
// Injured Queen Problem
// Accepted (0.102 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

typedef long long qword;

int main(){
	int i, j, c, N;
	char str[16];
	qword arrange[2][17], sum[2];

	arrange[0][0] = arrange[1][0] = 0;
	while (scanf("%s\n", str) == 1){
		for (N = 0; str[N]; ++N){
			if (str[N] >= 'A') str[N] += '9' - 'A';
			else if (str[N] != '?') --str[N];
		}
		sum[0] = arrange[0][N + 1] = arrange[1][N + 1] = 0;
		for (i = 1; i <= N; ++i){
			if (str[0] == '?' || str[0] == '0' + i - 1){
				arrange[0][i] = 1;
				++sum[0];
			}else arrange[0][i] = 0;
		}

		c = 0;
		for (j = 1; j < N; ++j){
			sum[c ^ 1] = 0;
			for (i = 1; i <= N; ++i){
				if (str[j] == '?' || str[j] == '0' + i - 1){
					arrange[c ^ 1][i] = sum[c] - arrange[c][i - 1] - arrange[c][i] - arrange[c][i + 1];
					sum[c ^ 1] += arrange[c ^ 1][i];
				}else arrange[c ^ 1][i] = 0;
			}
			c ^= 1;
		}

		printf("%lld\n", sum[c]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
