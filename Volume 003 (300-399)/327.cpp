/* @JUDGE_ID: 19899RK 327 C++ "By Anadan" */
// Evaluating Simple C Expressions
// Accepted (0.170 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char mask[26];
int values[26];

int getvalue(char *p){
	char prev, c, *q;
	int res = 0;

	prev = '+';
	while (1){
		while (*p == ' ') ++p;
		if (*p == 0) break;

		if (*p == '-' || *p == '+'){
			c = *p++; while (*p == ' ') ++p;
			++p; while (*p == ' ') ++p;
			if (c == '-') values[*p - 'a'] = *p - 'a';
			else values[*p - 'a'] = *p - 'a' + 2;

			if (prev == '+') res += values[*p - 'a'];
			else res -= values[*p - 'a'];
			mask[*p++ - 'a'] = 1;
		}else{
			mask[*p - 'a'] = 1;
			values[*p - 'a'] = *p - 'a' + 1;
			if (prev == '+') res += values[*p - 'a'];
			else res -= values[*p - 'a'];

			q = p + 1;
			while (*q == ' ') ++q;
			if (*q){
				c = *q++;
				while (*q == ' ') ++q;
				if (c == *q){
					if (c == '+') ++values[*p - 'a'];
					else --values[*p - 'a'];
					p = q;
				}
			}

			++p;
		}

		while (*p == ' ') ++p;
		if (*p == 0) break;
		prev = *p++;
	}

	return res;
}

int main(){
	int i;
	char str[100];

	while (gets(str)){
		printf("Expression: %s\n", str);
		memset(mask, 0, 26);
		printf("    value = %d\n", getvalue(str));
		for (i = 0; i < 26; ++i){
			if (mask[i]) printf("    %c = %d\n", 'a' + i, values[i]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
