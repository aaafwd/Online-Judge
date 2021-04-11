/* @JUDGE_ID: 19899RK 333 C++ "By Anadan" */
// Recognizing Good ISBNs
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	int s1, s2, nums;
	char buf[100], *p, *str;

	while (gets(buf)){
		for (str = buf; *str; str++) if (!isspace(*str)) break;
		for (p = str + strlen(str) - 1; p >= str; p--) if (!isspace(*p)) break;
		*++p = 0;
		s1 = s2 = nums = 0;
		for (p = str; *p; p++){
			if (('0' <= *p) && (*p <= '9')){
				if (++nums > 10) break;
				s1 += *p - '0'; s2 += s1;
			}else if (*p == 'X'){
				if (++nums != 10) break;
				s1 += 10; s2 += s1;
			}else if (*p != '-') break;
		}
		if ((*p) || (nums != 10) || (s2 % 11)) printf("%s is incorrect.\n", str);
		else printf("%s is correct.\n", str);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
