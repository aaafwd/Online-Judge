/* @JUDGE_ID: 19899RK 10027 C++ "By Anadan" */
// Language Cardinality
// Accepted (0.078 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
#define MAX_STR 1000

struct Rules {
	int len1;
	char s1[16], s2[16], substr;
} pt[101];
int totalRules;
std::set<std::string> myset;

void addRule(char * str) {
	char *p = strchr(str, '-');
	p[0] = p[-1] = str[strlen(str) - 1] = 0;
	strcpy(pt[totalRules].s1, str + 1);
	strcpy(pt[totalRules].s2, p + 3);
	pt[totalRules].len1 = strlen(pt[totalRules].s1);
	++totalRules;
}

int addToSet(const char * str) {
	int i, pos;
	char * p;
	
	if (myset.find(str) != myset.end()) return 0;
	myset.insert(str);
	if (myset.size() > MAX_STR) return 1;

	for (i = 0; i < totalRules; ++i) {
		if (pt[i].len1 == 0) continue;
		p = strstr(str, pt[i].s1);
		if (!p) continue;
		if (pt[i].substr) return 1;
		std::string tmp(str, p - str);
		tmp += pt[i].s2;
		tmp += (p + pt[i].len1);
		if (addToSet(tmp.c_str())) return 1;

		while ((p = strstr(p + 1, pt[i].s1)) != NULL) {
			std::string tmp(str, p - str);
			tmp += pt[i].s2;
			tmp += (p + pt[i].len1);
			if (addToSet(tmp.c_str())) return 1;
		}
	}
	return 0;
}

int main() {
	int set, i;
	char str[128], s[128];

	scanf("%d", &set);
	while (set--) {
		while (getchar() != '"');
		gets(str);
		str[strlen(str) - 1] = 0;

		totalRules = 0;
		while (gets(s) && *s) {
			addRule(s);
		}

		for (i = 0; i < totalRules; ++i) {
			pt[i].substr = 0;
			if (pt[i].len1 == 0 && strlen(pt[i].s2) != 0) break;
			if (strcmp(pt[i].s1, pt[i].s2) == 0) pt[i].len1 = 0;
			if (strstr(pt[i].s2, pt[i].s1)) pt[i].substr = 1;
		}
		if (i < totalRules) {
			puts("Too many.");
		} else {
			myset.clear();

			if (addToSet(str)) {
				puts("Too many.");
			} else {
				printf("%d\n", (int)myset.size());
			}
		}
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
