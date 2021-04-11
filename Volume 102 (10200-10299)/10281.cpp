/* @JUDGE_ID: 19899RK 10281 C++ "By Anadan" */ 
// Average Speed
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int v, t, hh, mm, ss, tt;
	double p;
	char str[81];

	p = 0.0;
	v = t = 0;
	while (scanf("%d:%d:%d", &hh, &mm, &ss) == 3){
		tt = hh*3600 + mm*60 + ss;
		gets(str);
		if (sscanf(str, "%d", &mm) == 1){
			p += double(tt - t) * v / 3600.0;
			t = tt; v = mm;
		}else printf("%.2d:%.2d:%.2d %.2lf km\n", hh, mm, ss, p + double(tt - t) * v / 3600.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
