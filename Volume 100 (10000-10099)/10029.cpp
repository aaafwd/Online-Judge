/* @JUDGE_ID: 19899RK 10029 C++ "By Anadan" */
// Edit Step Ladders
// Accepted (1.203 seconds using as much as 1024 kbytes)

#include <stdio.h>
#include <string.h>
#define HASH_SIZE 65536
#define HASH_JUMP 101
#define HASH_BASE 31

char words[25001][17];
int maxLen[25001], N = 0, maxMaxLen = 0;
short hash[HASH_SIZE];

int getHash(char * str) {
	int res = 0;
	while (*str) res = res * HASH_BASE + *str++ - 'a';
	return res;
}

void addToHash(char * str) {
	int h = getHash(str);
	if (h < 0) h = -h;
	h &= (HASH_SIZE - 1);
	while (hash[h]) h = (h + HASH_JUMP) & (HASH_SIZE - 1);
	hash[h] = N + 1;
}

int find(char * str) {
	int h = getHash(str);
	if (h < 0) h = -h;
	h &= (HASH_SIZE - 1);
	while (hash[h]) {
		if (strcmp(str, words[hash[h] - 1]) == 0) return int(hash[h] - 1);
		h = (h + HASH_JUMP) & (HASH_SIZE - 1);
	}
	return -1;
}

int calcMaxLenght(char * str) {
	int i, j, ndx, res = 1;
	static char buf[32];

	// deleting a letter
	for (i = 0; str[i]; ++i) {
		if (str[i] < str[i + 1]) continue;
		strncpy(buf, str, i);
		strcpy(buf + i, str + i + 1);
		ndx = find(buf);
		if (ndx != -1 && res < maxLen[ndx] + 1) {
			res = maxLen[ndx] + 1;
			if (res > maxMaxLen) return res;
		}
	}

	// inserting a letter
	for (i = 0; str[i]; ++i) {
		strncpy(buf, str, i);
		strcpy(buf + i + 1, str + i);
		for (j = 'a'; j <= str[i]; ++j) {
			buf[i] = j;
			ndx = find(buf);
			if (ndx != -1 && res < maxLen[ndx] + 1) {
				res = maxLen[ndx] + 1;
				if (res > maxMaxLen) return res;
			}
		}
	}

	// changing a letter
	strcpy(buf, str);
	for (i = 0; buf[i]; ++i) {
		for (j = 'a'; j < str[i]; ++j) {
			buf[i] = j;
			ndx = find(buf);
			if (ndx != -1 && res < maxLen[ndx] + 1) {
				res = maxLen[ndx] + 1;
				if (res > maxMaxLen) return res;
			}
			buf[i] = str[i];
		}
	}

	return res;
}

int main() {
	while (scanf("%s", words[N]) == 1) {
		addToHash(words[N]);
		maxLen[N] = calcMaxLenght(words[N]);
		if (maxMaxLen < maxLen[N]) maxMaxLen = maxLen[N];
		++N;
	}
	printf("%d\n", maxMaxLen);

	return 0;
}
/* @END_OF_SOURCE_CODE */
