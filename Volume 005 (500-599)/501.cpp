/* @JUDGE_ID: 19899RK 501 C++ "By Anadan" */ 
// Black Box
// Accepted (13.430 seconds using as much as 512 kbytes)
// Too much time !

#include <stdio.h>

int ptr[30000];

void do_arrange(int n){
	int i = 0, j = n - 1, k;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (ptr[k] > ptr[n]) j = k;
		else i = k;
	}

	while (ptr[i] < ptr[n]) ++i;

	k = ptr[n];
	for (j = n; j > i; --j){
		ptr[j] = ptr[j - 1];
	}

	ptr[i] = k;
}

int main(){
	int i, j, k, M, N, tmp, aranged, set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &M, &N);
		for (i = 0; i < M; ++i) scanf("%d", ptr + i);

		aranged = 1;
		for (i = j = 0; j < N; ++j){
			scanf("%d", &tmp);
			if (aranged >= tmp) printf("%d\n", ptr[i++]);
			else{
				while (aranged < tmp) do_arrange(aranged++);
				printf("%d\n", ptr[i++]);
			}
		}

		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
