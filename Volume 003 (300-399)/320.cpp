/* @JUDGE_ID: 19899RK 320 C++ "By Anadan" */
// Border
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	char str[1024], map[32][33], *p;
	int i, j, sets, x, y;
	scanf("%d", &sets);

	for (i = 1; i <= sets; i++){
		for (j = 0; j < 32; j++)
			sprintf(map[j], "................................");
		scanf("%d%d\n%s\n", &x, &y, str);

		for (p = str; *p != '.'; p++){
			switch(*p){
			case 'E': map[y-1][x++] = 'X'; break;
			case 'N': map[y++][x] = 'X'; break;
			case 'W': map[y][--x] = 'X'; break;
			case 'S': map[--y][x-1] = 'X'; break;
			}
		}

		printf("Bitmap #%d\n", i);
		for (j = 31; j >= 0; j--) printf("%s\n", map[j]);
		printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
