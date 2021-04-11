/* @JUDGE_ID: 19899RK 409 C++ "By Anadan" */
// Excuses, Excuses!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int K, E;
char dict[20][21], excuses[20][71];

char *stristr(char *s1, char *s2){
	char *p1, *p2;

	while (*s1){
		while (*s1 && tolower(*s1) != tolower(*s2)) s1++;
		for (p1 = s1, p2 = s2; *p1 && *p2 && tolower(*p1) == tolower(*p2); p1++, p2++);
		if (*p2 == 0) return s1;
		++s1;
	}
	return NULL;
}

int getwords(char *str){
	char *p;
	int i, len, res = 0;

	for (i = 0; i < K; i++){
		p = str;
		len = strlen(dict[i]);
		while ((p = stristr(p, dict[i])) != NULL){
			if ((p == str || isalpha(*(p-1)) == 0) && isalpha(*(p+len)) == 0){
				++res;
			}
			p += len;
		}
	}

	return res;
}

int main(){
	int i, max, set = 0;
	int words[20];

	while (scanf("%d%d\n", &K, &E) == 2){
		for (i = 0; i < K; i++) scanf("%s\n", dict[i]);
		for (max = i = 0; i < E; i++){
			gets(excuses[i]);
			words[i] = getwords(excuses[i]);
			if (words[i] > max) max = words[i];
		}
		printf("Excuse Set #%d\n", ++set);
		for (i = 0; i < E; i++){
			if (words[i] == max) printf("%s\n", excuses[i]);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
