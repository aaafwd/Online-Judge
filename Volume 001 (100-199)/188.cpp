/* @JUDGE_ID: 19899RK 188 C++ "By Anadan" */
// Perfect Hash
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef unsigned long dword;

int main(){
	int i, j, N;
	char str[512], *p, mask[13];
	dword words[13], C, tmp;

	while(gets(str)){
		printf("%s\n", str);
		N = 0;
		p = strtok(str, " ");
		while (p){
			words[N] = 0;
			while (*p){
				words[N] <<= 5;
				words[N] += *p++ - 'a' + 1;
			}
			++N;
			p = strtok(NULL, " ");
		}

		C = 1;
		while (1){
			while (1){
				for (i = 0; i < N; ++i){
					if (!(C % words[i])) break;
				}

				if (i < N) break;
				++C;
			}

			memset(mask, 0, 13);
			for (i = 0; i < N; ++i){
				j = (C / words[i]) % N;
				if (mask[j]) break;
				mask[j] = i + 1;
			}

			if (i == N) break;
			tmp = (C / words[i] + 1) * words[i];
			C = (C / words[mask[j] - 1] + 1) * words[mask[j] - 1];
			if (C > tmp) C = tmp;
		}

		printf("%lu\n\n", C);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
