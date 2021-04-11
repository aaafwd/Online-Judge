/* @JUDGE_ID: 19899RK 10197 C++ "By Anadan" */ 
// Learning Portuguese
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int len;
	char str[64], str1[64], c, out = 0;

	while (scanf("%s%s\n", str, str1) == 2){
		if (out) putchar('\n'); else out = 1;
		printf("%s (to %s)\n", str, str1);
		len = strlen(str);
		if (len < 2 || str[len - 1] != 'r' || (str[len - 2] != 'a' && str[len - 2] != 'e' && str[len - 2] != 'i')){
			printf("Unknown conjugation\n");
		}else{
			c = str[len - 2]; str[len - 2] = 0;
			printf("eu        %so\n", str);
			printf("tu        %s%cs\n", str, (c == 'a') ? ('a') : ('e'));
			printf("ele/ela   %s%c\n", str, (c == 'a') ? ('a') : ('e'));
			putchar('n'); putchar(243); printf("s       %s%cmos\n", str, c);
			putchar('v'); putchar(243); printf("s       %s%c%s\n", str, c, (c == 'i') ? ("s") : ("is"));
			printf("eles/elas %s%cm\n", str, (c == 'a') ? ('a') : ('e'));
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
