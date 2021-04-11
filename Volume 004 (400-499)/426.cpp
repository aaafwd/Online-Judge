/* @JUDGE_ID: 19899RK 426 C++ "By Anadan" */ 
// Fifth Bank of Swamp County
// Accepted (0.195 seconds using as much as 628 kbytes)

#include <stdio.h>
#include <stdlib.h>
#define SZ 10000

struct List{
	char date[9];
	int num;
	double price;
}pt[SZ];

int sort_function(const void *a, const void *b){
	if (((List *)a)->num < ((List *)b)->num) return -1;
	return 1;
}

int main(){
	int set, N, r, i, j;
	char str[81];
	double tmp;

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		while (gets(str) && str[0]){
			sscanf(str, "%s%d%lf", pt[N].date, &pt[N].num, &tmp);
			pt[N].price = tmp;
			++N;
		}

		qsort(pt, N, sizeof(List), sort_function);
		r = (N + 2) / 3;
		for (i = 0; i < r; ++i){
			printf("%4d", pt[i].num);
			if (i && pt[i].num != pt[i - 1].num + 1) putchar('*');
			else putchar(' ');
			printf("%10.2lf %s", pt[i].price, pt[i].date);

			for (j = i + r; j <= i + 2*r && j < N; j += r){
				printf("   %4d", pt[j].num);
				if (pt[j].num != pt[j - 1].num + 1) putchar('*');
				else putchar(' ');
				printf("%10.2lf %s", pt[j].price, pt[j].date);
			}
			putchar('\n');
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
