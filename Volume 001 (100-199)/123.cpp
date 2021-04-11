/* @JUDGE_ID: 19899RK 123 C++ "By Anadan" */
// Searching Quickly
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int ign, titl, W;
char ignwords[50][11];
char *titles[200];
struct KWIC{
	char *s, *p;
	int index;
}kwic[3000];

void _strlwr(char *s){ while (*s) *s++ = tolower(*s); }

int is_ignored(char *s){
	int i;
	for (i = 0; i < ign; ++i) if (!strcmp(ignwords[i], s)) return 1;
	return 0;
}

int sort_function(const void *a, const void *b){
	int i;
	KWIC *ka = (KWIC *)a, *kb = (KWIC *)b;
	if ((i = strcmp(ka->s, kb->s)) != 0) return i;
	if (ka->index < kb->index) return -1;
	if (ka->index > kb->index) return 1;
	if (ka->p < kb->p) return -1;
	return 1;
}

void outprint(int i, char *p){
	char *q = p;
	while (isalpha(*q)) *q++ = toupper(*q);
	printf("%s\n", titles[i]);
	q = p;
	while (isalpha(*q)) *q++ = tolower(*q);
}

int main(){
	int i;
	char str[1024], *p;

	W = titl = ign = 0;
	while (scanf("%s\n", str) == 1 && strcmp(str, "::"))
		strcpy(ignwords[ign++], str);

	while (gets(str)){
		strcpy(p = titles[titl] = (char *)malloc(strlen(str) + 1), str);
		_strlwr(titles[titl]);

		while (sscanf(p, "%s%n", str, &i) == 1){
			if (!is_ignored(str)){
				kwic[W].index = titl;
				kwic[W].p = p;
				strcpy(kwic[W].s = (char *)malloc(strlen(str) + 1), str);
				++W;
			}
			p += i;
		}

		++titl;
	}

	qsort(kwic, W, sizeof(KWIC), sort_function);
	for (i = 0; i < W; ++i){
		p = kwic[i].p;
		while (!isalpha(*p)) ++p;
		outprint(kwic[i].index, p);
	}

	while (W--) free(kwic[W].s);
	while (titl--) free(titles[titl]);
	return 0;
}
/* @END_OF_SOURCE_CODE */
