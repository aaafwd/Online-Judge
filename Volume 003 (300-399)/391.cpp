/* @JUDGE_ID: 19899RK 391 C++ "By Anadan" */
// Mark-up
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int c;
	char mark_ups = 1, point, nums, slash = 0;

	while ((c = getc(stdin)) != EOF){
		if (mark_ups){
			if (slash){
				if (c == 's'){
					point = nums = 0;
					while ((c = getc(stdin)) != NULL){
						if (('0' <= c) && (c <= '9')) nums = 1;
						else if (c == '.'){
							if (point) break; else point = 1;
						}else break;
					}

					if (point && nums == 0) ungetc('.', stdin);
					ungetc(c, stdin);
				}else if (c == '*') mark_ups = 0;
				else if (c != 'b' && c != 'i') putchar(c);
				slash = 0;
			}
			else if (c == '\\') slash = 1;
			else putchar(c);
		}else{
			if (c == '\\'){
				if (slash) putchar('\\');
				else slash = 1;
			}else if (c == '*'){
				if (slash) mark_ups = 1;
				else putchar('*');
				slash = 0;
			}else{
				if (slash) putchar('\\');
				putchar(c);
				slash = 0;
			}
		}
	}

	if (slash) putchar('\\');
	return 0;
}
/* @END_OF_SOURCE_CODE */
