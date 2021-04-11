/* @JUDGE_ID: 19899RK 10844 C++ "By Anadan" */
// Bloques
// Accepted (4.057 seconds using as much as 1844 kbytes)

#include <stdio.h>
#include <string.h>

class BigInt {
protected:
	int * nums, len;
	static const int defSize;
	static const int base;

	void adjustNumber() {
		int i, rest = 0;

		for (i = 0; i < len; ++i) {
			rest += nums[i];
			if (rest < base) {
				nums[i] = rest;
				rest = 0;
			} else if (rest < (base << 1)) {
				nums[i] = rest - base;
				rest = 1;
			} else {
				nums[i] = rest - base - base;
				rest = 2;
			}
		}

		while (rest) {
			if (rest < base) {
				nums[len++] = rest;
				rest = 0;
			} else {
				nums[len++] = rest % base;
				rest /= base;
			}
		}
	}

public:
	BigInt(int number = 0) {
		nums = new int[defSize];
		setNumber(number);
	}

	BigInt(const BigInt & b) {
		nums = NULL;
		setNumber(b);
	}

	void setNumber(int number) {
		len = 1;
		nums[0] = number;
		adjustNumber();
	}

	void setNumber(const BigInt & b) {
		int i;
		len = b.len;
		for (i = 0; i < len; ++i) {
			nums[i] = b.nums[i];
		}
	}

	/* !!! size control not implemented !!! */
	void operator += (const BigInt & b) {
		int i, rest = 0, base2 = base + base, minLen = (len < b.len)?(len):(b.len);

		for (i = 0; i < minLen; ++i) {
			rest += nums[i] + b.nums[i];

			if (rest < base) {
				nums[i] = rest;
				rest = 0;
			} else if (rest < base2) {
				nums[i] = rest - base;
				rest = 1;
			} else {
				nums[i] = rest - base2;
				rest = 2;
			}
		}
		for (; i < len; ++i) {
			rest += nums[i];
			if (rest < base) {
				nums[i] = rest;
				rest = 0;
			} else if (rest < base2) {
				nums[i] = rest - base;
				rest = 1;
			} else {
				nums[i] = rest - base2;
				rest = 2;
			}
		}
		for (; i < b.len; ++i) {
			rest += b.nums[i];
			if (rest < base) {
				nums[i] = rest;
				rest = 0;
			} else if (rest < base2) {
				nums[i] = rest - base;
				rest = 1;
			} else {
				nums[i] = rest - base2;
				rest = 2;
			}
		}
		while (rest) {
			nums[i++] = rest % base;
			rest /= base;
		}
		len = i;
	}

	void operator = (const BigInt & b) {
		setNumber(b);
	}

	void print() const {
		int i;
		printf("%d", nums[len-1]);
		for (i = len - 2; i >= 0; --i) {
			printf("%.9d", nums[i]);
		}
	}

	~BigInt() {
		delete [] nums;
	}
};
const int BigInt::defSize = 200;
const int BigInt::base = 1000000000;

BigInt BellNumber[901], arr[901];

/* Bell Triangle
 1
 1  2
 2  3  5
 5  7 10 15
15 20 27 37 52
*/
void solve() {
	int i, j;

	BellNumber[1].setNumber(1);
	arr[1].setNumber(1);

	for (i = 2; i < 901; ++i) {
		for (j = i-1; j > 0; --j) arr[j+1] = arr[j];
		arr[1] = arr[i];
		for (j = 2; j <= i; ++j) arr[j] += arr[j-1];
		BellNumber[i] = arr[i];
	}
}

int main() {
	int i;
	solve();
	while (scanf("%d", &i) == 1 && i) {
		printf("%d, ", i);
		BellNumber[i].print();
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
