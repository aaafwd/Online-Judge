/* @JUDGE_ID: 19899RK 10815 C++ "By Anadan" */
// Andy's First Dictionary
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define HASH_SIZE 32768
#define LEAP 7999

char * hashSet[HASH_SIZE];

int sort_function(const void *a, const void *b) {
	return strcmp(*(char**)a, *(char**)b);
}

void initHashSet() {
	int i;
	for (i = 0; i < HASH_SIZE; ++i) {
		hashSet[i] = NULL;
	}
}

int hashCode(char * str) {
	int res = 0;
	while (*str) {
		res = res*31 + (*str++ - 'a');
	}
	if (res < 0) res = -res;
	return res % HASH_SIZE;
}

void addword(char * str) {
	char * p;
	int h = hashCode(str);

	while (1) {
		p = hashSet[h];
		if (p == NULL) {
			hashSet[h] = strcpy(new char[strlen(str) + 1], str);
			break;
		} else if (strcmp(p, str) == 0) {
			break;
		} else {
			h = (h + LEAP) % HASH_SIZE;
		}
	}
}

int main() {
	int i, N;
	char str[256], *p;

	initHashSet();

	while ((i = getchar()) != EOF) {
		if (isalpha(i)) {
			p = str;
			while (isalpha(i)) {
				*p++ = tolower(i);
				i = getchar();
			}
			*p = 0;
			addword(str);
		}
	}

	for (i = N = 0; i < HASH_SIZE; ++i) {
		if (hashSet[i]) hashSet[N++] = hashSet[i];
	}
	qsort(hashSet, N, sizeof(char*), sort_function);
	for (i = 0; i < N; ++i) {
		puts(hashSet[i]);
		delete hashSet[i];
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
