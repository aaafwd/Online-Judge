/* @JUDGE_ID: 19899RK 10935 C++ "By Anadan" */
// Throwing cards away I
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <deque>

int main() {
	int N, i;
	std::deque<int> curr, discarded;

	while (scanf("%d", &N) == 1 && N) {
		curr.clear();
		discarded.clear();
		for (i = 1; i <= N; ++i) {
			curr.push_back(i);
		}
		while (curr.size() > 1) {
			i = curr.front();
			curr.pop_front();
			discarded.push_back(i);

			i = curr.front();
			curr.pop_front();
			curr.push_back(i);
		}

		printf("Discarded cards:");
		for (i = 0; i < discarded.size(); ++i) {
			if (i == 0) printf(" %d", discarded[i]);
			else printf(", %d", discarded[i]);
		}
		printf("\nRemaining card: %d\n", (int)curr.front());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
