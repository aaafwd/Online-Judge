/* @JUDGE_ID: 19899RK 377 C++ "By Anadan" */
// Cowculations
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int n, i, j, len;
	char let[] = "VUCD";
	char op1[10], op2[10], cop[2], cr;

	scanf("%d\n", &n);
	printf("COWCULATIONS OUTPUT\n");
	while (n--){
		scanf("%s\n%s\n", op1, op2);
		_strrev(op1);
		_strrev(op2);
		for (i = 0; i < 5; ++i){
			op1[i] = int(strchr(let, op1[i]) - let) + '0';
			op2[i] = int(strchr(let, op2[i]) - let) + '0';
		}

		len = 5;
		for (i = 0; i < 3; ++i){
			scanf("%s\n", cop);
			if (cop[0] == 'N') continue;
			if (cop[0] == 'A'){
				cr = 0;
				for (j = 0; j < 5; ++j){
					op2[j] += op1[j] - '0' + cr;
					if (op2[j] >= '4'){
						op2[j] -= 4;
						cr = 1;
					}else cr = 0;
				}

				if (cr) for (; j < len; ++j){
					op2[j] += cr;
					if (op2[j] >= '4') op2[j] -= 4;
					else break;
				}
				if (cr) op2[len++] = '1';
			}else if (cop[0] == 'R'){
				for (j = 0; j < len - 1; ++j) op2[j] = op2[j + 1];
				op2[len - 1] = '0';
			}else if (cop[0] == 'L'){
				for (j = len++; j > 0; --j) op2[j] = op2[j - 1];
				op2[0] = '0';
			}else return 1;
		}
		while (len < 8) op2[len++] = '0';
		op2[8] = 0;
		for (i = 0; i < 8; ++i) op2[i] = let[op2[i] - '0'];
		_strrev(op2);
		scanf("%s\n", op1);
		if (strcmp(op1, op2)) printf("NO\n"); else printf("YES\n");
	}

	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
