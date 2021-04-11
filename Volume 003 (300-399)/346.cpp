/* @JUDGE_ID: 19899RK 346 C++ "By Anadan" */
// Getting Chorded
// Accepted (0.283 seconds using as much as 384 kbytes)

#include <stdio.h>

int correct_note(char *s){
	if ('a' <= s[0] && s[0] <= 'z') s[0] += 'A' - 'a';
	if (s[1] == 'b' || s[1] == 'B'){
		if (s[0] == 'F'){
			s[0] = 'E'; s[1] = 0;
		}else if (s[0] == 'C'){
			s[0] = 'B'; s[1] = 0;
		}else{
			if (s[0] == 'A') s[0] = 'G'; else --s[0];
			s[1] = '#';
		}
	}

	switch (s[0]){
		case 'A': if (s[1] == 0) return 10; else return 11;
		case 'B': if (s[1] == 0) return 12;
				s[0] = 'C'; s[1] = 0; return 1;
		case 'C': if (s[1] == 0) return 1; else return 2;
		case 'D': if (s[1] == 0) return 3; else return 4;
		case 'E': if (s[1] == 0) return 5;
				s[0] = 'F'; s[1] = 0; return 6;
		case 'F': if (s[1] == 0) return 6; else return 7;
		case 'G': if (s[1] == 0) return 8; else return 9;
	}

	while (1);
	return -1;
}

char getchord(int i1, int i2, int i3){
	if (i3 < i1) i3 += 12;
	if (i3 - i1 != 7) return 0;
	if (i2 < i1) i2 += 12;
	if (i2 - i1 == 4) return 1;
	if (i2 - i1 == 3) return -1;
	return 0;
}

inline void outresult(char *s, char flag){
	if (flag > 0) printf("a %s Major chord.\n", s);
	else printf("a %s Minor chord.\n", s);
}

int main(){
	int i1, i2, i3;
	char nt1[3], nt2[3], nt3[3], flag;

	while (scanf("%s %s %s\n", nt1, nt2, nt3) == 3){
		printf("%s %s %s is ", nt1, nt2, nt3);
		i1 = correct_note(nt1);
		i2 = correct_note(nt2);
		i3 = correct_note(nt3);

		flag = getchord(i1, i2, i3);
		if (flag == 0) flag = getchord(i1, i3, i2);
		if (flag) outresult(nt1, flag);
		else{
			flag = getchord(i2, i1, i3);
			if (flag == 0) flag = getchord(i2, i3, i1);
			if (flag) outresult(nt2, flag);
			else{
				flag = getchord(i3, i1, i2);
				if (flag == 0) flag = getchord(i3, i2, i1);
				if (flag) outresult(nt3, flag);
				else printf("unrecognized.\n");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
