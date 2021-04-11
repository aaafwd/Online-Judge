/* @JUDGE_ID: 19899RK 605 C++ "By Anadan" */
// The Rotating Disk
// Accepted (0.203 seconds using as much as 700 kbytes)

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

#define SZ 6
#define SZ_FACTORIAL 720
int pi[SZ_FACTORIAL], rotPlace[SZ_FACTORIAL];
char mask[SZ_FACTORIAL];

inline void swap(int &a, int &b) { int c = a; a = b; b = c; }

void precalc() {
	int que[SZ_FACTORIAL];
	int i = 0, j = 1, k, m, *ptr, a;

	memset(mask, 0, sizeof(mask));
	mask[0] = 1;
	que[0] = 0;
	pi[0] = 0;

	while (i < j) {
		k = que[i++];

		ptr = Permutation::calcPermutation(k, SZ);
		for (a = 0; a <= SZ-4; ++a) {
			swap(ptr[a], ptr[a+3]); swap(ptr[a+1], ptr[a+2]);
			m = Permutation(ptr, SZ).getNumber();
			swap(ptr[a], ptr[a+3]); swap(ptr[a+1], ptr[a+2]);

			if (!mask[m]) {
				mask[m] = 1;
				que[j++] = m;
				pi[m] = k;
				rotPlace[m] = a;
			}
		}
		delete[] ptr;
	}
}

void rotate(int * arr, int N, int pos) {
	int i;

	swap(arr[pos+0], arr[pos+3]);
	swap(arr[pos+1], arr[pos+2]);

	for (i = 0; i < N; ++i) {
		if (i) putchar(' ');
		if (i == pos) putchar('*');
		printf("%d", arr[i] + 1);
		if (i == pos+3) putchar('*');
	}
	putchar('\n');
}

// optimizes calls of rotate() function in row
void rotateArray(int * arr, int N, int * pos, int NPos) {
	int begin[512], end[512], i, off;
	char str[2048], * p;

	begin[0] = 0;
	sprintf(str, "%d%n", arr[0]+1, &off);
	end[0] = off;

	for (i = 1; i < N; ++i) {
		p = str + end[i-1];
		*p++ = ' ';
		begin[i] = end[i-1] + 1;
		sprintf(p, "%d%n", arr[i]+1, &off);
		end[i] = begin[i] + off;
	}

	for (i = 0; i < NPos; ++i) {
		swap(arr[pos[i]+0], arr[pos[i]+3]);
		swap(arr[pos[i]+1], arr[pos[i]+2]);

		p = str + begin[pos[i]];
		sprintf(p, "%d%n", arr[pos[i]]+1, &off);
		end[pos[i]] = begin[pos[i]] + off;

		p = str + end[pos[i]];
		*p++ = ' ';
		begin[pos[i] + 1] = end[pos[i]] + 1;
		sprintf(p, "%d%n", arr[pos[i] + 1]+1, &off);
		end[pos[i] + 1] = begin[pos[i] + 1] + off;

		p = str + end[pos[i] + 1];
		*p++ = ' ';
		begin[pos[i] + 2] = end[pos[i] + 1] + 1;
		sprintf(p, "%d%n", arr[pos[i] + 2]+1, &off);
		end[pos[i] + 2] = begin[pos[i] + 2] + off;

		p = str + end[pos[i] + 2];
		*p++ = ' ';
		begin[pos[i] + 3] = end[pos[i] + 2] + 1;
		sprintf(p, "%d%n", arr[pos[i] + 3]+1, &off);
		end[pos[i] + 3] = begin[pos[i] + 3] + off;
		p[off] = ' ';

		if (pos[i] + 3 == N - 1) {
			p = str + end[pos[i] + 3];
			*p = 0;
		}

		fwrite(str, 1, begin[pos[i]], stdout);
		putchar('*');
		fwrite(str + begin[pos[i]], 1, end[pos[i]+3] - begin[pos[i]], stdout);
		putchar('*');
		fwrite(str + end[pos[i]+3], 1, end[N-1] - end[pos[i]+3], stdout);
		putchar('\n');
	}
}

