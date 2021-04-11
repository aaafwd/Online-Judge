/* @JUDGE_ID: 19899RK 488 C++ "By Anadan" */
// Triangle Wave
// Accepted (2.039 seconds using as much as 392 kbytes)

#include <stdio.h>

int ampl, freq;

void func() {
	int i, j;
	if (ampl == 1) printf("1\n");
	else for (i=1; i<=ampl; i++){
		for (j=0; j<i; j++) printf("%d", i);
		printf("\n");
	}

	for (i=ampl-1; i>0; i--) {
		for (j=0; j<i; j++) printf("%d", i);
		printf("\n");
	}
	if (freq) printf("\n");
}

int main() {
	int set;
	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &ampl, &freq);
		if (ampl) while (freq--) func();
		if (set) printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
