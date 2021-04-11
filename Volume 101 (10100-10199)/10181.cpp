/* @JUDGE_ID: 19899RK 10181 C++ "By Anadan" */
// 15-Puzzle Problem
// Accepted (3.578 seconds using as much as 396 kbytes)

#include <stdio.h>

struct Puzzle {
	int arr[16], zero, code1, code2;
};

int threshold, minimaxThreshold, codes[2][64], dstCode1, dstCode2;
char _buf[128], *solution = _buf + 1;

inline int abs(int x) { if (x < 0) return -x; return x; }
inline void swap(int &a, int &b) { int c = a; a = b; b = c; }
inline int manhattanPath(int x, int y) { return abs((x>>2)-(y>>2)) + abs((x&3)-(y&3)); }

int solvable(Puzzle& pz) {
	int i, j, res = 0;
	for (i = 0; i < 16; ++i) {
		if (!pz.arr[i]) {
			res += i >> 2;
			continue;
		}
		for (j = i + 1; j < 16; ++j) {
			if (!pz.arr[j]) continue;
			if (pz.arr[i] > pz.arr[j]) ++res;
		}
	}
	return (res & 1);
}

int manhattanHeuristics(Puzzle& pz) {
	int i, res = 0;

	for (i = 0; i < 16; ++i) {
		if (pz.arr[i]) res += manhattanPath(pz.arr[i]-1, i);
		else pz.zero = i;
	}

	pz.code1 = 0;
	for (i = 0; i < 8; ++i) {
		pz.code1 = (pz.code1 << 4) | pz.arr[i];
	}

	pz.code2 = 0;
	for (i = 8; i < 16; ++i) {
		pz.code2 = (pz.code2 << 4) | pz.arr[i];
	}

	return res;
}

inline void swapCode(Puzzle& pz, int i, int j) {
	int ci, cj, ki = (7-i) << 2, kj = (7-j) << 2;

	if (i < 8) ci = (pz.code1 >> ki) & 15; else ci = (pz.code2 >> ki) & 15;
	if (j < 8) cj = (pz.code1 >> kj) & 15; else cj = (pz.code2 >> kj) & 15;

	if (i < 8) {
		pz.code1 &= ~(15 << ki);
		pz.code1 |= cj << ki;
	} else {
		pz.code2 &= ~(15 << ki);
		pz.code2 |= cj << ki;
	}

	if (j < 8) {
		pz.code1 &= ~(15 << kj);
		pz.code1 |= ci << kj;
	} else {
		pz.code2 &= ~(15 << kj);
		pz.code2 |= ci << kj;
	}
}

int IDA(Puzzle& pz, int depth, int lowBound) {
	int i, j, h[4], step[4];

	lowBound += depth;
	if (lowBound > threshold) {
		if (minimaxThreshold == -1 || minimaxThreshold > lowBound) {
			minimaxThreshold = lowBound;
		}
		return 0;
	}

	if (pz.code1 == dstCode1 && pz.code2 == dstCode2) {
		solution[depth] = 0;
		return 1;
	}

	for (i = 0; i < depth; ++i) {
		if (codes[0][i] == pz.code1 && codes[1][i] == pz.code2) return 0;
	}
	codes[0][depth] = pz.code1;
	codes[1][depth] = pz.code2;

	i = pz.zero;
	lowBound -= depth;
	h[0] = h[1] = h[2] = h[3] = -1;
	if ((i & 3) && solution[depth-1] != 'R') {
		step[0] = 'L';
		h[0] = lowBound - manhattanPath(pz.arr[i-1]-1, i-1) + manhattanPath(pz.arr[i-1]-1, i);
	}
	if (((i+1) & 3) && solution[depth-1] != 'L') {
		step[1] = 'R';
		h[1] = lowBound - manhattanPath(pz.arr[i+1]-1, i+1) + manhattanPath(pz.arr[i+1]-1, i);
	}
	if (i >= 4 && solution[depth-1] != 'D') {
		step[2] = 'U';
		h[2] = lowBound - manhattanPath(pz.arr[i-4]-1, i-4) + manhattanPath(pz.arr[i-4]-1, i);
	}
	if (i < 12 && solution[depth-1] != 'U') {
		step[3] = 'D';
		h[3] = lowBound - manhattanPath(pz.arr[i+4]-1, i+4) + manhattanPath(pz.arr[i+4]-1, i);
	}

	for (j = 0; j < 3; ++j) {
		if (h[j] > h[j+1]) {
			swap(h[j], h[j+1]);
			swap(step[j], step[j+1]);
			if (j) j -= 2;
		}
	}

	for (j = 0; j < 4; ++j) {
		if (h[j] == -1) continue;
		solution[depth] = step[j];
		if (step[j] == 'L') {
			swap(pz.arr[i], pz.arr[i-1]);
			pz.zero = i - 1;
			swapCode(pz, i, i-1);

			if (IDA(pz, depth + 1, h[j])) return 1;

			swap(pz.arr[i], pz.arr[i-1]);
			pz.zero = i;
			swapCode(pz, i, i-1);
		} else if (step[j] == 'R') {
			swap(pz.arr[i], pz.arr[i+1]);
			pz.zero = i + 1;
			swapCode(pz, i, i+1);

			if (IDA(pz, depth + 1, h[j])) return 1;

			swap(pz.arr[i], pz.arr[i+1]);
			pz.zero = i;
			swapCode(pz, i, i+1);
		} else if (step[j] == 'U') {
			swap(pz.arr[i], pz.arr[i-4]);
			pz.zero = i - 4;
			swapCode(pz, i, i-4);

			if (IDA(pz, depth + 1, h[j])) return 1;

			swap(pz.arr[i], pz.arr[i-4]);
			pz.zero = i;
			swapCode(pz, i, i-4);
		} else if (step[j] == 'D') {
			swap(pz.arr[i], pz.arr[i+4]);
			pz.zero = i + 4;
			swapCode(pz, i, i+4);

			if (IDA(pz, depth + 1, h[j])) return 1;

			swap(pz.arr[i], pz.arr[i+4]);
			pz.zero = i;
			swapCode(pz, i, i+4);
		}
	}
	return 0;
}

int main() {
	int set, i, h;
	Puzzle pz;

	_buf[0] = 0;

	dstCode1 = dstCode2 = 0;
	for (i = 1; i < 9; ++i) dstCode1 = (dstCode1 << 4) | i;
	for (i = 9; i < 16; ++i) dstCode2 = (dstCode2 << 4) | i;
	dstCode2 <<= 4;

	scanf("%d", &set);
	while (set--) {
		for (i = 0; i < 16; ++i) scanf("%d", pz.arr+i);
		if (!solvable(pz)) puts("This puzzle is not solvable.");
		else {
			h = threshold = manhattanHeuristics(pz);
			minimaxThreshold = -1;
			while (!IDA(pz, 0, h)) {
				threshold = minimaxThreshold;
				minimaxThreshold = -1;
			}
			puts(solution);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
