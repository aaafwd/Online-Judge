/* @JUDGE_ID: 19899RK 10471 C++ "By Anadan" */ 
// Can't be too GREEDY
// Accepted (0.156 seconds using as much as 820 kbytes)

#include <stdio.h>
#include <stdlib.h>

int count;
struct Point{
	int i, k;
}pt[32768];

void outprint(int k){
	int i, v = ++count;

	pt[count - 1].i = v;
	pt[count - 1].k = k;
	if (k == 1) return;

	for (i = 1; i < k; ++i){
		printf("%d %d\n", v, count + 1);
		outprint(i);
	}
}

int sort_function(const void *a, const void *b){
	if (((Point *)a)->k < ((Point *)b)->k) return -1;
	return 1;
}

int main(){
	int k;

	while (scanf("%d\n", &k) == 1){
		printf("%d %d\n", 1 << (k - 1), (1 << (k - 1)) - 1);
		count = 0;
		outprint(k);
		qsort(pt, count, sizeof(Point), sort_function);
		printf("%d", pt[0].i);
		for (k = 1; k < count; ++k) printf(" %d", pt[k].i);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
