/* @JUDGE_ID: 19899RK 10093 C++ "By Anadan" */
// Easy Problem!
// Accepted (0.060 seconds using as much as 432 kbytes)

#include <stdio.h>

char str[40000];

int satisfy(int base){
	char *p = str;
	int rest = 0, i;

	if (*p < '0' || *p > '9') ++p;
	for (; *p; p++){
		if (('0' <= *p) && (*p <= '9')) i = *p - '0';
		else if (('A' <= *p) && (*p <= 'Z')) i = *p - 'A' + 10;
		else if (('a' <= *p) && (*p <= 'z')) i = *p - 'a' + 36;
		rest = (rest * base + i) % (base - 1);
	}
	if (!rest) return 1;
	return 0;
}

int main(){
	int i;
	char *p;

	while (scanf("%s\n", str) > 0){
		for (i = 2, p = str; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (*p - '0' >= i) i = *p - '0' + 1;
			}else if (('A' <= *p) && (*p <= 'Z')){
				if (*p - 'A' + 10 >= i) i = *p - 'A' + 11;
			}else if (('a' <= *p) && (*p <= 'z')){
				if (*p - 'a' + 36 >= i) i = *p - 'a' + 37;
			}
		}
		for (; i < 63; i++) if (satisfy(i)) break;
		if (i < 63) printf("%d\n", i);
		else printf("such number is impossible!\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
