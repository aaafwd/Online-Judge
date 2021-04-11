/* @JUDGE_ID: 19899RK 700 C++ "By Anadan" */ 
// Date Bugs
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Years{
	int yy, dy;
}pt[20];
int index;

int main(){
	int i, j, t1, t2, set = 0;

	while (scanf("%d", &index) == 1 && index){
		printf("Case #%d:\n", ++set);
		for (i = 0; i < index; i++){
			scanf("%d%d%d", &pt[i].yy, &t1, &t2);
			pt[i].dy = t2 - t1;
		}

		for (i = pt[0].yy; i < 10000; i += pt[0].dy){
			for (j = 1; j < index; j++){
				if (i < pt[j].yy) break;
				if ((i - pt[j].yy) % pt[j].dy) break;
			}

			if (j == index) break;
		}

		if (i < 10000) printf("The actual year is %d.\n\n", i);
		else printf("Unknown bugs detected.\n\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
