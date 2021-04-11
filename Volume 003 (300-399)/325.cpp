/* @JUDGE_ID: 19899RK 325 C++ "By Anadan" */
// Identifying Legal Pascal Real Constants
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>

int main(){
	char str[256], *p, point, expflag, nums;

	while (scanf("%s", str) > 0){
		if (str[0] == '*' && str[1] == 0) break;
		printf("%s is ", str);
		p = str;
		if (*p == '+' || *p == '-') ++p;

		point = expflag = nums = 0;
		while (*p){
			if (isdigit(*p)) nums = 1;
			else if (*p == '.'){
				if (point || expflag || nums == 0) break;
				if (!isdigit(*(p + 1))) break;
				++p;
				point = 1;
			}else if (*p == 'e' || *p == 'E'){
				if (expflag || nums == 0) break;
				++p;
				if (*p == '+' || *p == '-') ++p;
				if (!isdigit(*p)) { *p = 1; break; }
				expflag = 1;
			}else break;
			++p;
		}

		if (*p == 0 && (point || expflag)) printf("legal.\n");
		else printf("illegal.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
