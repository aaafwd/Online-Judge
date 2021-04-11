/* @JUDGE_ID: 19899RK 301 C++ "By Anadan" */
// Transportation
// Accepted (0.051 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int index, maxearn, n, m, map[7];
struct Order{
	int c1, c2, pass, price;
}ord[22];

void func(int i, int earn, int maxrest){
	int j;

	if (earn > maxearn) maxearn = earn;

	for (; i < index; i++){
		if (earn + maxrest <= maxearn) break;
		maxrest -= ord[i].price;

		for (j = ord[i].c1; j < ord[i].c2; j++){
			if (map[j] < ord[i].pass) break;
		}

		if (j >= ord[i].c2){
			for (j = ord[i].c1; j < ord[i].c2; j++) map[j] -= ord[i].pass;
			func(i + 1, earn + ord[i].price, maxrest);
			for (j = ord[i].c1; j < ord[i].c2; j++) map[j] += ord[i].pass;
		}
	}
}

int sort_function(const void *a, const void *b){
	if (((Order *)a)->price < ((Order *)b)->price) return 1;
	return -1;
}

int main(){
	int i, maxrest;

	while (scanf("%d%d%d", &n, &m, &index) == 3){
		if (!n && !m && !index) break;
		maxrest = 0;
		for (i = 0; i < index; i++){
			scanf("%d%d%d", &ord[i].c1, &ord[i].c2, &ord[i].pass);
			ord[i].price = (ord[i].c2 - ord[i].c1) * ord[i].pass;
			maxrest += ord[i].price;
		}

		qsort(ord, index, sizeof(Order), sort_function);

		for (i = 0; i < m; i++) map[i] = n;
		maxearn = 0;
		func(0, 0, maxrest);
		printf("%d\n", maxearn);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
