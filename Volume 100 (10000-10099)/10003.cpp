/* @JUDGE_ID: 19899RK 10003 C++ "By Anadan" */
// Cutting Sticks
// Accepted (2.654 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>

int N, cuts[52];
int mincosts[52][52];

int getmincost(int i, int j){
	int k, tmp;

	if (i >= j-1) return 0;
	if (mincosts[i][j] != -1) return mincosts[i][j];

	mincosts[i][j] = getmincost(i + 1, j);
	for (k = i + 2; k < j; ++k){
		tmp = getmincost(i, k) + getmincost(k, j);
		if (mincosts[i][j] > tmp) mincosts[i][j] = tmp;
	}
	mincosts[i][j] += cuts[j] - cuts[i];

	return mincosts[i][j];
}

int main(){
	int i, j, L;

	cuts[0] = 0;
	while (scanf("%d", &L) == 1 && L){
		scanf("%d", &N);
		memset(mincosts, -1, sizeof(mincosts));

		for (i = 1; i <= N; ++i) scanf("%d", cuts + i);
		cuts[i] = L;
		printf("The minimum cutting is %d.\n", getmincost(0, i));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
