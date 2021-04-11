/* @JUDGE_ID: 19899RK 10390 C++ "By Anadan" */
// Bean Counting
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, c, totnum, totshares, offone[26], right[26], beans[26];
	char str[512], *p;
	double wins;

	scanf("%d\n\n", &set);
	while (set--){
		totnum = totshares = 0;
		for (c = 0; c < 26; ++c){
			beans[c] = offone[c] = right[c] = 0;
		}

		while ((c = getchar()) != '\n' && c != EOF){
			++beans[c - 'a'];
		}

		while (gets(str)){
			if (str[0] < 'A' || str[0] > 'Z') break;
			p = strtok(str + 2, ",");
			while (p){
				++totnum;
				sscanf(p + 2, "%d", &c);
				if (c == beans[p[0] - 'a']){
					totshares += 2;
					++right[str[0] - 'A'];
				}else if (c == beans[p[0] - 'a'] - 1 || c == beans[p[0] - 'a'] + 1){
					++totshares;
					++offone[str[0] - 'A'];
				}

				p = strtok(NULL, ",");
			}
		}

		for (c = 0; c < 26; ++c){
			wins = 2.00 * totnum / double(totshares) * (offone[c] + 2.0 * right[c]);
			if (wins > 1e-10) printf("%c %.2lf\n", 'A' + c, wins);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
