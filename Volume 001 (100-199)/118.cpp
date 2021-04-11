/* @JUDGE_ID: 19899RK 118 C++ "By Anadan" */
// Mutant Flatworld Explorers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char scent[51][51];
int H, W;

int main(){
	int i, x, y, dx, dy;
	char str[101], *p;

	scanf("%d%d\n", &H, &W);
	for (i = 0; i <= H; ++i) memset(scent[i], 0, W + 1);
	while (scanf("%d %d %s\n", &x, &y, str) == 3){
		if (str[0] == 'N') dx = 0, dy = 1;
		else if (str[0] == 'S') dx = 0, dy = -1;
		else if (str[0] == 'W') dx = -1, dy = 0;
		else if (str[0] == 'E') dx = 1, dy = 0;
		else return 1;

		scanf("%s\n", str);
		for (p = str; *p; ++p){
			if (*p == 'F'){
				x += dx; y += dy;
				if (x < 0 || x > H || y < 0 || y > W){
					x -= dx; y -= dy;
					if (scent[x][y] == 0){
						scent[x][y] = 1;
						break;
					}
				}
			}else{
				dx ^= dy ^= dx ^= dy;
				if (*p == 'L') dx = -dx; else dy = -dy;
			}
		}

		printf("%d %d %c", x, y, "SW EN"[2 + dx + 2*dy]);
		if (*p) printf(" LOST");
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
