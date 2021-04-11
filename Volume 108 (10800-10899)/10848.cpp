/* @JUDGE_ID: 19899RK 10848 C++ "By Anadan" */
// Make Palindrome Checker
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int freq1[256], freq2[256];

int isInputCorrect(char * s1, char * num, char * s2) {
	int len;

	len = strlen(s1);
	if (len == 0 || len > 1000) return 0;
	len = strlen(s2);
	if (len == 0 || len > 2000) return 0;

	for (; *s1; ++s1) if (*s1 < 'a' || *s1 > 'z') return 0;
	for (; *s2; ++s2) if (*s2 < 'a' || *s2 > 'z') return 0;
	for (; *num; ++num) if (*num < '0' || *num > '9') return 0;

	return 1;
}

int palindrome(char * p) {
	char * q = p + strlen(p) - 1;
	while (p < q && *p == *q) { ++p; --q; }
	return (p >= q);
}

// all letters of the first string appear in the second string.
int property3(char * p1, char * p2) {
	int i;

	memset(freq1, 0, sizeof(freq1));
	memset(freq2, 0, sizeof(freq2));
	for (; *p1; ++p1) ++freq1[*p1];
	for (; *p2; ++p2) ++freq2[*p2];

	for (i = 0; i < 256; ++i) {
		if (freq1[i] && !freq2[i]) return 0;
	}
	return 1;
}

// the frequency of every letter in the second string is at least
// the frequency of this letter in the first string.
int property4(char * p1, char * p2) {
	int i;
	for (i = 0; i < 256; ++i) {
		if (freq1[i] > freq2[i]) return 0;
	}
	return 1;
}

// the first string can be made out of the second string by removing 0
// or more letters (and leaving the order of the letters intact).
int property5(char * p1, char * p2) {
	for (; *p1; ++p1, ++p2) {
		p2 = strchr(p2, *p1);
		if (!p2) return 0;
	}
	return 1;
}

// length of the second string is equal to
// the length of the first string plus the value of the integer.
int property6(char * p1, char * p2, int num) {
	return (strlen(p2) == strlen(p1) + num);
}

// the value of the integer is smaller than the length of the first string.
int property7(char * p1, char * p2, int num) {
	return (num < strlen(p1));
}

int main() {
	int num;
	char str[5100], *p1, *p2, res[8], accepted;

	while (gets(str)) {
		p1 = strchr(str, ' ');
		if (p1) p2 = strchr(p1 + 1, ' ');
		if (!p1 || !p2) {
			puts("FFFFFFF The solution is not accepted");
			continue;
		}

		*p1++ = 0;
		*p2++ = 0;
		sscanf(p1, "%d", &num);
		if (!isInputCorrect(str, p1, p2) || num < 0 || num > 1000) {
			puts("FFFFFFF The solution is not accepted");
			continue;
		}

		p1 = str;
		strcpy(res, "TTTTTTT");
		accepted = 1;

		if (!palindrome(p2)) { res[1] = 'F'; accepted = 0; }
		if (!property3(p1, p2)) { res[2] = 'F'; accepted = 0; }
		if (!property4(p1, p2)) { res[3] = 'F'; accepted = 0; }
		if (!property5(p1, p2)) { res[4] = 'F'; accepted = 0; }
		if (!property6(p1, p2, num)) { res[5] = 'F'; accepted = 0; }
		if (!property7(p1, p2, num)) { res[6] = 'F'; accepted = 0; }

		printf("%s ", res);
		if (accepted) puts("The solution is accepted");
		else puts("The solution is not accepted");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
