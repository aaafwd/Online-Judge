/* @JUDGE_ID: 19899RK 576 C++ "By Anadan" */
// Haiku Review
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int getsyll(char *p){
	int res = 0;

	while ((p = strpbrk(p, "aeiouy")) != NULL){
		while (*p == 'a' || *p == 'e' || *p == 'i' ||
		       *p == 'o' || *p == 'u' || *p == 'y') p++;
		res++;
	}

	return res;
}

int main(){
	char str[256], *p;

	while (gets(str)){
		if (!strcmp(str, "e/o/i")) break;
		p = strtok(str, "/");
		if (getsyll(p) != 5) printf("1\n");
		else{
			p = strtok(NULL, "/");
			if (getsyll(p) != 7) printf("2\n");
			else{
				p = strtok(NULL, "/");
				if (getsyll(p) != 5) printf("3\n");
				else printf("Y\n");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
