/* @JUDGE_ID: 19899RK 10361 C++ "By Anadan" */ 
// Automatic Poetry
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set;
	char str1[256], str2[256], *p, *b;

	scanf("%d\n", &set);
	while (set--){
		b = gets(str1);
		p = strchr(b, '<'); *p++ = 0;
		printf("%s", b); b = p;
		p = strchr(b, '>'); *p++ = 0;
		printf("%s", b); b = p;
		p = strchr(b, '<'); *p++ = 0;
		printf("%s", b); b = p;
		p = strchr(b, '>'); *p++ = 0;
		printf("%s%s\n", b, p);

		gets(str2);
		str2[strlen(str2) - 3] = 0;
		printf("%s", str2);
		p = str1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		printf("%s", p);
		p = str1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		printf("%s", p);
		p = str1;
		p += strlen(p) + 1;
		printf("%s", p);
		p = str1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		p += strlen(p) + 1;
		printf("%s\n", p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
