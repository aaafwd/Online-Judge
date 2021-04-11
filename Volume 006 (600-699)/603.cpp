/* @JUDGE_ID: 19899RK 603 C++ "By Anadan" */
// Parking Lot
// Accepted (0.100 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	char str[1000];
	int set, pos[20], origin[20], parked[20], N, p, i, offset, rest;

	scanf("%d\n\n", &set);
	while (set--){
		N = offset = 0;
		memset(pos, 0, 20 * sizeof(int));
		memset(parked, 0, 20 * sizeof(int));

		while (gets(str)){
			sscanf(str, "%d", &p);
			if (p == 99) break;
			origin[N] = p;
			pos[p - 1] = ++N;
		}

		rest = N;
		while (gets(str) && str[0]){
			if (!rest) continue;
			sscanf(str, "%d", &p);
			for (p += 39, i = 0; i <= 20; ++i){
				if (pos[(p - i - offset) % 20]){
					parked[pos[(p - i - offset) % 20] - 1] = p - 39;
					pos[(p - i - offset) % 20] = 0;
					offset = (offset + i) % 20;
					break;
				}
			}
			--rest;
		}

		for (i = 0; i < N; ++i){
			printf("Original position %d ", origin[i]);
			if (parked[i]) printf("parked in %d\n", parked[i]);
			else printf("did not park\n");
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
