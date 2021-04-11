/* @JUDGE_ID: 19899RK 652 C++ "By Anadan" */
// Eight
// Accepted (1.580 seconds using as much as 3608 kbytes)

#include <stdio.h>
#include <string.h>

class Permutation {
private:
	int * arr, size;
	static const int factorials[];
public:

	Permutation(int * ptr, int size) {
		this->arr = ptr;
		this->size = size;
	}

	const int * getPermutation() const { return arr; }
	int getSize() const { return size; }

	int getNumber() const {
		int res = 0, i, j, count;
		char * mask = new char[size];

		for (i = 0; i < size; ++i) mask[i] = 0;
		for (i = 0; i < size; ++i) {
			count = 0;
			for (j = 0; j < size; ++j) {
				if (mask[j]) continue;
				if (j == arr[i]) break;
				++count;
			}
			mask[j] = 1;
			res += count * factorials[size-i-1];
		}

		delete[] mask;
		return res;
	}

	// 0 <= number < sz!
	// O(sz^2) algorithm
	static int * calcPermutation(int number, int sz) {
		int * res = new int[sz], i, j;
		char * mask = new char[sz];

		for (i = 0; i < sz; ++i) mask[i] = 0;
		for (i = 0; i < sz; ++i) {
			res[i] = number / factorials[sz-i-1];
			for (j = 0; j < sz; ++j) {
				if (mask[j]) continue;
				if (res[i]-- == 0) {
					mask[j] = 1;
					res[i] = j;
					break;
				}
			}
			number %= factorials[sz-i-1];
		}

		delete[] mask;
		return res;
	}
};
const int Permutation::factorials[] = {
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800
};

#define SZ 9
#define SZ_FACTORIAL 362880
#define START 46233
int pi[SZ_FACTORIAL];
char mask[SZ_FACTORIAL];

inline void swap(int &a, int &b) { int c = a; a = b; b = c; }

void precalc() {
	static int que[SZ_FACTORIAL];
	int i = 0, j = 1, k, m, *ptr, a;

	memset(mask, 0, sizeof(mask));
	mask[START] = '\n';
	que[0] = START;
	pi[START] = START;

	while (i < j) {
		k = que[i++];

		ptr = Permutation::calcPermutation(k, SZ);
		for (a = 0; a < SZ; ++a) if (!ptr[a]) break;

		if (a != 2 && a != 5 && a != 8) {
			swap(ptr[a], ptr[a+1]);
			m = Permutation(ptr, SZ).getNumber();
			if (!mask[m]) {
				mask[m] = 'l';
				que[j++] = m;
				pi[m] = k;
			}
			swap(ptr[a], ptr[a+1]);
		}

		if (a != 0 && a != 3 && a != 6) {
			swap(ptr[a], ptr[a-1]);
			m = Permutation(ptr, SZ).getNumber();
			if (!mask[m]) {
				mask[m] = 'r';
				que[j++] = m;
				pi[m] = k;
			}
			swap(ptr[a], ptr[a-1]);
		}

		if (a >= 3) {
			swap(ptr[a], ptr[a-3]);
			m = Permutation(ptr, SZ).getNumber();
			if (!mask[m]) {
				mask[m] = 'd';
				que[j++] = m;
				pi[m] = k;
			}
			swap(ptr[a], ptr[a-3]);
		}

		if (a < SZ-3) {
			swap(ptr[a], ptr[a+3]);
			m = Permutation(ptr, SZ).getNumber();
			if (!mask[m]) {
				mask[m] = 'u';
				que[j++] = m;
				pi[m] = k;
			}
			swap(ptr[a], ptr[a+3]);
		}
		delete[] ptr;
	}
}

int main() {
	int set, arr[SZ], i, x;

	precalc();

	scanf("%d", &set);
	while (set--) {
		for (i = 0; i < SZ; ++i) {
			if (scanf("%d", &x) == 1) arr[i] = x;
			else {
				arr[i] = 0;
				scanf("%*1s");
			}
		}

		x = Permutation(arr, SZ).getNumber();
		if (!mask[x]) puts("unsolvable");
		else {
			while (1) {
				putchar(mask[x]);
				if (mask[x] == '\n') break;
				x = pi[x];
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
