/* @JUDGE_ID: 19899RK 484 C++ "By Anadan" */
// The Department of Redundancy Department
// Accepted (0.270 seconds using as much as 8192 kbytes)

#include <stdio.h>
#define SIZE 1000000

struct my_struct{
	long num, freq;
}nums[SIZE];

int main(){
	long index = 0, i, N;

	while (scanf("%ld", &N) > 0){
		for (i = 0L; i < index; i++){
			if (nums[i].num == N){
				nums[i].freq++;
				break;
			}
		}
		if (i == index){
			nums[index].num = N;
			nums[index++].freq = 1L;
		}
	}

	for (i = 0L; i < index; i++) printf("%ld %ld\n", nums[i].num, nums[i].freq);
	return 0;
}
/* @END_OF_SOURCE_CODE */
