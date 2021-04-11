/* @JUDGE_ID: 19899RK 146 C++ "By Anadan" */
// ID Codes
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _strrev(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int i, j;
	char str[81];

	while (scanf("%s\n", str) == 1 && str[0] != '#'){
		for (j = strlen(str) - 1; j > 0; --j){
			for (i = j - 1; i >= 0; --i) if (str[i] < str[j]) break;
			if (i >= 0){
				str[i] ^= str[j] ^= str[i] ^= str[j];
				_strrev(str + i + 1);
				break;
			}
		}

		if (j > 0) printf("%s\n", str);
		else printf("No Successor\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
