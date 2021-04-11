/* @JUDGE_ID: 19899RK 10058 C++ "By Anadan" */
// Jimmy's Riddles
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int off;
char *cur, buf[256];
const char nouns[8][8] = {
	"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"
};

int actor(){
	sscanf(cur, "%s%n", buf, &off); cur += off;
	if (strcmp(buf, "a") == 0 || strcmp(buf, "the") == 0){
		sscanf(cur, "%s%n", buf, &off); cur += off;
	}

	for (off = 0; off < 8; ++off) if (!strcmp(buf, nouns[off])) break;
	if (off == 8) return 0;
	return 1;
}

int verb(){
	sscanf(cur, "%s%n", buf, &off); cur += off;
	off = strlen(buf);

	if (off == 5){
	 	if (buf[--off] != 's') return 0;
	 	buf[off] = 0;
	}
	if (off != 4) return 0;

	if (!strcmp(buf, "hate")) return 1;
	if (!strcmp(buf, "love")) return 1;
	if (!strcmp(buf, "know")) return 1;
	if (!strcmp(buf, "like")) return 1;

	return 0;
}

int active_list(){
	if (!actor()) return 0;
	while (1){
		sscanf(cur, "%s%n", buf, &off);
		if (strcmp(buf, "and") == 0){
			cur += off;
	   		if (!actor()) return 0;
	   	}else break;
	}

	return 1;
}

int action(char *p){
	cur = p;
	if (!active_list()) return 0;
	if (!verb()) return 0;
	if (!active_list()) return 0;

	while (*cur) if (*cur != ' ') break; else ++cur;
	if (*cur) return 0;
	return 1;
}

int main(){
	char str[256], *p;

	while (gets(str)){
		p = strtok(str, ",");
		while (p){
			if (!action(p)) break;
			p = strtok(NULL, ",");
		}

		if (p) printf("NO I WON'T\n"); else printf("YES I WILL\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
