/* @JUDGE_ID: 19899RK 10606 C++ "By Anadan" */
// Opening Doors
// Accepted (1.301 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

char * squareRoot(char * str) {
	static char res[256], buf[512];
	char * r = res + sizeof(res) - 1, * s = str, * p, * A = buf + sizeof(res);
	int len = strlen(str), x, a, rest, lx, rx;

	*r-- = 0;
	if (len & 1) x = *s++ - '0';
	else { x = (s[0] - '0') * 10 + s[1] - '0'; s += 2; }

	for (a = 1; a < 10; ++a) if (a * a > x) break;
	*r-- = --a + '0';

	if (*s) {
		sprintf(A, "%d", x - a*a);
		_reverse(A);
		do {
			A -= 2;
			A[0] = s[1];
			A[1] = s[0];
			if (A[3] == 0) {
				for (a = 2; a > 0 && A[a] == '0'; A[a--] = 0);
			}

			s += 2;
			*r = '0';

			lx = 0; rx = 9;
			while (lx != rx) {
				x = (lx + rx + 1) >> 1;

				a = 1;
				rest = x * x;
				for (p = r; *p; ++p) {
					rest += (*p - '0') * 2 * x;
					len = rest % 10 + '0';
					if (len < A[int(p - r)]) a = 1;
					else if (len > A[int(p - r)]) a = 0;
					if (!A[int(p - r)]) break;
					rest /= 10;
				}
				if (!*p) {
					while (rest) {
						len = rest % 10 + '0';
						if (len < A[int(p - r)]) a = 1;
						else if (len > A[int(p - r)]) a = 0;
						if (!A[int(p - r)]) break;
						rest /= 10;
						++p;
					}
					if (A[int(p - r)]) a = 1;
				}

				if (a) lx = x; else rx = x - 1;
			}
			x = lx;

			rest = -x * x;
			for (a = 0, p = r; *p && A[a]; ++p, ++a) {
				rest += A[a] - '0' - (*p - '0') * 2 * x;
				if (rest >= 0) {
					A[a] = rest % 10 + '0';
					rest /= 10;
				} else {
					A[a] = rest % 10 + '0';
					rest /= 10;
					if (A[a] < '0') {
						A[a] += 10;
						--rest;
					}
				}
			}
			for (; A[a]; ++a) {
				rest += A[a] - '0';
				if (rest >= 0) {
					A[a] = rest % 10 + '0';
					rest /= 10;
				} else {
					A[a] = rest % 10 + '0';
					rest /= 10;
					if (A[a] < '0') {
						A[a] += 10;
						--rest;
					}
				}
			}
			A[a] = 0;

			*r-- = x + '0';
			for (--a; a > 0 && A[a] == '0'; --a) A[a] = 0;

		} while (*s);
	}

	return r + 1;
}

char * sqr(char * str) {
	static char res[256];
	int arr[256], i, j, rest = 0;

	memset(arr, 0, sizeof(arr));
	for (i = 0; str[i]; ++i) {
		for (j = 0; str[j]; ++j) {
			arr[i+j] += (str[i] - '0') * (str[j] - '0');
		}
	}

	for (i = 255; arr[i] == 0; --i);
	str = res;
	for (j = 0; j <= i; ++j) {
		rest += arr[j];
		*str++ = rest%10 + '0';
		rest /= 10;
	}
	while (rest) {
		*str++ = rest%10 + '0';
		rest /= 10;
	}
	*str = 0;
	_reverse(res);
	return res;
}

int main() {
	char str[256], *p;

	while (scanf("%s", str) == 1 && strcmp(str, "0")) {
		for (p = str; *p == '0'; ++p);
		if (!*p) --p;
		puts(sqr(squareRoot(p)));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
