/* @JUDGE_ID: 19899RK 139 C++ "By Anadan" */
// Telephone Tangles
// Accepted (0.578 seconds using as much as 468 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TNumber{
	struct TNumber *next;
	char number[16];
	char name[26];
	double price;
} *head = (TNumber *)malloc(sizeof(TNumber)), *last = head;

TNumber * getnumber(char *number, char *sub) {
	int len, i;
	char *s1, *s2;
	TNumber *p;

	// Local
	if (number[0] != '0') {
		strcpy(sub, number);
		return head;
	}
	len = strlen(number);

	// STD
	for (p = head->next; p; p = p->next) {
		i = strlen(p->number);
		if (len - i < 4 || len - i > 7) continue;
		for (s1 = p->number, s2 = number; *s1; s1++, s2++) {
			if (*s1 != *s2) break;
		}

		if (*s1 == 0) {
			strcpy(sub, s2);
			return p;
		}
	}

	// IDD
	if (number[1] == '0') {
		for (p = head->next; p; p = p->next) {
			i = strlen(p->number);
			if (len - i < 4 || len - i > 10) continue;
			for (s1 = p->number, s2 = number; *s1; s1++, s2++) {
				if (*s1 != *s2) break;
			}

			if (*s1 == 0) {
				strcpy(sub, s2);
				return p;
			}
		}
	}

	return NULL;
}

int main() {
	TNumber *p;
	double min;
	char number[16], sub[16], name[26], *str;

	strcpy(head->name, "Local");
	head->number[0] = 0;
	head->price = 0.0;
	head->next = NULL;
	while (1) {
		scanf("%s", number);
		if (!strcmp(number, "000000")) break;
		last = last->next = (TNumber *)malloc(sizeof(TNumber));
		last->next = NULL;
		scanf(" %[^$]$%lf\n", last->name, &last->price);
		last->price *= 0.01;
		strcpy(last->number, number);
	}

	while (scanf("%s %lf\n", number, &min) == 2) {
		if (number[0] == '#') break;
		p = getnumber(number, sub);
		if (p) printf("%-16s%-25s%10s%5.0lf%6.2lf%7.2lf\n", number, p->name, sub, min, p->price, p->price * min);
		else printf("%-16s%-25s%10s%5.0lf        -1.00\n", number, "Unknown", " ", min);
	}

	while (head) {
		last = head->next;
		free(head);
		head = last;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
