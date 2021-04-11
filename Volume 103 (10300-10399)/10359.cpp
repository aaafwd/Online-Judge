/* @JUDGE_ID: 19899RK 10359 C++ "By Anadan" */ 
// Tiling
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) { *p ^= *q; *q ^= *p; *p++ ^= *q--; }
}

int main(){
	int i, carry;
	char solves[251][80], *p, *q;

	solves[0][1] = solves[1][1] =  0 ;
	solves[0][0] = solves[1][0] = '1';

	for (i = 2; i <= 250; ++i){
		carry = 0;
		q = strcpy(solves[i], solves[i - 1]);
		for (p = solves[i - 2]; *p; ++p, ++q){
			*q += ((*p - '0') << 1) + carry;
			carry = 0;
			if (*q > '9') ++carry, *q -= 10;
			if (*q > '9') ++carry, *q -= 10;
		}

		while (*q){
			*q += carry;
			if (*q > '9'){
				*q++ -= 10;
				carry = 1;
			}else break;
		}

		if (*q == 0 && carry){
			*q++ = '0' + carry;
			*q = 0;
		}
	}

	for (i = 3; i <= 250; ++i) _strrev(solves[i]);

	while (scanf("%d\n", &i) == 1){
		printf("%s\n", solves[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
