/* @JUDGE_ID: 19899RK 592 C++ "By Anadan" */
// Island of Logic
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
const char names[4][7] = { "divine", "human", "evil", "lying" };
struct Conversation{
	int auth, targ, what;
	char nt;
// what: 0 - divine; 1 - human; 2 - evil; 3 - lying; 4 - day; 5 - night
// targ: 0..4 - A..E;
}conv[50];

int main(){
	int set = 0, i, j, w[5];
	char str[256], res[5], day, istrue;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			gets(str);
			conv[i].auth = str[0] - 'A';
			conv[i].nt = (strstr(str, "not") != NULL);
			if (strstr(str, "day")) conv[i].what = 4;
			else if (strstr(str, "night")) conv[i].what = 5;
			else{
				if (str[3] == 'I') conv[i].targ = conv[i].auth;
				else conv[i].targ = str[3] - 'A';
				for (j = 0; strstr(str, names[j]) == NULL; ++j);
				conv[i].what = j;
			}
		}

		for (day = 0, i = 0; i < 5; ++i) res[i] = 0;
		for (w[0] = 0; w[0] < 3; ++w[0]) for (w[1] = 0; w[1] < 3; ++w[1])
		for (w[2] = 0; w[2] < 3; ++w[2]) for (w[3] = 0; w[3] < 3; ++w[3])
		for (w[4] = 0; w[4] < 3; ++w[4]) for (j = 1; j <= 2; ++j){
			for (i = 0; i < N; ++i){
				istrue = (w[conv[i].auth] == 0 || (w[conv[i].auth] == 1 && j == 1)) ^ conv[i].nt;
				if (conv[i].what >= 4){
					if (istrue ^ (conv[i].what - 3 == j)) break;
				}else if (conv[i].what == 3){
					if (istrue ^ (w[conv[i].targ] == 2 || (w[conv[i].targ] == 1 && j == 2))) break;
				}else if (istrue ^ (w[conv[i].targ] == conv[i].what)) break;
			}

			if (i < N) continue;
			for (i = 0; i < 5; ++i) res[i] |= 1 << w[i];
			day |= j;
		}

		printf("Conversation #%d\n", ++set);
		for (i = 0; i < 5; ++i) if (res[i] == 0) break;
		if (i < 5) printf("This is impossible.\n\n");
		else{
			for (i = j = 0; i < 5; ++i){
				if (res[i] == 1) printf("%c is divine.\n", 'A' + i), ++j;
				else if (res[i] == 2) printf("%c is human.\n", 'A' + i), ++j;
				else if (res[i] == 4) printf("%c is evil.\n", 'A' + i), ++j;
			}

			if (day == 1) printf("It is day.\n"), ++j;
			else if (day == 2) printf("It is night.\n"), ++j;
			if (j == 0) printf("No facts are deducible.\n");
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
