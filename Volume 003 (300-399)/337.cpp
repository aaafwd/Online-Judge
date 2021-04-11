/* @JUDGE_ID: 19899RK 337 C++ "By Anadan" */
// Interpreting Control Sequences
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int row, col;
char screen[10][11];
char insert_mode;

void clear(){
	for (int i = 0; i < 10; i++) sprintf(screen[i], "%10s", "");
}

void printchar(char ch){
	if (insert_mode){
		for (int i = 9; i > col; i--){
			screen[row][i] = screen[row][i-1];
		}
	}
	screen[row][col] = ch;
	if (col < 9) ++col;
}

int main(){
	char str[80], *p, *q;
	int set = 0, i, N;

	while (scanf("%d\n", &N) > 0){
		if (N == 0) break;
		clear();
		insert_mode = 0;
		row = col = 0;
		for (i = 0; i < N; i++){
			gets(str);
			for (p = str; *p; p++){
				if (*p == '^'){
					p++;
					switch(*p){
					case 'b': col = 0; break;
					case 'c': clear(); break;
					case 'd': if (row < 9) ++row; break;
					case 'e': for (q = screen[row] + col; *q; q++) *q = ' '; break;
					case 'h': row = col = 0; break;
					case 'i': insert_mode = 1; break;
					case 'l': if (col) --col; break;
					case 'o': insert_mode = 0; break;
					case 'r': if (col < 9) ++col; break;
					case 'u': if (row) --row; break;
					case '^': printchar('^'); break;
					default:
						row = *p++ - '0';
						col = *p - '0';
						break;
					}
				}else printchar(*p);
			}
		}
		printf("Case %d\n", ++set);
		printf("+----------+\n");
		for (i = 0; i < 10; i++) printf("|%s|\n", screen[i]);
		printf("+----------+\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
