/* @JUDGE_ID: 19899RK 10409 C++ "By Anadan" */
// Die Game
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, t, n, w;
	char str[10];

	while (scanf("%d", &set) == 1 && set){
		t = 1; n = 2; w = 3;
		while (set--){
			scanf("%s\n", str);
			if (str[0] == 'n'){
				t ^= n ^= t ^= n;
				t = 7 - t;
			}else if (str[0] == 's'){
				t ^= n ^= t ^= n;
				n = 7 - n;
			}else if (str[0] == 'w'){
				t ^= w ^= t ^= w;
				t = 7 - t;
			}else if (str[0] == 'e'){
				t ^= w ^= t ^= w;
				w = 7 - w;
			}else return 1;
		}

		printf("%d\n", t);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
