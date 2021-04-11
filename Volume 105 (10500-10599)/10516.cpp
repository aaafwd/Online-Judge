/* @JUDGE_ID: 19899RK 10516 C++ "By Anadan" */
// Another Counting Problem
// Accepted (0.002 seconds with low memory spent)
/*
	Algorithm by Anadan:
	Let A[d] - required number, S[d] = SUMMA(A[i]), i = 0..d
	then:

	A[d] = A[d-1] * (s[d-1]^(N-1) + s[d-2] * s[d-1]^(N-2) +
	       + s[d-2]^2 * s[d-1]^(N-3) + ... + s[d-2]^(N-1)) = 
	= A[d-1] * (s[d-1]^N - s[d-2]^N) / (s[d-1] - s[d-2]) = 
	= s[d-1]^N - s[d-2]^N

	So, A[d] = s[d-1]^N - s[d-2]^N (!)

	Starting condition: A[0] = S[0] = A[1] = 1; S[1] = 2.

	In the program: SN[i] == S[i]^N
*/

#include <stdio.h>
#include <string.h>
#define MAXSZ 500

char S[17][MAXSZ], SN[17][MAXSZ];

void add(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' + *q - '0';
		if (rest >= 10){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}
		++p; ++q;
	}

	while (*q){
		rest += *q - '0';
		if (rest >= 10){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}
		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest >= 10){
			*p = rest - 10 + '0';
			rest = 1;
		}else{
			*p = rest + '0';
			rest = 0;
		}
		++p;
	}

	if (rest) *p++ = '1';
	*p = 0;
}

void sub(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' - (*q - '0');
		if (rest < 0){
			*p = rest + 10 + '0';
			rest = -1;
		}else{
			*p = rest + '0';
			rest = 0;
		}
		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		if (rest < 0){
			*p = rest + 10 + '0';
			rest = -1;
		}else{
			*p = rest + '0';
			rest = 0;
		}
		++p;
	}

	*p = 0;
}

void mulnum(char *p, int N){
	int rest = 0;

	while (*p){
		rest += (*p - '0') * N;
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	*p = 0;
}

void mul(char *p, const char *q){
	int rest = 0, i, j, l1, l2;
	static char res[MAXSZ];

	l1 = strlen(p);
	l2 = strlen(q);

	for (i = 0; i < l1 + l2; ++i){
		for (j = 0; j <= i; ++j){
			if (i - j >= l1 || j >= l2) continue;
			rest += (p[i - j] - '0') * (q[j] - '0');
		}

		res[i] = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		res[i++] = '0' + (rest % 10);
		rest /= 10;
	}

	res[i] = 0;
	strcpy(p, res);
}

int main(){
	int N, d, i, j;
	char str[MAXSZ];

	strcpy(S[0], "1");
	strcpy(S[1], "2");
	strcpy(SN[0], "1");

	while (scanf("%d%d", &N, &d) == 2 && N){
		printf("%d %d ", N, d);
		if (N == 1 || d < 2) { puts("1"); continue; }

		strcpy(SN[1], "1");
		for (i = 0; i < N; ++i) mulnum(SN[1], 2);

		for (i = 2; i < d; ++i){
			strcpy(str, SN[i - 1]);
			sub(str, SN[i - 2]);
			strcpy(S[i], S[i - 1]);
			add(S[i], str);
			strcpy(SN[i], S[i]);
			for (j = 1; j < N; ++j) mul(SN[i], S[i]);
		}

		strcpy(str, SN[i - 1]);
		sub(str, SN[i - 2]);
		i = strlen(str) - 1;
		while (i && str[i] == '0') --i;
		while (i >= 0) putchar(str[i--]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
