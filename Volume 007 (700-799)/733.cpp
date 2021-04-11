/* @JUDGE_ID: 19899RK 733 C++ "By Anadan" */
// Follow the Folding Dot
// Accepted (0.168 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <math.h>

double w, h, x, y;

int onmovingside(char ch){
	if (ch == 'T') return (y < h * 0.5);
	else if (ch == 'B') return (y > h * 0.5);
	else if (ch == 'L') return (x < w * 0.5);
	return (x > w * 0.5);
}

int main(){
	int set = 0, curpage, pages;
	char str[3], istop;

	while (scanf("%lf%lf\n%lf%lf%s\n", &w, &h, &x, &y, str) == 5){
		curpage = pages = 1;
		if (str[0] == 'T') istop = 1; else istop = 0;
		printf("Paper number %d\n", ++set);
		printf("Beginning paper dimensions %.6lf X %.6lf\n", w, h);
		printf("Dot is on %s of page 1. Position: %.6lf X %.6lf\n\n", (istop)?("TOP"):("BOTTOM"), x, y);

		while (scanf("%s\n", str) == 1 && str[0] != 'S'){
			if (onmovingside(str[0])){
				curpage = pages - curpage + 1;
				istop ^= 1;
				if (str[1] == 'U') curpage += pages;
			}else{
				if (str[1] == 'O') curpage += pages;
			}

			pages <<= 1;

			switch (str[0]){
			case 'T': y = fabs(y - h * 0.5); h *= 0.5; break;
			case 'B': y = h * 0.5 - fabs(y - h * 0.5); h *= 0.5; break;
			case 'L': x = fabs(x - w * 0.5); w *= 0.5; break;
			case 'R': x = w * 0.5 - fabs(x - w * 0.5); w *= 0.5; break;
			}
		}

		printf("After folding paper. Paper dimensions: %.6lf X %.6lf\n", w, h);
		printf("Dot is on %s of page %d. Position %.6lf X %.6lf\n\n", (istop)?("TOP"):("BOTTOM"), curpage, x, y);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
