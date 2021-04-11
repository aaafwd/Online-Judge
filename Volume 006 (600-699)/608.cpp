/* @JUDGE_ID: 19899RK 608 C++ "By Anadan" */
// Counterfeit Dollar
// Accepted (0.110 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	int i, j, set;
	char s1[9], s2[9], res[9], flags[12], tmpf[12];

	scanf("%d\n", &set);
	while (set--){
		memset(flags, 2, 12);
		for (j = 0; j < 3; j++){
			scanf("%s %s %s\n", s1, s2, res);
			memset(tmpf, 0, 12);

			if (res[0] == 'd'){
				for (i = 0; s1[i]; i++){
					tmpf[s1[i] - 'A'] = -1;
					tmpf[s2[i] - 'A'] = 1;
				}
			}else{
				for (i = 0; s1[i]; i++){
					tmpf[s1[i] - 'A'] = 1;
					tmpf[s2[i] - 'A'] = -1;
				}
			}

			if (res[0] == 'e'){
				for (i = 0; i < 12; i++){
					if (tmpf[i]) flags[i] = 0;
				}
			}else{
				for (i = 0; i < 12; i++){
					if (!tmpf[i]) flags[i] = 0;
					else if (flags[i]){
						if (flags[i] == 2) flags[i] = tmpf[i];
						else if (flags[i] != tmpf[i]) flags[i] = 0;
					}
				}
			}
		}

		for (i = 0; i < 12; i++){
			if (flags[i]){
				printf("%c is the counterfeit coin and it is %s.\n", 'A' + i, (flags[i] < 0) ? ("light") : ("heavy"));
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
