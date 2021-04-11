/* @JUDGE_ID: 19899RK 499 C++ "By Anadan" */
// What's The Frequency, Kenneth?
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

char str[256], outp[53];
int freq[52];

int sort_function(const void *a, const void *b){
	if (*((char *)a) > *((char *)b)) return 1;
	return -1;
}

void func(){
	int i, j, max = 0;
	for (i = 0; i < 52; i++) freq[i] = 0;
	for (char *p = str; *p; p++){
		if (('A' <= *p) && (*p <= 'Z')){
			i = ++freq[*p - 'A'];
			if (i > max) max = i;
		}
		else if (('a' <= *p) && (*p <= 'z')){
			i = ++freq[26 + *p - 'a'];
			if (i > max) max = i;
		}
	}

	if (max == 0) return;
	for (i = j = 0; i < 26; i++){
		if (freq[i] == max) outp[j++] = 'A' + i;
	}
	for (; i < 52; i++){
		if (freq[i] == max) outp[j++] = 'a' + i - 26;
	}
	outp[j] = 0;
	qsort((void *)outp, j, 1, sort_function);
	printf("%s %d\n", outp, max);
}

int main(){
	while (gets(str)){
		func();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
