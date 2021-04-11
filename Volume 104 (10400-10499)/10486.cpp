/* @JUDGE_ID: 19899RK 10486 C++ "By Anadan" */ 
// Mountain Village
// Accepted (0.355 seconds using as much as 428 kbytes)

#include <stdio.h>

int r, c, entries[100], h1, h2, count, min, max;
char mask[40][40], map[40][40];

void fill(int i, int j){
	mask[i][j] = 1;
	++count;

	if (i && mask[i - 1][j] == 0 && h1 <= map[i - 1][j] && map[i - 1][j] <= h2) fill(i - 1, j);
	if (i < r - 1 && mask[i + 1][j] == 0 && h1 <= map[i + 1][j] && map[i + 1][j] <= h2) fill(i + 1, j);
	if (j && mask[i][j - 1] == 0 && h1 <= map[i][j - 1] && map[i][j - 1] <= h2) fill(i, j - 1);
	if (j < c - 1 && mask[i][j + 1] == 0 && h1 <= map[i][j + 1] && map[i][j + 1] <= h2) fill(i, j + 1);
}

int getentries(){
	int i, j, max = 0;

	for (i = 0; i < r; ++i) for (j = 0; j < c; ++j){
		mask[i][j] = 0;
	}

	for (i = 0; i < r; ++i) for (j = 0; j < c; ++j){
		if (mask[i][j] || map[i][j] < h1 || map[i][j] > h2) continue;
		count = 0;
		fill(i, j);
		if (max < count) max = count;
	}

	return max;
}

int getmindiff(int x){
	int i = 0, j = max - min, k;

	while (i < j - 1){
		k = (i + j) >> 1;
		if (entries[k] > x) j = k; else i = k;
	}

	if (entries[i] < x) ++i;
	while (i && entries[i - 1] >= x) --i;
	return i;
}

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int i, j;

	scanf("%d%d", &r, &c);
	min = 100; max = 0;
	for (i = 0; i < r; ++i){
		for (j = 0; j < c; ++j){
			myscanf(count);
			map[i][j] = count;
			if (min > count) min = count;
			if (max < count) max = count;
		}
	}

	for (i = max - min; i >= 0; --i) entries[i] = 0;

	for (h1 = min; h1 <= max; ++h1){
		for (h2 = h1; h2 <= max; ++h2){
			i = getentries();
			if (entries[h2 - h1] < i) entries[h2 - h1] = i;
		}
	}

	myscanf(j);
	while (j--){
		myscanf(i);
		printf("%d\n", getmindiff(i));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
