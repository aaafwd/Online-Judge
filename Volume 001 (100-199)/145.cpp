/* @JUDGE_ID: 19899RK 145 C++ "By Anadan" */
// Gondwanaland Telecom
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int step, h1, m1, h2, m2, mins[3];
	const int times[] = { 480, 1080, 1320, 1920, 2520, 2760, 3360 };
	const double rate[5][3] = {
		{ 0.10, 0.06, 0.02 },
		{ 0.25, 0.15, 0.05 },
		{ 0.53, 0.33, 0.13 },
		{ 0.87, 0.47, 0.17 },
		{ 1.44, 0.80, 0.30 }
	};
	double total;
	char str[9];

	while (scanf("%s", str) == 1 && str[0] != '#'){
		step = str[0] - 'A';
		scanf("%s%d%d%d%d\n", str, &h1, &m1, &h2, &m2);
		m1 += h1 * 60;
		m2 += h2 * 60;
		if (m2 <= m1) m2 += 1440;
		mins[0] = mins[1] = mins[2] = 0;

		for (h1 = 0 ;; ++h1){
			if (m1 >= times[h1]) continue;
			if (m2 < times[h1]){
				mins[(h1 + 2) % 3] += m2 - m1;
				break;
			}
			mins[(h1 + 2) % 3] += times[h1] - m1;
			m1 = times[h1];
		}

		total = 0.0;
		for (m1 = 0; m1 < 3; ++m1) total += rate[step][m1] * mins[m1];

		printf("%10s%6d%6d%6d  %c%8.2lf\n", str, mins[0], mins[1], mins[2], 'A' + step, total);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
