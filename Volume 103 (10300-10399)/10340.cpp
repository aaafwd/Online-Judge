/* @JUDGE_ID: 19899RK 10340 C++ "By Anadan" */
// All in All
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char str1[100000], str2[100000], *p, *q;

	while (scanf("%s %s\n", str1, str2) == 2){
		for (p = str1, q = str2; *p; ++p, ++q)
			if ((q = strchr(q, *p)) == NULL) break;
		if (*p) printf("No\n"); else printf("Yes\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
