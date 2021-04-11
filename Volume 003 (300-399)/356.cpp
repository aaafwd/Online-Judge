/* @JUDGE_ID: 19899RK 356 C++ "By Anadan" */
// Square Pegs And Round Holes
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int i, n, in, out = 0;
	double r, x;

	while (scanf("%d", &n) > 0){
		if (out) printf("\n");
		in = out = 0;
		r = double(n) - 0.5; r *= r;
		for (i = 1; i < n; i++){
			x = sqrt(r - i*i);
			in += floor(x);
			if (x == floor(x)){
				out++;
			}else out += 2;
		}
		out++;
		in <<= 2;; out <<= 2;
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, out);
		printf("There are %d cells completely contained in the circle.\n", in);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
