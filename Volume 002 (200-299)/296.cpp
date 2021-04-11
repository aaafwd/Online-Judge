/* @JUDGE_ID: 19899RK 296 C++ "By Anadan" */
// Safebreaker
// Accepted (3.060 seconds using as much as 412 kbytes)
// Too much time !

#include <stdio.h>

int satisfy(int N, char *s, int a, int b){
	int i, j, k = 0;
	char buf[5], str[5];
	sprintf(str, "%s", s);
	sprintf(buf, "%.4d", N);

	for (i = 0; i < 4; i++){
		if (buf[i] == str[i]){
			a--;
			buf[i] = k++;
			str[i] = k++;
		}
	}
	if (a) return 0;

	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (buf[i] == str[j]){
				b--;
				buf[i] = k++;
				str[j] = k++;
				break;
			}
		}
	}
	if (b) return 0;

	return 1;
}

int main(){
	char str[5];
	int N, G, nums[7000], a, b, i, j, max;
	scanf("%d", &N);

	while (N--){
		scanf("%d\n", &G);
		if (!G){
			printf("indeterminate\n");
			continue;
		}
		G--;
		scanf("%4s %d/%d\n", str, &a, &b);

		for (max = i = 0; i < 10000; i++){
			if (satisfy(i, str, a, b)) nums[max++] = i;
		}

		while (G--){
			scanf("%4s %d/%d\n", str, &a, &b);
			for (i = j = 0; i < max; i++){
				if (satisfy(nums[i], str, a, b)) nums[j++] = nums[i];
			}
			max = j;
		}
		if (max == 0) printf("impossible\n");
		else if (max > 1) printf("indeterminate\n");
		else printf("%.4d\n", nums[0]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
