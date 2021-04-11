/* @JUDGE_ID: 19899RK 183 C++ "By Anadan" */
// Bit Maps
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[200][200];
int count;

void outprint_d(int r0, int r1, int c0, int c1){
	int i, j = map[r0][c0] ^ 1;

	if (r0 > r1 || c0 > c1) return;
	for (i = r0; i <= r1; ++i){
		if (memchr(map[i] + c0, j, c1 - c0 + 1)) break;
	}

	if (i <= r1){
		++count;
		if (count == 51){
			count = 1;
			putchar('\n');
		}
		putchar('D');
		outprint_d(r0, r0+((r1-r0) >> 1), c0, c0+((c1-c0) >> 1));
		outprint_d(r0, r0+((r1-r0) >> 1), c0+((c1-c0) >> 1) + 1, c1);
		outprint_d(r0+((r1-r0) >> 1) + 1, r1, c0, c0+((c1-c0) >> 1));
		outprint_d(r0+((r1-r0) >> 1) + 1, r1, c0+((c1-c0) >> 1) + 1, c1);
	}else{
		++count;
		if (count == 51){
			count = 1;
			putchar('\n');
		}
		putchar(j ^ 1);
	}
}

void fillmap(int r0, int r1, int c0, int c1){
	int i, j;
	char ch[2];

	if (r0 > r1 || c0 > c1) return;
	scanf("%1s", ch);
	if (ch[0] == 'D'){
		fillmap(r0, r0+((r1-r0) >> 1), c0, c0+((c1-c0) >> 1));
		fillmap(r0, r0+((r1-r0) >> 1), c0+((c1-c0) >> 1) + 1, c1);
		fillmap(r0+((r1-r0) >> 1) + 1, r1, c0, c0+((c1-c0) >> 1));
		fillmap(r0+((r1-r0) >> 1) + 1, r1, c0+((c1-c0) >> 1) + 1, c1);
	}else{
		for (i = r0; i <= r1; ++i){
			for (j = c0; j <= c1; ++j) map[i][j] = ch[0];
		}
	}
}

int main(){
	char ch[2];
	int rows, cols, i, j;

	while (scanf("%s%d%d", ch, &rows, &cols) == 3 && ch[0] != '#'){
		if (ch[0] == 'B'){
			for (i = 0; i < rows; ++i) for (j = 0; j < cols; ++j){
				scanf("%1s", &map[i][j]);
			}
			printf("D%4d%4d\n", rows, cols);
			count = 0;
			outprint_d(0, rows - 1, 0, cols - 1);
			putchar('\n');
		}else if (ch[0] == 'D'){
			fillmap(0, rows - 1, 0, cols - 1);
			printf("B%4d%4d\n", rows, cols);
			count = 0;
			for (i = 0; i < rows; ++i) for (j = 0; j < cols; ++j){
				++count;
				if (count == 51){
					count = 1;
					putchar('\n');
				}
				putchar(map[i][j]);
			}
			putchar('\n');
		}else return 1;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
