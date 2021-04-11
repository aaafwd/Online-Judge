/* @JUDGE_ID: 19899RK 105 C++ "By Anadan" */
// The Skyline Problem
// Accepted (0.140 seconds using as much as 424 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int i, L, H, R, flags[10000];

	memset(flags, 0, 10000u * sizeof(int));
	while (scanf("%d%d%d", &L, &H, &R) == 3){
		for (i = L; i < R; i++) if (flags[i] < H) flags[i] = H;
	}
	for (i = 0; flags[i] == 0; i++);
	printf("%d %d", i, flags[i]); H = flags[i];
	for (++i; i < 10000; i++){
		if (flags[i] == H) continue;
		printf(" %d %d", i, flags[i]); H = flags[i];
	}
	printf("\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
