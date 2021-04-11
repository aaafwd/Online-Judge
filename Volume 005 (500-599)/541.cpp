/* @JUDGE_ID: 19899RK 541 C++ "By Anadan" */
// Error Correction
// Accepted (0.020 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int i, j, k, n, r, c;
	char col[100], row;

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		r = c = -1;
		for (j = 0; j < n; j++) col[j] = 0;
		for (i = 0; i < n; i++){
			for (j = row = 0; j < n; j++){
				scanf("%d", &k);
				if (k){
					col[j]++;
					row++;
				}
			}
			if (row & 1){
				if (r == -1) r = i;
				else r = -2;
			}
		}
		if (r == -2){
			printf("Corrupt\n");
			continue;
		}
		for (j = 0; j < n; j++){
			if (col[j] & 1){
				if (c == -1) c = j;
				else break;
			}
		}
		if (j < n){
			printf("Corrupt\n");
			continue;
		}
		if (r < 0) printf("OK\n");
		else printf("Change bit (%d,%d)\n", r + 1, c + 1);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
