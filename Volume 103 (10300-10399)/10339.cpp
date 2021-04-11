/* @JUDGE_ID: 19899RK 10339 C++ "By Anadan" */
// Watching Watches
// Accepted (0.271 seconds using as much as 384 kbytes)

#include <stdio.h>

typedef unsigned long dword;

int main(){
	int k, m, d;
	dword res;

	while (scanf("%d%d\n", &k, &m) == 2){
		if (k == m){
			printf("%d %d 12:00\n", k, m);
		}else{
			if (k > m) d = k - m; else d = m - k;
			res = (86400LU - k) * 43200LU / d;
			res = (res + 30) / 60;
			res %= 720;
			d = res / 60;
			res %= 60;
			if (d == 0) d = 12;
			printf("%d %d %.2d:%.2lu\n", k, m, d, res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
