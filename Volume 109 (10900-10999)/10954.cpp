/* @JUDGE_ID: 19899RK 10954 C++ "By Anadan" */
// Add All
// Accepted (0.156 seconds using as much as 420 kbytes)

#include <stdio.h>
#include <algorithm>

int less(int a, int b) {
	if (a > b) return 1;
	return 0;
}

int main() {
	int i, N, sum, arr[5010];

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) scanf("%d", arr+i);
		std::make_heap(arr, arr+N, less);

		sum = 0;
		while (N > 1) {
			std::pop_heap(arr, arr+N,less);
			std::pop_heap(arr, arr+N-1,less);
			sum += arr[N-1]+arr[N-2];
			arr[N-2] += arr[N-1];
			--N;
			std::push_heap(arr, arr+N,less);
		}
		printf("%d\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