void solveSmallCase(int * arr, int N) {
	int spi[SZ_FACTORIAL / SZ], que[SZ_FACTORIAL / SZ], srotPlace[SZ_FACTORIAL / SZ];
	char smask[SZ_FACTORIAL / SZ];
	int i = 0, j = 1, k, m, a, * ptr = NULL;

	memset(smask, 0, sizeof(smask));
	k = Permutation(arr, N).getNumber();
	smask[k] = 1;
	que[0] = k;
	spi[k] = k;

	while (i < j) {
		k = que[i++];

		ptr = Permutation::calcPermutation(k, N);
		for (m = 1; m < N; ++m) {
			if (ptr[m] && ptr[m] != ptr[m-1] + 1) break;
		}
		if (m >= N) break;

		for (a = 0; a <= N-4; ++a) {
			swap(ptr[a], ptr[a+3]); swap(ptr[a+1], ptr[a+2]);
			m = Permutation(ptr, N).getNumber();
			swap(ptr[a], ptr[a+3]); swap(ptr[a+1], ptr[a+2]);

			if (!smask[m]) {
				smask[m] = 1;
				que[j++] = m;
				spi[m] = k;
				srotPlace[m] = a;
			}
		}
		delete[] ptr;
		ptr = NULL;
	}

	if (ptr == NULL) puts("It is not possible to rearrange these disks in natural order.");
	else {
		delete[] ptr;
		i = 0;
		while (spi[k] != k) {
			que[i++] = k;
			k = spi[k];
		}
		while (i--) rotate(arr, N, srotPlace[que[i]]);
	}
}

void solveBigCase(int * arr, int N) {
	int * nums = new int[N], perm[SZ], sp, i, j, k;
	static int rots[65536];

	for (i = 0; i <= 1; ++i) {
		for (j = 0; j < N; ++j) nums[j] = arr[j];

		sp = 0;
		for (j = 0; j < N - SZ; ++j) {
			for (k = 0; k < N; ++k) if (nums[k] == i + j) break;
			if (j == k) continue;
			while (k > j + 3) {
				rots[sp++] = k-3;
				swap(nums[k-3], nums[k-0]);
				swap(nums[k-2], nums[k-1]);
				k -= 3;
			}
			if (k == j + 1) {
				rots[sp++] = j;
				swap(nums[j+0], nums[j+3]);
				swap(nums[j+1], nums[j+2]);
				++k;
			}
			if (k == j + 2) {
				rots[sp++] = j+1;
				swap(nums[j+1], nums[j+4]);
				swap(nums[j+2], nums[j+3]);
				++k;
			}
			rots[sp++] = j;
			swap(nums[j+0], nums[j+3]);
			swap(nums[j+1], nums[j+2]);
		}

		for (j = N - SZ; j < N; ++j) {
			if (nums[j] > i) nums[j] -= N - SZ;
			if (nums[j] < i) k = SZ - i + nums[j];
			else k = nums[j] - i;
			perm[k] = j - N + SZ;
		}

		k = Permutation(perm, SZ).getNumber();
		if (!mask[k]) continue;

		// solution
		rotateArray(arr, N, rots, sp);
//		for (i = 0; i < sp; ++i) rotate(arr, N, rots[i]);
		sp = 0;
		while (pi[k] != k) {
			rots[sp++] = k;
			k = pi[k];
		}
		while (sp--) rotate(arr, N, rotPlace[rots[sp]] + N - SZ);
		if (arr[0] != 0 && arr[0] != 1) fprintf(stderr, "ERROR: %d\n", arr[0]+1);

		delete[] nums;
		return;
	}

	puts("It is not possible to rearrange these disks in natural order.");
}

int main() {
	int arr[512], i, N = -1;

	precalc();

	while ((i = getchar()) != EOF) {
		if (i < '0' || i > '9') continue;
		if (N != -1) putchar('\n');

		arr[0] = i - '0';
		while ((i = getchar()) != EOF && '0' <= i && i <= '9') {
			arr[0] = arr[0]*10 + i - '0';
		}
		N = 1;

		while ((i = getchar()) != EOF && i != '\n') {
			if (i < '0' || i > '9') continue;
			arr[N] = i - '0';
			while ((i = getchar()) != EOF && '0' <= i && i <= '9') {
				arr[N] = arr[N]*10 + i - '0';
			}
			++N;
			if (i == EOF || i == '\n') break;
		}

		for (i = 0; i < N; ++i) {
			if (i) putchar(' ');
			printf("%d", arr[i]--);
		}
		putchar('\n');

		if (N < SZ) solveSmallCase(arr, N);
		else solveBigCase(arr, N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
