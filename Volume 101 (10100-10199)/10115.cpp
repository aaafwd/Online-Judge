/* @JUDGE_ID: 19899RK 10115 C++ "By Anadan" */
// Automatic Editing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[256];

void replace(char *find, char *torep){
	int l1 = strlen(find), l2 = strlen(torep);
	char *p;

	while ((p = strstr(str, find)) != NULL){
		memmove(p + l2, p + l1, strlen(p + l1) + 1);
		memcpy(p, torep, l2);
	}
}

int main(){
	int N, i;
	char fn[10][81], rp[10][81];

	while (scanf("%d", &N) == 1 && N){
		while (getchar() != '\n');
		for (i = 0; i < N; ++i){
			gets(fn[i]); gets(rp[i]);
		}

		gets(str);
		for (i = 0; i < N; ++i) replace(fn[i], rp[i]);
		printf("%s\n", str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
