/* @JUDGE_ID: 19899RK 151 C++ "By Anadan" */
// Power Crisis
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int i, n, m, flags[110], pos;

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		if (n < 14) printf("1\n");
		else for (m = 4 ;; m++){
			for (i = 0; i < n; i++) flags[i] = i;
			for (pos = 0, i = n - 1; i > 1; i--){
				pos = (pos + m) % i;
				if (flags[pos] == 11) break;
				memcpy(flags + pos, flags + pos + 1, sizeof(int)*(i - pos - 1));
			}
			if (i == 1){
				printf("%d\n", m + 1);
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
