/* @JUDGE_ID: 19899RK 763 C++ "By Anadan" */ 
// Fibinary Numbers
// Accepted (0.150 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

char str1[128], str2[128], *p1, *p2;

char *_strrev(char *s){
	char tmp;
	int i, len = strlen(s);
	for (i = 0; i < (len >> 1); i++){
		tmp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = tmp;
	}
	return s;
}

void normalize(){
	char *p = p1;
	while ((p = strstr(p, "11")) != NULL){
		if (*(p + 2) == '1') p++;
		*p++ = '0'; *p++ = '0'; *p = '1';
	}
}

void addf(int i){
	if (p1[i] == '0'){
		p1[i] = '1';
		normalize();
		return;
	}

	p1[i] = '0';
	p1[i + 1] = '1';
	if (i == 1) p1[0] = '1';
	normalize();
	if (i > 1) addf(i - 2);
}

int main(){
	int i;
	char flag = 0;

	while (1){
		for (i = 0; i < 128; i++) str1[i] = str2[i] = 0;
		if (scanf("%s\n%s\n\n", str1, str2) < 2) break;
		p1 = _strrev(str1); p2 = _strrev(str2);

		if (strlen(p1) < strlen(p2)){
			char *tmp = p1; p1 = p2; p2 = tmp;
		}

		for (i = 0; *p2; i++, p2++) if (*p2 == '1') addf(i);
		if (flag) printf("\n"); else flag = 1;
		printf("%s\n", _strrev(p1));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
