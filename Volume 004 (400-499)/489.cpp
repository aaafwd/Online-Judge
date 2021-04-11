/* @JUDGE_ID: 19899RK 489 C++ "By Anadan" */
// Hangman Judge
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[256], lts[256];

void func(){
	char *q;
	int tryies = 7, len = strlen(str);

	for (char *p = lts; *p; p++){
		q = strchr(str, *p);
		if (q == NULL){
			tryies--;
			if (tryies == 0) break;
		}else if (strchr(lts, *p) < p) continue;
		else{
			while(q){
				len--;
				q = strchr(q + 1, *p);
			}
			if (len <= 0) break;
		}
	}

	if (tryies){
		if (len > 0) printf("You chickened out.\n");
		else printf("You win.\n");
	}else printf("You lose.\n");
}

int main(){
	long N;
	while (scanf("%ld\n", &N) > 0){
		if (N == -1L) break;
		scanf("%s\n%s\n", str, lts);
		printf("Round %ld\n", N);
		func();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
