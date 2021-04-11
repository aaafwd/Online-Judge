/* @JUDGE_ID: 19899RK 743 C++ "By Anadan" */ 
// The MTM Machine
// Accepted (0.040 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int i, len;
	char str[40], res[1024], *p;

	while (scanf("%s\n", str) > 0){
		if (str[0] == '0' && str[1] == 0) break;
		if (strchr(str, '0')) printf("NOT ACCEPTABLE\n");
		else{
			for (i = 0, p = str; *p == '3'; ++p, ++i);
			if (*p == '2' && *(p + 1)){
				strcpy(res, ++p);
				while (i--){
					len = strlen(res);
					res[len] = '2';
					memcpy(res + len + 1, res, len);
					res[(len << 1) + 1] = 0;
				}
				printf("%s\n", res);
			}else printf("NOT ACCEPTABLE\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
