/* @JUDGE_ID: 19899RK 10476 C++ "By Anadan" */ 
// Spam or Not Spam
// Accepted (1.502 seconds using as much as 5588 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef short word;

word spam[884736], nspam[884736], curr[884736];

void count3(char *s, word *ptr){
	int i, j, len = strlen(s);

	for (i = 0; i <= len - 3; ++i){
		j = (s[i] - 32) * 96 * 96 + (s[i + 1] - 32) * 96 + s[i + 2] - 32;
		++ptr[j];
	}
}

double similarity(word *p1, word *p2){
	int i;
	double res = 0.0;

	for (i = 0; i < 884736; ++i){
		res += double(*p1++) * double(*p2++);
	}

	return res;
}

int main(){
	int set = 0 , s, n, c;
	char str[1024];
	double a, b, d, s1, s2;

	while (scanf("%d%d%d\n", &s, &n, &c) == 3){
		if (s == 0 && n == 0 && c == 0) break;
		memset(spam, 0, sizeof(spam));
		memset(nspam, 0, sizeof(nspam));

		while (s--){
			while (1){
				gets(str);
				if (strcmp(str, "ENDMESSAGE") == 0) break;
				count3(str, spam);
			}
		}

		while (n--){
			while (1){
				gets(str);
				if (strcmp(str, "ENDMESSAGE") == 0) break;
				count3(str, nspam);
			}
		}

		a = sqrt(similarity(spam, spam));
		b = sqrt(similarity(nspam, nspam));

		printf("Set %d:\n", ++set);
		while (c--){
			memset(curr, 0, sizeof(curr));
			while (1){
				gets(str);
				if (strcmp(str, "ENDMESSAGE") == 0) break;
				count3(str, curr);
			}

			d = sqrt(similarity(curr, curr));
			s1 = similarity(curr, spam) / d / a;
			s2 = similarity(curr, nspam) / d / b;

			printf("%.5lf %.5lf\n", s1, s2);
			puts((s1 > s2 + 1e-12) ? ("spam") : ("non-spam"));
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
