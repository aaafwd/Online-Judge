/* @JUDGE_ID: 19899RK 10438 C++ "By Anadan" */ 
// Meta Editor
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 1000

int N;
char words[SZ][51];

int remove(int p){
	int i, j;

	for (i = 0; i <= N - p - p; ++i){
		for (j = 0; j < p; ++j) if (strcmp(words[i + j], words[i + j + p])) break;
		if (j == p){
			for (i += p, j = i + p; j < N; ++j) strcpy(words[i++], words[j]);
			N = i;
			return 1;
		}
	}

	return 0;
}

int main(){
	int c, i;
	char *p, changed, str[51];

	while (1){
		N = 0;
		while ((c = getchar()) != '\n' && c != EOF){
			if (c != ' ' && c != '\t'){
				p = str; *p++ = c;
				while ((c = getchar()) != '\n' && c != EOF && c != ' ' && c != '\t') *p++ = c;
				*p = 0;
				strcpy(words[N++], str);
				if (c == '\n' || c == EOF) break;
			}
		}

		changed = 1;
		while (changed){
			changed = 0;
			for (i = N / 2; i > 0; --i){
				if (remove(i)) { changed = 1; break; }
			}
		}

		if (N) printf("%s", words[0]);
		for (i = 1; i < N; ++i) printf(" %s", words[i]);

		putchar('\n');
		if (c == EOF) break;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
