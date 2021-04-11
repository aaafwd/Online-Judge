/* @JUDGE_ID: 19899RK 10129 C++ "By Anadan" */ 
// Play on Words
// Accepted (0.105 seconds using as much as 388 kbytes)

#include <stdio.h>

int main(){
	int set, T, i, a, b, d[26];
	char mask[26], groups[26];

	scanf("%d\n", &set);
	while (set--){
		for (i = 0; i < 26; ++i){
			d[i] = 0;
			mask[i] = 0;
			groups[i] = i;
		}

		scanf("%d\n", &T);
		while (T--){
			while ((a = getchar()) != EOF && (a < 'a' || a > 'z'));
			b = a;
			while ((i = getchar()) != EOF && 'a' <= i && i <= 'z') b = i;
			a -= 'a'; b -= 'a';
			++d[a]; --d[b];
			mask[a] = mask[b] = 1;
			a = groups[a]; b = groups[b];
			for (i = 0; i < 26; ++i) if (groups[i] == b) groups[i] = a;
		}

		for (i = 0; i < 26; ++i) if (mask[i]) break;
		for (a = i + 1; a < 26; ++a) if (mask[a] && groups[a] != groups[i]) break;

		if (a == 26){
			a = b = 0;
			for (i = 0; i < 26; ++i){
				if (d[i] == 0) continue;
				if (d[i] == 1) ++a;
				else if (d[i] == -1) --b;
				else break;
			}
		}

		if (i < 26 || a + b != 0 || a > 1) printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
