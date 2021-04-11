/* @JUDGE_ID: 19899RK 10324 C++ "By Anadan" */
// Zeros and Ones
// Accepted (0.290 seconds using as much as 4296 kbytes)

#include <stdio.h>
#define MAX 1000000

int main(){
	int ptr[MAX], c, d, N, count, set = 0, i, j;

	while ((c = getchar()) != '\n' && c != -1){
		N = count = ptr[0] = 1;
		do{
			if ((d = getchar()) == '\n' || d == -1) break;
			if (c == d) ptr[N++] = ++count;
			else{
				c = d;
				ptr[N++] = count = 1;
			}
		}while (1);

		printf("Case %d:\n", ++set);
		scanf("%d\n", &d);
		for (c = 0; c < d; ++c){
			scanf("%d %d\n", &i, &j);
			if (i > j) i ^= j ^= i ^= j;
			if (ptr[j] > j - i) printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
