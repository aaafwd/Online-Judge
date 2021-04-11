/* @JUDGE_ID: 19899RK 175 C++ "By Anadan" */ 
// Keywords
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Profile{
	int T, N, titles[250], tot;
	char *words[50];
}pt[50];

int W, titl;
char *words[256];

inline char *_strdup(char *s) { return strcpy((char *)malloc(strlen(s) + 1), s); }

void settitle(int n){
	int mask[256], i, j;

	memset(mask, -1, sizeof(int) * W);

	for (i = 0; i < W; ++i){
		for (j = 0; j < pt[n].N; ++j){
			if (strcmp(words[i], pt[n].words[j]) == 0){
				if (mask[i] != -1){
					mask[i] = -j - 100;
					break;
				}
				mask[i] = j;
			}
		}
	}

	for (i = 0; i < W; ++i){
		if (mask[i] == -1) continue;
		for (j = i + 1; j < W; ++j){
			if (mask[j] != -1 && (mask[j] < 0 || mask[i] < 0 || mask[j] != mask[i])) break;
			if (j - i - 1 > pt[n].T) break;
		}

		if (j < W && j - i - 1 <= pt[n].T) break;
	}

	if (i < W) pt[n].titles[pt[n].tot++] = titl;
}

int main(){
	int i, j, P = 0;
	char str[1024], *s;

	titl = 0;

	while ((i = getchar()) != EOF && i != '#'){
		if (i == 'P' || i == 'T') getchar();
		if (i == 'P'){
			scanf("%d", &pt[P].T);
			pt[P].N = 0;

			while (1){
				while (isspace(i = getchar()) && i != '\n');
				if (i == '\n') break;
				str[0] = i;
				for (s = str + 1; !isspace(i = getchar()); *s++ = i);
				*s = 0;

				pt[P].words[pt[P].N++] = _strdup(str);

				if (i == '\n') break;
			}

			pt[P++].tot = 0;

		}else if (i == 'T'){
			++titl;
			s = str;
			while ((i = getchar()) != '|'){
				if (isspace(i)) *s++ = ' ';
				else if (isalpha(i)) *s++ = tolower(i);
			}
			*s = 0;

			W = 0;
			s = strtok(str, " ");

			while (s){
				words[W++] = s;
				s = strtok(NULL, " ");
			}

			for (i = 0; i < P; ++i){
				settitle(i);
			}
		}
	}

	for (i = 0; i < P; ++i){
		printf("%d: ", i + 1);
		for (j = 0; j < pt[i].tot; ++j){
			if (j) putchar(',');
			printf("%d", pt[i].titles[j]);
		}
		putchar('\n');
	}

	while (P--) while (pt[P].N--) free(pt[P].words[pt[P].N]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
