/* @JUDGE_ID: 19899RK 134 C++ "By Anadan" */
// Loglan-A Logical Language
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 100

int N, cur;
char *words[SZ];

char *_strdup(char *str){
	return strcpy((char *)malloc(strlen(str) + 1), str);
}

int a(){
	if (cur == N) return 0;
	if (words[cur][1]) return 0;
	if (strchr("aeiou", words[cur][0])){
		++cur;
		return 1;
	}
	return 0;
}

int mod(){
	if (cur == N) return 0;
	if (words[cur][0] != 'g' || words[cur][2]) return 0;
	if (strchr("aeiou", words[cur][1])){
		++cur;
		return 1;
	}
	return 0;
}

int ba(){
	if (cur == N) return 0;
	if (words[cur][0] != 'b' || words[cur][2]) return 0;
	if (strchr("aeiou", words[cur][1])){
		++cur;
		return 1;
	}
	return 0;
}

int da(){
	if (cur == N) return 0;
	if (words[cur][0] != 'd' || words[cur][2]) return 0;
	if (strchr("aeiou", words[cur][1])){
		++cur;
		return 1;
	}
	return 0;
}

int la(){
	if (cur == N) return 0;
	if (words[cur][0] != 'l' || words[cur][2]) return 0;
	if (strchr("aeiou", words[cur][1])){
		++cur;
		return 1;
	}
	return 0;
}

int predstring(){
	int i = cur;

	if (cur == N) return 0;
	while (i < N){
		if (strlen(words[i]) != 5) break;
		if (strchr("aeiou", words[i][4]) && !strchr("aeiou", words[i][0]) && !strchr("aeiou", words[i][3])){
			if ((strchr("aeiou", words[i][1]) && !strchr("aeiou", words[i][2])) ||
			    (!strchr("aeiou", words[i][1]) && strchr("aeiou", words[i][2]))){
				++i;
				continue;
			}
		}

		break;
	}

	if (i == cur) return 0;
	cur = i;
	return 1;
}

int predname(){
	int sav = cur;
	if (cur == N) return 0;
	if (la()){
		if (predstring()){
			return 1;
		}
	}else{
		int len = strlen(words[cur]);
		char ch = words[cur][len - 1];
		if (!strchr("aeiou", ch)){
			++cur;
			return 1;
		}
	}

	cur = sav;
	return 0;
}

int preds(){
	if (cur == N) return 0;
	if (!predstring()) return 0;
	while (a() && predstring());
	return 1;
}

int verbpred(){
	if (cur == N) return 0;
	return (mod() && predstring());
}

int statement(){
	if (predname()){
		if (verbpred()){
			predname();
			return 1;
		}
	}

	return 0;
}

int predclaim(){
	if (predname()){
		if (ba()){
			if (preds()){
				return 1;
			}
		}
	}else if (da()){
		if (preds()){
			return 1;
		}
	}

	return 0;
}

int sentence(){
	if (statement()) return (cur == N);
	cur = 0;
	if (predclaim()) return (cur == N);
	return 0;
}

int main(){
	int i, len;
	char str[256];

	while(scanf("%s", str) == 1 && str[0] != '#'){
		N = 0;
		len = strlen(str);
		while (str[len - 1] != '.'){
			words[N++] = _strdup(str);
			scanf("%s", str);
			len = strlen(str);
		}

		str[len - 1] = 0;
		words[N++] = _strdup(str);

		cur = 0;
		if (sentence()) printf("Good\n");
		else printf("Bad!\n");
		for (i = 0; i < N; ++i) free(words[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
