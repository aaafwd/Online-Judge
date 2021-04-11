/* @JUDGE_ID: 19899RK 392 C++ "By Anadan" */
// Polynomial Showdown
// Accepted (0.630 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int i, a[9], flag;

	while (1){
		for (i = 0; i < 9; i++)
			if (scanf("%d", &a[i]) < 1) goto return_label;
		for (i = flag = 0; i < 8; i++){
			if (!a[i]) continue;
			if (flag){
				if (a[i] < 0){
					a[i] = -a[i];
					printf(" - ");
				}else printf(" + ");
			}else{
				if (a[i] < 0){
					a[i] = -a[i];
					printf("-");
				}
			}
			if (a[i] > 1) printf("%d", a[i]);
			if (i == 7) printf("x");
			else printf("x^%d", 8 - i);
			flag = 1;
		}

		if (a[i]){
			if (flag){
				if (a[i] < 0){
					a[i] = -a[i];
					printf(" - ");
				}else printf(" + ");
			}else{
				if (a[i] < 0){
					a[i] = -a[i];
					printf("-");
				}
			}
			printf("%d", a[i]);
		}else{
			if (!flag) printf("%d", a[i]);
		}
		printf("\n");
	}

	return_label: return 0;
}
/* @END_OF_SOURCE_CODE */
