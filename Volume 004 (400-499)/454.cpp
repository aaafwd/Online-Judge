/* @JUDGE_ID: 19899RK 454 C++ "By Anadan" */
// Anagrams
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_function(const void *a, const void *b){
	return (strcmp((char *)a, (char *)b));
}

int anagrams(const char *s1, const char *s2){
	char *p, str[100];
	strcpy(str, s1);

	for(; *s2; s2++){
		if (*s2 == ' ') continue;
		if ((p = strchr(str, *s2)) == NULL) return 0;
		*p = ' ';
	}
	for (p = str; *p; p++) if (*p != ' ') return 0;
	return 1;
}

int main(){
	int i, j, n, set;
	char str[101][128], arr[101][128];

	str[100][0] = 0;
	scanf("%d\n", &set);
	while (set--){
		n = 0;
		while (gets(str[n])){
			if (str[n][0] == 0) break;
			++n;
		}
		qsort((void *)str, n, sizeof(str[0]), sort_function);

		for (i = j = 0; i < n; i++){
			while (!strcmp(str[i], str[i + 1])) ++i;
			strcpy(arr[j++], str[i]);
		}

		for (i = 0, n = j; i < n; i++){
			for (j = i + 1; j < n; j++){
				if (anagrams(arr[i], arr[j])){
					printf("%s = %s\n", arr[i], arr[j]);
				}
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
