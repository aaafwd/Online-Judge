/* @JUDGE_ID: 19899RK 402 C++ "By Anadan" */
// M*A*S*H
// Accepted (0.885 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int main(){
	char line[80], *p;
	int N, X, cards[20], i, j, cur_card, pos, set = 0;

	while (gets(line)){
		sscanf(line, "%d%d%n", &N, &X, &j);
		p = line + j;
		for (i = 0; i < 20 && *p; ++i, p += j) sscanf(p, "%d%n", cards + i, &j);
		for (i = 0; i < N; ++i) line[i] = i + 1;
		cur_card = pos = 0;

		while (X < N && cur_card < 20){
			pos += cards[cur_card] - 1;
			if (pos < N){
				memcpy(line + pos, line + pos + 1, N - pos - 1);
				--N;
			}else{
				pos = 0;
				++cur_card;
			}
		}

		printf("Selection #%d\n", ++set);
		printf("%d", int(line[0]));
		for (i = 1; i < N; ++i) printf(" %d", int(line[i]));
		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
