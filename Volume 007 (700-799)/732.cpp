/* @JUDGE_ID: 19899RK 732 C++ "By Anadan" */
// Anagrams by Stack
// Accepted (0.180 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int len;
char str1[80], str2[80], stack[80], res[160], *p1, *p2, *sp;

void func(int i, int pushes){
	if (pushes == len){
		int j;
		char *sp_t = sp - 1, *p2_t = p2;
		while (sp_t >= stack) if (*sp_t-- != *p2_t++) return;
		for (j = 0; j < i; j++) printf("%c ", res[j]);
		printf("o");
		for (++j; j < len*2; j++) printf(" o");
		printf("\n");
		return;
	}
	res[i] = 'i';
	*sp++ = *p1++;
	func(i + 1, pushes + 1);
	--sp; --p1;
	if (sp > stack && *(sp-1) == *p2){
		res[i] = 'o';
		--sp; ++p2;
		func(i + 1, pushes);
		*sp++ = *--p2;
	}
}

int main(){
	res[0] = 'i';
	while (scanf("%s\n%s\n", str1, str2) == 2){
		len = strlen(str1);
		printf("[\n");
		if (strlen(str2) == len){
			p1 = str1;
			p2 = str2;
			sp = stack;
			*sp++ = *p1++;
			func(1, 1);
		}
		printf("]\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
