/* @JUDGE_ID: 19899RK 455 C++ "By Anadan" */ 
// Periodic Strings
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[1024];

int func(){
	char *p = str + 1, *q;
	int len = strlen(str), period = len, i;

	while ((p = strchr(p, str[0])) != NULL){
		i = int(p++ - str);
		if (len % i) continue;
		for (q = str + i; *q; q += i){
			if (strncmp(q, str, i)) goto next_p;
		}
		return i;
		next_p: continue;
	}

	return period;
}

int main(){
	int set;
	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		printf("%d\n", func());
		if (set) putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
