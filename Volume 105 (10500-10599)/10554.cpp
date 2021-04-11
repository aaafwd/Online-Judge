/* @JUDGE_ID: 19899RK 10554 C++ "By Anadan" */
// Calories from Fat
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>

const int cal_g[] = { 9, 4, 4, 4, 7 };

int main(){
	int i, N, v[5], a, b;
	char ch[5];
	double fat, total, tmp;

	while (1){
		fat = total = 0.0;
		for (N = 0 ;; ++N){
			for (i = 0; i < 5; ++i){
				if (scanf("%d%c", v + i, ch + i) != 2) break;
			}

			if (i < 5) break;
			a = b = 0;
			for (i = 0; i < 5; ++i){
				if (ch[i] == 'g') a += v[i] * cal_g[i];
				else if (ch[i] == 'C') a += v[i];
				else if (ch[i] == '%') b += v[i];
				else while (1) putchar('=');
			}

			tmp = double(a) * 100.0 / (100 - b);
			total += tmp;
			if (ch[0] == 'g') fat += v[0] * cal_g[0];
			else if (ch[0] == 'C') fat += v[0];
			else if (ch[0] == '%') fat += v[0] * 0.01 * tmp;
		}

		if (N == 0) break;
		printf("%.0lf%%\n", fat / total * 100);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
