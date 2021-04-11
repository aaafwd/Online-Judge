/* @JUDGE_ID: 19899RK 103 C++ "By Anadan" */
// Stacking Boxes
// Accepted (4.750 seconds using as much as 396 kbytes)
// Too much time !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k, n, maxD, res[30], maxres[30];
struct Box{
	int dim[10], pos;
}pt[30], curbox;

int sort_func1(const void *a, const void *b){
	return ( *((int *)a) < *((int *)b) ) ? (-1) : (1);
}

int sort_func2(const void *a, const void *b){
	Box *p1 = (Box *)a, *p2 = (Box *)b;
	for (int i = 0; i < n; i++){
		if (p1->dim[i] < p2->dim[i]) return 1;
		else if (p1->dim[i] > p2->dim[i]) return -1;
	}
	return 0;
}

int isnest(Box *small, Box *big){
	int i;
	for (i = 0; i < n; i++) if (small->dim[i] >= big->dim[i]) return 0;
	return 1;
}

void func(int i, int D){
	if (D == 0){
		for (; i < k; i++){
			curbox = pt[i];
			res[0] = pt[i].pos;
			func(i + 1, 1);
		}
	}else{
		Box tmp = curbox;
		for (; i < k; i++){
			if (isnest(pt + i, &curbox)){
				curbox = pt[i];
				res[D] = pt[i].pos;
				func(i + 1, D + 1);
				curbox = tmp;

				if (D >= maxD){
					maxD = D + 1;
					memcpy(maxres, res, maxD * sizeof(int));
				}
			}
		}
	}
}

int main(){
	int i, j;

	while (scanf("%d%d", &k, &n) == 2){
		for (i = 0; i < k; i++){
			pt[i].pos = i + 1;
			for (j = 0; j < n; j++) scanf("%d", &pt[i].dim[j]);
			qsort((void *)pt[i].dim, n, sizeof(int), sort_func1);
		}
		qsort((void *)pt, k, sizeof(Box), sort_func2);
		if (k) maxD = maxres[0] = 1; else maxD = 0;
		func(0, 0);
		printf("%d\n", maxD);
		if (maxD) printf("%d", maxres[--maxD]);
		for (i = maxD - 1; i >= 0; i--) printf(" %d", maxres[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
