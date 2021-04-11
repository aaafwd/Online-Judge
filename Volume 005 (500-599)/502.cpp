/* @JUDGE_ID: 19899RK 502 C++ "By Anadan" */
// DEL command
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char files[1000][13], str[14], pattern[9], patext[4], *p;
	int N, i, j, set;

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		while (gets(str) && str[0]){
			if (str[0] == '+') strcpy(files[N++], str + 1);
			else if (str[0] == '-') break;
			else return 1;
		}

		p = strchr(str, '.');
		if (p) *p++ = 0;
		strcpy(pattern, str + 1);
		if (p) strcpy(patext, p); else patext[0] = 0;

		while (gets(str) && str[0]){
			if (str[0] == '+') strcpy(files[N++], str + 1);
			else if (str[0] == '-'){
				for (i = 1; str[i] && str[i] != '.'; ++i){
					if (pattern[i - 1] == 0 || pattern[i - 1] == '*'){
						pattern[i - 1] = '*';
						pattern[i] = 0;
						while (str[i] && str[i] != '.') ++i;
						break;
					}else if (pattern[i - 1] != str[i]){
						pattern[i - 1] = '?';
					}
				}

				if (pattern[i - 1]){
					pattern[i - 1] = '*';
					pattern[i] = 0;
				}

				p = patext;
				if (str[i] == '.') ++i;
				while (str[i]){
					if (*p == 0 || *p == '*'){
						*p++ = '*';
						*p = 0;
						break;
					}else if (*p != str[i]){
						*p = '?';
					}

					++i; ++p;
				}

				if (*p) { *p++ = '*'; *p = 0; }
			}
			else return 1;
		}

		for (i = 0; i < N; ++i){
			for (p = pattern, j = 0; files[i][j] && files[i][j] != '.'; ++j, ++p){
				if (*p == '*'){
					while (files[i][j] && files[i][j] != '.') ++j;
					break;
				}
				if (*p != '?' && *p != files[i][j]) break;
			}

			if ((files[i][j] == 0 || files[i][j] == '.') && (*p == 0 || *p == '*')){
				if (files[i][j] == '.') ++j;
				for (p = patext; files[i][j]; ++j, ++p){
					if (*p == '*'){
						while (files[i][j]) ++j;
						break;
					}
					if (*p != '?' && *p != files[i][j]) break;
				}

				if (files[i][j] == 0 && (*p == 0 || *p == '*')) break;
			}
		}

		if (i < N) printf("IMPOSSIBLE\n");
		else printf("DEL %s.%s\n", pattern, patext);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
