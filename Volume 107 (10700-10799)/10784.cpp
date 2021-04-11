/* @JUDGE_ID: 19899RK 10784 C++ "By Anadan" */
// Diagonal
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

typedef long long qword;

int main() {
	int set = 0;
	qword N, tmp;

	while (scanf("%lld", &N) == 1 && N) {
		tmp = qword((sqrt(N*8+9)+3)*0.5);
		if (tmp*(tmp-3) < N+N) ++tmp;
		printf("Case %d: %lld\n", ++set, tmp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
