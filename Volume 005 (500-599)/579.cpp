/* @JUDGE_ID: 19899RK 579 C++ "By Anadan" */
// ClockHands
// Accepted (0.190 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int h, m;
	double tmp;

	while (scanf("%d:%d\n", &h, &m) == 2){
		if (h == 0 && m == 0) break;
		if (h == 12) h = 0;
		tmp = 30.0 * double(h) - 5.5 * double(m);
		if (tmp < 0) tmp = -tmp;
		if (360.0 - tmp < tmp) tmp = 360.0 - tmp;
		printf("%.3lf\n", tmp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
