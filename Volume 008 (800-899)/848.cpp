/* @JUDGE_ID: 19899RK 848 C++ "By Anadan" */ 
// Fmt
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[100];

int isempty(char *s){
	for (; *s; ++s) if (*s != ' ')  return 0;
	return 1;
}

void outprint(char *s, int &N){
	char *p, *q;

	if (N <= 72){
		while (N > 0 && (s[N - 1] == ' ')) --N;
		s[N] = 0;
		printf("%s\n", s);
		N = 0;
		return;
	}

	p = s + 72;
	while (p >= s && (*p != ' ')) --p;
	if (p < s) return;
	*p = 0;
	q = p + 1;
	N = int(s + N - q);
	--p;
	while (p >= s && (*p == ' ')) --p;
	*(p + 1) = 0;
	printf("%s\n", s);

	while (N && (*q == ' ')) --N, ++q;
	strcpy(s, q);
}

int main(){
	int c, empty = 1, i = 0, j;
	char *p;

	while ((c = getchar()) != EOF){
		if (i > 80){
			str[i] = 0;
			outprint(str, i);
			if (i > 72){
				for (p = str; *p; ++p){
					if (*p == ' ') break;
					putchar(*p);
					--i;
				}

				if (i == 0){
					while (c != '\n' && c != EOF && c != ' '){
						putchar(c);
						c = getchar();
					}
					empty = 1;
					str[0] = 0;
					putchar('\n');
					if (c == '\n') continue;
				}else{
					for (; *p == ' '; ++p) --i;
					strcpy(str, p);
					empty = isempty(str);
					putchar('\n');
				}
			}

			if (i == 0){
				while (c == ' ') c = getchar();
				if (c == EOF) break;
			}
			str[i] = 0;
			empty = isempty(str);
		}

		if (c == '\n'){
			c = getchar();
			if (empty || c == ' ' || c == '\n'){
				str[i] = 0;
				outprint(str, i);
				while (i > 0 && (str[i - 1] == ' ')) --i;
				str[i] = 0;
				for (j = 0; j < i; ++j) if (str[j] != ' ') break;
				if (j != i) printf("%s\n", str);
				i = 0;
			}else{
				str[i++] = ' ';
			}
			ungetc(c, stdin);
			empty = 1;
		}else{
			if (c != ' ') empty = 0;
			str[i++] = c;
		}
	}

	if (i){
		str[i] = 0;
		outprint(str, i);
		while (i > 0 && (str[i - 1] == ' ')) --i;
		str[i] = 0;
		for (p = str; *p == ' '; ++p);

		if (*p){
			if (strlen(p) <= 72) printf("%s\n", p);
			else{
				while (*p && *p != ' ') putchar(*p++);
				putchar('\n');
				while (*p == ' ') ++p;
				if (*p) printf("%s\n", p);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
