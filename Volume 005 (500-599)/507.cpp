/* @JUDGE_ID: 19899RK 507 C++ "By Anadan" */ 
// Jill Rides Again
// Accepted (0.350 seconds using as much as 384 kbytes)

#include <stdio.h>

int main(){
	int set, route = 0, N, i, j, a, b, min, max, sum, x, y, z;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d", &N);
		j = a = b = sum = max = min = 0;

		for (i = 1; i < N; ++i){
			while ((x = getchar()) == ' ' || x == '\n');
			if (x == '-') { x = getchar(); z = 1; } else z = 0;
			x -= '0';
			while ((y = getchar()) != ' ' && y != '\n') x = x * 10 + y - '0';
			if (z) x = -x;

			sum += x;
			if (max < sum - min || (max == sum - min && i - j > b - a)){
				max = sum - min;
				a = j; b = i;
			}

			if (min > sum){
				min = sum;
				j = i;
			}
		}

		if (max <= 0) printf("Route %d has no nice parts\n", ++route);
		else printf("The nicest part of route %d is between stops %d and %d\n", ++route, a + 1, b + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
