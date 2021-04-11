/* @JUDGE_ID: 19899RK 739 C++ "By Anadan" */
// Soundex Indexing
// Accepted (0.250 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

char getcode(char ch){
	char c;
	if (strchr("AEIOUYWH", ch)) c = '0';
	else if (ch == 'R') c = '6';
	else if (ch == 'L') c = '4';
	else if (ch == 'M' || ch == 'N') c = '5';
	else if (ch == 'D' || ch == 'T') c = '3';
	else if (ch == 'B' || ch == 'P' || ch == 'F' || ch == 'V') c = '1';
	else c = '2';
	return c;
}

int main(){
	int i;
	char str[21], *p, code[4], c, prev;

	code[3] = 0;
	printf("         NAME                     SOUNDEX CODE\n");
	while (scanf("%s\n", str) > 0){
		prev = getcode(str[0]);
		code[0] = code[1] = code[2] = '0';
		for (i = 0, p = str + 1; *p; p++){
			c = getcode(*p);
			if (c == prev) continue;
			if (c != '0'){
				code[i++] = c;
				if (i == 3) break;
			}
			prev = c;
		}
		printf("         %s", str);
		i = 25 - strlen(str);
		while (i--) printf(" ");
		printf("%c%s\n", str[0], code);
	}

	printf("                   END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
