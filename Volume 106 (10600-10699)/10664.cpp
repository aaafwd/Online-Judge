/* @JUDGE_ID: 19899RK 10664 C++ "By Anadan" */
// Luggage
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, sum, arr[32];

void getinput(){
	int i;

	sum = N = 0;
	while ((i = getchar()) != EOF && i != '\n'){
		if ('0' <= i && i <= '9'){
			ungetc(i, stdin);
			scanf("%d", arr + N);
			sum += arr[N++];
		}
	}
}

int main(){
	int set, i, j;
	char mass[256];

	scanf("%d\n", &set);
	while (set--){
		getinput();
		if (sum & 1) { puts("NO"); continue; }

		sum >>= 1;
		memset(mass, 0, sum + 1);
		mass[0] = 1;

		for (i = 0; i < N; ++i){
			for (j = sum - arr[i]; j >= 0; --j){
				if (mass[j]){
					mass[j + arr[i]] = 1;
					if (mass[sum]) { i = N; break; }
				}
			}
		}

		puts(mass[sum] ? "YES" : "NO");
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
