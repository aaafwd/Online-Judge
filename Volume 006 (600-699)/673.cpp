/* @JUDGE_ID: 19899RK 673 C++ "By Anadan" */
// Parentheses Balance
// Accepted (0.610 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int remove(char *str, const char *torem){
	int flag = 0;
	char *ptr;

	while ((ptr = strstr(str, torem)) != NULL){
		strcpy(ptr, ptr + strlen(torem));
		flag = 1;
	}
	return flag;
}

int main(){
	long set;
	char str[200];
	scanf("%ld\n", &set);

	while (set--){
		gets(str);
		while (remove(str, "()") || remove(str, "[]"));
		if (str[0] == 0) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
