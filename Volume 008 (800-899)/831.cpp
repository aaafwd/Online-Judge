/* @JUDGE_ID: 19899RK 831 C++ "By Anadan" */ 
// Document Validator
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 100

int stri, semi;
char *strtag[SZ], *semtag[SZ];

int getindex(char *s){
	int i;
	for (i = 0; i < stri; ++i) if (strcmp(strtag[i], s) == 0) return i;
	strtag[i] = strcpy((char *)malloc(strlen(s) + 1), s);
	return stri++;
}

int main(){
	int set, i, j, k, stack[SZ], sp;
	char str[256], *p;

	scanf("%d", &set);
	while (getchar() != '\n'); while (getchar() != '\n');
	while (set--){
		stri = semi = sp = 0;
		i = '\n';
		while (1){
			j = getchar();
			if (j == EOF) j = '\n';
			if (j == '\n'){
				if (i == '\n') break;
			}else if (j == '['){
				for (p = str; (j = getchar()) != '[' && j != '\n' && j != EOF; *p++ = j);
				*p = 0;
				stack[sp++] = getindex(str);
			}else if (j == ']'){
				for (p = str; (j = getchar()) != ']' && j != '\n' && j != EOF; *p++ = j);
				*p = 0;
				k = getindex(str);
				if (sp == 0 || stack[--sp] != k) break;
			}else if (j == '{'){
				for (p = str; (j = getchar()) != '}' && j != ' ' && j != '{' && j != '[' && j != ']'; *p++ = j);
				if (j != ' ' && j != '}') { j = 0; break; }
				if (j != '}') while ((j = getchar()) != '}' && j != '{' && j != '[' && j != ']');
				if (j != '}') { j = 0; break; }
				*p = 0;
				for (k = 0; k < semi; ++k) if (strcmp(semtag[k], str) == 0) break;
				if (k == semi) semtag[semi++] = strcpy((char *)malloc(strlen(str) + 1), str);
			}else if (j == '}') break;

			i = j;
		}

		if (i != '\n' || j != '\n' || sp){
			i = j;
			if (j != '\n') while ((j = getchar()) != EOF && (j != '\n' || i != '\n')) i = j;
			printf("ERROR\n");
			while (stri--) free((void *)strtag[stri]);
			while (semi--) free((void *)semtag[semi]);
		}else{
			printf("STRUCTURAL TAGS\n");
			for (i = 0; i < stri; ++i){
				printf("%s\n", strtag[i]);
				free((void *)strtag[i]);
			}
			printf("SEMANTIC TAGS\n");
			for (i = 0; i < semi; ++i){
				printf("%s\n", semtag[i]);
				free((void *)semtag[i]);
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
