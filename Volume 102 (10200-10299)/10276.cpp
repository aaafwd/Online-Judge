/* @JUDGE_ID: 19899RK 10276 C++ "By Anadan" */ 
// Hanoi Tower Troubles Again!
// Accepted (0.090 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline int square(int N){
	int i = sqrt(N);
	return (i * i == N);
}

int main(){
	int T, nums[50], solves[51], i, j;

	for (T = 1; T <= 50; ++T){
		for (i = 0; i < T; ++i) nums[i] = 0;
		for (i = 1; i < 10000; ++i){
			for (j = 0; j < T; ++j){
				if (nums[j] == 0 || square(nums[j] + i)){
					nums[j] = i;
					break;
				}
			}

			if (j == T) break;
		}

		solves[T] = i - 1;
	}

	scanf("%d\n", &T);
	while (T--){
		scanf("%d\n", &i);
		printf("%d\n", solves[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
