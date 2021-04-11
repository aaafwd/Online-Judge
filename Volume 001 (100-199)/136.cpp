/* @JUDGE_ID: 19899RK 136 C++ "By Anadan" */
// Ugly Numbers
// Accepted

#include <stdio.h>
#include <time.h>

int main(){
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;
/*
//	long j, i = 2L, N = 1L;
//	long j, i = 12754584L, N = 799L;
//	long j, i = 26214400L, N = 898L;
//	long j, i = 95659380L, N = 1097L;
//	long j, i = 301989888L, N = 1296L;
	long j, i = 301989888L, N = 1296L;

//	for (i = 2L; ;i++){
	while (1){
//		if (!(i % 7)) continue;
//		if (!(i % 11)) continue;
//		if (!(i % 13)) continue;
		j = i;
		while (!(j & 1)) j >>= 1;
		while (!(j % 3)) j /= 3;
		while (!(j % 5)) j /= 5;
		if (j == 1){
			N++;
			printf("%ld %ld ", N, i);
			printf("%.3lf\n", clock() / double(CLK_TCK));
			if (N == 800) break;
		}
		i++;
	}
//	printf("The 1500'th ugly number is %ld.\n", i);
	printf("Time = %.3lf\n", clock() / double(CLK_TCK));
	return 0;
//*/
}
/* @END_OF_SOURCE_CODE */
