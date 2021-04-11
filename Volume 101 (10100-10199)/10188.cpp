/* @JUDGE_ID: 19899RK 10188 C++ "By Anadan" */ 
// Automated Judge Script
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int getsolution(char *s){
	int N;

	if (scanf("%d", &N) != 1 || N == 0) return 0;
	while (getchar() != '\n');

	while (N){
		*s = getchar();
		if (*s == '\n') --N;
		++s;
	}
	*s = 0;

	return 1;
}

int pe(char *p, char *q){
	while (1){
		while (*p && (*p < '0' || *p > '9')) ++p;
		while (*q && (*q < '0' || *q > '9')) ++q;
		if (*p == 0 && *q == 0) return 1;
		if (*p++ != *q++) break;
	}

	return 0;
}

int main(){
	int set = 0;
	char correct[10010], answer[10010];

	while (getsolution(correct)){
		getsolution(answer);
		printf("Run #%d: ", ++set);
		if (strcmp(correct, answer)){
			if (pe(correct, answer)) printf("Presentation Error\n");
			else printf("Wrong Answer\n");
		}else printf("Accepted\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
