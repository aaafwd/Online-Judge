/* @JUDGE_ID: 19899RK 10800 C++ "By Anadan" */
// Not That Kind of Graph
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[51][51];

void paint(int row, int col, char ch) {
	char * p = map[row];
	while (col--) {
		if (*p == 0) *p = ' ';
		++p;
	}
	*p = ch;
}

int main(){
	int set, st = 0, i, ox, count, miny, maxy;
	char str[64];

	scanf("%d", &set);
	while (set--) {
		scanf("%s", str);
		maxy = -1; miny = 128;
		for (ox = count = 0; str[ox]; ++ox) {
			if (str[ox] == 'C' || str[ox] == 'R') {
				if (ox && str[ox-1] == 'R') ++count;
			} else if (str[ox] == 'F') {
				if (ox && str[ox-1] != 'R') --count;
			}

			if (miny > count) miny = count;
			if (maxy < count) maxy = count;
		}

		memset(map, 0, sizeof(map));
		for (ox = count = 0; str[ox]; ++ox) {
			if (str[ox] == 'C' || str[ox] == 'R') {
				if (ox && str[ox-1] == 'R') ++count;
				paint(maxy-count, ox, (str[ox] == 'C') ? '_' : '/');
			} else if (str[ox] == 'F') {
				if (ox && str[ox-1] != 'R') --count;
				paint(maxy-count, ox, '\\');
			}
		}

		printf("Case #%d:\n", ++st);
		maxy -= miny - 1;
		for (i = 0; i < maxy; ++i) {
			printf("| %s\n", map[i]);
		}
		printf("+--");
		while (ox--) putchar('-');
		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
