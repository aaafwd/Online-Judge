/* @JUDGE_ID: 19899RK 850 C++ "By Anadan" */
// Crypt Kicker II
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const int lens[9] = { 3, 5, 5, 3, 5, 4, 3, 4, 3 };
const char pattern[] = "thequickbrownfoxjumpsoverthelazydog";

int main(){
	int set, index, N, off, i;
	char lines[101][81], str[81], *p, decode[26];
	char words[9][6];

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		index = -1;
		while (gets(lines[N]) && lines[N][0]){
			if (index == -1){
				for (p = lines[N], i = 0; i < 9; ++i){
					if (sscanf(p, "%s%n", str, &off) < 1) break;
					if (strlen(str) != lens[i]) break;
					p += off;
					strcpy(words[i], str);
				}

				if (i == 9 && sscanf(p, "%s", str) != 1){
					if (strcmp(words[0], words[6]) ||
					    words[2][2] != words[3][1] || words[2][2] != words[5][0] || words[2][2] != words[8][1] ||
					    words[2][1] != words[5][3] || words[5][2] != words[0][2] || words[1][1] != words[4][1])
					{
						++N;
						continue;
					}

					memset(decode, 0, 26);
					for (i = off = 0, p = lines[N]; *p; ++p){
						if (*p == ' ') continue;
						if (!decode[*p - 'a']) ++off;
						decode[*p - 'a'] = pattern[i++];
					}

					if (off == 26){
						index = N;
					}
				}
			}
			++N;
		}

		if (index == -1) printf("No solution.\n");
		else{
			for (i = 0; i < N; ++i){
				for (p = lines[i]; *p; ++p){
					if (*p != ' ') *p = decode[*p - 'a'];
					putchar(*p);
				}
				putchar('\n');
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
