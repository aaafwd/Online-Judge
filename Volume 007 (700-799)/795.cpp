/* @JUDGE_ID: 19899RK 795 C++ "By Anadan" */ 
// Sandorf's Cipher
// Accepted (0.139 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

const int pos[36] = {
	18, 9, 27, 10, 19, 11, 28, 20, 0, 21, 12, 1, 22, 29, 13, 2, 30, 23,
	3, 14, 24, 31, 15, 4, 25, 32, 5, 26, 6, 16, 33, 7, 34, 17, 35, 8
};

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

int main(){
	int i;
	char str[110], enc[110], *p, *q;

	while (gets(str)){
		_reverse(str);
		p = str; q = enc;

		while (*p){
			for (i = 0; i < 36; ++i) q[pos[i]] = *p++;
			q += 36;
		}

		while (--q >= enc && *q == '#');
		*(q + 1) = 0;

		printf("%s\n", enc);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
