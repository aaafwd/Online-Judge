/* @JUDGE_ID: 19899RK 343 C++ "By Anadan" */
// What Base Is This?
// Accepted (0.160 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

unsigned long long getnum(char *str, int i){
	char *p = str + strlen(str) - 1;
	unsigned long long res = 0L, base = 1L;

	for (; p >= str; p--, base *= i){
		if (('0' <= *p) && (*p <= '9')){
			res += base * (*p - '0');
		}else res += base * (*p - 'A' + 10);
	}

	return res;
}

int main(){
	int i, j, j0;
	unsigned long long d1, d2;
	char str1[128], str2[128], *p;

	while (scanf("%s %s\n", str1, str2) == 2){
		for (p = str1, i = 2; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (*p - '0' >= i) i = *p - '0' + 1;
			}else{
				if (*p - 'A' + 10 >= i) i = *p - 'A' + 11;
			}
		}
		for (p = str2, j0 = 2; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (*p - '0' >= j0) j0 = *p - '0' + 1;
			}else{
				if (*p - 'A' + 10 >= j0) j0 = *p - 'A' + 11;
			}
		}

		for (; i <= 36; i++){
			d1 = getnum(str1, i);
			for (j = j0; j <= 36; j++){
				d2 = getnum(str2, j);
				if (d1 == d2) goto l_solved;
			}
		}
		printf("%s is not equal to %s in any base 2..36\n", str1, str2);
		continue;
l_solved:	printf("%s (base %d) = %s (base %d)\n", str1, i, str2, j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
