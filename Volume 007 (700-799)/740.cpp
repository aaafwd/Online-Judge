/* @JUDGE_ID: 19899RK 740 C++ "By Anadan" */
// Baudot Data Communication Code
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	char up[33], down[33], str[100], upshift, *p, code;
	gets(down);
	gets(up);

	while (gets(str)){
		upshift = 0;
		for (p = str; *p; p++){
			code = 0;
			if (*p++ == '1') code |= 1; code <<= 1;
			if (*p++ == '1') code |= 1; code <<= 1;
			if (*p++ == '1') code |= 1; code <<= 1;
			if (*p++ == '1') code |= 1; code <<= 1;
			if (*p == '1') code |= 1;
			if (code == 27) upshift = 0;
			else if (code == 31) upshift = 1;
			else{
				if (upshift) printf("%c", up[code]);
				else printf("%c", down[code]);
			}
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
