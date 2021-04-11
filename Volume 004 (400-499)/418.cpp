/* @JUDGE_ID: 19899RK 418 C++ "By Anadan" */
// Molecules
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))

int main(){
	char a[4][13];
	int i, j, x, y, x1, x2, y1, y2, S, tmp;

	while(1){
		if (scanf("%1s", a[0]) <= 0) break;
		if ((a[0][0] == 'Q') || (a[0][0] == 'q')) break;
		for (i = 1; i < 12; i++) scanf("%1s", &a[0][i]);
		for (i = 0; i < 12; i++) scanf("%1s", &a[1][i]);
		for (i = 0; i < 12; i++) scanf("%1s", &a[2][i]);
		for (i = 0; i < 12; i++) scanf("%1s", &a[3][i]);

		S = 0;
		for (i=1; i<4; i++)
		for (x1=1; x1<11; x1++)
		for (y1=1; y1<11; y1++)
		if (a[0][x1] == a[i][y1])

		for (j=1; j<4; j++){
			if (j == i) continue;

			for (x2=x1+2; x2<11; x2++)
			for (y2=1; y2<11; y2++)
			if (a[0][x2] == a[j][y2]){
				for (y=2; y<MIN(y1,y2); y++)
				for (x=1; x<(11-x2+x1); x++)
				if (a[6-i-j][x] == a[i][y1-y])
				if (a[6-i-j][x+(x2-x1)] == a[j][y2-y]){
					tmp = (x2-x1-1)*(y-1);
					if (tmp > S) S = tmp;
				}
				for (y=2; y<11-MAX(y1,y2); y++)
				for (x=1; x<(11-x2+x1); x++)
				if (a[6-i-j][x] == a[i][y1+y])
				if (a[6-i-j][x+(x2-x1)] == a[j][y2+y]){
					tmp = (x2-x1-1)*(y-1);
					if (tmp > S) S = tmp;
				}
			}
		}
		printf("%d\n", S);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
