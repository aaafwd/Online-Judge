/* @JUDGE_ID: 19899RK 373 C++ "By Anadan" */
// Romulan Spelling
// Accepted (0.270 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 256

inline void swapc(char &a, char &b) { a ^= b; b ^= a; a ^= b; }

int main(){
	int i;
	char buf[SIZE];
	memset(buf, 0, SIZE);

	while(fgets(buf, SIZE, stdin)){
		for (i = 0; buf[i]; i++){
			if (tolower(buf[i]) == 'p' && tolower(buf[i+1]) == 'g'){
				if (!(i > 0 && tolower(buf[i-1]) == 'e' ||
					tolower(buf[i+2]) == 'u' && tolower(buf[i+3]) == 'k')){
					swapc(buf[i], buf[i+1]);
					if (i) i -= 2; else i--;
				}
			}
			else if (tolower(buf[i]) == 'g' && tolower(buf[i+1]) == 'p'){
				if (i > 0 && tolower(buf[i-1]) == 'e' ||
					tolower(buf[i+2]) == 'u' && tolower(buf[i+3]) == 'k'){
					swapc(buf[i], buf[i+1]);
					if (i) i -= 2; else i--;
				}
			}
		}
		fputs(buf, stdout);
		memset(buf, 0, SIZE);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
