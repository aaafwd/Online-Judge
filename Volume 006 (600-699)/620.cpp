/* @JUDGE_ID: 19899RK 620 C++ "By Anadan" */
// Cellular Structure
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int ishealth(char *s, int len){
	if (!(len & 1)) return 0;

	while (len > 1){
		if (s[len - 1] != 'B' || s[len - 2] != 'A'){
			if (*s == 'B' && s[len - 1] == 'A') ++s;
			else return 0;
		}
		len -= 2;
	}

	if (*s == 'A') return 1;
	return 0;
}

int main(){
	int N, len;
	char str[1024];

	scanf("%d\n", &N);
	while (N--){
		scanf("%s\n", str);
		len = strlen(str);
		if (len == 1 && str[0] == 'A') printf("SIMPLE\n");
		else{
			if (str[len - 1] == 'B' && str[len - 2] == 'A'){
				if (ishealth(str, len - 2)){
					printf("FULLY-GROWN\n");
					continue;
				}
			}

			if (str[0] == 'B' && str[len - 1] == 'A'){
				if (ishealth(str + 1, len - 2)){
					printf("MUTAGENIC\n");
					continue;
				}
			}

			printf("MUTANT\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
