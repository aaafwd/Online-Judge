/* @JUDGE_ID: 19899RK 10700 C++ "By Anadan" */
// Camel trading
// Accepted (0.125 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

typedef long long qword;

qword min[12][12], max[12][12];
char str[512], * ptr[12];

inline int getnumber(char * str){
	int res;
	sscanf(str, "%d", &res);
	return res;
}

qword getmin(int i, int j){
	if (min[i][j] != -1) return min[i][j];
	if (i == j) min[i][j] = getnumber(ptr[i]);
	else{
		int k, tmp;
		qword q1, q2;
		for (k = i + 1; k <= j; ++k){
			q1 = getmin(i, k - 1);
			q2 = getmin(k, j);
			if (*(ptr[k] - 1) == '+') q1 += q2; else q1 *= q2;
			if (min[i][j] == -1 || min[i][j] > q1) min[i][j] = q1;
		}
	}

	return min[i][j];
}

qword getmax(int i, int j){
	if (max[i][j] != -1) return max[i][j];
	if (i == j) max[i][j] = getnumber(ptr[i]);
	else{
		int k, tmp;
		qword q1, q2;
		for (k = i + 1; k <= j; ++k){
			q1 = getmax(i, k - 1);
			q2 = getmax(k, j);
			if (*(ptr[k] - 1) == '+') q1 += q2; else q1 *= q2;
			if (max[i][j] == -1 || max[i][j] < q1) max[i][j] = q1;
		}
	}

	return max[i][j];
}

int main(){
	int set, i;
	char *p;

	scanf("%d\n", &set);
	ptr[0] = str;
	while (set--){
		gets(str);
		for (i = 0, p = str; *p; ++p){
			if (*p == '+' || *p == '*') ptr[++i] = p + 1;
		}
		memset(min, -1, sizeof(min));
		memset(max, -1, sizeof(max));
		printf("The maximum and minimum are %lld and %lld.\n", getmax(0, i), getmin(0, i));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
