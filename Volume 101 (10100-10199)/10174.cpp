/* @JUDGE_ID: 19899RK 10174 C++ "By Anadan" */ 
// Couple-Bachelor-Spinster Numbers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int n1, n2, res;
	char str[128];

	while (gets(str)){
		n1 = -1;
		if (sscanf(str, "%d%d", &n1, &n2) == 2){
			if (n1 & 1) ++n1;
			n1 |= 2;
			if (n2 >= n1) res = ((n2 - n1) >> 2) + 1;
			else res = 0;

			printf("%d\n", res);
		}else{
			if (n1 == -1) break;
			if (n1 == 0) printf("0 0\n");
			else if (n1 & 1) printf("%d %d\n", (n1 + 1) >> 1, (n1 - 1) >> 1);
			else if (n1 & 3) printf("Bachelor Number.\n");
			else printf("%d %d\n", (n1 >> 2) + 1, (n1 >> 2) - 1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
