/* @JUDGE_ID: 19899RK 362 C++ "By Anadan" */ 
// 18,000 Seconds Remaining 
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#define SECONDS 5

int main(){
	int num = 0, cur, remain, rate, sec;

	while (scanf("%d", &remain) > 0){
		if (remain == 0L) break;
		printf("Output for data set %d, %d bytes:\n", ++num, remain);

		rate = 0L; sec = 0L;
		while (remain > 0L){
			scanf("%d", &cur);
			rate += cur; sec++; remain -= cur;
			if (!(sec % SECONDS)){
				if (rate == 0L) printf("   Time remaining: stalled\n");
				else {
					cur = (remain*SECONDS+rate-1)/rate;
					printf("   Time remaining: %d seconds\n", cur);
					rate = 0L;
				}
			}
		}
		printf("Total time: %d seconds\n\n", sec);
	}
	return 0;
}
/*   @END_OF_SOURCE_CODE   */
