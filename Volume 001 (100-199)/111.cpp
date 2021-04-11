/* @JUDGE_ID: 19899RK 111 C++ "By Anadan" */
// History Grading
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, n, res, history[21], answer[21], maxchain[21];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", history + i);
	while (1){
		for (i = 1; i <= n; i++){
			if (scanf("%d", &j) != 1) return 0;
			answer[j] = i;
		}

		for (res = 0, i = n; i > 0; i--){
			maxchain[i] = 1;
			for (j = i + 1; j <= n; j++){
				if (history[answer[i]] < history[answer[j]]){
					if (maxchain[j] >= maxchain[i]){
						maxchain[i] = maxchain[j] + 1;
					}
				}
			}
			if (maxchain[i] > res) res = maxchain[i];
		}
		printf("%d\n", res);
	}
}
/* @END_OF_SOURCE_CODE */
