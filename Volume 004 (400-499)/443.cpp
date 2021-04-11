/* @JUDGE_ID: 19899RK 443 C++ "By Anadan" */ 
// Humble Numbers
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long dword;

int sort_function(const void *a, const void *b){
	if (*((dword *)a) > *((dword *)b)) return 1;
	return -1;
}

int main(){
	int n = 0;
	char *suffix[3] = { "st", "nd", "rd" };
	dword solves[5843];
	double c7, c5, c3, c2, max = 2000000000.0;

	for (c7 = 1.; c7 <= max; c7 *= 7.0)
	for (c5 = c7; c5 <= max; c5 *= 5.0)
	for (c3 = c5; c3 <= max; c3 *= 3.0)
	for (c2 = c3; c2 <= max; c2 *= 2.0) solves[n++] = (dword)c2;
	qsort((void *)solves, n, sizeof(dword), sort_function);

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		if (((n % 100 < 11) || (n % 100 > 13)) && 0 < (n % 10) && (n % 10) < 4){
			printf("The %d%s humble number is %lu.\n", n, suffix[(n%10)-1], solves[n-1]);
		}
		else printf("The %dth humble number is %lu.\n", n, solves[n-1]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
