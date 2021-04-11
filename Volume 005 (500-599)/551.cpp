/* @JUDGE_ID: 19899RK 551 C++ "By Anadan" */ 
// Nesting a Bunch of Brackets
// Accepted (0.014 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, pos;
	char str[3001], *p;

	while (gets(str)){
		for (i = pos = 0, p = str; *p; ++p, ++pos){
			if (*p == '('){
				if (*(p + 1) == '*'){
					++p;
					str[i++] = 1;
				}else str[i++] = 0;
			}
			else if (*p == '[') str[i++] = 2;
			else if (*p == '{') str[i++] = 3;
			else if (*p == '<') str[i++] = 4;
			else if (*p == ')'){
				if (i == 0 || str[--i] != 0) break;
			}else if (*p == '*'){
				if (*(p + 1) == ')'){
					if (i == 0 || str[--i] != 1) break;
					++p;
				}
			}else if (*p == ']'){
				if (i == 0 || str[--i] != 2) break;
			}else if (*p == '}'){
				if (i == 0 || str[--i] != 3) break;
			}else if (*p == '>'){
				if (i == 0 || str[--i] != 4) break;
			}
		}

		if (i || *p) printf("NO %d\n", pos + 1);
		else printf("YES\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
