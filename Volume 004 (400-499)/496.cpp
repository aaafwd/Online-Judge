/* @JUDGE_ID: 19899RK 496 C++ "By Anadan" */
// Simply Subsets
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#define SZ 1000

int sort_function(const void *a, const void *b){
	if (*((int *)a) < *((int *)b)) return -1;
	if (*((int *)a) > *((int *)b)) return 1;
	return 0;
}

int main(){
	char flag;
	int arr[SZ], cur, N, c, *ptr, in, notin;

	while (1){
		N = 0;
		flag = 0;
		while ((c = getchar()) != '\n' && c != EOF){
			if ('0' <= c && c <= '9'){
				if (flag == 0) cur = c - '0';
				else{
					cur *= 10;
					cur += c - '0';
				}
				flag = 1;
			}else if (flag){
				arr[N++] = cur;
				flag = 0;
				cur = 0;
			}
		}

		if (!N) break;

		if (flag){
			arr[N++] = cur;
			flag = 0;
		}

		qsort(arr, N, sizeof(int), sort_function);
		in = notin = 0;

		while ((c = getchar()) != '\n' && c != EOF){
			if ('0' <= c && c <= '9'){
				if (flag == 0) cur = c - '0';
				else{
					cur *= 10;
					cur += c - '0';
				}
				flag = 1;
			}else if (flag){
				ptr = (int *)bsearch(&cur, arr, N, sizeof(int), sort_function);
				if (ptr) ++in;
				else ++notin;

				flag = 0;
				cur = 0;
			}
		}

		if (flag){
			ptr = (int *)bsearch(&cur, arr, N, sizeof(int), sort_function);
			if (ptr) ++in;
			else ++notin;
		}

		if (notin == 0){
			if (in == N) printf("A equals B\n");
			else printf("B is a proper subset of A\n");
		}else if (in == 0){
			printf("A and B are disjoint\n");
		}else if (in == N){
			printf("A is a proper subset of B\n");
		}else{
			printf("I'm confused!\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
