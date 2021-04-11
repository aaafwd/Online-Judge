/* @JUDGE_ID: 19899RK 471 C++ "By Anadan" */
// Magic Numbers
// Accepted (1.440 seconds using as much as 404 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>
#include <math.h>

const double max = 9876543210.0;
double M;
char nzflag, num[11], flags[10], len;

int magic(double &d){
	char str[15], *p, *s;
	sprintf(str, "%.0lf", d);

	for (s = str + 1; *s; s++){
		p = strchr(str, *s);
		if (p < s){
			int c;
			double tmp;
			if (*++s){
				sscanf(s, "%lf%n", &tmp, &c);
				d += pow(10.0, c) - tmp;
			}else d++;
			return 0;
		}
	}
	return 1;
}

void func(int i){
	if (i == 10){
		if (M == 0.0){
			printf("0 / %s = 0\n", num);
		}else{
			double tmp, tmp2;
			sscanf(num, "%lf", &tmp);
			tmp /= M; tmp2 = tmp;
			if (tmp == floor(tmp) && magic(tmp2)){
				char *p = num;
				while (*p == '0') p++;
				printf("%s / %.0lf = %.0lf\n", p, tmp, M);
			}
		}
		return;
	}
	num[i] = '0';
	if (!nzflag) { if (10 - i > len) func(i + 1); }
	else if (!flags[0]){
		flags[0]++;
		func(i + 1);
		flags[0]--;
	}
	nzflag++;
	for (num[i] = '1'; num[i] <= '9'; num[i]++){
		if (flags[num[i] - '0']) continue;
		flags[num[i] - '0']++;
		func(i + 1);
		flags[num[i] - '0']--;
	}
	nzflag--;
}

int main(){
	long N;
	double S1, S2;
	scanf("%ld\n\n", &N);
	num[10] = 0;

	while (N--){
		scanf("%s\n\n", num);
		sscanf(num, "%lf", &M);

		if (M < 100.0){
			len = strlen(num);
			memset(flags, 0, 10); nzflag = 0;
			func(0);
		}else
		for (S1 = 1.0; S1 <= max/M;){
			if (!magic(S1)) continue;
			S2 = S1*M;
			if (magic(S2)) printf("%.0lf / %.0lf = %.0lf\n", S2, S1, M);
			S1++;
		}
		if (N) printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
