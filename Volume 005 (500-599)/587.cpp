/* @JUDGE_ID: 19899RK 587 C++ "By Anadan" */
// There's treasure everywhere!
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	long n = 0;
	int off, tmp;
	char str[256], *p;
	double x, y, step, part = 1.0 / sqrt(2.0);

	while (scanf("%255s\n", str) > 0){
		if (str[0] == 'E') break;
		x = y = 0.0;
		printf("Map #%ld\n", ++n);
		p = strtok(str, ",.");
		while(p){
			sscanf(p, "%d%n", &tmp, &off); p += off;
			step = double(tmp);
			if (p[0] == 'N'){
				p++;
				if (p[0] == 'E'){
					step *= part;
					x += step; y += step;
				}else if (p[0] == 'W'){
					step *= part;
					x -= step; y += step;
				}else y += step;
			}else if (p[0] == 'S'){
				p++;
				if (p[0] == 'E'){
					step *= part;
					x += step; y -= step;
				}else if (p[0] == 'W'){
					step *= part;
					x -= step; y -= step;
				}else y -= step;
			}
			else if (p[0] == 'W') x -= step;
			else if (p[0] == 'E') x += step;
			p = strtok(NULL, ",.");
		}
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x+y*y));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
