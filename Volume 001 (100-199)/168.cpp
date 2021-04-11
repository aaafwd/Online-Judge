/* @JUDGE_ID: 19899RK 168 C++ "By Anadan" */ 
// Theseus and the Minotaur
// Accepted (0.586 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char map[26][32], mask[26];

int main(){
	int k, step, next, prev;
	char str[256], ch1[2], ch2[2], *p;

	while (scanf("%s%s%s%d", str, ch1, ch2, &k) == 4 && str[0] != '#'){
		for (next = 0; next < 26; ++next) map[next][0] = 0;
		p = strtok(str, ";.");
		while (p){
			strcpy(map[p[0] - 'A'], p + 2);
			p = strtok(NULL, ";.");
		}

		memset(mask, 0, sizeof(mask));
		step = 0;
		next = ch1[0] - 'A'; prev = ch2[0] - 'A';
		while (1){
			for (p = map[next]; *p; ++p){
				if (*p - 'A' != prev && mask[*p - 'A'] == 0) break;
			}

			if (*p){
				prev = next;
				next = *p - 'A';
			}else{
				printf("/%c\n", next + 'A');
				break;
			}

			++step;
			if (step == k){
				step = 0;
				mask[prev] = 1;
				printf("%c ", prev + 'A');
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
