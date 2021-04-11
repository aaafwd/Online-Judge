/* @JUDGE_ID: 19899RK 712 C++ "By Anadan" */
// S-Trees
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	char str[8], nodes[130];
	int i, a, b, set, n, index[7], tree = 0;

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		for (i = 0; i < n; i++){
			scanf("%*1s%d", index + i);
			--index[i];
		}
		scanf("%s\n%d\n", nodes, &set);
		printf("S-Tree #%d:\n", ++tree);
		while (set--){
			scanf("%s\n", str);
			for (i = 0, a = 0, b = 1 << n; i < n; i++){
				if (str[index[i]] == '0') b = a + (b - a)/2;
				else a = a + (b - a)/2;
			}
			putchar(nodes[b - 1]);
		}
		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
