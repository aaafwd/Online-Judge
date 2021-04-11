/* @JUDGE_ID: 19899RK 10665 C++ "By Anadan" */
// Diatribe against Pigeonholes
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int nums[26], lets[26];

inline void swap(int &a, int &b) { int c = a; a = b; b = c; }

int main(){
	int set, N, i, j, a, b, m1, m2;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);

		for (i = 0; i < N; ++i){
			lets[i] = i + 'A';
			nums[i] = 0;
		}

		while ((i = getchar()) != EOF && i != '#'){
			if ('A' <= i && i <= 'Z') ++nums[i - 'A'];
		}

		for (a = 0, b = N - 1; a < b; ++a, --b){
			m1 = nums[a]; m2 = nums[a + 1];
			if (m1 < m2) swap(m1, m2);
			for (j = a + 2; j <= b; ++j){
				if (m2 < nums[j]){
					if (m1 < nums[j]) { m2 = m1; m1 = nums[j]; }
					else m2 = nums[j];
				}
			}

			for (i = -1, j = a; j <= b; ++j){
				if ((nums[j] == m1 || nums[j] == m2) && (i == -1 || lets[i] > lets[j])) i = j;
			}
			swap(nums[a], nums[i]); swap(lets[a], lets[i]);

			for (j = a + 1; j <= b; ++j) if (nums[j] == m1) break;
			if (j <= b) m2 = m1;

			for (i = -1, j = a + 1; j <= b; ++j){
				if ((nums[j] == m1 || nums[j] == m2) && (i == -1 || lets[i] < lets[j])) i = j;
			}
			swap(nums[b], nums[i]); swap(lets[b], lets[i]);
		}

		for (i = 0; i < N; ++i) { if (i) putchar(' '); putchar(lets[i]); }
		putchar('\n');
		for (i = 0; i < N; ++i) { if (i) putchar(' '); printf("%d", nums[i]); }
		putchar('\n');
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
